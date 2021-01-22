/**
 *  @file     clientserver.c
 *  @brief    TCP client-server communication.
 *
 *  Simple client server communication library used by PUSopen(R)
 *  examples. This code shall only be used in examples of PUSopen(R)
 *  usage. It shall not be used for the mission (critical) code.
 *
 *  @copyright
 *
 *  Copyright (c) 2019, 12G Flight Systems Sweden AB.
 *
 *  This program is the property of 12G Flight Systems Sweden AB.
 *  The right to copy, distribute, modify or otherwise make use
 *  of this software may be licensed only pursuant to the terms
 *  of agreement obtained from 12G Flight Systems Sweden AB.
 *
 */

/* -- Includes -- */

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32_GCC630) || defined(_WIN32_GCC630_DEMO)
  #ifndef _WIN32_WINNT
    #define _WIN32_WINNT 0x0501  /* Windows XP. */
  #endif
    #include <windows.h>
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #include <stdlib.h>
    #include <stdio.h>
#endif
#if defined(_ARM53_GCC630) || defined(_ARM53_GCC630_DEMO) || defined(_LINUB1604_GCC540) || defined(_LINUB1604_GCC810) || defined(_LINUB1804_GCC750)
  #define _DEFAULT_SOURCE      /* Required for usleep to be include in unistd.h */
  #include <sys/socket.h>
  #include <arpa/inet.h>
  #include <netinet/tcp.h>
  #include <netdb.h>
  #include <sys/ioctl.h>
  #include <sys/time.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <errno.h>
  #include <fcntl.h>
  #include <string.h>
  #include <unistd.h>
  #include <time.h>
#endif

#include "clientserver.h"

/* -- Defines -- */

/* -- Typedefs -- */

/* -- Global data -- */

/* -- Local data -- */

#define DEFAULT_PORT "27015"

#if defined(_WIN32_GCC630) || defined(_WIN32_GCC630_DEMO)
    static WSADATA wsaData;
    static struct addrinfo *result = NULL;
    static struct addrinfo hints;
    static int res;
    static SOCKET listenSocket = INVALID_SOCKET;
    static SOCKET connectSocket = INVALID_SOCKET;
#else
    static int serversocket = 0;
    static int connection = 0;
#endif

/* -- Local functions declarations -- */

/* -- Local functions -- */

/* -- Global functions -- */


/** Returns true on success, or false if there was an error */
int set_non_blocking(int fd)
{
    int res = 0;
    if (fd < 0) return -1;

#if defined(_WIN32_GCC630) || defined(_WIN32_GCC630_DEMO)
    unsigned long mode = 1; /* non-blocking */
    res = ioctlsocket(fd, FIONBIO, &mode);
#else
    res = fcntl(fd, F_SETFL, fcntl(fd, F_GETFL, 0) | O_NONBLOCK);
#endif

    if (res != 0)
    { printf("Unable to set socket to non-blocking mode (%d).\n", res); }
    else { printf("Socket in non-blocking mode (%d).\n", res); }
    return res;
}

int client(const char* addr)
{
#if defined(_WIN32_GCC630) || defined(_WIN32_GCC630_DEMO)

    res = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (res != 0) {
        printf("WSAStartup failed with error: %d\n", res);
        return 1;
    }

    ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    res = getaddrinfo(addr, DEFAULT_PORT, &hints, &result);
    if ( res != 0 ) {
        printf("getaddrinfo failed with error: %d\n", res);
        WSACleanup();
        return 1;
    }

    connectSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (connectSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    res = connect( connectSocket, result->ai_addr, (int)result->ai_addrlen);
    if (res == SOCKET_ERROR) {
        closesocket(connectSocket);
        connectSocket = INVALID_SOCKET;
    }

    freeaddrinfo(result);

    if (connectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return 1;
    }

    set_non_blocking(connectSocket);

#else
    int i = 1;
    struct sockaddr_in address;

    connection = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    memset((uint8_t*)&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(addr);
    address.sin_port = htons(27015);

    connect(connection, (struct sockaddr *) &address, sizeof(address));
    set_non_blocking(connection);
    setsockopt(connection, IPPROTO_TCP, TCP_NODELAY, (void *)&i, sizeof(i));
#endif
    return 0;
}

int client_send(char* data, int numbytes)
{
#if defined(_WIN32_GCC630) || defined(_WIN32_GCC630_DEMO)
    res = send( connectSocket, data, numbytes, 0 );
    if (res == SOCKET_ERROR) {
        printf("send failed with error: %d\n", WSAGetLastError());
        closesocket(connectSocket);
        WSACleanup();
        return 1;
    }
#else
    int res;
    res = send(connection, data, numbytes, 0);
    if (res == -1) {
        printf("Client send err.\n");
    }
#endif

    return 0;
}

int client_recv(char *data, int numbytes)
{
#if defined(_WIN32_GCC630) || defined(_WIN32_GCC630_DEMO)

    return res = recv(connectSocket, data, numbytes, 0);

#else
    return recv(connection, data, numbytes, 0);
#endif
}

int client_close()
{
#if defined(_WIN32_GCC630) || defined(_WIN32_GCC630_DEMO)
    /* shutdown the connection since no more data will be sent */
    res = shutdown(connectSocket, SD_BOTH);
    if (res == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(connectSocket);
        WSACleanup();
        return 1;
    }

    /* cleanup */
    closesocket(connectSocket);
    WSACleanup();
#else
    int res;
    res = shutdown(connection, SHUT_RDWR);
    if (res == 0) { close(connection); }
#endif

    return 0;
}

int server(void)
{
#if defined(_WIN32_GCC630) || defined(_WIN32_GCC630_DEMO)

    struct sockaddr_in sa;
    int salen = sizeof(sa);

    res = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (res != 0) {
        printf("WSAStartup failed with error: %d\n", res);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    res = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if ( res != 0 ) {
        printf("getaddrinfo failed with error: %d\n", res);
        WSACleanup();
        return 1;
    }

    listenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (listenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    res = bind( listenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (res == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);

    res = listen(listenSocket, SOMAXCONN);
    if (res == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }

    connectSocket = accept(listenSocket, (struct sockaddr *)&sa, &salen);
    if (connectSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    } else {
        printf("New connection from %s\n", inet_ntoa(sa.sin_addr));
    }

    closesocket(listenSocket);
    set_non_blocking(connectSocket);

#else

    int i = 1;
    socklen_t addrSize;
    struct sockaddr_in serverAddr, clientAddr;

    memset((uint8_t*)&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(27015);
    addrSize = sizeof(clientAddr);

    serversocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    bind(serversocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
    listen(serversocket, 5);

    connection = accept(serversocket, (struct sockaddr *) &clientAddr, &addrSize);
    printf("New connection from %s\n", inet_ntoa(clientAddr.sin_addr));
    set_non_blocking(connection);
    setsockopt(connection, IPPROTO_TCP, TCP_NODELAY, (void *)&i, sizeof(i));
#endif

    return 0;
}

int server_recv(char *data, int numbytes)
{
#if defined(_WIN32_GCC630) || defined(_WIN32_GCC630_DEMO)
    return recv(connectSocket, data, numbytes, 0);
#else
    return recv(connection, data, numbytes, 0);
#endif
}

int server_send(char* data, int numbytes)
{
#if defined(_WIN32_GCC630) || defined(_WIN32_GCC630_DEMO)
    res = send( connectSocket, data, numbytes, 0 );
    if (res == SOCKET_ERROR) {
        printf("send failed with error: %d\n", WSAGetLastError());
        closesocket(connectSocket);
        WSACleanup();
        return 1;
    }
    return res;
#else
    int res;
    res = send(connection, data, numbytes, 0);
    if (res < 0) {
        printf("Server send err (%d, %s).\n", res, strerror(errno));
    }
    return res;
#endif
}


int server_close() {
#if defined(_WIN32_GCC630) || defined(_WIN32_GCC630_DEMO)
    res = shutdown(connectSocket, SD_SEND);
    if (res == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(connectSocket);
        WSACleanup();
        return 1;
    }

    closesocket(connectSocket);
    WSACleanup();
    return 0;
#else
    int res;
    res = shutdown(connection, SHUT_RDWR);
    if (res == 0) { close(connection); }
    return 0;
#endif
}


void sleep_ms(int milliseconds)
{
    /*
#if defined(_WIN32_GCC630) || defined(_WIN32_GCC630_DEMO)
    Sleep(milliseconds);
#else
    usleep(milliseconds);
#endif*/
#if defined(_WIN32_GCC630) || defined(_WIN32_GCC630_DEMO)
    Sleep(milliseconds);
#elif _POSIX_C_SOURCE >= 199309L
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
#else
    struct timeval tv;
    tv.tv_sec = milliseconds / 1000;
    tv.tv_usec = milliseconds % 1000 * 1000;
    select(0, NULL, NULL, NULL, &tv);
#endif
}


void printHex(uint8_t *data, uint16_t len, char* hdr, uint16_t cut)
{
    int i;

    printf("%s %d bytes: ", hdr, len);

    if ((cut > 0) && (len > cut))
    {
        len = cut;
        cut = 1;
    }

    for (i = 0U; i < len; i++)
    {
        printf("%02x ", data[i]);
    }

    if (cut > 0)
    {
        printf("...");
    }

    printf("\n");
}

#ifdef __cplusplus
}
#endif

