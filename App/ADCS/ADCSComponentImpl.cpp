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
#include <App/Config/ADCSCfg.hpp>
#include <Fw/Logger/Logger.hpp>
#include <stdio.h>
#include <cctype>

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
    if(packet[2] < 128){
      log_ACTIVITY_LO_MS_TC_RECV_ADCS(packet[2],packet[3]);
      tlmWrite_ADCS_LAST_CMD(packet[3]);
    }else{
      log_ACTIVITY_LO_MS_TM_RECV_ADCS(packet[2],packet[3]);
      tlmWrite_ADCS_LAST_TM_DATA(packet[3]);
    }

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
    if(id < 128){
      log_WARNING_LO_MS_ID_ERROR(id);  
      this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_EXECUTION_ERROR);
      return;
    }
    this->dataSendTmBuffer.getData()[2] = id;
    log_ACTIVITY_LO_MS_TM_SEND_ADCS(id);
    this->DataOut_out(0,dataSendTmBuffer);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
         
  }

  void ADCSComponentImpl::
  MS_SEND_CMD_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          U8 id, /*!< The telecommand id*/
          const Fw::CmdStringArg& payload /*!< The payload data*/
      )
      {
      if(id > 127){
        log_WARNING_LO_MS_ID_ERROR(id);  
        this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_EXECUTION_ERROR);
        return;
    }
        const char* data = payload.toChar();
        int isPayload = strcmp(data,"null");
        Fw::LogStringArg eventLog(data);
        const NATIVE_UINT_TYPE len = (isPayload != 0) ? payload.length()/2 + SIZE_TC_PACKET : SIZE_TC_PACKET;
        U8 hexData[len]; 
        dataSendTcBuffer.setSize(len);
        if(isPayload != 0){
            if(!isPayloadOK(data,payload.length())){
                log_WARNING_LO_MS_TC_PAYLOAD_ERROR(id,eventLog);
                this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_EXECUTION_ERROR);
                return;
            }
            stringToHex(data,hexData);
        }
        setTcPacket(hexData,id,len);
        dataSendTcBuffer.setData(hexData);
        this->DataOut_out(0,dataSendTcBuffer);
        log_ACTIVITY_LO_MS_TC_SEND_ADCS(id,eventLog);
        this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
      }

      void ADCSComponentImpl::stringToHex(const char* data, U8 hexArray[]){
          for (size_t count = 3; count < sizeof data/sizeof *data; count++) {
            sscanf(data, "%2hhx", &hexArray[count]);
            data += 2;
        }
      }

     void ADCSComponentImpl::setTcPacket(U8 hexData[],U8 id, NATIVE_UINT_TYPE len){
        hexData[0]=0x1F;
        hexData[1]=0x7f;
        hexData[2]=id;
        hexData[len-1]=0xFF;
        hexData[len-2]=0x1F;
        hexData[len-3]= adcsHelper.getCrc(hexData,len);
      }
    
    bool ADCSComponentImpl::isPayloadOK(const char* payload,NATIVE_UINT_TYPE len){
        if(len % 2 == 1){
          return false;
        }

      bool flag = true;

      for (int i=0; i<len; i++)
      {
          if (!isxdigit(payload[i]))
          {
              flag = false;
              break;
          }
      }
      
      return flag;

    }
  U8 ADCSComponentImpl::TmPacket[] = {0x1F,0x7F,0x00,0x1F,0xFF};

} // end namespace App
