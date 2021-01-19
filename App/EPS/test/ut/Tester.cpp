// ====================================================================== 
// \title  EPS.hpp
// \author root
// \brief  cpp file for EPS test harness implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
// 
// ====================================================================== 

#include "Tester.hpp"
#include "App/Config/EPSCfg.hpp"
#include "App/Config/SocketCspIpDriverCfg.hpp"

#define INSTANCE 0
#define MAX_HISTORY_SIZE 10
#define QUEUE_DEPTH 10

namespace App {

  // ----------------------------------------------------------------------
  // Construction and destruction 
  // ----------------------------------------------------------------------

  Tester ::
    Tester(void) : 
#if FW_OBJECT_NAMES == 1
      EPSGTestBase("Tester", MAX_HISTORY_SIZE),
      component("EPS")
#else
      EPSGTestBase(MAX_HISTORY_SIZE),
      component()
#endif
  {
    this->initComponents();
    this->connectPorts();
  }

  Tester ::
    ~Tester(void) 
  {
    
  }

  // ----------------------------------------------------------------------
  // Tests 
  // ----------------------------------------------------------------------

void Tester::cmdCmdGoodpayloadGoodPort(void){
 //Init data for TM test
    EPSComponentBase::EPSOp operation = EPSComponentBase::EPS_INST_TLM;
    Fw::CmdStringArg goodPayload1("00");
    Fw::CmdStringArg goodPayload2("00A2");
    // goodpayload1
    {

    U8 cmdTheoritical = 0x00;
    U8 sizeTheoritical = 1;
    U8 dataTheoritical[sizeTheoritical] = {cmdTheoritical};
    U8 portTheoritical = (U8)EPS_INST_TLM_PORT;
    U8 schedTheoritical = 0;

    //Send MS_SEND_CMD badPayload1 command
    
    this->sendCmd_MS_SEND_CMD(0,10,operation,goodPayload1);
    //Dispatch the message queue
    this->component.doDispatch();

    //Verify port param
    U8* dataEmpirical = this->fromPortHistory_DataOut->at(0).data.getData();
    U32 sizeEmpirical = this->fromPortHistory_DataOut->at(0).data.getSize();
    U8 portEmpirical = this->fromPortHistory_DataOut->at(0).port;
    U8 schedEmpirical = this->fromPortHistory_DataOut->at(0).isSched;

    ASSERT_EQ(portTheoritical,portEmpirical);
    ASSERT_EQ(sizeTheoritical,sizeEmpirical);
    ASSERT_EQ(schedTheoritical,schedEmpirical);

    for(int i = 0; i < sizeTheoritical ;i++){
      ASSERT_EQ(dataTheoritical[i],dataEmpirical[i]);
    }

    //Verify that no port was called.
    ASSERT_FROM_PORT_HISTORY_SIZE(1);
    ASSERT_from_DataOut_SIZE(1);

    //Verifiy events
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_MS_CMD_SEND_EPS_SIZE(1);
    ASSERT_EVENTS_MS_CMD_SEND_EPS(0,portTheoritical,cmdTheoritical,goodPayload1.toChar());

    //Verify command response
    ASSERT_CMD_RESPONSE_SIZE(1);
    ASSERT_CMD_RESPONSE(0,EPSComponentBase::OPCODE_MS_SEND_CMD,10,
    Fw::COMMAND_OK);
  }

   // goodpayload2
    {

    U8 cmdTheoritical = 0x00;
    U8 sizeTheoritical = 2;
    U8 dataTheoritical[sizeTheoritical] = {cmdTheoritical,0Xa2};
    U8 portTheoritical = (U8)EPS_INST_TLM_PORT;
    U8 schedTheoritical = 0;

    //Send MS_SEND_CMD badPayload1 command
    
    this->sendCmd_MS_SEND_CMD(0,11,operation,goodPayload2);
    //Dispatch the message queue
    this->component.doDispatch();

    //Verify port param
    U8* dataEmpirical = this->fromPortHistory_DataOut->at(1).data.getData();
    U32 sizeEmpirical = this->fromPortHistory_DataOut->at(1).data.getSize();
    U8 portEmpirical = this->fromPortHistory_DataOut->at(1).port;
    U8 schedEmpirical = this->fromPortHistory_DataOut->at(1).isSched;

    ASSERT_EQ(portTheoritical,portEmpirical);
    ASSERT_EQ(sizeTheoritical,sizeEmpirical);
    ASSERT_EQ(schedTheoritical,schedEmpirical);

    for(int i = 0; i < sizeTheoritical ;i++){
      ASSERT_EQ(dataTheoritical[i],dataEmpirical[i]);
    }

    //Verify that no port was called.
    ASSERT_FROM_PORT_HISTORY_SIZE(2);
    ASSERT_from_DataOut_SIZE(2);

    //Verifiy events
    ASSERT_EVENTS_SIZE(2);
    ASSERT_EVENTS_MS_CMD_SEND_EPS_SIZE(2);
    ASSERT_EVENTS_MS_CMD_SEND_EPS(1,portTheoritical,cmdTheoritical,goodPayload2.toChar());

    //Verify command response
    ASSERT_CMD_RESPONSE_SIZE(2);
    ASSERT_CMD_RESPONSE(1,EPSComponentBase::OPCODE_MS_SEND_CMD,11,
    Fw::COMMAND_OK);
  }

    this->clearHistory();
    
  }
  void Tester::cmdCmdbadPayload(void){
    //Init data for TM test
    EPSComponentBase::EPSOp operation = EPSComponentBase::EPS_INST_TLM;
    Fw::CmdStringArg badPayload1("bad");
    Fw::CmdStringArg badPayload2("0AB");
    Fw::CmdStringArg badPayload3("bads");

    //Send MS_SEND_CMD badPayload1 command
    {
    this->sendCmd_MS_SEND_CMD(0,10,operation,badPayload1);
    //Dispatch the message queue
    this->component.doDispatch();

    //Verify that no port was called.
    ASSERT_FROM_PORT_HISTORY_SIZE(0);

    //Verifiy events
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_MS_CMD_PAYLOAD_ERROR_SIZE(1);
    ASSERT_EVENTS_MS_CMD_PAYLOAD_ERROR(0,badPayload1.toChar());

    //Verify command response
    ASSERT_CMD_RESPONSE_SIZE(1);
    ASSERT_CMD_RESPONSE(0,EPSComponentBase::OPCODE_MS_SEND_CMD,10,
    Fw::COMMAND_EXECUTION_ERROR);
    }

    //Send MS_SEND_CMD badPayload2 command
    {
    this->sendCmd_MS_SEND_CMD(0,11,operation,badPayload2);
    //Dispatch the message queue
    this->component.doDispatch();

    //Verify that no port was called.
    ASSERT_FROM_PORT_HISTORY_SIZE(0);

    //Verifiy events
    ASSERT_EVENTS_SIZE(2);
    ASSERT_EVENTS_MS_CMD_PAYLOAD_ERROR_SIZE(2);
    ASSERT_EVENTS_MS_CMD_PAYLOAD_ERROR(1,badPayload2.toChar());

    //Verify command response
    ASSERT_CMD_RESPONSE_SIZE(2);
    ASSERT_CMD_RESPONSE(1,EPSComponentBase::OPCODE_MS_SEND_CMD,11,
    Fw::COMMAND_EXECUTION_ERROR);
    }

     //Send MS_SEND_CMD badPayload3 command
    {
    this->sendCmd_MS_SEND_CMD(0,12,operation,badPayload3);
    //Dispatch the message queue
    this->component.doDispatch();

    //Verify that no port was called.
    ASSERT_FROM_PORT_HISTORY_SIZE(0);

    //Verifiy events
    ASSERT_EVENTS_SIZE(3);
    ASSERT_EVENTS_MS_CMD_PAYLOAD_ERROR_SIZE(3);
    ASSERT_EVENTS_MS_CMD_PAYLOAD_ERROR(2,badPayload3.toChar());

    //Verify command response
    ASSERT_CMD_RESPONSE_SIZE(3);
    ASSERT_CMD_RESPONSE(2,EPSComponentBase::OPCODE_MS_SEND_CMD,12,
    Fw::COMMAND_EXECUTION_ERROR);
    }

    this->clearHistory();

  }
  /*void Tester::cmdCmdbadPort(void){
  EPSComponentBase::EPSOp badOperation = (EPSComponentBase::EPSOp)12;
   Fw::CmdStringArg payload("00");


    //Send MS_SEND_CMD badOperation command
    {
    this->sendCmd_MS_SEND_CMD(0,10,badOperation,payload);
    //Dispatch the message queue
    this->component.doDispatch();

    //Verify that no port was called.
    ASSERT_FROM_PORT_HISTORY_SIZE(0);

    //Verifiy events
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_MS_CMD_PORT_ERROR_SIZE(1);
    ASSERT_EVENTS_MS_CMD_PORT_ERROR(0,badOperation);

    //Verify command response
    ASSERT_CMD_RESPONSE_SIZE(1);
    ASSERT_CMD_RESPONSE(0,EPSComponentBase::OPCODE_MS_SEND_CMD,10,
    Fw::COMMAND_EXECUTION_ERROR);
    }

    this->clearHistory();

  }*/
  void Tester::portStatusOKSched(void){
     //Init data for cmd test
    Fw::Buffer bufferData;
    U8 port = EPS_INST_TLM_PORT;
    U8 sched = 1;
    U8 dataSize = 232;
    U8 data[dataSize] = {0};
    data[EPSCMD] = 0x00;
    data[EPSSTATUS] = 0x00;
    data[EPSVBATT] = 10;
    data[EPSTEMP] = 50;
    data[EPSBATTMODE] = 2;
    bufferData.setData(data);
    bufferData.setSize(dataSize);
    //Invoke DataIn port
    this->invoke_to_DataIn(0,port,bufferData,sched);
    //Dispatch the message queue
    this->component.doDispatch();

   
    //Verify Telemetry
    ASSERT_TLM_SIZE(3);

    ASSERT_TLM_EPS_Battery_mode_SIZE(1);
    ASSERT_TLM_EPS_Battery_mode(0,data[EPSBATTMODE]);

    ASSERT_TLM_EPS_Voltage_battery_mV_SIZE(1);
    ASSERT_TLM_EPS_Voltage_battery_mV(0,data[EPSVBATT]);

    ASSERT_TLM_EPS_Temp_Battery_Celsuis_SIZE(1);
    ASSERT_TLM_EPS_Temp_Battery_Celsuis(0,data[EPSTEMP]);

    this->clearHistory();

    
  }
  void Tester::portStatusOKNoSched(void){
   //Init data for cmd test
    Fw::Buffer bufferData;
    U8 port = EPS_INST_TLM_PORT;
    U8 sched = 0;
    U8 dataSize = 232;
    U8 data[dataSize] = {0};
    data[EPSCMD] = 0x00;
    data[EPSSTATUS] = 0x00;
    data[EPSVBATT] = 10;
    data[EPSTEMP] = 50;
    data[EPSBATTMODE] = 2;
    bufferData.setData(data);
    bufferData.setSize(dataSize);
    //Invoke DataIn port
    this->invoke_to_DataIn(0,port,bufferData,sched);
    //Dispatch the message queue
    this->component.doDispatch();


    char dataTheoritical[dataSize*3];
    for(int i = 0; i< dataSize;i++){
      switch(i){
        case EPSCMD:
          strcat(dataTheoritical,"00");
          break;
        case EPSSTATUS:
          strcat(dataTheoritical,":00");
          break;
        case EPSVBATT:
          strcat(dataTheoritical,":0A");
          break;
        case EPSTEMP:
          strcat(dataTheoritical,":32");
          break;
        case EPSBATTMODE:
          strcat(dataTheoritical,":02");
          break;
        default:
          strcat(dataTheoritical,":00");
          break;
      }

    }

    //Verify Event
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_MS_CMD_RECV_EPS_SIZE(1);
    this->eventHistory_MS_CMD_RECV_EPS->at(0).payload.toChar();
    ASSERT_EVENTS_MS_CMD_RECV_EPS(0,EPS_INST_TLM_PORT,data[EPSCMD],dataTheoritical);

    //Verify Telemetry
    ASSERT_TLM_SIZE(1);
    ASSERT_TLM_EPS_LAST_CMD_RETURN_SIZE(1);
    ASSERT_TLM_EPS_LAST_CMD_RETURN(0,dataTheoritical);

    this->clearHistory();

  }
  void Tester::portStatusNOK(void){
     //Init data for cmd test
    Fw::Buffer bufferData;
    U8 port = EPS_INST_TLM_PORT;
    U8 sched = 0;
    U8 dataSize = 2;
    U8 data[dataSize] = {0};
    data[EPSCMD] = 0x00;
    data[EPSSTATUS] = 0x01;
    bufferData.setData(data);
    bufferData.setSize(dataSize);
    //Invoke DataIn port
    this->invoke_to_DataIn(0,port,bufferData,sched);
    //Dispatch the message queue
    this->component.doDispatch();

   //Verify Event
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_MS_CMD_ERROR_SIZE(1);
    ASSERT_EVENTS_MS_CMD_ERROR(0,EPS_INST_TLM_PORT,data[EPSCMD],data[EPSSTATUS]);

    this->clearHistory();
  }

  void Tester::portChangeMode(void){
     //Init data for cmd test
    Fw::Buffer bufferData;
    U8 port = EPS_INST_TLM_PORT;
    U8 sched = 1;
    U8 dataSize = 232;
    U8 data[dataSize] = {0};
    data[EPSCMD] = 0x00;
    data[EPSSTATUS] = 0x00;
    data[EPSVBATT] = 10;
    data[EPSTEMP] = 50;
    data[EPSBATTMODE] = 1;
    bufferData.setData(data);
    bufferData.setSize(dataSize);
    //Invoke DataIn port
    this->invoke_to_DataIn(0,port,bufferData,sched);
    //Dispatch the message queue
    this->component.doDispatch();

   
    //Verify Telemetry
    ASSERT_TLM_SIZE(3);

    ASSERT_TLM_EPS_Battery_mode_SIZE(1);
    ASSERT_TLM_EPS_Battery_mode(0,data[EPSBATTMODE]);

    ASSERT_TLM_EPS_Voltage_battery_mV_SIZE(1);
    ASSERT_TLM_EPS_Voltage_battery_mV(0,data[EPSVBATT]);

    ASSERT_TLM_EPS_Temp_Battery_Celsuis_SIZE(1);
    ASSERT_TLM_EPS_Temp_Battery_Celsuis(0,data[EPSTEMP]);

    //Verify Event
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_MS_CHNG_BATT_MOD_SIZE(1);
    ASSERT_EVENTS_MS_CHNG_BATT_MOD(0,data[EPSBATTMODE]);

    this->clearHistory();
  }
  void Tester::portTestLowVolt(void){
     //Init data for cmd test
    Fw::Buffer bufferData;
    U8 port = EPS_INST_TLM_PORT;
    U8 sched = 1;
    U8 dataSize = 232;
    U8 data[dataSize] = {0};
    data[EPSCMD] = 0x00;
    data[EPSSTATUS] = 0x00;
    data[EPSVBATT] = 9;
    data[EPSTEMP] = 50;
    data[EPSBATTMODE] = 2;
    bufferData.setData(data);
    bufferData.setSize(dataSize);
    //Invoke DataIn port
    this->invoke_to_DataIn(0,port,bufferData,sched);
    //Dispatch the message queue
    this->component.doDispatch();

   
    //Verify Telemetry
    ASSERT_TLM_SIZE(3);

    ASSERT_TLM_EPS_Battery_mode_SIZE(1);
    ASSERT_TLM_EPS_Battery_mode(0,data[EPSBATTMODE]);

    ASSERT_TLM_EPS_Voltage_battery_mV_SIZE(1);
    ASSERT_TLM_EPS_Voltage_battery_mV(0,data[EPSVBATT]);

    ASSERT_TLM_EPS_Temp_Battery_Celsuis_SIZE(1);
    ASSERT_TLM_EPS_Temp_Battery_Celsuis(0,data[EPSTEMP]);

    //Verify Event
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_MS_BATT_VOLT_LOW_SIZE(1);
    ASSERT_EVENTS_MS_BATT_VOLT_LOW(0,data[EPSVBATT]);

    this->clearHistory();
  }
  void Tester::portTestHighTemp(void){
    //Init data for cmd test
    Fw::Buffer bufferData;
    U8 port = EPS_INST_TLM_PORT;
    U8 sched = 1;
    U8 dataSize = 232;
    U8 data[dataSize] = {0};
    data[EPSCMD] = 0x00;
    data[EPSSTATUS] = 0x00;
    data[EPSVBATT] = 10;
    data[EPSTEMP] = 101;
    data[EPSBATTMODE] = 2;
    bufferData.setData(data);
    bufferData.setSize(dataSize);
    //Invoke DataIn port
    this->invoke_to_DataIn(0,port,bufferData,sched);
    //Dispatch the message queue
    this->component.doDispatch();

   
    //Verify Telemetry
    ASSERT_TLM_SIZE(3);

    ASSERT_TLM_EPS_Battery_mode_SIZE(1);
    ASSERT_TLM_EPS_Battery_mode(0,data[EPSBATTMODE]);

    ASSERT_TLM_EPS_Voltage_battery_mV_SIZE(1);
    ASSERT_TLM_EPS_Voltage_battery_mV(0,data[EPSVBATT]);

    ASSERT_TLM_EPS_Temp_Battery_Celsuis_SIZE(1);
    ASSERT_TLM_EPS_Temp_Battery_Celsuis(0,data[EPSTEMP]);

    //Verify Event
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_MS_BATT_TEMP_HIGH_SIZE(1);
    ASSERT_EVENTS_MS_BATT_TEMP_HIGH(0,data[EPSTEMP]);

    this->clearHistory();
  }
  

  void Tester::cmdSendPing(void){


    U8 portTheoritical = (U8)CSP_PING_PORT;
    U8 schedTheoritical = 0;
    U32 sizeTheoritical = 0; 

    //Send MS_SEND:PING badPayload1 command
    
    this->sendCmd_MS_SEND_PING(0,10);
    //Dispatch the message queue
    this->component.doDispatch();

    //Verify port param
    U32 sizeEmpirical = this->fromPortHistory_DataOut->at(0).data.getSize();
    U8 portEmpirical = this->fromPortHistory_DataOut->at(0).port;
    U8 schedEmpirical = this->fromPortHistory_DataOut->at(0).isSched;

    ASSERT_EQ(portTheoritical,portEmpirical);
    ASSERT_EQ(sizeTheoritical,sizeEmpirical);
    ASSERT_EQ(schedTheoritical,schedEmpirical);

    //Verify command response
    ASSERT_CMD_RESPONSE_SIZE(1);
    ASSERT_CMD_RESPONSE(0,EPSComponentBase::OPCODE_MS_SEND_PING,10,
    Fw::COMMAND_OK);

    this->clearHistory();
  }

  void Tester::cmdPortPingOk(void){
    //Init data for cmd test
    Fw::Buffer bufferData;
    U8 port = CSP_PING_PORT;
    U8 sched = 0;
    U8 dataSize = 4;
    U8 data[dataSize] = {0};
    data[3] = 0x0A;
    bufferData.setData(data);
    bufferData.setSize(dataSize);
    //Invoke DataIn port
    this->invoke_to_DataIn(0,port,bufferData,sched);
    //Dispatch the message queue
    this->component.doDispatch();

    I32 pingEmpirical = 10;
    //Verify Telemetry
    ASSERT_TLM_SIZE(0);

    //Verify Event
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_MS_PING_SIZE(1);
    ASSERT_EVENTS_MS_PING(0,pingEmpirical);

    this->clearHistory();
  }

    void Tester::cmdPortPingNOK(void){
    //Init data for cmd test
    Fw::Buffer bufferData;
    U8 port = CSP_PING_PORT;
    U8 sched = 0;
    U8 dataSize = 4;
    U8 data[dataSize] = {0};
    data[3] = 0xFF;
    data[2] = 0xFF;
    data[1] = 0xFF;
    data[0] = 0xFF;
    bufferData.setData(data);
    bufferData.setSize(dataSize);
    //Invoke DataIn port
    this->invoke_to_DataIn(0,port,bufferData,sched);
    //Dispatch the message queue
    this->component.doDispatch();

    I32 pingEmpirical = -1;
    //Verify Telemetry
    ASSERT_TLM_SIZE(0);

    //Verify Event
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_MS_PING_SIZE(1);
    ASSERT_EVENTS_MS_PING(0,pingEmpirical);

    this->clearHistory();
  }

  // ----------------------------------------------------------------------
  // Handlers for typed from ports
  // ----------------------------------------------------------------------

  void Tester ::
    from_DataOut_handler(
        const NATIVE_INT_TYPE portNum,
        U8 port,
        Fw::Buffer &data,
        U8 isSched
    )
  {
    this->pushFromPortEntry_DataOut(port, data, isSched);
  }

  // ----------------------------------------------------------------------
  // Helper methods 
  // ----------------------------------------------------------------------

  void Tester ::
    connectPorts(void) 
  {

    // DataIn
    this->connect_to_DataIn(
        0,
        this->component.get_DataIn_InputPort(0)
    );

    // Schedin
    this->connect_to_Schedin(
        0,
        this->component.get_Schedin_InputPort(0)
    );

    // CmdDisp
    this->connect_to_CmdDisp(
        0,
        this->component.get_CmdDisp_InputPort(0)
    );

    // DataOut
    this->component.set_DataOut_OutputPort(
        0, 
        this->get_from_DataOut(0)
    );

    // CmdStatus
    this->component.set_CmdStatus_OutputPort(
        0, 
        this->get_from_CmdStatus(0)
    );

    // CmdReg
    this->component.set_CmdReg_OutputPort(
        0, 
        this->get_from_CmdReg(0)
    );

    // Tlm
    this->component.set_Tlm_OutputPort(
        0, 
        this->get_from_Tlm(0)
    );

    // Time
    this->component.set_Time_OutputPort(
        0, 
        this->get_from_Time(0)
    );

    // Log
    this->component.set_Log_OutputPort(
        0, 
        this->get_from_Log(0)
    );

    // LogText
    this->component.set_LogText_OutputPort(
        0, 
        this->get_from_LogText(0)
    );




  }

  void Tester ::
    initComponents(void) 
  {
    this->init();
    this->component.init(
        QUEUE_DEPTH, INSTANCE
    );
  }

} // end namespace App
