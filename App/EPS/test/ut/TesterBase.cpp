// ======================================================================
// \title  EPS/test/ut/TesterBase.cpp
// \author Auto-generated
// \brief  cpp file for EPS component test harness base class
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

  EPSTesterBase ::
    EPSTesterBase(
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
    // Initialize telemetry histories
    this->tlmHistory_EPS_Voltage_battery_mV =
      new History<TlmEntry_EPS_Voltage_battery_mV>(maxHistorySize);
    this->tlmHistory_EPS_Battery_mode =
      new History<TlmEntry_EPS_Battery_mode>(maxHistorySize);
    this->tlmHistory_EPS_Temp_Battery_Celsuis =
      new History<TlmEntry_EPS_Temp_Battery_Celsuis>(maxHistorySize);
    this->tlmHistory_EPS_LAST_CMD_RETURN =
      new History<TlmEntry_EPS_LAST_CMD_RETURN>(maxHistorySize);
    // Initialize event histories
#if FW_ENABLE_TEXT_LOGGING
    this->textLogHistory = new History<TextLogEntry>(maxHistorySize);
#endif
    this->eventHistory_MS_CMD_SEND_EPS =
      new History<EventEntry_MS_CMD_SEND_EPS>(maxHistorySize);
    this->eventHistory_MS_CMD_RECV_EPS =
      new History<EventEntry_MS_CMD_RECV_EPS>(maxHistorySize);
    this->eventHistory_MS_CMD_ERROR =
      new History<EventEntry_MS_CMD_ERROR>(maxHistorySize);
    this->eventHistory_MS_BATT_VOLT_LOW =
      new History<EventEntry_MS_BATT_VOLT_LOW>(maxHistorySize);
    this->eventHistory_MS_BATT_TEMP_HIGH =
      new History<EventEntry_MS_BATT_TEMP_HIGH>(maxHistorySize);
    this->eventHistory_MS_CHNG_BATT_MOD =
      new History<EventEntry_MS_CHNG_BATT_MOD>(maxHistorySize);
    this->eventHistory_MS_CMD_PAYLOAD_ERROR =
      new History<EventEntry_MS_CMD_PAYLOAD_ERROR>(maxHistorySize);
    this->eventHistory_MS_CMD_PORT_ERROR =
      new History<EventEntry_MS_CMD_PORT_ERROR>(maxHistorySize);
    this->eventHistory_MS_PING =
      new History<EventEntry_MS_PING>(maxHistorySize);
    // Initialize histories for typed user output ports
    this->fromPortHistory_DataOut =
      new History<FromPortEntry_DataOut>(maxHistorySize);
    // Clear history
    this->clearHistory();
  }

  EPSTesterBase ::
    ~EPSTesterBase(void)
  {
    // Destroy command history
    delete this->cmdResponseHistory;
    // Destroy telemetry histories
    delete this->tlmHistory_EPS_Voltage_battery_mV;
    delete this->tlmHistory_EPS_Battery_mode;
    delete this->tlmHistory_EPS_Temp_Battery_Celsuis;
    delete this->tlmHistory_EPS_LAST_CMD_RETURN;
    // Destroy event histories
#if FW_ENABLE_TEXT_LOGGING
    delete this->textLogHistory;
#endif
    delete this->eventHistory_MS_CMD_SEND_EPS;
    delete this->eventHistory_MS_CMD_RECV_EPS;
    delete this->eventHistory_MS_CMD_ERROR;
    delete this->eventHistory_MS_BATT_VOLT_LOW;
    delete this->eventHistory_MS_BATT_TEMP_HIGH;
    delete this->eventHistory_MS_CHNG_BATT_MOD;
    delete this->eventHistory_MS_CMD_PAYLOAD_ERROR;
    delete this->eventHistory_MS_CMD_PORT_ERROR;
    delete this->eventHistory_MS_PING;
    // Destroy port histories
    delete this->fromPortHistory_DataOut;
  }

  void EPSTesterBase ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {

    // Initialize base class

		Fw::PassiveComponentBase::init(instance);

    // Attach input port DataOut

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_DataOut();
        ++_port
    ) {

      this->m_from_DataOut[_port].init();
      this->m_from_DataOut[_port].addCallComp(
          this,
          from_DataOut_static
      );
      this->m_from_DataOut[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_DataOut[%d]",
          this->m_objName,
          _port
      );
      this->m_from_DataOut[_port].setObjName(_portName);
#endif

    }

    // Attach input port CmdStatus

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_CmdStatus();
        ++_port
    ) {

      this->m_from_CmdStatus[_port].init();
      this->m_from_CmdStatus[_port].addCallComp(
          this,
          from_CmdStatus_static
      );
      this->m_from_CmdStatus[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_CmdStatus[%d]",
          this->m_objName,
          _port
      );
      this->m_from_CmdStatus[_port].setObjName(_portName);
#endif

    }

    // Attach input port CmdReg

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_CmdReg();
        ++_port
    ) {

      this->m_from_CmdReg[_port].init();
      this->m_from_CmdReg[_port].addCallComp(
          this,
          from_CmdReg_static
      );
      this->m_from_CmdReg[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_CmdReg[%d]",
          this->m_objName,
          _port
      );
      this->m_from_CmdReg[_port].setObjName(_portName);
#endif

    }

    // Attach input port Tlm

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_Tlm();
        ++_port
    ) {

      this->m_from_Tlm[_port].init();
      this->m_from_Tlm[_port].addCallComp(
          this,
          from_Tlm_static
      );
      this->m_from_Tlm[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_Tlm[%d]",
          this->m_objName,
          _port
      );
      this->m_from_Tlm[_port].setObjName(_portName);
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

    // Attach input port Log

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_Log();
        ++_port
    ) {

      this->m_from_Log[_port].init();
      this->m_from_Log[_port].addCallComp(
          this,
          from_Log_static
      );
      this->m_from_Log[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_Log[%d]",
          this->m_objName,
          _port
      );
      this->m_from_Log[_port].setObjName(_portName);
#endif

    }

    // Attach input port LogText

#if FW_ENABLE_TEXT_LOGGING == 1
    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_LogText();
        ++_port
    ) {

      this->m_from_LogText[_port].init();
      this->m_from_LogText[_port].addCallComp(
          this,
          from_LogText_static
      );
      this->m_from_LogText[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_LogText[%d]",
          this->m_objName,
          _port
      );
      this->m_from_LogText[_port].setObjName(_portName);
#endif

    }
#endif

    // Initialize output port DataIn

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_DataIn();
        ++_port
    ) {
      this->m_to_DataIn[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_DataIn[%d]",
          this->m_objName,
          _port
      );
      this->m_to_DataIn[_port].setObjName(_portName);
#endif

    }

    // Initialize output port Schedin

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_Schedin();
        ++_port
    ) {
      this->m_to_Schedin[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[120];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_Schedin[%d]",
          this->m_objName,
          _port
      );
      this->m_to_Schedin[_port].setObjName(_portName);
#endif

    }

  }

  // ----------------------------------------------------------------------
  // Getters for port counts
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE EPSTesterBase ::
    getNum_from_DataOut(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_DataOut);
  }

  NATIVE_INT_TYPE EPSTesterBase ::
    getNum_to_DataIn(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_DataIn);
  }

  NATIVE_INT_TYPE EPSTesterBase ::
    getNum_to_Schedin(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_Schedin);
  }

  NATIVE_INT_TYPE EPSTesterBase ::
    getNum_to_CmdDisp(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_CmdDisp);
  }

  NATIVE_INT_TYPE EPSTesterBase ::
    getNum_from_CmdStatus(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_CmdStatus);
  }

  NATIVE_INT_TYPE EPSTesterBase ::
    getNum_from_CmdReg(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_CmdReg);
  }

  NATIVE_INT_TYPE EPSTesterBase ::
    getNum_from_Tlm(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_Tlm);
  }

  NATIVE_INT_TYPE EPSTesterBase ::
    getNum_from_Time(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_Time);
  }

  NATIVE_INT_TYPE EPSTesterBase ::
    getNum_from_Log(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_Log);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  NATIVE_INT_TYPE EPSTesterBase ::
    getNum_from_LogText(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_LogText);
  }
#endif

  // ----------------------------------------------------------------------
  // Connectors for to ports
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    connect_to_DataIn(
        const NATIVE_INT_TYPE portNum,
        App::InputEPSCmdPort *const DataIn
    )
  {
    FW_ASSERT(portNum < this->getNum_to_DataIn(),static_cast<AssertArg>(portNum));
    this->m_to_DataIn[portNum].addCallPort(DataIn);
  }

  void EPSTesterBase ::
    connect_to_Schedin(
        const NATIVE_INT_TYPE portNum,
        Svc::InputSchedPort *const Schedin
    )
  {
    FW_ASSERT(portNum < this->getNum_to_Schedin(),static_cast<AssertArg>(portNum));
    this->m_to_Schedin[portNum].addCallPort(Schedin);
  }

  void EPSTesterBase ::
    connect_to_CmdDisp(
        const NATIVE_INT_TYPE portNum,
        Fw::InputCmdPort *const CmdDisp
    )
  {
    FW_ASSERT(portNum < this->getNum_to_CmdDisp(),static_cast<AssertArg>(portNum));
    this->m_to_CmdDisp[portNum].addCallPort(CmdDisp);
  }


  // ----------------------------------------------------------------------
  // Invocation functions for to ports
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    invoke_to_DataIn(
        const NATIVE_INT_TYPE portNum,
        U8 port,
        Fw::Buffer &data,
        U8 isSched
    )
  {
    FW_ASSERT(portNum < this->getNum_to_DataIn(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_DataIn(),static_cast<AssertArg>(portNum));
    this->m_to_DataIn[portNum].invoke(
        port, data, isSched
    );
  }

  void EPSTesterBase ::
    invoke_to_Schedin(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    FW_ASSERT(portNum < this->getNum_to_Schedin(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_Schedin(),static_cast<AssertArg>(portNum));
    this->m_to_Schedin[portNum].invoke(
        context
    );
  }

  // ----------------------------------------------------------------------
  // Connection status for to ports
  // ----------------------------------------------------------------------

  bool EPSTesterBase ::
    isConnected_to_DataIn(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_DataIn(), static_cast<AssertArg>(portNum));
    return this->m_to_DataIn[portNum].isConnected();
  }

  bool EPSTesterBase ::
    isConnected_to_Schedin(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_Schedin(), static_cast<AssertArg>(portNum));
    return this->m_to_Schedin[portNum].isConnected();
  }

  bool EPSTesterBase ::
    isConnected_to_CmdDisp(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_CmdDisp(), static_cast<AssertArg>(portNum));
    return this->m_to_CmdDisp[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Getters for from ports
  // ----------------------------------------------------------------------

  App::InputEPSCmdPort *EPSTesterBase ::
    get_from_DataOut(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_DataOut(),static_cast<AssertArg>(portNum));
    return &this->m_from_DataOut[portNum];
  }

  Fw::InputCmdResponsePort *EPSTesterBase ::
    get_from_CmdStatus(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_CmdStatus(),static_cast<AssertArg>(portNum));
    return &this->m_from_CmdStatus[portNum];
  }

  Fw::InputCmdRegPort *EPSTesterBase ::
    get_from_CmdReg(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_CmdReg(),static_cast<AssertArg>(portNum));
    return &this->m_from_CmdReg[portNum];
  }

  Fw::InputTlmPort *EPSTesterBase ::
    get_from_Tlm(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_Tlm(),static_cast<AssertArg>(portNum));
    return &this->m_from_Tlm[portNum];
  }

  Fw::InputTimePort *EPSTesterBase ::
    get_from_Time(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_Time(),static_cast<AssertArg>(portNum));
    return &this->m_from_Time[portNum];
  }

  Fw::InputLogPort *EPSTesterBase ::
    get_from_Log(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_Log(),static_cast<AssertArg>(portNum));
    return &this->m_from_Log[portNum];
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  Fw::InputLogTextPort *EPSTesterBase ::
    get_from_LogText(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_LogText(),static_cast<AssertArg>(portNum));
    return &this->m_from_LogText[portNum];
  }
#endif

  // ----------------------------------------------------------------------
  // Static functions for from ports
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    from_DataOut_static(
        Fw::PassiveComponentBase *const callComp,
        const NATIVE_INT_TYPE portNum,
        U8 port,
        Fw::Buffer &data,
        U8 isSched
    )
  {
    FW_ASSERT(callComp);
    EPSTesterBase* _testerBase =
      static_cast<EPSTesterBase*>(callComp);
    _testerBase->from_DataOut_handlerBase(
        portNum,
        port, data, isSched
    );
  }

  void EPSTesterBase ::
    from_CmdStatus_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        const Fw::CommandResponse response
    )
  {
    EPSTesterBase* _testerBase =
      static_cast<EPSTesterBase*>(component);
    _testerBase->cmdResponseIn(opCode, cmdSeq, response);
  }

  void EPSTesterBase ::
    from_CmdReg_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        const FwOpcodeType opCode
    )
  {

  }

  void EPSTesterBase ::
    from_Tlm_static(
        Fw::PassiveComponentBase *const component,
        NATIVE_INT_TYPE portNum,
        FwChanIdType id,
        Fw::Time &timeTag,
        Fw::TlmBuffer &val
    )
  {
    EPSTesterBase* _testerBase =
      static_cast<EPSTesterBase*>(component);
    _testerBase->dispatchTlm(id, timeTag, val);
  }

  void EPSTesterBase ::
    from_Log_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        FwEventIdType id,
        Fw::Time &timeTag,
        Fw::LogSeverity severity,
        Fw::LogBuffer &args
    )
  {
    EPSTesterBase* _testerBase =
      static_cast<EPSTesterBase*>(component);
    _testerBase->dispatchEvents(id, timeTag, severity, args);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void EPSTesterBase ::
    from_LogText_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        FwEventIdType id,
        Fw::Time &timeTag,
        Fw::TextLogSeverity severity,
        Fw::TextLogString &text
    )
  {
    EPSTesterBase* _testerBase =
      static_cast<EPSTesterBase*>(component);
    _testerBase->textLogIn(id,timeTag,severity,text);
  }
#endif

  void EPSTesterBase ::
    from_Time_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        Fw::Time& time
    )
  {
    EPSTesterBase* _testerBase =
      static_cast<EPSTesterBase*>(component);
    time = _testerBase->m_testTime;
  }

  // ----------------------------------------------------------------------
  // Histories for typed from ports
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    clearFromPortHistory(void)
  {
    this->fromPortHistorySize = 0;
    this->fromPortHistory_DataOut->clear();
  }

  // ----------------------------------------------------------------------
  // From port: DataOut
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    pushFromPortEntry_DataOut(
        U8 port,
        Fw::Buffer &data,
        U8 isSched
    )
  {
    FromPortEntry_DataOut _e = {
      port, data, isSched
    };
    this->fromPortHistory_DataOut->push_back(_e);
    ++this->fromPortHistorySize;
  }

  // ----------------------------------------------------------------------
  // Handler base functions for from ports
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    from_DataOut_handlerBase(
        const NATIVE_INT_TYPE portNum,
        U8 port,
        Fw::Buffer &data,
        U8 isSched
    )
  {
    FW_ASSERT(portNum < this->getNum_from_DataOut(),static_cast<AssertArg>(portNum));
    this->from_DataOut_handler(
        portNum,
        port, data, isSched
    );
  }

  // ----------------------------------------------------------------------
  // Command response handling
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
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
  // Command: MS_SEND_CMD
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    sendCmd_MS_SEND_CMD(
        const NATIVE_INT_TYPE instance,
        const U32 cmdSeq,
        EPSComponentBase::EPSOp operation,
        const Fw::CmdStringArg& payload
    )
  {

    // Serialize arguments

    Fw::CmdArgBuffer buff;
    Fw::SerializeStatus _status;
    _status = buff.serialize((FwEnumStoreType) operation);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK,static_cast<AssertArg>(_status));
    _status = buff.serialize(payload);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK,static_cast<AssertArg>(_status));

    // Call output command port

    FwOpcodeType _opcode;
    const U32 idBase = this->getIdBase();
    _opcode = EPSComponentBase::OPCODE_MS_SEND_CMD + idBase;

    if (this->m_to_CmdDisp[0].isConnected()) {
      this->m_to_CmdDisp[0].invoke(
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
  // Command: MS_SEND_PING
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    sendCmd_MS_SEND_PING(
        const NATIVE_INT_TYPE instance,
        const U32 cmdSeq
    )
  {

    // Serialize arguments

    Fw::CmdArgBuffer buff;

    // Call output command port

    FwOpcodeType _opcode;
    const U32 idBase = this->getIdBase();
    _opcode = EPSComponentBase::OPCODE_MS_SEND_PING + idBase;

    if (this->m_to_CmdDisp[0].isConnected()) {
      this->m_to_CmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          buff
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }

  }


  void EPSTesterBase ::
    sendRawCmd(FwOpcodeType opcode, U32 cmdSeq, Fw::CmdArgBuffer& args) {

    const U32 idBase = this->getIdBase();
    FwOpcodeType _opcode = opcode + idBase;
    if (this->m_to_CmdDisp[0].isConnected()) {
      this->m_to_CmdDisp[0].invoke(
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

  void EPSTesterBase ::
    clearHistory()
  {
    this->cmdResponseHistory->clear();
    this->clearTlm();
    this->textLogHistory->clear();
    this->clearEvents();
    this->clearFromPortHistory();
  }

  // ----------------------------------------------------------------------
  // Time
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    setTestTime(const Fw::Time& time)
  {
    this->m_testTime = time;
  }

  // ----------------------------------------------------------------------
  // Telemetry dispatch
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    dispatchTlm(
        const FwChanIdType id,
        const Fw::Time &timeTag,
        Fw::TlmBuffer &val
    )
  {

    val.resetDeser();

    const U32 idBase = this->getIdBase();
    FW_ASSERT(id >= idBase, id, idBase);

    switch (id - idBase) {

      case EPSComponentBase::CHANNELID_EPS_VOLTAGE_BATTERY_MV:
      {
        U16 arg;
        const Fw::SerializeStatus _status = val.deserialize(arg);
        if (_status != Fw::FW_SERIALIZE_OK) {
          printf("Error deserializing EPS_Voltage_battery_mV: %d\n", _status);
          return;
        }
        this->tlmInput_EPS_Voltage_battery_mV(timeTag, arg);
        break;
      }

      case EPSComponentBase::CHANNELID_EPS_BATTERY_MODE:
      {
        U8 arg;
        const Fw::SerializeStatus _status = val.deserialize(arg);
        if (_status != Fw::FW_SERIALIZE_OK) {
          printf("Error deserializing EPS_Battery_mode: %d\n", _status);
          return;
        }
        this->tlmInput_EPS_Battery_mode(timeTag, arg);
        break;
      }

      case EPSComponentBase::CHANNELID_EPS_TEMP_BATTERY_CELSUIS:
      {
        U16 arg;
        const Fw::SerializeStatus _status = val.deserialize(arg);
        if (_status != Fw::FW_SERIALIZE_OK) {
          printf("Error deserializing EPS_Temp_Battery_Celsuis: %d\n", _status);
          return;
        }
        this->tlmInput_EPS_Temp_Battery_Celsuis(timeTag, arg);
        break;
      }

      case EPSComponentBase::CHANNELID_EPS_LAST_CMD_RETURN:
      {
        Fw::TlmString arg;
        const Fw::SerializeStatus _status = val.deserialize(arg);
        if (_status != Fw::FW_SERIALIZE_OK) {
          printf("Error deserializing EPS_LAST_CMD_RETURN: %d\n", _status);
          return;
        }
        this->tlmInput_EPS_LAST_CMD_RETURN(timeTag, arg);
        break;
      }

      default: {
        FW_ASSERT(0, id);
        break;
      }

    }

  }

  void EPSTesterBase ::
    clearTlm(void)
  {
    this->tlmSize = 0;
    this->tlmHistory_EPS_Voltage_battery_mV->clear();
    this->tlmHistory_EPS_Battery_mode->clear();
    this->tlmHistory_EPS_Temp_Battery_Celsuis->clear();
    this->tlmHistory_EPS_LAST_CMD_RETURN->clear();
  }

  // ----------------------------------------------------------------------
  // Channel: EPS_Voltage_battery_mV
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    tlmInput_EPS_Voltage_battery_mV(
        const Fw::Time& timeTag,
        const U16& val
    )
  {
    TlmEntry_EPS_Voltage_battery_mV e = { timeTag, val };
    this->tlmHistory_EPS_Voltage_battery_mV->push_back(e);
    ++this->tlmSize;
  }

  // ----------------------------------------------------------------------
  // Channel: EPS_Battery_mode
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    tlmInput_EPS_Battery_mode(
        const Fw::Time& timeTag,
        const U8& val
    )
  {
    TlmEntry_EPS_Battery_mode e = { timeTag, val };
    this->tlmHistory_EPS_Battery_mode->push_back(e);
    ++this->tlmSize;
  }

  // ----------------------------------------------------------------------
  // Channel: EPS_Temp_Battery_Celsuis
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    tlmInput_EPS_Temp_Battery_Celsuis(
        const Fw::Time& timeTag,
        const U16& val
    )
  {
    TlmEntry_EPS_Temp_Battery_Celsuis e = { timeTag, val };
    this->tlmHistory_EPS_Temp_Battery_Celsuis->push_back(e);
    ++this->tlmSize;
  }

  // ----------------------------------------------------------------------
  // Channel: EPS_LAST_CMD_RETURN
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    tlmInput_EPS_LAST_CMD_RETURN(
        const Fw::Time& timeTag,
        const Fw::TlmString& val
    )
  {
    TlmEntry_EPS_LAST_CMD_RETURN e = { timeTag, val };
    this->tlmHistory_EPS_LAST_CMD_RETURN->push_back(e);
    ++this->tlmSize;
  }

  // ----------------------------------------------------------------------
  // Event dispatch
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
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

      case EPSComponentBase::EVENTID_MS_CMD_SEND_EPS:
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
        FW_ASSERT(_numArgs == 3,_numArgs,3);

#endif
        U8 port;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U8),_argSize,sizeof(U8));
        }
#endif
        _status = args.deserialize(port);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        U8 cmd;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U8),_argSize,sizeof(U8));
        }
#endif
        _status = args.deserialize(cmd);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        Fw::LogStringArg payload;
        _status = args.deserialize(payload);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_LO_MS_CMD_SEND_EPS(port, cmd, payload);

        break;

      }

      case EPSComponentBase::EVENTID_MS_CMD_RECV_EPS:
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
        FW_ASSERT(_numArgs == 3,_numArgs,3);

#endif
        U8 port;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U8),_argSize,sizeof(U8));
        }
#endif
        _status = args.deserialize(port);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        U8 cmd;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U8),_argSize,sizeof(U8));
        }
#endif
        _status = args.deserialize(cmd);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        Fw::LogStringArg payload;
        _status = args.deserialize(payload);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_LO_MS_CMD_RECV_EPS(port, cmd, payload);

        break;

      }

      case EPSComponentBase::EVENTID_MS_CMD_ERROR:
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
        FW_ASSERT(_numArgs == 3,_numArgs,3);

#endif
        U8 port;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U8),_argSize,sizeof(U8));
        }
#endif
        _status = args.deserialize(port);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        U8 cmd;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U8),_argSize,sizeof(U8));
        }
#endif
        _status = args.deserialize(cmd);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        U8 status;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U8),_argSize,sizeof(U8));
        }
#endif
        _status = args.deserialize(status);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_WARNING_LO_MS_CMD_ERROR(port, cmd, status);

        break;

      }

      case EPSComponentBase::EVENTID_MS_BATT_VOLT_LOW:
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
        U16 volt;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U16),_argSize,sizeof(U16));
        }
#endif
        _status = args.deserialize(volt);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_WARNING_HI_MS_BATT_VOLT_LOW(volt);

        break;

      }

      case EPSComponentBase::EVENTID_MS_BATT_TEMP_HIGH:
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
        U8 temp;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U8),_argSize,sizeof(U8));
        }
#endif
        _status = args.deserialize(temp);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_WARNING_HI_MS_BATT_TEMP_HIGH(temp);

        break;

      }

      case EPSComponentBase::EVENTID_MS_CHNG_BATT_MOD:
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
        U8 mode;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U8),_argSize,sizeof(U8));
        }
#endif
        _status = args.deserialize(mode);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_WARNING_HI_MS_CHNG_BATT_MOD(mode);

        break;

      }

      case EPSComponentBase::EVENTID_MS_CMD_PAYLOAD_ERROR:
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
        Fw::LogStringArg payload;
        _status = args.deserialize(payload);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_WARNING_LO_MS_CMD_PAYLOAD_ERROR(payload);

        break;

      }

      case EPSComponentBase::EVENTID_MS_CMD_PORT_ERROR:
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
        U8 port;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(U8),_argSize,sizeof(U8));
        }
#endif
        _status = args.deserialize(port);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_WARNING_LO_MS_CMD_PORT_ERROR(port);

        break;

      }

      case EPSComponentBase::EVENTID_MS_PING:
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
        I32 port;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(I32),_argSize,sizeof(I32));
        }
#endif
        _status = args.deserialize(port);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_LO_MS_PING(port);

        break;

      }

      default: {
        FW_ASSERT(0, id);
        break;
      }

    }

  }

  void EPSTesterBase ::
    clearEvents(void)
  {
    this->eventsSize = 0;
    this->eventHistory_MS_CMD_SEND_EPS->clear();
    this->eventHistory_MS_CMD_RECV_EPS->clear();
    this->eventHistory_MS_CMD_ERROR->clear();
    this->eventHistory_MS_BATT_VOLT_LOW->clear();
    this->eventHistory_MS_BATT_TEMP_HIGH->clear();
    this->eventHistory_MS_CHNG_BATT_MOD->clear();
    this->eventHistory_MS_CMD_PAYLOAD_ERROR->clear();
    this->eventHistory_MS_CMD_PORT_ERROR->clear();
    this->eventHistory_MS_PING->clear();
  }

#if FW_ENABLE_TEXT_LOGGING

  // ----------------------------------------------------------------------
  // Text events
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
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

  void EPSTesterBase ::
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

  void EPSTesterBase ::
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
  // Event: MS_CMD_SEND_EPS
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    logIn_ACTIVITY_LO_MS_CMD_SEND_EPS(
        U8 port,
        U8 cmd,
        Fw::LogStringArg& payload
    )
  {
    EventEntry_MS_CMD_SEND_EPS e = {
      port, cmd, payload
    };
    eventHistory_MS_CMD_SEND_EPS->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: MS_CMD_RECV_EPS
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    logIn_ACTIVITY_LO_MS_CMD_RECV_EPS(
        U8 port,
        U8 cmd,
        Fw::LogStringArg& payload
    )
  {
    EventEntry_MS_CMD_RECV_EPS e = {
      port, cmd, payload
    };
    eventHistory_MS_CMD_RECV_EPS->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: MS_CMD_ERROR
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    logIn_WARNING_LO_MS_CMD_ERROR(
        U8 port,
        U8 cmd,
        U8 status
    )
  {
    EventEntry_MS_CMD_ERROR e = {
      port, cmd, status
    };
    eventHistory_MS_CMD_ERROR->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: MS_BATT_VOLT_LOW
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    logIn_WARNING_HI_MS_BATT_VOLT_LOW(
        U16 volt
    )
  {
    EventEntry_MS_BATT_VOLT_LOW e = {
      volt
    };
    eventHistory_MS_BATT_VOLT_LOW->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: MS_BATT_TEMP_HIGH
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    logIn_WARNING_HI_MS_BATT_TEMP_HIGH(
        U8 temp
    )
  {
    EventEntry_MS_BATT_TEMP_HIGH e = {
      temp
    };
    eventHistory_MS_BATT_TEMP_HIGH->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: MS_CHNG_BATT_MOD
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    logIn_WARNING_HI_MS_CHNG_BATT_MOD(
        U8 mode
    )
  {
    EventEntry_MS_CHNG_BATT_MOD e = {
      mode
    };
    eventHistory_MS_CHNG_BATT_MOD->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: MS_CMD_PAYLOAD_ERROR
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    logIn_WARNING_LO_MS_CMD_PAYLOAD_ERROR(
        Fw::LogStringArg& payload
    )
  {
    EventEntry_MS_CMD_PAYLOAD_ERROR e = {
      payload
    };
    eventHistory_MS_CMD_PAYLOAD_ERROR->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: MS_CMD_PORT_ERROR
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    logIn_WARNING_LO_MS_CMD_PORT_ERROR(
        U8 port
    )
  {
    EventEntry_MS_CMD_PORT_ERROR e = {
      port
    };
    eventHistory_MS_CMD_PORT_ERROR->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: MS_PING
  // ----------------------------------------------------------------------

  void EPSTesterBase ::
    logIn_ACTIVITY_LO_MS_PING(
        I32 port
    )
  {
    EventEntry_MS_PING e = {
      port
    };
    eventHistory_MS_PING->push_back(e);
    ++this->eventsSize;
  }

} // end namespace App
