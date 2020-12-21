/*
 * SocketHelper.hpp
 *
 *  Created on: May 28, 2020
 *      Author: tcanham
 */

#ifndef DRV_SOCKETTCPDRIVER_SOCKETHELPER_HPP_
#define DRV_SOCKETTCPDRIVER_SOCKETHELPER_HPP_

#include <Fw/Types/BasicTypes.hpp>
#include <Drv/SocketIpDriver/SocketIpDriverTypes.hpp>
#include <SocketIpDriverCfg.hpp>
#include <Fw/Buffer/Buffer.hpp>


namespace Drv {

    class SocketTcpHelper {
        public:

            SocketTcpHelper();
            virtual ~SocketTcpHelper();
            SocketIpStatus configure(
                    const char* hostname,
                    const U16 port,
                    const U32 timeout_seconds,
                    const U32 timeout_microseconds
                    );
            bool isOpened(void);
            SocketIpStatus open(void);
            void send(U8* data, const U32 size, Fw::Buffer& back_data); //Forwards to sendto, which on some OSes requires a non-const data pointer
            void close(void);

        PRIVATE:

            SocketIpStatus openProtocol(NATIVE_INT_TYPE protocol);

            NATIVE_INT_TYPE m_socketOutFd;  //!< Input file descriptor, always TCP
            U32 m_timeoutSeconds;
            U32 m_timeoutMicroseconds;
            char m_hostname[MAX_HOSTNAME_SIZE]; //!< Hostname to supply
            U16 m_port;                    //!< IP address port used

    };

}

#endif /* DRV_SOCKETIPDRIVER_SOCKETHELPER_HPP_ */
