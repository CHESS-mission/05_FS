// ======================================================================
// \title  SocketCspDriverComponentImpl.cpp
// \author root
// \brief  cpp file for SocketCspDriver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <App/Drv/SocketCspDriver/SocketCspDriverComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Drv {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  SocketCspDriverComponentImpl ::
    SocketCspDriverComponentImpl(
        const char *const compName
    ) : SocketCspDriverComponentBase(compName)
  {

  }

  void SocketCspDriverComponentImpl ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    SocketCspDriverComponentBase::init(instance);
  }

  SocketCspDriverComponentImpl ::
    ~SocketCspDriverComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void SocketCspDriverComponentImpl ::
    send_handler(
        const NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    // TODO
  }

} // end namespace Drv
