// ======================================================================
// \title  EventActionComponentImpl.cpp
// \author jonathan
// \brief  cpp file for EventAction component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <App/EventAction/EventActionComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Log/LogString.hpp"

namespace App {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  EventActionComponentImpl ::
    EventActionComponentImpl(
        const char *const compName
    ) : EventActionComponentBase(compName)
  {

  }

  void EventActionComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    EventActionComponentBase::init(queueDepth, instance);
  }

  EventActionComponentImpl ::
    ~EventActionComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void EventActionComponentImpl ::
    seqResp_handler(
        const NATIVE_INT_TYPE portNum,
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CommandResponse response
    )
  {
    Fw::LogStringArg message("Response");
    this->log_ACTIVITY_HI_EVA_EVENT(message);
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void EventActionComponentImpl ::
    EVAC_RUN_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    //this->set_seqRun_OutputPort()
    Fw::LogStringArg message("EVAC_RUN_cmdHandler reached");
    this->log_ACTIVITY_HI_EVA_EVENT(message);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace App
