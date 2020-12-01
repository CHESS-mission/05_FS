// ======================================================================
// \title  EventAction/test/ut/TesterBase.cpp
// \author Auto-generated
// \brief  cpp file for EventAction component test harness base class
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

namespace App {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  EventActionTesterBase ::
    EventActionTesterBase(
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
    // Initialize command history
    this->cmdResponseHistory = new History<CmdResponse>(maxHistorySize);
    // Initialize event histories
#if FW_ENABLE_TEXT_LOGGING
    this->textLogHistory = new History<TextLogEntry>(maxHistorySize);
#endif
    this->eventHistory_EVAC_ADDED =
      new History<EventEntry_EVAC_ADDED>(maxHistorySize);
    this->eventHistory_EVAC_REMOVED =
      new History<EventEntry_EVAC_REMOVED>(maxHistorySize);
    this->eventHistory_EVAC_LIST_FULL =
      new History<EventEntry_EVAC_LIST_FULL>(maxHistorySize);
    this->eventHistory_EVAC_NOT_FOUND =
      new History<EventEntry_EVAC_NOT_FOUND>(maxHistorySize);
    this->eventHistory_EVAC_ALREADY_REGISTERED =
      new History<EventEntry_EVAC_ALREADY_REGISTERED>(maxHistorySize);
    this->eventHistory_EVAC_DUMP =
      new History<EventEntry_EVAC_DUMP>(maxHistorySize);
    this->eventHistory_EVAC_RUN =
      new History<EventEntry_EVAC_RUN>(maxHistorySize);
    // Initialize histories for typed user output ports
    this->fromPortHistory_seqRun =
      new History<FromPortEntry_seqRun>(maxHistorySize);
    // Clear history
    this->clearHistory();
  }

  EventActionTesterBase ::
    ~EventActionTesterBase(void)
  {
    // Destroy command history
    delete this->cmdResponseHistory;
    // Destroy event histories
#if FW_ENABLE_TEXT_LOGGING
    delete this->textLogHistory;
#endif
    delete this->eventHistory_EVAC_ADDED;
    delete this->eventHistory_EVAC_REMOVED;
    delete this->eventHistory_EVAC_LIST_FULL;
    delete this->eventHistory_EVAC_NOT_FOUND;
    delete this->eventHistory_EVAC_ALREADY_REGISTERED;
    delete this->eventHistory_EVAC_DUMP;
    delete this->eventHistory_EVAC_RUN;
    // Destroy port histories
    delete this->fromPortHistory_seqRun;
  }

  void EventActionTesterBase ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {

    // Initialize base class

		Fw::PassiveComponentBase::init(instance);

    // Attach input port cmdRegOut

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_cmdRegOut();
        ++_port
    ) {

      this->m_from_cmdRegOut[_port].init();
      this->m_from_cmdRegOut[_port].addCallComp(
          this,
          from_cmdRegOut_static
      );
      this->m_from_cmdRegOut[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_cmdRegOut[%d]",
          this->m_objName,
          _port
      );
      this->m_from_cmdRegOut[_port].setObjName(_portName);
#endif

    }

    // Attach input port cmdResponseOut

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_cmdResponseOut();
        ++_port
    ) {

      this->m_from_cmdResponseOut[_port].init();
      this->m_from_cmdResponseOut[_port].addCallComp(
          this,
          from_cmdResponseOut_static
      );
      this->m_from_cmdResponseOut[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_cmdResponseOut[%d]",
          this->m_objName,
          _port
      );
      this->m_from_cmdResponseOut[_port].setObjName(_portName);
#endif

    }

    // Attach input port eventOut

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_eventOut();
        ++_port
    ) {

      this->m_from_eventOut[_port].init();
      this->m_from_eventOut[_port].addCallComp(
          this,
          from_eventOut_static
      );
      this->m_from_eventOut[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_eventOut[%d]",
          this->m_objName,
          _port
      );
      this->m_from_eventOut[_port].setObjName(_portName);
#endif

    }

    // Attach input port txtEventOut

#if FW_ENABLE_TEXT_LOGGING == 1
    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_txtEventOut();
        ++_port
    ) {

      this->m_from_txtEventOut[_port].init();
      this->m_from_txtEventOut[_port].addCallComp(
          this,
          from_txtEventOut_static
      );
      this->m_from_txtEventOut[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_txtEventOut[%d]",
          this->m_objName,
          _port
      );
      this->m_from_txtEventOut[_port].setObjName(_portName);
#endif

    }
#endif

    // Attach input port seqRun

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_seqRun();
        ++_port
    ) {

      this->m_from_seqRun[_port].init();
      this->m_from_seqRun[_port].addCallComp(
          this,
          from_seqRun_static
      );
      this->m_from_seqRun[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_seqRun[%d]",
          this->m_objName,
          _port
      );
      this->m_from_seqRun[_port].setObjName(_portName);
#endif

    }

    // Attach input port Time

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_Time();
        ++_port
    ) {

      this->m_from_Time[_port].init();
      this->m_from_Time[_port].addCallComp(
          this,
          from_Time_static
      );
      this->m_from_Time[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_Time[%d]",
          this->m_objName,
          _port
      );
      this->m_from_Time[_port].setObjName(_portName);
#endif

    }

    // Initialize output port seqResp

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_seqResp();
        ++_port
    ) {
      this->m_to_seqResp[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_seqResp[%d]",
          this->m_objName,
          _port
      );
      this->m_to_seqResp[_port].setObjName(_portName);
#endif

    }

    // Initialize output port logRecv

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_logRecv();
        ++_port
    ) {
      this->m_to_logRecv[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_logRecv[%d]",
          this->m_objName,
          _port
      );
      this->m_to_logRecv[_port].setObjName(_portName);
#endif

    }

  }

  // ----------------------------------------------------------------------
  // Getters for port counts
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE EventActionTesterBase ::
    getNum_to_cmdDisp(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_cmdDisp);
  }

  NATIVE_INT_TYPE EventActionTesterBase ::
    getNum_from_cmdRegOut(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_cmdRegOut);
  }

  NATIVE_INT_TYPE EventActionTesterBase ::
    getNum_from_cmdResponseOut(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_cmdResponseOut);
  }

  NATIVE_INT_TYPE EventActionTesterBase ::
    getNum_from_eventOut(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_eventOut);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  NATIVE_INT_TYPE EventActionTesterBase ::
    getNum_from_txtEventOut(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_txtEventOut);
  }
#endif

  NATIVE_INT_TYPE EventActionTesterBase ::
    getNum_from_seqRun(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_seqRun);
  }

  NATIVE_INT_TYPE EventActionTesterBase ::
    getNum_to_seqResp(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_seqResp);
  }

  NATIVE_INT_TYPE EventActionTesterBase ::
    getNum_to_logRecv(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_logRecv);
  }

  NATIVE_INT_TYPE EventActionTesterBase ::
    getNum_from_Time(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_Time);
  }

  // ----------------------------------------------------------------------
  // Connectors for to ports
  // ----------------------------------------------------------------------

  void EventActionTesterBase ::
    connect_to_cmdDisp(
        const NATIVE_INT_TYPE portNum,
        Fw::InputCmdPort *const cmdDisp
    )
  {
    FW_ASSERT(portNum < this->getNum_to_cmdDisp(),static_cast<AssertArg>(portNum));
    this->m_to_cmdDisp[portNum].addCallPort(cmdDisp);
  }

  void EventActionTesterBase ::
    connect_to_seqResp(
        const NATIVE_INT_TYPE portNum,
        Fw::InputCmdResponsePort *const seqResp
    )
  {
    FW_ASSERT(portNum < this->getNum_to_seqResp(),static_cast<AssertArg>(portNum));
    this->m_to_seqResp[portNum].addCallPort(seqResp);
  }

  void EventActionTesterBase ::
    connect_to_logRecv(
        const NATIVE_INT_TYPE portNum,
        Fw::InputLogPort *const logRecv
    )
  {
    FW_ASSERT(portNum < this->getNum_to_logRecv(),static_cast<AssertArg>(portNum));
    this->m_to_logRecv[portNum].addCallPort(logRecv);
  }


  // ----------------------------------------------------------------------
  // Invocation functions for to ports
  // ----------------------------------------------------------------------

  void EventActionTesterBase ::
    invoke_to_seqResp(
        const NATIVE_INT_TYPE portNum,
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::CommandResponse response
    )
  {
    FW_ASSERT(portNum < this->getNum_to_seqResp(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_seqResp(),static_cast<AssertArg>(portNum));
    this->m_to_seqResp[portNum].invoke(
        opCode, cmdSeq, response
    );
  }

  void EventActionTesterBase ::
    invoke_to_logRecv(
        const NATIVE_INT_TYPE portNum,
        FwEventIdType id,
        Fw::Time &timeTag,
        Fw::LogSeverity severity,
        Fw::LogBuffer &args
    )
  {
    FW_ASSERT(portNum < this->getNum_to_logRecv(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_logRecv(),static_cast<AssertArg>(portNum));
    this->m_to_logRecv[portNum].invoke(
        id, timeTag, severity, args
    );
  }

  // ----------------------------------------------------------------------
  // Connection status for to ports
  // ----------------------------------------------------------------------

  bool EventActionTesterBase ::
    isConnected_to_cmdDisp(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_cmdDisp(), static_cast<AssertArg>(portNum));
    return this->m_to_cmdDisp[portNum].isConnected();
  }

  bool EventActionTesterBase ::
    isConnected_to_seqResp(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_seqResp(), static_cast<AssertArg>(portNum));
    return this->m_to_seqResp[portNum].isConnected();
  }

  bool EventActionTesterBase ::
    isConnected_to_logRecv(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_logRecv(), static_cast<AssertArg>(portNum));
    return this->m_to_logRecv[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Getters for from ports
  // ----------------------------------------------------------------------

  Fw::InputCmdRegPort *EventActionTesterBase ::
    get_from_cmdRegOut(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_cmdRegOut(),static_cast<AssertArg>(portNum));
    return &this->m_from_cmdRegOut[portNum];
  }

  Fw::InputCmdResponsePort *EventActionTesterBase ::
    get_from_cmdResponseOut(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_cmdResponseOut(),static_cast<AssertArg>(portNum));
    return &this->m_from_cmdResponseOut[portNum];
  }

  Fw::InputLogPort *EventActionTesterBase ::
    get_from_eventOut(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_eventOut(),static_cast<AssertArg>(portNum));
    return &this->m_from_eventOut[portNum];
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  Fw::InputLogTextPort *EventActionTesterBase ::
    get_from_txtEventOut(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_txtEventOut(),static_cast<AssertArg>(portNum));
    return &this->m_from_txtEventOut[portNum];
  }
#endif

  Svc::InputCmdSeqInPort *EventActionTesterBase ::
    get_from_seqRun(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_seqRun(),static_cast<AssertArg>(portNum));
    return &this->m_from_seqRun[portNum];
  }

  Fw::InputTimePort *EventActionTesterBase ::
    get_from_Time(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_Time(),static_cast<AssertArg>(portNum));
    return &this->m_from_Time[portNum];
  }

  // ----------------------------------------------------------------------
  // Static functions for from ports
  // ----------------------------------------------------------------------

  void EventActionTesterBase ::
    from_seqRun_static(
        Fw::PassiveComponentBase *const callComp,
        const NATIVE_INT_TYPE portNum,
        Fw::EightyCharString &filename
    )
  {
    FW_ASSERT(callComp);
    EventActionTesterBase* _testerBase =
      static_cast<EventActionTesterBase*>(callComp);
    _testerBase->from_seqRun_handlerBase(
        portNum,
        filename
    );
  }

  void EventActionTesterBase ::
    from_cmdResponseOut_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        const Fw::CommandResponse response
    )
  {
    EventActionTesterBase* _testerBase =
      static_cast<EventActionTesterBase*>(component);
    _testerBase->cmdResponseIn(opCode, cmdSeq, response);
  }

  void EventActionTesterBase ::
    from_cmdRegOut_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        const FwOpcodeType opCode
    )
  {

  }

  void EventActionTesterBase ::
    from_eventOut_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        FwEventIdType id,
        Fw::Time &timeTag,
        Fw::LogSeverity severity,
        Fw::LogBuffer &args
    )
  {
    EventActionTesterBase* _testerBase =
      static_cast<EventActionTesterBase*>(component);
    _testerBase->dispatchEvents(id, timeTag, severity, args);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void EventActionTesterBase ::
    from_txtEventOut_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        FwEventIdType id,
        Fw::Time &timeTag,
        Fw::TextLogSeverity severity,
        Fw::TextLogString &text
    )
  {
    EventActionTesterBase* _testerBase =
      static_cast<EventActionTesterBase*>(component);
    _testerBase->textLogIn(id,timeTag,severity,text);
  }
#endif

  void EventActionTesterBase ::
    from_Time_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        Fw::Time& time
    )
  {
    EventActionTesterBase* _testerBase =
      static_cast<EventActionTesterBase*>(component);
    time = _testerBase->m_testTime;
  }

  // ----------------------------------------------------------------------
  // Histories for typed from ports
  // ----------------------------------------------------------------------

  void EventActionTesterBase ::
    clearFromPortHistory(void)
  {
    this->fromPortHistorySize = 0;
    this->fromPortHistory_seqRun->clear();
  }

  // ----------------------------------------------------------------------
  // From port: seqRun
  // ----------------------------------------------------------------------

  void EventActionTesterBase ::
    pushFromPortEntry_seqRun(
        Fw::EightyCharString &filename
    )
  {
    FromPortEntry_seqRun _e = {
      filename
    };
    this->fromPortHistory_seqRun->push_back(_e);
    ++this->fromPortHistorySize;
  }

  // ----------------------------------------------------------------------
  // Handler base functions for from ports
  // ----------------------------------------------------------------------

  void EventActionTesterBase ::
    from_seqRun_handlerBase(
        const NATIVE_INT_TYPE portNum,
        Fw::EightyCharString &filename
    )
  {
    FW_ASSERT(portNum < this->getNum_from_seqRun(),static_cast<AssertArg>(portNum));
    this->from_seqRun_handler(
        portNum,
        filename
    );
  }

  // ----------------------------------------------------------------------
  // Command response handling
  // ----------------------------------------------------------------------

  void EventActionTesterBase ::
    cmdResponseIn(
        const FwOpcodeType opCode,
        const U32 seq,
        const Fw::CommandResponse response
    )
  {
    CmdResponse e = { opCode, seq, response };
    this->cmdResponseHistory->push_back(e);
  }

  // ----------------------------------------------------------------------
  // Command: EVAC_ADD
  // ----------------------------------------------------------------------

  void EventActionTesterBase ::
    sendCmd_EVAC_ADD(
        const NATIVE_INT_TYPE instance,
        const U32 cmdSeq,
        U32 id,
        const Fw::CmdStringArg& sequence
    )
  {

    // Serialize arguments

    Fw::CmdArgBuffer buff;
    Fw::SerializeStatus _status;
    _status = buff.serialize(id);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK,static_cast<AssertArg>(_status));
    _status = buff.serialize(sequence);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK,static_cast<AssertArg>(_status));

    // Call output command port

    FwOpcodeType _opcode;
    const U32 idBase = this->getIdBase();
    _opcode = EventActionComponentBase::OPCODE_EVAC_ADD + idBase;

    if (this->m_to_cmdDisp[0].isConnected()) {
      this->m_to_cmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          buff
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }

  }

  // ----------------------------------------------------------------------
  // Command: EVAC_REMOVE
  // ----------------------------------------------------------------------

  void EventActionTesterBase ::
    sendCmd_EVAC_REMOVE(
        const NATIVE_INT_TYPE instance,
        const U32 cmdSeq,
        U32 id
    )
  {

    // Serialize arguments

    Fw::CmdArgBuffer buff;
    Fw::SerializeStatus _status;
    _status = buff.serialize(id);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK,static_cast<AssertArg>(_status));

    // Call output command port

    FwOpcodeType _opcode;
    const U32 idBase = this->getIdBase();
    _opcode = EventActionComponentBase::OPCODE_EVAC_REMOVE + idBase;

    if (this->m_to_cmdDisp[0].isConnected()) {
      this->m_to_cmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          buff
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }

  }

  // ----------------------------------------------------------------------
  // Command: EVAC_DUMP
  // ----------------------------------------------------------------------

  void EventActionTesterBase ::
    sendCmd_EVAC_DUMP(
        const NATIVE_INT_TYPE instance,
        const U32 cmdSeq
    )
  {

    // Serialize arguments

    Fw::CmdArgBuffer buff;

    // Call output command port

    FwOpcodeType _opcode;
    const U32 idBase = this->getIdBase();
    _opcode = EventActionComponentBase::OPCODE_EVAC_DUMP + idBase;

    if (this->m_to_cmdDisp[0].isConnected()) {
      this->m_to_cmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          buff
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }

  }


  void EventActionTesterBase ::
    sendRawCmd(FwOpcodeType opcode, U32 cmdSeq, Fw::CmdArgBuffer& args) {

    const U32 idBase = this->getIdBase();
    FwOpcodeType _opcode = opcode + idBase;
    if (this->m_to_cmdDisp[0].isConnected()) {
      this->m_to_cmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          args
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }

  }

  // ----------------------------------------------------------------------
  // History
  // ----------------------------------------------------------------------

  void EventActionTesterBase ::
    clearHistory()
  {
    this->cmdResponseHistory->clear();
    this->textLogHistory->clear();
    this->clearEvents();
    this->clearFromPortHistory();
  }

  // ----------------------------------------------------------------------
  // Time
  // ----------------------------------------------------------------------

  void EventActionTesterBase ::
    setTestTime(const Fw::Time& time)
  {
    this->m_testTime = time;
  }

  // ----------------------------------------------------------------------
  // Event dispatch
  // ----------------------------------------------------------------------

  void EventActionTesterBase ::
    dispatchEvents(
        const FwEventIdType id,
        Fw::Time &timeTag,
        const Fw::LogSeverity severity,
        Fw::LogBuffer &args
    )
  {

    args.resetDeser();

    const U32 idBase = this->getIdBase();
    FW_ASSERT(id >= idBase, id, idBase);
    switch (id - idBase) {

      case EventActionComponentBase::EVENTID_EVAC_ADDED:
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 2,_numArgs,2);

#endif
        Fw::LogStringArg sequence;
        _status = args.deserialize(sequence);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        U32 eventId;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U32),_argSize,sizeof(U32));
        }
#endif
        _status = args.deserialize(eventId);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_HI_EVAC_ADDED(sequence, eventId);

        break;

      }

      case EventActionComponentBase::EVENTID_EVAC_REMOVED:
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 2,_numArgs,2);

#endif
        Fw::LogStringArg sequence;
        _status = args.deserialize(sequence);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        U32 eventId;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U32),_argSize,sizeof(U32));
        }
#endif
        _status = args.deserialize(eventId);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_HI_EVAC_REMOVED(sequence, eventId);

        break;

      }

      case EventActionComponentBase::EVENTID_EVAC_LIST_FULL:
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);

#endif
        U32 eventId;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U32),_argSize,sizeof(U32));
        }
#endif
        _status = args.deserialize(eventId);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_WARNING_LO_EVAC_LIST_FULL(eventId);

        break;

      }

      case EventActionComponentBase::EVENTID_EVAC_NOT_FOUND:
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);

#endif
        U32 eventId;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U32),_argSize,sizeof(U32));
        }
#endif
        _status = args.deserialize(eventId);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_WARNING_LO_EVAC_NOT_FOUND(eventId);

        break;

      }

      case EventActionComponentBase::EVENTID_EVAC_ALREADY_REGISTERED:
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 2,_numArgs,2);

#endif
        U32 eventId;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U32),_argSize,sizeof(U32));
        }
#endif
        _status = args.deserialize(eventId);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        Fw::LogStringArg sequence;
        _status = args.deserialize(sequence);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_WARNING_HI_EVAC_ALREADY_REGISTERED(eventId, sequence);

        break;

      }

      case EventActionComponentBase::EVENTID_EVAC_DUMP:
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 2,_numArgs,2);

#endif
        Fw::LogStringArg sequence;
        _status = args.deserialize(sequence);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        U32 eventId;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U32),_argSize,sizeof(U32));
        }
#endif
        _status = args.deserialize(eventId);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_HI_EVAC_DUMP(sequence, eventId);

        break;

      }

      case EventActionComponentBase::EVENTID_EVAC_RUN:
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 2,_numArgs,2);

#endif
        U32 eventId;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U32),_argSize,sizeof(U32));
        }
#endif
        _status = args.deserialize(eventId);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        Fw::LogStringArg sequence;
        _status = args.deserialize(sequence);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_HI_EVAC_RUN(eventId, sequence);

        break;

      }

      default: {
        FW_ASSERT(0, id);
        break;
      }

    }

  }

  void EventActionTesterBase ::
    clearEvents(void)
  {
    this->eventsSize = 0;
    this->eventHistory_EVAC_ADDED->clear();
    this->eventHistory_EVAC_REMOVED->clear();
    this->eventHistory_EVAC_LIST_FULL->clear();
    this->eventHistory_EVAC_NOT_FOUND->clear();
    this->eventHistory_EVAC_ALREADY_REGISTERED->clear();
    this->eventHistory_EVAC_DUMP->clear();
    this->eventHistory_EVAC_RUN->clear();
  }

#if FW_ENABLE_TEXT_LOGGING

  // ----------------------------------------------------------------------
  // Text events
  // ----------------------------------------------------------------------

  void EventActionTesterBase ::
    textLogIn(
        const U32 id,
        Fw::Time &timeTag,
        const Fw::TextLogSeverity severity,
        const Fw::TextLogString &text
    )
  {
    TextLogEntry e = { id, timeTag, severity, text };
    textLogHistory->push_back(e);
  }

  void EventActionTesterBase ::
    printTextLogHistoryEntry(
        const TextLogEntry& e,
        FILE* file
    )
  {
    const char *severityString = "UNKNOWN";
    switch (e.severity) {
      case Fw::TEXT_LOG_FATAL:
        severityString = "FATAL";
        break;
      case Fw::TEXT_LOG_WARNING_HI:
        severityString = "WARNING_HI";
        break;
      case Fw::TEXT_LOG_WARNING_LO:
        severityString = "WARNING_LO";
        break;
      case Fw::TEXT_LOG_COMMAND:
        severityString = "COMMAND";
        break;
      case Fw::TEXT_LOG_ACTIVITY_HI:
        severityString = "ACTIVITY_HI";
        break;
      case Fw::TEXT_LOG_ACTIVITY_LO:
        severityString = "ACTIVITY_LO";
        break;
      case Fw::TEXT_LOG_DIAGNOSTIC:
       severityString = "DIAGNOSTIC";
        break;
      default:
        severityString = "SEVERITY ERROR";
        break;
    }

    fprintf(
        file,
        "EVENT: (%d) (%d:%d,%d) %s: %s\n",
        e.id,
        const_cast<TextLogEntry&>(e).timeTag.getTimeBase(),
        const_cast<TextLogEntry&>(e).timeTag.getSeconds(),
        const_cast<TextLogEntry&>(e).timeTag.getUSeconds(),
        severityString,
        e.text.toChar()
    );

  }

  void EventActionTesterBase ::
    printTextLogHistory(FILE *file)
  {
    for (U32 i = 0; i < this->textLogHistory->size(); ++i) {
      this->printTextLogHistoryEntry(
          this->textLogHistory->at(i),
          file
      );
    }
  }

#endif

  // ----------------------------------------------------------------------
  // Event: EVAC_ADDED
  // ----------------------------------------------------------------------

  void EventActionTesterBase ::
    logIn_ACTIVITY_HI_EVAC_ADDED(
        Fw::LogStringArg& sequence,
        U32 eventId
    )
  {
    EventEntry_EVAC_ADDED e = {
      sequence, eventId
    };
    eventHistory_EVAC_ADDED->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: EVAC_REMOVED
  // ----------------------------------------------------------------------

  void EventActionTesterBase ::
    logIn_ACTIVITY_HI_EVAC_REMOVED(
        Fw::LogStringArg& sequence,
        U32 eventId
    )
  {
    EventEntry_EVAC_REMOVED e = {
      sequence, eventId
    };
    eventHistory_EVAC_REMOVED->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: EVAC_LIST_FULL
  // ----------------------------------------------------------------------

  void EventActionTesterBase ::
    logIn_WARNING_LO_EVAC_LIST_FULL(
        U32 eventId
    )
  {
    EventEntry_EVAC_LIST_FULL e = {
      eventId
    };
    eventHistory_EVAC_LIST_FULL->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: EVAC_NOT_FOUND
  // ----------------------------------------------------------------------

  void EventActionTesterBase ::
    logIn_WARNING_LO_EVAC_NOT_FOUND(
        U32 eventId
    )
  {
    EventEntry_EVAC_NOT_FOUND e = {
      eventId
    };
    eventHistory_EVAC_NOT_FOUND->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: EVAC_ALREADY_REGISTERED
  // ----------------------------------------------------------------------

  void EventActionTesterBase ::
    logIn_WARNING_HI_EVAC_ALREADY_REGISTERED(
        U32 eventId,
        Fw::LogStringArg& sequence
    )
  {
    EventEntry_EVAC_ALREADY_REGISTERED e = {
      eventId, sequence
    };
    eventHistory_EVAC_ALREADY_REGISTERED->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: EVAC_DUMP
  // ----------------------------------------------------------------------

  void EventActionTesterBase ::
    logIn_ACTIVITY_HI_EVAC_DUMP(
        Fw::LogStringArg& sequence,
        U32 eventId
    )
  {
    EventEntry_EVAC_DUMP e = {
      sequence, eventId
    };
    eventHistory_EVAC_DUMP->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: EVAC_RUN
  // ----------------------------------------------------------------------

  void EventActionTesterBase ::
    logIn_ACTIVITY_HI_EVAC_RUN(
        U32 eventId,
        Fw::LogStringArg& sequence
    )
  {
    EventEntry_EVAC_RUN e = {
      eventId, sequence
    };
    eventHistory_EVAC_RUN->push_back(e);
    ++this->eventsSize;
  }

} // end namespace App
