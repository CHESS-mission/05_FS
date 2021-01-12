// ======================================================================
// \title  EPS/test/ut/GTestBase.hpp
// \author Auto-generated
// \brief  hpp file for EPS component Google Test harness base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef EPS_GTEST_BASE_HPP
#define EPS_GTEST_BASE_HPP

#include "TesterBase.hpp"
#include "gtest/gtest.h"

// ----------------------------------------------------------------------
// Macros for command history assertions
// ----------------------------------------------------------------------

#define ASSERT_CMD_RESPONSE_SIZE(size) \
  this->assertCmdResponse_size(__FILE__, __LINE__, size)

#define ASSERT_CMD_RESPONSE(index, opCode, cmdSeq, response) \
  this->assertCmdResponse(__FILE__, __LINE__, index, opCode, cmdSeq, response)

// ----------------------------------------------------------------------
// Macros for telemetry history assertions
// ----------------------------------------------------------------------

#define ASSERT_TLM_SIZE(size) \
  this->assertTlm_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_EPS_Voltage_battery_mV_SIZE(size) \
  this->assertTlm_EPS_Voltage_battery_mV_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_EPS_Voltage_battery_mV(index, value) \
  this->assertTlm_EPS_Voltage_battery_mV(__FILE__, __LINE__, index, value)

#define ASSERT_TLM_EPS_Battery_mode_SIZE(size) \
  this->assertTlm_EPS_Battery_mode_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_EPS_Battery_mode(index, value) \
  this->assertTlm_EPS_Battery_mode(__FILE__, __LINE__, index, value)

#define ASSERT_TLM_EPS_Temp_Battery_Celsuis_SIZE(size) \
  this->assertTlm_EPS_Temp_Battery_Celsuis_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_EPS_Temp_Battery_Celsuis(index, value) \
  this->assertTlm_EPS_Temp_Battery_Celsuis(__FILE__, __LINE__, index, value)

#define ASSERT_TLM_EPS_LAST_CMD_RETURN_SIZE(size) \
  this->assertTlm_EPS_LAST_CMD_RETURN_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_EPS_LAST_CMD_RETURN(index, value) \
  this->assertTlm_EPS_LAST_CMD_RETURN(__FILE__, __LINE__, index, value)

// ----------------------------------------------------------------------
// Macros for event history assertions
// ----------------------------------------------------------------------

#define ASSERT_EVENTS_SIZE(size) \
  this->assertEvents_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_MS_CMD_SEND_EPS_SIZE(size) \
  this->assertEvents_MS_CMD_SEND_EPS_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_MS_CMD_SEND_EPS(index, _port, _cmd, _payload) \
  this->assertEvents_MS_CMD_SEND_EPS(__FILE__, __LINE__, index, _port, _cmd, _payload)

#define ASSERT_EVENTS_MS_CMD_RECV_EPS_SIZE(size) \
  this->assertEvents_MS_CMD_RECV_EPS_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_MS_CMD_RECV_EPS(index, _port, _cmd, _payload) \
  this->assertEvents_MS_CMD_RECV_EPS(__FILE__, __LINE__, index, _port, _cmd, _payload)

#define ASSERT_EVENTS_MS_CMD_ERROR_SIZE(size) \
  this->assertEvents_MS_CMD_ERROR_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_MS_CMD_ERROR(index, _port, _cmd, _status) \
  this->assertEvents_MS_CMD_ERROR(__FILE__, __LINE__, index, _port, _cmd, _status)

#define ASSERT_EVENTS_MS_BATT_VOLT_LOW_SIZE(size) \
  this->assertEvents_MS_BATT_VOLT_LOW_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_MS_BATT_VOLT_LOW(index, _volt) \
  this->assertEvents_MS_BATT_VOLT_LOW(__FILE__, __LINE__, index, _volt)

#define ASSERT_EVENTS_MS_BATT_TEMP_HIGH_SIZE(size) \
  this->assertEvents_MS_BATT_TEMP_HIGH_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_MS_BATT_TEMP_HIGH(index, _temp) \
  this->assertEvents_MS_BATT_TEMP_HIGH(__FILE__, __LINE__, index, _temp)

#define ASSERT_EVENTS_MS_CHNG_BATT_MOD_SIZE(size) \
  this->assertEvents_MS_CHNG_BATT_MOD_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_MS_CHNG_BATT_MOD(index, _mode) \
  this->assertEvents_MS_CHNG_BATT_MOD(__FILE__, __LINE__, index, _mode)

#define ASSERT_EVENTS_MS_CMD_PAYLOAD_ERROR_SIZE(size) \
  this->assertEvents_MS_CMD_PAYLOAD_ERROR_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_MS_CMD_PAYLOAD_ERROR(index, _payload) \
  this->assertEvents_MS_CMD_PAYLOAD_ERROR(__FILE__, __LINE__, index, _payload)

#define ASSERT_EVENTS_MS_CMD_PORT_ERROR_SIZE(size) \
  this->assertEvents_MS_CMD_PORT_ERROR_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_MS_CMD_PORT_ERROR(index, _port) \
  this->assertEvents_MS_CMD_PORT_ERROR(__FILE__, __LINE__, index, _port)

#define ASSERT_EVENTS_MS_PING_SIZE(size) \
  this->assertEvents_MS_PING_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_MS_PING(index, _port) \
  this->assertEvents_MS_PING(__FILE__, __LINE__, index, _port)

// ----------------------------------------------------------------------
// Macros for typed user from port history assertions
// ----------------------------------------------------------------------

#define ASSERT_FROM_PORT_HISTORY_SIZE(size) \
  this->assertFromPortHistory_size(__FILE__, __LINE__, size)

#define ASSERT_from_DataOut_SIZE(size) \
  this->assert_from_DataOut_size(__FILE__, __LINE__, size)

#define ASSERT_from_DataOut(index, _port, _data, _isSched) \
  { \
    ASSERT_GT(this->fromPortHistory_DataOut->size(), static_cast<U32>(index)) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Index into history of from_DataOut\n" \
    << "  Expected: Less than size of history (" \
    << this->fromPortHistory_DataOut->size() << ")\n" \
    << "  Actual:   " << index << "\n"; \
    const FromPortEntry_DataOut& _e = \
      this->fromPortHistory_DataOut->at(index); \
    ASSERT_EQ(_port, _e.port) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument port at index " \
    << index \
    << " in history of from_DataOut\n" \
    << "  Expected: " << _port << "\n" \
    << "  Actual:   " << _e.port << "\n"; \
    ASSERT_EQ(_data, _e.data) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument data at index " \
    << index \
    << " in history of from_DataOut\n" \
    << "  Expected: " << _data << "\n" \
    << "  Actual:   " << _e.data << "\n"; \
    ASSERT_EQ(_isSched, _e.isSched) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument isSched at index " \
    << index \
    << " in history of from_DataOut\n" \
    << "  Expected: " << _isSched << "\n" \
    << "  Actual:   " << _e.isSched << "\n"; \
  }

namespace App {

  //! \class EPSGTestBase
  //! \brief Auto-generated base class for EPS component Google Test harness
  //!
  class EPSGTestBase :
    public EPSTesterBase
  {

    protected:

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

      //! Construct object EPSGTestBase
      //!
      EPSGTestBase(
#if FW_OBJECT_NAMES == 1
          const char *const compName, /*!< The component name*/
          const U32 maxHistorySize /*!< The maximum size of each history*/
#else
          const U32 maxHistorySize /*!< The maximum size of each history*/
#endif
      );

      //! Destroy object EPSGTestBase
      //!
      virtual ~EPSGTestBase(void);

    protected:

      // ----------------------------------------------------------------------
      // Commands
      // ----------------------------------------------------------------------

      //! Assert size of command response history
      //!
      void assertCmdResponse_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      //! Assert command response in history at index
      //!
      void assertCmdResponse(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          const Fw::CommandResponse response /*!< The command response*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Telemetry
      // ----------------------------------------------------------------------

      //! Assert size of telemetry history
      //!
      void assertTlm_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Channel: EPS_Voltage_battery_mV
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_EPS_Voltage_battery_mV_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_EPS_Voltage_battery_mV(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const U16& val /*!< The channel value*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Channel: EPS_Battery_mode
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_EPS_Battery_mode_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_EPS_Battery_mode(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const U8& val /*!< The channel value*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Channel: EPS_Temp_Battery_Celsuis
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_EPS_Temp_Battery_Celsuis_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_EPS_Temp_Battery_Celsuis(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const U16& val /*!< The channel value*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Channel: EPS_LAST_CMD_RETURN
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_EPS_LAST_CMD_RETURN_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_EPS_LAST_CMD_RETURN(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const char *const val /*!< The channel value*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Events
      // ----------------------------------------------------------------------

      void assertEvents_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: MS_CMD_SEND_EPS
      // ----------------------------------------------------------------------

      void assertEvents_MS_CMD_SEND_EPS_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_MS_CMD_SEND_EPS(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const U8 port, /*!< The port id*/
          const U8 cmd, /*!< The cmd id*/
          const char *const payload /*!< The command data*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: MS_CMD_RECV_EPS
      // ----------------------------------------------------------------------

      void assertEvents_MS_CMD_RECV_EPS_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_MS_CMD_RECV_EPS(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const U8 port, /*!< The port id*/
          const U8 cmd, /*!< The command id*/
          const char *const payload /*!< The command return data*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: MS_CMD_ERROR
      // ----------------------------------------------------------------------

      void assertEvents_MS_CMD_ERROR_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_MS_CMD_ERROR(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const U8 port, /*!< The port id*/
          const U8 cmd, /*!< the cmd error*/
          const U8 status /*!< the status error*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: MS_BATT_VOLT_LOW
      // ----------------------------------------------------------------------

      void assertEvents_MS_BATT_VOLT_LOW_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_MS_BATT_VOLT_LOW(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const U16 volt /*!< Voltage*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: MS_BATT_TEMP_HIGH
      // ----------------------------------------------------------------------

      void assertEvents_MS_BATT_TEMP_HIGH_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_MS_BATT_TEMP_HIGH(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const U8 temp /*!< the id error*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: MS_CHNG_BATT_MOD
      // ----------------------------------------------------------------------

      void assertEvents_MS_CHNG_BATT_MOD_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_MS_CHNG_BATT_MOD(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const U8 mode /*!< battery mode*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: MS_CMD_PAYLOAD_ERROR
      // ----------------------------------------------------------------------

      void assertEvents_MS_CMD_PAYLOAD_ERROR_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_MS_CMD_PAYLOAD_ERROR(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const char *const payload /*!< the payload error*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: MS_CMD_PORT_ERROR
      // ----------------------------------------------------------------------

      void assertEvents_MS_CMD_PORT_ERROR_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_MS_CMD_PORT_ERROR(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const U8 port /*!< The port id*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: MS_PING
      // ----------------------------------------------------------------------

      void assertEvents_MS_PING_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_MS_PING(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const I32 port /*!< port response ms*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // From ports
      // ----------------------------------------------------------------------

      void assertFromPortHistory_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // From port: DataOut
      // ----------------------------------------------------------------------

      void assert_from_DataOut_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

  };

} // end namespace App

#endif
