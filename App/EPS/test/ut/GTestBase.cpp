// ======================================================================
// \title  EPS/test/ut/GTestBase.cpp
// \author Auto-generated
// \brief  cpp file for EPS component Google Test harness base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include "GTestBase.hpp"

namespace App {

  // ----------------------------------------------------------------------
  // Construction and destruction
  // ----------------------------------------------------------------------

  EPSGTestBase ::
    EPSGTestBase(
#if FW_OBJECT_NAMES == 1
        const char *const compName,
        const U32 maxHistorySize
#else
        const U32 maxHistorySize
#endif
    ) :
        EPSTesterBase (
#if FW_OBJECT_NAMES == 1
            compName,
#endif
            maxHistorySize
        )
  {

  }

  EPSGTestBase ::
    ~EPSGTestBase(void)
  {

  }

  // ----------------------------------------------------------------------
  // Commands
  // ----------------------------------------------------------------------

  void EPSGTestBase ::
    assertCmdResponse_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ((unsigned long) size, this->cmdResponseHistory->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of command response history\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->cmdResponseHistory->size() << "\n";
  }

  void EPSGTestBase ::
    assertCmdResponse(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        const Fw::CommandResponse response
    )
    const
  {
    ASSERT_LT(__index, this->cmdResponseHistory->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into command response history\n"
      << "  Expected: Less than size of command response history ("
      << this->cmdResponseHistory->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const CmdResponse& e = this->cmdResponseHistory->at(__index);
    ASSERT_EQ(opCode, e.opCode)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Opcode at index "
      << __index
      << " in command response history\n"
      << "  Expected: " << opCode << "\n"
      << "  Actual:   " << e.opCode << "\n";
    ASSERT_EQ(cmdSeq, e.cmdSeq)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Command sequence number at index "
      << __index
      << " in command response history\n"
      << "  Expected: " << cmdSeq << "\n"
      << "  Actual:   " << e.cmdSeq << "\n";
    ASSERT_EQ(response, e.response)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Command response at index "
      << __index
      << " in command response history\n"
      << "  Expected: " << response << "\n"
      << "  Actual:   " << e.response << "\n";
  }

  // ----------------------------------------------------------------------
  // Telemetry
  // ----------------------------------------------------------------------

  void EPSGTestBase ::
    assertTlm_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->tlmSize)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Total size of all telemetry histories\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmSize << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: EPS_Voltage_battery_mV
  // ----------------------------------------------------------------------

  void EPSGTestBase ::
    assertTlm_EPS_Voltage_battery_mV_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_EPS_Voltage_battery_mV->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel EPS_Voltage_battery_mV\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_EPS_Voltage_battery_mV->size() << "\n";
  }

  void EPSGTestBase ::
    assertTlm_EPS_Voltage_battery_mV(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U16& val
    )
    const
  {
    ASSERT_LT(__index, this->tlmHistory_EPS_Voltage_battery_mV->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel EPS_Voltage_battery_mV\n"
      << "  Expected: Less than size of history ("
      << this->tlmHistory_EPS_Voltage_battery_mV->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const TlmEntry_EPS_Voltage_battery_mV& e =
      this->tlmHistory_EPS_Voltage_battery_mV->at(__index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << __index
      << " on telmetry channel EPS_Voltage_battery_mV\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: EPS_Battery_mode
  // ----------------------------------------------------------------------

  void EPSGTestBase ::
    assertTlm_EPS_Battery_mode_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_EPS_Battery_mode->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel EPS_Battery_mode\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_EPS_Battery_mode->size() << "\n";
  }

  void EPSGTestBase ::
    assertTlm_EPS_Battery_mode(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U8& val
    )
    const
  {
    ASSERT_LT(__index, this->tlmHistory_EPS_Battery_mode->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel EPS_Battery_mode\n"
      << "  Expected: Less than size of history ("
      << this->tlmHistory_EPS_Battery_mode->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const TlmEntry_EPS_Battery_mode& e =
      this->tlmHistory_EPS_Battery_mode->at(__index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << __index
      << " on telmetry channel EPS_Battery_mode\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: EPS_Temp_Battery_Celsuis
  // ----------------------------------------------------------------------

  void EPSGTestBase ::
    assertTlm_EPS_Temp_Battery_Celsuis_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_EPS_Temp_Battery_Celsuis->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel EPS_Temp_Battery_Celsuis\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_EPS_Temp_Battery_Celsuis->size() << "\n";
  }

  void EPSGTestBase ::
    assertTlm_EPS_Temp_Battery_Celsuis(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U16& val
    )
    const
  {
    ASSERT_LT(__index, this->tlmHistory_EPS_Temp_Battery_Celsuis->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel EPS_Temp_Battery_Celsuis\n"
      << "  Expected: Less than size of history ("
      << this->tlmHistory_EPS_Temp_Battery_Celsuis->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const TlmEntry_EPS_Temp_Battery_Celsuis& e =
      this->tlmHistory_EPS_Temp_Battery_Celsuis->at(__index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << __index
      << " on telmetry channel EPS_Temp_Battery_Celsuis\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: EPS_LAST_CMD_RETURN
  // ----------------------------------------------------------------------

  void EPSGTestBase ::
    assertTlm_EPS_LAST_CMD_RETURN_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_EPS_LAST_CMD_RETURN->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel EPS_LAST_CMD_RETURN\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_EPS_LAST_CMD_RETURN->size() << "\n";
  }

  void EPSGTestBase ::
    assertTlm_EPS_LAST_CMD_RETURN(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const char *const val
    )
    const
  {
    ASSERT_LT(__index, this->tlmHistory_EPS_LAST_CMD_RETURN->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel EPS_LAST_CMD_RETURN\n"
      << "  Expected: Less than size of history ("
      << this->tlmHistory_EPS_LAST_CMD_RETURN->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const TlmEntry_EPS_LAST_CMD_RETURN& e =
      this->tlmHistory_EPS_LAST_CMD_RETURN->at(__index);
    ASSERT_STREQ(val, e.arg.toChar())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << __index
      << " on telmetry channel EPS_LAST_CMD_RETURN\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Events
  // ----------------------------------------------------------------------

  void EPSGTestBase ::
    assertEvents_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventsSize)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Total size of all event histories\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventsSize << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: MS_CMD_SEND_EPS
  // ----------------------------------------------------------------------

  void EPSGTestBase ::
    assertEvents_MS_CMD_SEND_EPS_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_MS_CMD_SEND_EPS->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event MS_CMD_SEND_EPS\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_MS_CMD_SEND_EPS->size() << "\n";
  }

  void EPSGTestBase ::
    assertEvents_MS_CMD_SEND_EPS(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U8 port,
        const U8 cmd,
        const char *const payload
    ) const
  {
    ASSERT_GT(this->eventHistory_MS_CMD_SEND_EPS->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event MS_CMD_SEND_EPS\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_MS_CMD_SEND_EPS->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_MS_CMD_SEND_EPS& e =
      this->eventHistory_MS_CMD_SEND_EPS->at(__index);
    ASSERT_EQ(port, e.port)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument port at index "
      << __index
      << " in history of event MS_CMD_SEND_EPS\n"
      << "  Expected: " << port << "\n"
      << "  Actual:   " << e.port << "\n";
    ASSERT_EQ(cmd, e.cmd)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument cmd at index "
      << __index
      << " in history of event MS_CMD_SEND_EPS\n"
      << "  Expected: " << cmd << "\n"
      << "  Actual:   " << e.cmd << "\n";
    ASSERT_STREQ(payload, e.payload.toChar())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument payload at index "
      << __index
      << " in history of event MS_CMD_SEND_EPS\n"
      << "  Expected: " << payload << "\n"
      << "  Actual:   " << e.payload.toChar() << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: MS_CMD_RECV_EPS
  // ----------------------------------------------------------------------

  void EPSGTestBase ::
    assertEvents_MS_CMD_RECV_EPS_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_MS_CMD_RECV_EPS->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event MS_CMD_RECV_EPS\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_MS_CMD_RECV_EPS->size() << "\n";
  }

  void EPSGTestBase ::
    assertEvents_MS_CMD_RECV_EPS(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U8 port,
        const U8 cmd,
        const char *const payload
    ) const
  {
    ASSERT_GT(this->eventHistory_MS_CMD_RECV_EPS->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event MS_CMD_RECV_EPS\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_MS_CMD_RECV_EPS->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_MS_CMD_RECV_EPS& e =
      this->eventHistory_MS_CMD_RECV_EPS->at(__index);
    ASSERT_EQ(port, e.port)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument port at index "
      << __index
      << " in history of event MS_CMD_RECV_EPS\n"
      << "  Expected: " << port << "\n"
      << "  Actual:   " << e.port << "\n";
    ASSERT_EQ(cmd, e.cmd)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument cmd at index "
      << __index
      << " in history of event MS_CMD_RECV_EPS\n"
      << "  Expected: " << cmd << "\n"
      << "  Actual:   " << e.cmd << "\n";
    ASSERT_STREQ(payload, e.payload.toChar())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument payload at index "
      << __index
      << " in history of event MS_CMD_RECV_EPS\n"
      << "  Expected: " << payload << "\n"
      << "  Actual:   " << e.payload.toChar() << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: MS_CMD_ERROR
  // ----------------------------------------------------------------------

  void EPSGTestBase ::
    assertEvents_MS_CMD_ERROR_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_MS_CMD_ERROR->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event MS_CMD_ERROR\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_MS_CMD_ERROR->size() << "\n";
  }

  void EPSGTestBase ::
    assertEvents_MS_CMD_ERROR(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U8 port,
        const U8 cmd,
        const U8 status
    ) const
  {
    ASSERT_GT(this->eventHistory_MS_CMD_ERROR->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event MS_CMD_ERROR\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_MS_CMD_ERROR->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_MS_CMD_ERROR& e =
      this->eventHistory_MS_CMD_ERROR->at(__index);
    ASSERT_EQ(port, e.port)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument port at index "
      << __index
      << " in history of event MS_CMD_ERROR\n"
      << "  Expected: " << port << "\n"
      << "  Actual:   " << e.port << "\n";
    ASSERT_EQ(cmd, e.cmd)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument cmd at index "
      << __index
      << " in history of event MS_CMD_ERROR\n"
      << "  Expected: " << cmd << "\n"
      << "  Actual:   " << e.cmd << "\n";
    ASSERT_EQ(status, e.status)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument status at index "
      << __index
      << " in history of event MS_CMD_ERROR\n"
      << "  Expected: " << status << "\n"
      << "  Actual:   " << e.status << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: MS_BATT_VOLT_LOW
  // ----------------------------------------------------------------------

  void EPSGTestBase ::
    assertEvents_MS_BATT_VOLT_LOW_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_MS_BATT_VOLT_LOW->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event MS_BATT_VOLT_LOW\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_MS_BATT_VOLT_LOW->size() << "\n";
  }

  void EPSGTestBase ::
    assertEvents_MS_BATT_VOLT_LOW(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U16 volt
    ) const
  {
    ASSERT_GT(this->eventHistory_MS_BATT_VOLT_LOW->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event MS_BATT_VOLT_LOW\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_MS_BATT_VOLT_LOW->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_MS_BATT_VOLT_LOW& e =
      this->eventHistory_MS_BATT_VOLT_LOW->at(__index);
    ASSERT_EQ(volt, e.volt)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument volt at index "
      << __index
      << " in history of event MS_BATT_VOLT_LOW\n"
      << "  Expected: " << volt << "\n"
      << "  Actual:   " << e.volt << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: MS_BATT_TEMP_HIGH
  // ----------------------------------------------------------------------

  void EPSGTestBase ::
    assertEvents_MS_BATT_TEMP_HIGH_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_MS_BATT_TEMP_HIGH->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event MS_BATT_TEMP_HIGH\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_MS_BATT_TEMP_HIGH->size() << "\n";
  }

  void EPSGTestBase ::
    assertEvents_MS_BATT_TEMP_HIGH(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U8 temp
    ) const
  {
    ASSERT_GT(this->eventHistory_MS_BATT_TEMP_HIGH->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event MS_BATT_TEMP_HIGH\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_MS_BATT_TEMP_HIGH->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_MS_BATT_TEMP_HIGH& e =
      this->eventHistory_MS_BATT_TEMP_HIGH->at(__index);
    ASSERT_EQ(temp, e.temp)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument temp at index "
      << __index
      << " in history of event MS_BATT_TEMP_HIGH\n"
      << "  Expected: " << temp << "\n"
      << "  Actual:   " << e.temp << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: MS_CHNG_BATT_MOD
  // ----------------------------------------------------------------------

  void EPSGTestBase ::
    assertEvents_MS_CHNG_BATT_MOD_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_MS_CHNG_BATT_MOD->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event MS_CHNG_BATT_MOD\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_MS_CHNG_BATT_MOD->size() << "\n";
  }

  void EPSGTestBase ::
    assertEvents_MS_CHNG_BATT_MOD(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U8 mode
    ) const
  {
    ASSERT_GT(this->eventHistory_MS_CHNG_BATT_MOD->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event MS_CHNG_BATT_MOD\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_MS_CHNG_BATT_MOD->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_MS_CHNG_BATT_MOD& e =
      this->eventHistory_MS_CHNG_BATT_MOD->at(__index);
    ASSERT_EQ(mode, e.mode)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument mode at index "
      << __index
      << " in history of event MS_CHNG_BATT_MOD\n"
      << "  Expected: " << mode << "\n"
      << "  Actual:   " << e.mode << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: MS_CMD_PAYLOAD_ERROR
  // ----------------------------------------------------------------------

  void EPSGTestBase ::
    assertEvents_MS_CMD_PAYLOAD_ERROR_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_MS_CMD_PAYLOAD_ERROR->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event MS_CMD_PAYLOAD_ERROR\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_MS_CMD_PAYLOAD_ERROR->size() << "\n";
  }

  void EPSGTestBase ::
    assertEvents_MS_CMD_PAYLOAD_ERROR(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const char *const payload
    ) const
  {
    ASSERT_GT(this->eventHistory_MS_CMD_PAYLOAD_ERROR->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event MS_CMD_PAYLOAD_ERROR\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_MS_CMD_PAYLOAD_ERROR->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_MS_CMD_PAYLOAD_ERROR& e =
      this->eventHistory_MS_CMD_PAYLOAD_ERROR->at(__index);
    ASSERT_STREQ(payload, e.payload.toChar())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument payload at index "
      << __index
      << " in history of event MS_CMD_PAYLOAD_ERROR\n"
      << "  Expected: " << payload << "\n"
      << "  Actual:   " << e.payload.toChar() << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: MS_CMD_PORT_ERROR
  // ----------------------------------------------------------------------

  void EPSGTestBase ::
    assertEvents_MS_CMD_PORT_ERROR_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_MS_CMD_PORT_ERROR->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event MS_CMD_PORT_ERROR\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_MS_CMD_PORT_ERROR->size() << "\n";
  }

  void EPSGTestBase ::
    assertEvents_MS_CMD_PORT_ERROR(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U8 port
    ) const
  {
    ASSERT_GT(this->eventHistory_MS_CMD_PORT_ERROR->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event MS_CMD_PORT_ERROR\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_MS_CMD_PORT_ERROR->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_MS_CMD_PORT_ERROR& e =
      this->eventHistory_MS_CMD_PORT_ERROR->at(__index);
    ASSERT_EQ(port, e.port)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument port at index "
      << __index
      << " in history of event MS_CMD_PORT_ERROR\n"
      << "  Expected: " << port << "\n"
      << "  Actual:   " << e.port << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: MS_PING
  // ----------------------------------------------------------------------

  void EPSGTestBase ::
    assertEvents_MS_PING_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_MS_PING->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event MS_PING\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_MS_PING->size() << "\n";
  }

  void EPSGTestBase ::
    assertEvents_MS_PING(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const I32 port
    ) const
  {
    ASSERT_GT(this->eventHistory_MS_PING->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event MS_PING\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_MS_PING->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_MS_PING& e =
      this->eventHistory_MS_PING->at(__index);
    ASSERT_EQ(port, e.port)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument port at index "
      << __index
      << " in history of event MS_PING\n"
      << "  Expected: " << port << "\n"
      << "  Actual:   " << e.port << "\n";
  }

  // ----------------------------------------------------------------------
  // From ports
  // ----------------------------------------------------------------------

  void EPSGTestBase ::
    assertFromPortHistory_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->fromPortHistorySize)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Total size of all from port histories\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->fromPortHistorySize << "\n";
  }

  // ----------------------------------------------------------------------
  // From port: DataOut
  // ----------------------------------------------------------------------

  void EPSGTestBase ::
    assert_from_DataOut_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->fromPortHistory_DataOut->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for from_DataOut\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->fromPortHistory_DataOut->size() << "\n";
  }

} // end namespace App
