// ======================================================================
// \title  ADCSComponentImpl.cpp
// \author root
// \brief  cpp file for ADCS component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <App/ADCS/ADCSComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include <Fw/Types/Assert.hpp>
#include <Fw/Logger/Logger.hpp>

namespace App {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ADCSComponentImpl ::
    ADCSComponentImpl(
        const char *const compName
    ) : ADCSComponentBase(compName)
  {
    dataSendTmBuffer.setSize(5);
    dataSendTmBuffer.setData(ADCSComponentImpl::TmPacket);
  }

  void ADCSComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    ADCSComponentBase::init(queueDepth, instance);
  }

  ADCSComponentImpl ::
    ~ADCSComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void ADCSComponentImpl ::
    DataIn_handler(
        const NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
     U8* packet = fwBuffer.getData();
    log_ACTIVITY_LO_MS_TM_RECV_ADCS(packet[2],packet[3]);
    tlmWrite_ADCS_PARAM(packet[3]);
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void ADCSComponentImpl ::
    MS_GET_TM_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        U8 id
    )
  {
   this->dataSendTmBuffer.getData()[2] = id;
   this->DataOut_out(0,dataSendTmBuffer);
   log_ACTIVITY_LO_MS_TM_SEND_ADCS(id);
   this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  U8 ADCSComponentImpl::TmPacket[] = {0x1F,0x7F,0x00,0x1F,0xFF};

} // end namespace App
