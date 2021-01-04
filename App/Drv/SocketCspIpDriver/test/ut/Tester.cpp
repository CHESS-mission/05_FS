// ====================================================================== 
// \title  SocketCspIpDriver.hpp
// \author root
// \brief  cpp file for SocketCspIpDriver test harness implementation class
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
      SocketCspIpDriverGTestBase("Tester", MAX_HISTORY_SIZE),
      component("SocketCspIpDriver")
#else
      SocketCspIpDriverGTestBase(MAX_HISTORY_SIZE),
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
    toDo(void) 
  {
        // set test data
    U8 tmId = 128;
    U32 sizeDataSend = 5;
    U8 dataSend[]={0x1F,0x7F,tmId,0x1F,0xFF};

    U32 sizeDataRecvTheoritical = 6;
    U8 tmReturnTheoritical = 10;
    U8 dataRecvTheoretical[] ={0x1F,0x7F,tmId,tmReturnTheoritical,0x1F,0xFF};

    Fw::Buffer bufferSend;

    bufferSend.setData(dataSend);
    bufferSend.setSize(sizeDataSend);

    //Invok send port in
    this->invoke_to_send(0,14,bufferSend);
    //Verify port out
    ASSERT_FROM_PORT_HISTORY_SIZE(1);
    ASSERT_from_recv_SIZE(1);

    //Verify data recv form simulator
    U8* dataRecvEmpirical = this->fromPortHistory_recv->at(0).fwBuffer.getData();
    U32 sizeDataRecvEmpirical = this->fromPortHistory_recv->at(0).fwBuffer.getSize();

    for(int i = 0; i< sizeDataRecvEmpirical;i++){
      printf("%d\n",dataRecvEmpirical[i]);
    }

    //Clean test
    this->clearHistory();
  }

  void Tester::toDo2(void){
            // set test data
    U8 tmId = 128;
    U32 sizeDataSend = 5;
    U8 dataSend[]={0x1F,0x7F,tmId,0x1F,0xFF};

    U32 sizeDataRecvTheoritical = 6;
    U8 tmReturnTheoritical = 10;
    U8 dataRecvTheoretical[] ={0x1F,0x7F,tmId,tmReturnTheoritical,0x1F,0xFF};

    Fw::Buffer bufferSend;

    bufferSend.setData(dataSend);
    bufferSend.setSize(sizeDataSend);

    //Invok send port in
    this->invoke_to_send(0,14,bufferSend);
    //Verify port out
    ASSERT_FROM_PORT_HISTORY_SIZE(1);
    ASSERT_from_recv_SIZE(1);

    //Verify data recv form simulator
    U8* dataRecvEmpirical = this->fromPortHistory_recv->at(0).fwBuffer.getData();
    U32 sizeDataRecvEmpirical = this->fromPortHistory_recv->at(0).fwBuffer.getSize();

    for(int i = 0; i< sizeDataRecvEmpirical;i++){
      printf("%d\n",dataRecvEmpirical[i]);
    }

    //Clean test
    this->clearHistory();
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
    this->component.configure(10,"localhost");
    this->component.open(27);   
  }

} // end namespace Drv
