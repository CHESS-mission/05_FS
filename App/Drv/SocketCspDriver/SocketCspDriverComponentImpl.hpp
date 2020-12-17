// ======================================================================
// \title  SocketCspDriverComponentImpl.hpp
// \author root
// \brief  hpp file for SocketCspDriver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef SocketCspDriver_HPP
#define SocketCspDriver_HPP

#include "App/Drv/SocketCspDriver/SocketCspDriverComponentAc.hpp"

namespace Drv {

  class SocketCspDriverComponentImpl :
    public SocketCspDriverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object SocketCspDriver
      //!
      SocketCspDriverComponentImpl(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object SocketCspDriver
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object SocketCspDriver
      //!
      ~SocketCspDriverComponentImpl(void);

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


    };

} // end namespace Drv

#endif
