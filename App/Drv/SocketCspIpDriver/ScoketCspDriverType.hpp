/*
 * SocketIpTypes.hpp
 *
 *  Created on: Jun 2, 2020
 *      Author: tcanham
 */

#ifndef DRV_SOCKETCSPDRIVER_SOCKETCSPDRIVERTYPES_HPP_
#define DRV_SOCKETCSPDRIVER_SOCKETCSPDRIVERTYPES_HPP_

namespace Drv {


    // Put the definitions here so that the
    // driver and helper can share

    enum SocketCspProtocol {
        CSP_SOCK_PROT_RDP, //!< Send using RDP
        CSP_SOCK_PROT_UDP_CSP //!< Send using UDP
    };

    enum SocketCspStatus {
        CSP_SOCK_SUCCESS = 0,
        CSP_SOCK_INIT_FAILED = -1,
        CPS_SOCK_INTERFACE_KISS_FAILED = -2,
        CSP_SOCK_INTERFACE_CAN_FAILED = -3,
        CSP_SOCK_INTERFACE_ZMQ_FAILED = -4,
        CSP_SOCK_LOAD_RTABLE_FAILED = -5,
        CSP_SOCK_CONNNECT_FAILED = -6,
        CSP_SOCK_GET_BUFFER_FAILED = -7,
        CSP_SOCK_SEND_FAILED = -8
    };


}

#endif