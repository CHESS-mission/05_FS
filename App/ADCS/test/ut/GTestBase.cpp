// ======================================================================
// \title  ADCS/test/ut/GTestBase.cpp
// \author Auto-generated
// \brief  cpp file for ADCS component Google Test harness base class
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

  ADCSGTestBase ::
    ADCSGTestBase(
#if FW_OBJECT_NAMES == 1
        const char *const compName,
        const U32 maxHistorySize
#else
        const U32 maxHistorySize
#endif
    ) :
        ADCSTesterBase (
#if FW_OBJECT_NAMES == 1
            compName,
#endif
            maxHistorySize
        )
  {

  }

  ADCSGTestBase ::
    ~ADCSGTestBase(void)
  {

  }

  // ----------------------------------------------------------------------
  // Commands
  // ----------------------------------------------------------------------

  void ADCSGTestBase ::
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

  void ADCSGTestBase ::
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

  void ADCSGTestBase ::
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
  // Channel: ADCS_PARAM
  // ----------------------------------------------------------------------

  void ADCSGTestBase ::
    assertTlm_ADCS_PARAM_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_ADCS_PARAM->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel ADCS_PARAM\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_ADCS_PARAM->size() << "\n";
  }

  void ADCSGTestBase ::
    assertTlm_ADCS_PARAM(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U8& val
    )
    const
  {
    ASSERT_LT(__index, this->tlmHistory_ADCS_PARAM->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel ADCS_PARAM\n"
      << "  Expected: Less than size of history ("
      << this->tlmHistory_ADCS_PARAM->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const TlmEntry_ADCS_PARAM& e =
      this->tlmHistory_ADCS_PARAM->at(__index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << __index
      << " on telmetry channel ADCS_PARAM\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Events
  // ----------------------------------------------------------------------

  void ADCSGTestBase ::
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
  // Event: MS_TM_SEND_ADCS
  // ----------------------------------------------------------------------

  void ADCSGTestBase ::
    assertEvents_MS_TM_SEND_ADCS_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_MS_TM_SEND_ADCS->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event MS_TM_SEND_ADCS\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_MS_TM_SEND_ADCS->size() << "\n";
  }

  void ADCSGTestBase ::
    assertEvents_MS_TM_SEND_ADCS(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U8 id
    ) const
  {
    ASSERT_GT(this->eventHistory_MS_TM_SEND_ADCS->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event MS_TM_SEND_ADCS\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_MS_TM_SEND_ADCS->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_MS_TM_SEND_ADCS& e =
      this->eventHistory_MS_TM_SEND_ADCS->at(__index);
    ASSERT_EQ(id, e.id)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument id at index "
      << __index
      << " in history of event MS_TM_SEND_ADCS\n"
      << "  Expected: " << id << "\n"
      << "  Actual:   " << e.id << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: MS_TM_RECV_ADCS
  // ----------------------------------------------------------------------

  void ADCSGTestBase ::
    assertEvents_MS_TM_RECV_ADCS_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_MS_TM_RECV_ADCS->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event MS_TM_RECV_ADCS\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_MS_TM_RECV_ADCS->size() << "\n";
  }

  void ADCSGTestBase ::
    assertEvents_MS_TM_RECV_ADCS(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U8 id,
        const I8 tm
    ) const
  {
    ASSERT_GT(this->eventHistory_MS_TM_RECV_ADCS->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event MS_TM_RECV_ADCS\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_MS_TM_RECV_ADCS->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_MS_TM_RECV_ADCS& e =
      this->eventHistory_MS_TM_RECV_ADCS->at(__index);
    ASSERT_EQ(id, e.id)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument id at index "
      << __index
      << " in history of event MS_TM_RECV_ADCS\n"
      << "  Expected: " << id << "\n"
      << "  Actual:   " << e.id << "\n";
    ASSERT_EQ(tm, e.tm)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument tm at index "
      << __index
      << " in history of event MS_TM_RECV_ADCS\n"
      << "  Expected: " << tm << "\n"
      << "  Actual:   " << e.tm << "\n";
  }

  // ----------------------------------------------------------------------
  // From ports
  // ----------------------------------------------------------------------

  void ADCSGTestBase ::
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

  void ADCSGTestBase ::
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
