/*
 * SocketHelper.cpp
 *
 *  Created on: May 28, 2020
 *      Author: tcanham
 */

#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Assert.hpp>
#include <App/Drv/SocketTcpDriver/SocketTcpHelper.hpp>
#include <Fw/Logger/Logger.hpp>
#include <iostream>

// This implementation has primarily implemented to isolate
// the socket interface from the F' Fw::Buffer class.
// There is a macro in VxWorks (m_data) that collides with
// the m_data member in Fw::Buffer.


#ifdef TGT_OS_TYPE_VXWORKS
    #include <socket.h>
    #include <inetLib.h>
    #include <fioLib.h>
    #include <hostLib.h>
    #include <ioLib.h>
    #include <vxWorks.h>
    #include <sockLib.h>
    #include <fioLib.h>
    #include <taskLib.h>
    #include <sysLib.h>
    #include <errnoLib.h>
    #include <string.h>
#elif defined TGT_OS_TYPE_LINUX || TGT_OS_TYPE_DARWIN
    #include <sys/socket.h>
    #include <netdb.h>
    #include <unistd.h>
    #include <errno.h>
    #include <arpa/inet.h>
#else
    #error OS not supported for IP Socket Communications
#endif

#include <stdio.h>
#include <string.h>


namespace Drv {

    // put network specific state we need to isolate here

    SocketTcpHelper::SocketTcpHelper() : m_socketOutFd(-1)
        ,m_timeoutSeconds(0)
        ,m_timeoutMicroseconds(0)
        ,m_port(0)
    {
    }

    SocketTcpHelper::~SocketTcpHelper() {
    }

    SocketIpStatus SocketTcpHelper::configure(
            const char* hostname,
            const U16 port,
            const U32 timeout_seconds,
            const U32 timeout_microseconds
            ) {
        this->m_timeoutSeconds = timeout_seconds;
        this->m_timeoutSeconds = timeout_seconds;
        this->m_port = port;
        // copy hostname to local copy
        (void)strncpy(this->m_hostname,hostname,MAX_HOSTNAME_SIZE);
        // null terminate
        this->m_hostname[MAX_HOSTNAME_SIZE-1] = 0;
        return SOCK_SUCCESS;
    }

    bool SocketTcpHelper::isOpened(void) {
        return (-1 != this->m_socketOutFd);
    }

    void SocketTcpHelper::close(void) {
        if (this->m_socketOutFd != -1) {
            (void) ::close(this->m_socketOutFd);
        }
        this->m_socketOutFd = -1;
    }

    SocketIpStatus SocketTcpHelper::open(void) {

        SocketIpStatus status = SOCK_SUCCESS;
        // Only the input (TCP) socket needs closing
        if (this->m_socketOutFd != -1) {
            (void) ::close(this->m_socketOutFd); // Close open sockets, to force a re-open
        }
        this->m_socketOutFd = -1;
        // Open a TCP socket for incoming commands, and outgoing data if not using UDP
        status = this->openProtocol(SOCK_STREAM);
        if (status != SOCK_SUCCESS) {
            return status;
        }
         // Coding error, if not successful here
        FW_ASSERT(status == SOCK_SUCCESS);
       
        return status;

    }

    SocketIpStatus SocketTcpHelper::openProtocol(NATIVE_INT_TYPE protocol) {

        NATIVE_INT_TYPE socketFd = -1;
        struct sockaddr_in address;

        // Clear existing file descriptors
   
        if (this->m_socketOutFd != -1) {
            (void) ::close(this->m_socketOutFd);
            this->m_socketOutFd = -1;
        }
        // Acquire a socket, or return error
        if ((socketFd = ::socket(AF_INET, protocol, 0)) < 0) {
            return SOCK_FAILED_TO_GET_SOCKET;
        }
        // Set up the address port and name
        address.sin_family = AF_INET;
        address.sin_port = htons(this->m_port);
  #if defined TGT_OS_TYPE_VXWORKS || TGT_OS_TYPE_DARWIN
        address.sin_len = static_cast<U8>(sizeof(struct sockaddr_in));
  #endif
  // Get the IP address from host
  #ifdef TGT_OS_TYPE_VXWORKS
        address.sin_addr.s_addr = inet_addr(this->m_hostname);
  #else
        // Set timeout socket option
        struct timeval timeout;
        timeout.tv_sec = this->m_timeoutSeconds;
        timeout.tv_usec = this->m_timeoutMicroseconds;
        // set socket write to timeout after 1 sec
        if (setsockopt(socketFd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
            (void) ::close(socketFd);
            return SOCK_FAILED_TO_SET_SOCKET_OPTIONS;
        }
        // Get possible IP addresses
        struct hostent *host_entry;
        if ((host_entry = gethostbyname(this->m_hostname)) == NULL || host_entry->h_addr_list[0] == NULL) {
            ::close(socketFd);
            return SOCK_FAILED_TO_GET_HOST_IP;
        }
        // First IP address to socket sin_addr
        if (inet_pton(address.sin_family, m_hostname, &(address.sin_addr)) < 0) {
            ::close(socketFd);
            return SOCK_INVALID_IP_ADDRESS;
        };
  #endif
        // If TCP, connect to the socket to allow for communication
        if (connect(socketFd, reinterpret_cast<struct sockaddr *>(&address),
                sizeof(address)) < 0) {
            ::close(socketFd);
            return SOCK_FAILED_TO_CONNECT;
        }

        this->m_socketOutFd = socketFd;

        Fw::Logger::logMsg("Connected to %s:%hu for %s using %s\n", reinterpret_cast<POINTER_CAST>(m_hostname), m_port,
                           reinterpret_cast<POINTER_CAST>("ADCS"),
                           reinterpret_cast<POINTER_CAST>("tcp"));
        return SOCK_SUCCESS;

    }

    void SocketTcpHelper::send(U8* data, const U32 size,  Fw::Buffer& backBuffer) {

        U32 total = 0;
        NATIVE_INT_TYPE valread;
        // Prevent transmission before connection, or after a disconnect
        if (this->m_socketOutFd == -1) {
            return;
        }
        // Attempt to send out data
        for (U32 i = 0; i < MAX_SEND_ITERATIONS && total < size; i++) {
            I32 sent = 0;
            sent = ::send(this->m_socketOutFd, data + total, size - total, SOCKET_SEND_FLAGS);

            // Error is EINTR, just try again
            if (sent == -1 && errno == EINTR) {
                continue;
            }
            // Error bad file descriptor is a close
            else if (sent == -1 && errno == EBADF) {
                Fw::Logger::logMsg("[ERROR] Server disconnected\n");
                this->close();
                this->m_socketOutFd = -1;
                break;
            }
            // Error returned, and it wasn't an interrupt
            else if (sent == -1 && errno == EINTR) {
                Fw::Logger::logMsg("[ERROR] IP send failed ERRNO: %d UDP: %d\n", errno, false);
                break;
            }
            // Successful write
            else {
                total += sent;
            }
        }
        valread = ::read( this->m_socketOutFd , backBuffer.getData(), MAX_RECV_BUFFER_SIZE);
        backBuffer.setSize(total);
    }
}
