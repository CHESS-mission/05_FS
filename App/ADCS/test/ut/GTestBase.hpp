// ======================================================================
// \title  ADCS/test/ut/GTestBase.hpp
// \author Auto-generated
// \brief  hpp file for ADCS component Google Test harness base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef ADCS_GTEST_BASE_HPP
#define ADCS_GTEST_BASE_HPP

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

#define ASSERT_TLM_ADCS_PARAM_SIZE(size) \
  this->assertTlm_ADCS_PARAM_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_ADCS_PARAM(index, value) \
  this->assertTlm_ADCS_PARAM(__FILE__, __LINE__, index, value)

// ----------------------------------------------------------------------
// Macros for event history assertions
// ----------------------------------------------------------------------

#define ASSERT_EVENTS_SIZE(size) \
  this->assertEvents_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_MS_TM_SEND_ADCS_SIZE(size) \
  this->assertEvents_MS_TM_SEND_ADCS_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_MS_TM_SEND_ADCS(index, _id) \
  this->assertEvents_MS_TM_SEND_ADCS(__FILE__, __LINE__, index, _id)

#define ASSERT_EVENTS_MS_TM_RECV_ADCS_SIZE(size) \
  this->assertEvents_MS_TM_RECV_ADCS_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_MS_TM_RECV_ADCS(index, _id, _tm) \
  this->assertEvents_MS_TM_RECV_ADCS(__FILE__, __LINE__, index, _id, _tm)

// ----------------------------------------------------------------------
// Macros for typed user from port history assertions
// ----------------------------------------------------------------------

#define ASSERT_FROM_PORT_HISTORY_SIZE(size) \
  this->assertFromPortHistory_size(__FILE__, __LINE__, size)

#define ASSERT_from_DataOut_SIZE(size) \
  this->assert_from_DataOut_size(__FILE__, __LINE__, size)

#define ASSERT_from_DataOut(index, _fwBuffer) \
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
    ASSERT_EQ(_fwBuffer, _e.fwBuffer) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument fwBuffer at index " \
    << index \
    << " in history of from_DataOut\n" \
    << "  Expected: " << _fwBuffer << "\n" \
    << "  Actual:   " << _e.fwBuffer << "\n"; \
  }

namespace App {

  //! \class ADCSGTestBase
  //! \brief Auto-generated base class for ADCS component Google Test harness
  //!
  class ADCSGTestBase :
    public ADCSTesterBase
  {

    protected:

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

      //! Construct object ADCSGTestBase
      //!
      ADCSGTestBase(
#if FW_OBJECT_NAMES == 1
          const char *const compName, /*!< The component name*/
          const U32 maxHistorySize /*!< The maximum size of each history*/
#else
          const U32 maxHistorySize /*!< The maximum size of each history*/
#endif
      );

      //! Destroy object ADCSGTestBase
      //!
      virtual ~ADCSGTestBase(void);

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
      // Channel: ADCS_PARAM
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_ADCS_PARAM_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_ADCS_PARAM(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const U8& val /*!< The channel value*/
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
      // Event: MS_TM_SEND_ADCS
      // ----------------------------------------------------------------------

      void assertEvents_MS_TM_SEND_ADCS_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_MS_TM_SEND_ADCS(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const U8 id /*!< The telemetry id*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: MS_TM_RECV_ADCS
      // ----------------------------------------------------------------------

      void assertEvents_MS_TM_RECV_ADCS_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_MS_TM_RECV_ADCS(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const U8 id, /*!< The telemetry id*/
          const I8 tm /*!< The telemetry data*/
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
