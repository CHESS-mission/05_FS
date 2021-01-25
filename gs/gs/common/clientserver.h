/**
 *  @file     clientserver.h
 *  @brief    TCP client-server communication.
 *
 *  Simple client-server communication for PUSopen(R) examples.
 *  This code shall only be used in examples of PUSopen(R) usage.
 *  It shall not be used for the mission (critical) code.
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

#ifndef CLIENTSERVER_H
#define CLIENTSERVER_H

/* -- Includes -- */

#include "pusopen.h"

/* -- Defines -- */

/* -- Typedefs -- */

/* -- Global data -- */

/* -- Global functions -- */

#ifdef __cplusplus
extern "C" {
#endif

extern int client(const char* addr);

extern int server(void);

extern int server_send(char *data, int numbytes);

extern int server_recv(char *data, int numbytes);

extern int server_close();

extern int server_restart();

extern int client_send(char *data, int numbytes);

extern int client_recv(char *data, int numbytes);

extern int client_close();

extern int lastSockErr();

extern void sleep_ms(int milliseconds);

extern void printHex(uint8_t *data, uint16_t len, char* hdr, uint16_t cut);

#ifdef __cplusplus
}
#endif

#endif /* CLIENTSERVER_H */
