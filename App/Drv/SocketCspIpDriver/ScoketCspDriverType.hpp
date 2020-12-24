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
        SOCK_PROT_RDP, //!< Send using RDP
        SOCK_PROT_UDP //!< Send using UDP
    };

    enum SocketCspStatus {
        SOCK_SUCCESS = 0,
        SOCK_INIT_FAILED = -1,
        SOCK_INTERFACE_KISS_FAILED = -2,
        SOCK_INTERFACE_CAN_FAILED = -3,
        SOCK_INTERFACE_ZMQ_FAILED = -4,
        SOCK_LOAD_RTABLE_FAILED = -5,
        SOCK_CONNNECT_FAILED = -6,
        SOCK_GET_BUFFER_FAILED = -7,
        SOCK_SEND_FAILED = -8
    };


}

#endif