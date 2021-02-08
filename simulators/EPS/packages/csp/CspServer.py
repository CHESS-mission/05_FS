#!/usr/bin/python3

# Build required code:
# $ ./examples/buildall.py
#
# Start zmqproxy (only one instance)
# $ ./build/zmqproxy
#
# Run server, default enabling ZMQ interface:
# $ LD_LIBRARY_PATH=build PYTHONPATH=build python3 examples/CspServer.py
#

import os
import time
import sys
import threading

import packages.csp.lib.libcsp_py3 as libcsp


def csp_server(eps):
    sock = libcsp.socket()
    libcsp.bind(sock, libcsp.CSP_ANY)
    libcsp.listen(sock, 10)
    while True:
        # wait for incoming connection
        print("Waiting connexion")
        conn = libcsp.accept(sock, libcsp.CSP_MAX_TIMEOUT)
        if not conn:
            continue

        print ("connection: source=%i:%i, dest=%i:%i" % (libcsp.conn_src(conn),
                                                         libcsp.conn_sport(conn),
                                                         libcsp.conn_dst(conn),
                                                         libcsp.conn_dport(conn)))

        while True:
            # Read all packets on the connection
            packet = libcsp.read(conn, 100)
            if packet is None:
                break

            if libcsp.conn_dport(conn) == 7:
                # print request
                data = bytearray(libcsp.packet_get_data(packet))
                length = libcsp.packet_get_length(packet)
                print ("got packet, len=" + str(length) + ", data=" + ''.join('{:02x}'.format(x) for x in data))
                # send reply
                back_data = eps.request(data)
                print(f"volt : {back_data[26]}")
                print(f'sending data back to client : data {back_data}\n')
                reply = libcsp.buffer_get(1)
                libcsp.packet_set_data(reply, back_data)
                libcsp.sendto_reply(packet, reply, libcsp.CSP_O_NONE)

            else:
                # pass request on to service handler
                libcsp.service_handler(conn, packet)


def init(eps, address):

    # init csp
    libcsp.init(address, "test_service", "bindings", "1.2.3", 10, 300)
    libcsp.zmqhub_init(27, "localhost")
    libcsp.rtable_set(0, 0, "ZMQHUB")
    libcsp.route_start_task()

    print("Hostname: %s" % libcsp.get_hostname())
    print("Model:    %s" % libcsp.get_model())
    print("Revision: %s" % libcsp.get_revision())

    print("Routes:")
    libcsp.print_routes()

    # start CSP server
    threading.Thread(target=csp_server,args=(eps,)).start()
