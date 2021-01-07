// ====================================================================== 
// \title  ADCS.hpp
// \author root
// \brief  cpp file for ADCS test harness implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
// 
// ====================================================================== 

#include "Tester.hpp"
#include <Fw/Types/BasicTypes.hpp>
#include <App/ADCS/ADCSHelper.hpp>

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
      ADCSGTestBase("Tester", MAX_HISTORY_SIZE),
      component("ADCS")
#else
      ADCSGTestBase(MAX_HISTORY_SIZE),
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

  void Tester ::
    testCmdTMBadId(void) 
  {
    //Init data for TM test
    U8 wrongId = 127;

    //Send MS_GET_TM command
    this->sendCmd_MS_GET_TM(0,10,wrongId);
    //Dispatch the message queue
    this->component.doDispatch();

    //Verify that no port was called.
    ASSERT_FROM_PORT_HISTORY_SIZE(0);

    //Verifiy events
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_MS_ID_ERROR_SIZE(1);
    ASSERT_EVENTS_MS_ID_ERROR(0,wrongId);

    //Verify command response
    ASSERT_CMD_RESPONSE_SIZE(1);
    ASSERT_CMD_RESPONSE(0,ADCSComponentBase::OPCODE_MS_GET_TM,10,
    Fw::COMMAND_EXECUTION_ERROR);

    this->clearHistory();

  }

    void Tester ::
    testCmdTMGoodId(void) 
  {
    //Init data for TM test
    Fw::Buffer bufferTm;
    U8 goodId = 128;
    U8 dataTheoritical[] = {0x1F,0x7F,goodId,0x1F,0xFF};
    U32 sizeTheoritical= 5;
    bufferTm.setData(dataTheoritical);
    bufferTm.setSize(sizeTheoritical);

    //Send MS_GET_TM command
    this->sendCmd_MS_GET_TM(0,10,goodId);
    //Dispatch the message queue
    this->component.doDispatch();

    //Verify that port was called.
    ASSERT_FROM_PORT_HISTORY_SIZE(1);
    ASSERT_from_DataOut_SIZE(1);

    //Verify port param
    U8* dataEmpirical = this->fromPortHistory_DataOut->at(0).fwBuffer.getData();
    U32 sizeEmpirical = this->fromPortHistory_DataOut->at(0).fwBuffer.getSize();

    ASSERT_EQ(sizeTheoritical,sizeEmpirical);

    for(int i = 0; i < sizeTheoritical ;i++){
      ASSERT_EQ(dataTheoritical[i],dataEmpirical[i]);
    }

    //Verifiy events
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_MS_TM_SEND_ADCS_SIZE(1);
    ASSERT_EVENTS_MS_TM_SEND_ADCS(0,goodId);

    //Verify command response
    ASSERT_CMD_RESPONSE_SIZE(1);
    ASSERT_CMD_RESPONSE(0,ADCSComponentBase::OPCODE_MS_GET_TM,10,
    Fw::COMMAND_OK);

    this->clearHistory();

  }
  void Tester::testCmdTCBadId(void){
    //Init data for TC test
    U8 wrongId = 128;
    Fw::CmdStringArg fakePayload("fake");
    //Send MS_GET_TM command
    this->sendCmd_MS_SEND_CMD(0,10,wrongId,fakePayload);
    //Dispatch the message queue
    this->component.doDispatch();

    //Verify that no port was called.
    ASSERT_FROM_PORT_HISTORY_SIZE(0);

    //Verifiy events
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_MS_ID_ERROR_SIZE(1);
    ASSERT_EVENTS_MS_ID_ERROR(0,wrongId);

    //Verify command response
    ASSERT_CMD_RESPONSE_SIZE(1);
    ASSERT_CMD_RESPONSE(0,ADCSComponentBase::OPCODE_MS_SEND_CMD,10,
    Fw::COMMAND_EXECUTION_ERROR);

    this->clearHistory();
  }
  void Tester::testCmdTCGoodIdPayload(void){
    //Init data for TC test
    App::ADCSHelper adcsHelper;
    Fw::Buffer bufferTm;
    U8 goodId = 127;
    U32 sizeTheoritical= 7;
    U8 dataTheoritical[] = {0x1F,0x7F,goodId,0x00,0x1F,0xFF,0x00};
    adcsHelper.getCrc(dataTheoritical,sizeTheoritical);
    bufferTm.setData(dataTheoritical);
    bufferTm.setSize(sizeTheoritical);

    Fw::CmdStringArg payload("00");

    //Send MS_GET_TM command
    this->sendCmd_MS_SEND_CMD(0,10,goodId,payload);
    //Dispatch the message queue
    this->component.doDispatch();

    //Verify that port was called.
    ASSERT_FROM_PORT_HISTORY_SIZE(1);
    ASSERT_from_DataOut_SIZE(1);

    //Verify port param
    U8* dataEmpirical = this->fromPortHistory_DataOut->at(0).fwBuffer.getData();
    U32 sizeEmpirical = this->fromPortHistory_DataOut->at(0).fwBuffer.getSize();

    ASSERT_EQ(sizeTheoritical,sizeEmpirical);

    for(int i = 0; i < 5 ;i++){
      ASSERT_EQ(dataTheoritical[i],dataEmpirical[i]);
    }

    //Verifiy events
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_MS_TC_SEND_ADCS_SIZE(1);
    ASSERT_EVENTS_MS_TC_SEND_ADCS(0,goodId,payload.toChar());

    //Verify command response
    ASSERT_CMD_RESPONSE_SIZE(1);
    ASSERT_CMD_RESPONSE(0,ADCSComponentBase::OPCODE_MS_SEND_CMD,10,
    Fw::COMMAND_OK);

    this->clearHistory();
  }
  void Tester::testCmdTCBadPayloadData(void){
  //Init data for TC test
    U8 goodId = 127;
    Fw::CmdStringArg payload("bug");

    //Send MS_GET_TM command
    this->sendCmd_MS_SEND_CMD(0,10,goodId,payload);
    //Dispatch the message queue
    this->component.doDispatch();

    //Verify that port was called.
    ASSERT_FROM_PORT_HISTORY_SIZE(0);
    ASSERT_from_DataOut_SIZE(0);

      //Verifiy events
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_MS_TC_PAYLOAD_ERROR_SIZE(1);
    ASSERT_EVENTS_MS_TC_PAYLOAD_ERROR(0,goodId,payload.toChar());

    //Verify command response
    ASSERT_CMD_RESPONSE_SIZE(1);
    ASSERT_CMD_RESPONSE(0,ADCSComponentBase::OPCODE_MS_SEND_CMD,10,
    Fw::COMMAND_EXECUTION_ERROR);

    this->clearHistory();
  }
  void Tester::testCmdTCBadPayloadSize(void){
  //Init data for TC test
    U8 goodId = 127;
    Fw::CmdStringArg payload("0F0");

    //Send MS_GET_TM command
    this->sendCmd_MS_SEND_CMD(0,10,goodId,payload);
    //Dispatch the message queue
    this->component.doDispatch();

    //Verify that port was called.
    ASSERT_FROM_PORT_HISTORY_SIZE(0);
    ASSERT_from_DataOut_SIZE(0);

      //Verifiy events
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_MS_TC_PAYLOAD_ERROR_SIZE(1);
    ASSERT_EVENTS_MS_TC_PAYLOAD_ERROR(0,goodId,payload.toChar());

    //Verify command response
    ASSERT_CMD_RESPONSE_SIZE(1);
    ASSERT_CMD_RESPONSE(0,ADCSComponentBase::OPCODE_MS_SEND_CMD,10,
    Fw::COMMAND_EXECUTION_ERROR);

    this->clearHistory();
  }

  void Tester::testPortTM(void){
    //Init data for TM test
    Fw::Buffer bufferTm;
    U8 goodId = 128;
    U8 tm = 12;
    U8 data[] = {0x1F,0x7F,goodId,tm,0x1F,0xFF};
    bufferTm.setData(data);
    bufferTm.setSize(6);
    //Invoke DataIn port
    this->invoke_to_DataIn(0,bufferTm);
    //Dispatch the message queue
    this->component.doDispatch();

    //Verify Event
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_MS_TM_RECV_ADCS_SIZE(1);
    ASSERT_EVENTS_MS_TM_RECV_ADCS(0,goodId,tm);

    //Verify Telemetry
    ASSERT_TLM_SIZE(1);
    ASSERT_TLM_ADCS_LAST_TM_DATA_SIZE(1);
    ASSERT_TLM_ADCS_LAST_TM_DATA(0,tm);

    this->clearHistory();
  }

  void Tester::testPortTC(void){
   //Init data for TC test
    Fw::Buffer bufferTm;
    U8 goodId = 127;
    U8 tc = 00;
    U8 data[] = {0x1F,0x7F,goodId,tc,0x1F,0xFF};
    bufferTm.setData(data);
    bufferTm.setSize(6);
    //Invoke DataIn port
    this->invoke_to_DataIn(0,bufferTm);
    //Dispatch the message queue
    this->component.doDispatch();

    //Verify Event
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_MS_TC_RECV_ADCS_SIZE(1);
    ASSERT_EVENTS_MS_TC_RECV_ADCS(0,goodId,tc);

    //Verify Telemetry
    ASSERT_TLM_SIZE(1);
    ASSERT_TLM_ADCS_LAST_CMD_SIZE(1);
    ASSERT_TLM_ADCS_LAST_CMD(0,tc);

    this->clearHistory();

  }

  // ----------------------------------------------------------------------
  // Handlers for typed from ports
  // ----------------------------------------------------------------------

  void Tester ::
    from_DataOut_handler(
        const NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    this->pushFromPortEntry_DataOut(fwBuffer);
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
