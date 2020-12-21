// ======================================================================
// \title  SocketTcpDriver/test/ut/TesterBase.cpp
// \author Auto-generated
// \brief  cpp file for SocketTcpDriver component test harness base class
//
// \copyright
// Copyright 2009-2016, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include <stdlib.h>
#include <string.h>
#include "TesterBase.hpp"

namespace Drv {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  SocketTcpDriverTesterBase ::
    SocketTcpDriverTesterBase(
#if FW_OBJECT_NAMES == 1
        const char *const compName,
        const U32 maxHistorySize
#else
        const U32 maxHistorySize
#endif
    ) :
#if FW_OBJECT_NAMES == 1
      Fw::PassiveComponentBase(compName)
#else
      Fw::PassiveComponentBase()
#endif
  {
    // Initialize histories for typed user output ports
    this->fromPortHistory_recv =
      new History<FromPortEntry_recv>(maxHistorySize);
    // Clear history
    this->clearHistory();
  }

  SocketTcpDriverTesterBase ::
    ~SocketTcpDriverTesterBase(void)
  {
    // Destroy port histories
    delete this->fromPortHistory_recv;
  }

  void SocketTcpDriverTesterBase ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {

    // Initialize base class

		Fw::PassiveComponentBase::init(instance);

    // Attach input port recv

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_recv();
        ++_port
    ) {

      this->m_from_recv[_port].init();
      this->m_from_recv[_port].addCallComp(
          this,
          from_recv_static
      );
      this->m_from_recv[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_recv[%d]",
          this->m_objName,
          _port
      );
      this->m_from_recv[_port].setObjName(_portName);
#endif

    }

    // Initialize output port send

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_send();
        ++_port
    ) {
      this->m_to_send[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_send[%d]",
          this->m_objName,
          _port
      );
      this->m_to_send[_port].setObjName(_portName);
#endif

    }

  }

  // ----------------------------------------------------------------------
  // Getters for port counts
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE SocketTcpDriverTesterBase ::
    getNum_from_recv(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_recv);
  }

  NATIVE_INT_TYPE SocketTcpDriverTesterBase ::
    getNum_to_send(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_send);
  }

  // ----------------------------------------------------------------------
  // Connectors for to ports
  // ----------------------------------------------------------------------

  void SocketTcpDriverTesterBase ::
    connect_to_send(
        const NATIVE_INT_TYPE portNum,
        Fw::InputBufferSendPort *const send
    )
  {
    FW_ASSERT(portNum < this->getNum_to_send(),static_cast<AssertArg>(portNum));
    this->m_to_send[portNum].addCallPort(send);
  }


  // ----------------------------------------------------------------------
  // Invocation functions for to ports
  // ----------------------------------------------------------------------

  void SocketTcpDriverTesterBase ::
    invoke_to_send(
        const NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_to_send(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_send(),static_cast<AssertArg>(portNum));
    this->m_to_send[portNum].invoke(
        fwBuffer
    );
  }

  // ----------------------------------------------------------------------
  // Connection status for to ports
  // ----------------------------------------------------------------------

  bool SocketTcpDriverTesterBase ::
    isConnected_to_send(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_send(), static_cast<AssertArg>(portNum));
    return this->m_to_send[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Getters for from ports
  // ----------------------------------------------------------------------

  Fw::InputBufferSendPort *SocketTcpDriverTesterBase ::
    get_from_recv(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_recv(),static_cast<AssertArg>(portNum));
    return &this->m_from_recv[portNum];
  }

  // ----------------------------------------------------------------------
  // Static functions for from ports
  // ----------------------------------------------------------------------

  void SocketTcpDriverTesterBase ::
    from_recv_static(
        Fw::PassiveComponentBase *const callComp,
        const NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(callComp);
    SocketTcpDriverTesterBase* _testerBase =
      static_cast<SocketTcpDriverTesterBase*>(callComp);
    _testerBase->from_recv_handlerBase(
        portNum,
        fwBuffer
    );
  }

  // ----------------------------------------------------------------------
  // Histories for typed from ports
  // ----------------------------------------------------------------------

  void SocketTcpDriverTesterBase ::
    clearFromPortHistory(void)
  {
    this->fromPortHistorySize = 0;
    this->fromPortHistory_recv->clear();
  }

  // ----------------------------------------------------------------------
  // From port: recv
  // ----------------------------------------------------------------------

  void SocketTcpDriverTesterBase ::
    pushFromPortEntry_recv(
        Fw::Buffer &fwBuffer
    )
  {
    FromPortEntry_recv _e = {
      fwBuffer
    };
    this->fromPortHistory_recv->push_back(_e);
    ++this->fromPortHistorySize;
  }

  // ----------------------------------------------------------------------
  // Handler base functions for from ports
  // ----------------------------------------------------------------------

  void SocketTcpDriverTesterBase ::
    from_recv_handlerBase(
        const NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_from_recv(),static_cast<AssertArg>(portNum));
    this->from_recv_handler(
        portNum,
        fwBuffer
    );
  }

  // ----------------------------------------------------------------------
  // History
  // ----------------------------------------------------------------------

  void SocketTcpDriverTesterBase ::
    clearHistory()
  {
    this->clearFromPortHistory();
  }

} // end namespace Drv
