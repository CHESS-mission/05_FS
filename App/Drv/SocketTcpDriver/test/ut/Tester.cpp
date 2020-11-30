// ====================================================================== 
// \title  SocketTcpDriver.hpp
// \author root
// \brief  cpp file for SocketTcpDriver test harness implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
// 
// ====================================================================== 

#include "Tester.hpp"

#define INSTANCE 0
#define MAX_HISTORY_SIZE 10

namespace Drv {

  // ----------------------------------------------------------------------
  // Construction and destruction 
  // ----------------------------------------------------------------------

  Tester ::
    Tester(void) : 
#if FW_OBJECT_NAMES == 1
      SocketTcpDriverGTestBase("Tester", MAX_HISTORY_SIZE),
      component("SocketTcpDriver")
#else
      SocketTcpDriverGTestBase(MAX_HISTORY_SIZE),
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

  void Tester::testSendTM(void){
    U8 dataSend[]={0x1F,0x7F,0x80,0x1F,0xFF};
    U8 dataRecv[] ={0x1F,0x7F,0x80,0x0A,0x1F,0xFF};
    Fw::Buffer bufferSend;
    Fw::Buffer bufferRecv;
    bufferSend.setData(dataSend);
    bufferSend.setSize(5);
    bufferRecv.setData(dataRecv);
    this->invoke_to_send(0,bufferSend);
    ASSERT_FROM_PORT_HISTORY_SIZE(1);
    ASSERT_from_recv_SIZE(1);
    //ASSERT_from_recv(0,bufferRecv);
  }


  // ----------------------------------------------------------------------
  // Handlers for typed from ports
  // ----------------------------------------------------------------------

  void Tester ::
    from_recv_handler(
        const NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    this->pushFromPortEntry_recv(fwBuffer);
  }

  // ----------------------------------------------------------------------
  // Helper methods 
  // ----------------------------------------------------------------------

  void Tester ::
    connectPorts(void) 
  {

    // send
    this->connect_to_send(
        0,
        this->component.get_send_InputPort(0)
    );

    // recv
    this->component.set_recv_OutputPort(
        0, 
        this->get_from_recv(0)
    );




  }

  void Tester ::
    initComponents(void) 
  {
    this->init();
    this->component.init(
        INSTANCE
    );
    this->component.configure("127.0.0.1",5005);
  }

} // end namespace Drv
