// ======================================================================
// \title  SocketCspIpDriverComponentImpl.hpp
// \author root
// \brief  hpp file for SocketCspIpDriver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef SocketCspIpDriver_HPP
#define SocketCspIpDriver_HPP

#include "App/Drv/SocketCspIpDriver/SocketCspIpDriverComponentAc.hpp"
#include "App/Drv/SocketCspIpDriver/ScoketCspDriverType.hpp"
#include "App/Drv/SocketCspIpDriver/SocketCspIpHelper.hpp"

namespace Drv {

  class SocketCspIpDriverComponentImpl :
    public SocketCspIpDriverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object SocketCspIpDriver
      //!
      SocketCspIpDriverComponentImpl(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object SocketCspIpDriver
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object SocketCspIpDriver
      //!
      ~SocketCspIpDriverComponentImpl(void);

      SocketCspStatus configure(
            I32 address,
            const char* zmqHost
        );
      SocketCspStatus open(I32 server_address);
      void close(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for send
      //!
      void send_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U8 port, 
          Fw::Buffer &data 
      );

      SocketCspIpHelper m_helper;

      Fw::Buffer outBuffer;           //!< Fw::Buffer used to pass data
      U8 outBufferData [MAX_SIZE_PACKET]; //!< Buffer used to store data

    };

} // end namespace Drv

#endif
