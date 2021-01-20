// ======================================================================
// \title  EPSComponentImpl.cpp
// \author root
// \brief  cpp file for EPS component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <App/EPS/EPSComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include "App/Config/EPSCfg.hpp"
#include "App/Config/SocketCspIpDriverCfg.hpp"
#include "App/EPS/EPSHkAnalyser.hpp"
#include <stdio.h>
#include <cctype>

namespace App {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  EPSComponentImpl ::
    EPSComponentImpl(
        const char *const compName
    ) : EPSComponentBase(compName)
  {

  }

  void EPSComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    EPSComponentBase::init(queueDepth, instance);
  }

  EPSComponentImpl ::
    ~EPSComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------
  void EPSComponentImpl ::
    PingIn_handler(
        const NATIVE_INT_TYPE portNum,
        U32 key
    )
  {
    U8 noData[0];
    m_key = key;
    dataSendCmdBuffer.setData(noData);
    dataSendCmdBuffer.setSize(0);
    this->DataOut_out(0,CSP_PING_PORT,dataSendCmdBuffer,0);
  }

  void EPSComponentImpl ::
    DataIn_handler(
        const NATIVE_INT_TYPE portNum,
        U8 port,
        Fw::Buffer &data,
        U8 isSched
    )
  {
  U8* returnData = data.getData();
  U32 returnSize = data.getSize();
  U8 status = returnData[EPSSTATUS];
  if(port == 1){
    U32 ping = bytesToInt(returnData);
    if((I32)ping != -1){
       PingOut_out(0,m_key);
    }
    return;
  }
  if(status){
    log_WARNING_LO_MS_CMD_ERROR(port,returnData[EPSCMD],returnData[EPSSTATUS]);

  }else{
    if(isSched){
      EPSHkAnalyser helper(data);
      U8 mode = helper.getbattMode();
      U16 voltage = helper.getvBatt();
      U16 temp = helper.getTemp();
      tlmWrite_EPS_Battery_mode(mode);
      tlmWrite_EPS_Voltage_battery_mV(voltage);
      tlmWrite_EPS_Temp_Battery_Celsuis(temp);

      if(mode != this->battMode){
        log_WARNING_HI_MS_CHNG_BATT_MOD(mode);
      }
      if(voltage < EPS_LIMIT_LOW_BATTERY){
        log_WARNING_HI_MS_BATT_VOLT_LOW(voltage);
      }
      if(temp > EPS_LIMIT_TEMP_HIGH){
        log_WARNING_HI_MS_BATT_TEMP_HIGH(temp);
      }
              
    }else{
      if(port == EPS_INST_TLM_PORT){
      char returnString[returnSize*3];
      hexToString(returnString,returnData,returnSize);
      Fw::LogStringArg logString(returnString);
      log_ACTIVITY_LO_MS_CMD_RECV_EPS(port,returnData[EPSCMD],logString);
      Fw::TlmString tlmString(returnString);
      this->tlmWrite_EPS_LAST_CMD_RETURN(tlmString);
      }
    }
  }


  }

  void EPSComponentImpl ::
    Schedin_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    dataSendCmdBuffer.setSize(1);
    U8 hexData[] = {0x00};
    dataSendCmdBuffer.setData(hexData);

    this->DataOut_out(0,EPS_INST_TLM_PORT,dataSendCmdBuffer,1);
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void EPSComponentImpl ::
    MS_SEND_CMD_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        EPSOp operation,
        const Fw::CmdStringArg& payload
    )
  {
    const char* data = payload.toChar();
    Fw::LogStringArg eventLog(data);
    if(!isPayloadOK(data,payload.length())){
      log_WARNING_LO_MS_CMD_PAYLOAD_ERROR(eventLog);
      this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_EXECUTION_ERROR);
      return;
    }
    const NATIVE_UINT_TYPE len = payload.length()/2;
    U8 hexData[len];
    stringToHex(data,hexData);
    dataSendCmdBuffer.setSize(len);
    dataSendCmdBuffer.setData(hexData);

    U8 port;
    switch(operation){
      case EPS_DIRECT_CONTROL:
        port = EPS_DIRECT_CONTROL_PORT; 
        break;
      case EPS_CONF_MGMT:
        port = EPS_CONF_MGMT_PORT;
        break;
      case EPS_RESET_PORT:
        port = EPS_RESET_PORT_PORT;
        break;
      case EPS_INST_TLM:
        port = EPS_INST_TLM_PORT;
        break;
      case EPS_TIME_SYNC:
        port = EPS_TIME_SYNC_PORT;
        break;
      default:
        this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_EXECUTION_ERROR);
        log_WARNING_LO_MS_CMD_PORT_ERROR(operation);
        return;
      break;
    } 
    this->DataOut_out(0,port,dataSendCmdBuffer,0);
    Fw::LogStringArg logString(data);
    log_ACTIVITY_LO_MS_CMD_SEND_EPS(port,hexData[EPSCMD],logString);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void EPSComponentImpl::stringToHex(const char* data, U8 hexArray[]){
      for (size_t count = 0; count < sizeof data/sizeof *data; count++) {
        sscanf(data, "%2hhx", &hexArray[count]);
        data += 2;
    }
  }
  void EPSComponentImpl::hexToString (char* string, U8 hex[], U16 size){
      char* endofbuf = string + size*3*sizeof(char);
      for (int i = 0; i < size; i++)
      {
          if (string + 3 < endofbuf)
          {
              if (i > 0)
              {
                  string += sprintf(string, ":");
              }
              string += sprintf(string, "%02X", hex[i]);
          }
      }
    }

    bool EPSComponentImpl::isPayloadOK(const char* payload,NATIVE_UINT_TYPE len){
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

    U32 EPSComponentImpl::bytesToInt (U8* bytes){
        return  (U32)bytes[0] << 24 | (U32)bytes[1] << 16 
        | (U32)bytes[2] << 8 | (U32)bytes[3];
    }

} // end namespace App
