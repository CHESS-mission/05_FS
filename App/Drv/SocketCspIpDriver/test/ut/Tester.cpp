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
#include "App/Config/EPSCfg.hpp"
#include "App/Config/SocketCspIpDriverCfg.hpp"

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
    testSendCmdPort7(void) 
  {
        // set test data
    U8 port = 7;
    U8 cmd = 0x00;
    U32 sizeDataSend = 1;
    U8 dataSend[]={cmd};
    U8 sched = 0;

    U8 portRecvTheoritical = 7;
    U8 schedRecvTheoritical = 0;
    U32 sizeDataRecvTheoritical = 232;
    U8 dataRecvTheoretical[sizeDataRecvTheoritical] = {0};


    dataRecvTheoretical[EPSCMD] = cmd;
    dataRecvTheoretical[EPSSTATUS] = 0;
    dataRecvTheoretical[EPSVBATT] = 11;
    dataRecvTheoretical[EPSTEMP] = 50;
    dataRecvTheoretical[EPSBATTMODE] = 2;

    Fw::Buffer bufferSend;

    bufferSend.setData(dataSend);
    bufferSend.setSize(sizeDataSend);

    //Invok send port in
    this->invoke_to_send(0,port,bufferSend,sched);
    //Verify port out
    ASSERT_FROM_PORT_HISTORY_SIZE(1);
    ASSERT_from_recv_SIZE(1);

    //Verify data recv form simulator
    U8* dataRecvEmpirical = this->fromPortHistory_recv->at(0).data.getData();
    U32 sizeDataRecvEmpirical = this->fromPortHistory_recv->at(0).data.getSize();
    U8 portEmpirical = this->fromPortHistory_recv->at(0).port;
    U8 schedEmpirical = this->fromPortHistory_recv->at(0).isSched;

    ASSERT_EQ(sizeDataRecvTheoritical,sizeDataRecvEmpirical);

    for(int i = 0 ; i< sizeDataRecvTheoritical;i++){
      ASSERT_EQ(dataRecvTheoretical[i],dataRecvEmpirical[i]);
    }

    ASSERT_EQ(portRecvTheoritical,portEmpirical);
    ASSERT_EQ(schedRecvTheoritical,schedEmpirical);
    
    //Clean test
    this->clearHistory();
  }

void Tester ::
    testSendSchedPort7(void) 
  {
        // set test data
    U8 port = 7;
    U8 cmd = 0x00;
    U32 sizeDataSend = 1;
    U8 dataSend[]={cmd};
    U8 sched = 1;

    U8 portRecvTheoritical = 7;
    U8 schedRecvTheoritical = 1;
    U32 sizeDataRecvTheoritical = 232;
    U8 dataRecvTheoretical[sizeDataRecvTheoritical] = {0};


    dataRecvTheoretical[EPSCMD] = cmd;
    dataRecvTheoretical[EPSSTATUS] = 0;
    dataRecvTheoretical[EPSVBATT] = 10;
    dataRecvTheoretical[EPSTEMP] = 50;
    dataRecvTheoretical[EPSBATTMODE] = 2;

    Fw::Buffer bufferSend;

    bufferSend.setData(dataSend);
    bufferSend.setSize(sizeDataSend);

    //Invok send port in
    this->invoke_to_send(0,port,bufferSend,sched);
    //Verify port out
    ASSERT_FROM_PORT_HISTORY_SIZE(1);
    ASSERT_from_recv_SIZE(1);

    //Verify data recv form simulator
    U8* dataRecvEmpirical = this->fromPortHistory_recv->at(0).data.getData();
    U32 sizeDataRecvEmpirical = this->fromPortHistory_recv->at(0).data.getSize();
    U8 portEmpirical = this->fromPortHistory_recv->at(0).port;
    U8 schedEmpirical = this->fromPortHistory_recv->at(0).isSched;

    ASSERT_EQ(sizeDataRecvTheoritical,sizeDataRecvEmpirical);

    for(int i = 0 ; i< sizeDataRecvTheoritical;i++){
      ASSERT_EQ(dataRecvTheoretical[i],dataRecvEmpirical[i]);
    }

    ASSERT_EQ(portRecvTheoritical,portEmpirical);
    ASSERT_EQ(schedRecvTheoritical,schedEmpirical);
    
    //Clean test
    this->clearHistory();
  }

void Tester::testSendPing(void){
          // set test data
    U8 port = CSP_PING_PORT;
    U32 sizeDataSend = 0;
    U8 dataSend[sizeDataSend];
    U8 sched = 0;

    U8 portRecvTheoritical = CSP_PING_PORT;
    U8 schedRecvTheoritical = 0;
    U32 sizeDataRecvTheoritical = 4;

    Fw::Buffer bufferSend;

    bufferSend.setData(dataSend);
    bufferSend.setSize(sizeDataSend);

    //Invok send port in
    this->invoke_to_send(0,port,bufferSend,sched);
    //Verify port out
    ASSERT_FROM_PORT_HISTORY_SIZE(1);
    ASSERT_from_recv_SIZE(1);

    //Verify data recv form simulator
    U32 sizeDataRecvEmpirical = this->fromPortHistory_recv->at(0).data.getSize();
    U8 portEmpirical = this->fromPortHistory_recv->at(0).port;
    U8 schedEmpirical = this->fromPortHistory_recv->at(0).isSched;

    ASSERT_EQ(sizeDataRecvTheoritical,sizeDataRecvEmpirical);
    ASSERT_EQ(portRecvTheoritical,portEmpirical);
    ASSERT_EQ(schedRecvTheoritical,schedEmpirical);
    
    //Clean test
    this->clearHistory();
}
  
  // ----------------------------------------------------------------------
  // Handlers for typed from ports
  // ----------------------------------------------------------------------

  void Tester ::
    from_recv_handler(
        const NATIVE_INT_TYPE portNum,
        U8 port,
        Fw::Buffer &data,
        U8 isSched
    )
  {
    this->pushFromPortEntry_recv(port, data, isSched);
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
    this->component.openSocket(27);   
  }

} // end namespace Drv
