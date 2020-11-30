// ======================================================================
// \title  SocketTcpDriverComponentImpl.hpp
// \author root
// \brief  hpp file for SocketTcpDriver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef SocketTcpDriver_HPP
#define SocketTcpDriver_HPP

#include "App/Drv/SocketTcpDriver/SocketTcpDriverComponentAc.hpp"
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <App/Drv/SocketTcpDriver/SocketTcpHelper.hpp>
#include <Drv/SocketIpDriver/SocketIpDriverTypes.hpp>
#include <SocketIpDriverCfg.hpp>

namespace Drv {

  class SocketTcpDriverComponentImpl :
    public SocketTcpDriverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object SocketTcpDriver
      //!
      SocketTcpDriverComponentImpl(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object SocketTcpDriver
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object SocketTcpDriver
      //!
      ~SocketTcpDriverComponentImpl(void);

      
      SocketIpStatus configure(
          const char* hostname,
          U16 port,
          const U32 timeout_seconds = SOCKET_TIMEOUT_SECONDS, /*!< Timeout(S). Default: from configuration HPP*/
          const U32 timeout_microseconds = SOCKET_TIMEOUT_MICROSECONDS /*!< Timeout(uS). Default: from configuration HPP*/
          );

      SocketIpStatus openSocket(void);

    PRIVATE:
      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for send
      //!
      void send_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Buffer &fwBuffer 
      );

      // socket helper instance
      SocketTcpHelper m_helper;

      Fw::Buffer outBuffer;           //!< Fw::Buffer used to pass data
      U8 outBufferData [MAX_RECV_BUFFER_SIZE]; //!< Buffer used to store data

    };

} // end namespace Drv

#endif
