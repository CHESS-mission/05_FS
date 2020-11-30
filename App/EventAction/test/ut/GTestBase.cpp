// ======================================================================
// \title  EventAction/test/ut/GTestBase.cpp
// \author Auto-generated
// \brief  cpp file for EventAction component Google Test harness base class
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

  EventActionGTestBase ::
    EventActionGTestBase(
#if FW_OBJECT_NAMES == 1
        const char *const compName,
        const U32 maxHistorySize
#else
        const U32 maxHistorySize
#endif
    ) :
        EventActionTesterBase (
#if FW_OBJECT_NAMES == 1
            compName,
#endif
            maxHistorySize
        )
  {

  }

  EventActionGTestBase ::
    ~EventActionGTestBase(void)
  {

  }

  // ----------------------------------------------------------------------
  // Commands
  // ----------------------------------------------------------------------

  void EventActionGTestBase ::
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

  void EventActionGTestBase ::
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

  void EventActionGTestBase ::
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
  // Channel: EVAC_CHA
  // ----------------------------------------------------------------------

  void EventActionGTestBase ::
    assertTlm_EVAC_CHA_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_EVAC_CHA->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel EVAC_CHA\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_EVAC_CHA->size() << "\n";
  }

  void EventActionGTestBase ::
    assertTlm_EVAC_CHA(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U32& val
    )
    const
  {
    ASSERT_LT(__index, this->tlmHistory_EVAC_CHA->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel EVAC_CHA\n"
      << "  Expected: Less than size of history ("
      << this->tlmHistory_EVAC_CHA->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const TlmEntry_EVAC_CHA& e =
      this->tlmHistory_EVAC_CHA->at(__index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << __index
      << " on telmetry channel EVAC_CHA\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Events
  // ----------------------------------------------------------------------

  void EventActionGTestBase ::
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
  // Event: EVAC_ADDED
  // ----------------------------------------------------------------------

  void EventActionGTestBase ::
    assertEvents_EVAC_ADDED_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_EVAC_ADDED->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event EVAC_ADDED\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_EVAC_ADDED->size() << "\n";
  }

  void EventActionGTestBase ::
    assertEvents_EVAC_ADDED(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const char *const sequence,
        const U32 eventId
    ) const
  {
    ASSERT_GT(this->eventHistory_EVAC_ADDED->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event EVAC_ADDED\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_EVAC_ADDED->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_EVAC_ADDED& e =
      this->eventHistory_EVAC_ADDED->at(__index);
    ASSERT_STREQ(sequence, e.sequence.toChar())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument sequence at index "
      << __index
      << " in history of event EVAC_ADDED\n"
      << "  Expected: " << sequence << "\n"
      << "  Actual:   " << e.sequence.toChar() << "\n";
    ASSERT_EQ(eventId, e.eventId)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument eventId at index "
      << __index
      << " in history of event EVAC_ADDED\n"
      << "  Expected: " << eventId << "\n"
      << "  Actual:   " << e.eventId << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: EVAC_REMOVED
  // ----------------------------------------------------------------------

  void EventActionGTestBase ::
    assertEvents_EVAC_REMOVED_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_EVAC_REMOVED->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event EVAC_REMOVED\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_EVAC_REMOVED->size() << "\n";
  }

  void EventActionGTestBase ::
    assertEvents_EVAC_REMOVED(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const char *const sequence,
        const U32 eventId
    ) const
  {
    ASSERT_GT(this->eventHistory_EVAC_REMOVED->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event EVAC_REMOVED\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_EVAC_REMOVED->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_EVAC_REMOVED& e =
      this->eventHistory_EVAC_REMOVED->at(__index);
    ASSERT_STREQ(sequence, e.sequence.toChar())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument sequence at index "
      << __index
      << " in history of event EVAC_REMOVED\n"
      << "  Expected: " << sequence << "\n"
      << "  Actual:   " << e.sequence.toChar() << "\n";
    ASSERT_EQ(eventId, e.eventId)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument eventId at index "
      << __index
      << " in history of event EVAC_REMOVED\n"
      << "  Expected: " << eventId << "\n"
      << "  Actual:   " << e.eventId << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: EVAC_LIST_FULL
  // ----------------------------------------------------------------------

  void EventActionGTestBase ::
    assertEvents_EVAC_LIST_FULL_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_EVAC_LIST_FULL->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event EVAC_LIST_FULL\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_EVAC_LIST_FULL->size() << "\n";
  }

  void EventActionGTestBase ::
    assertEvents_EVAC_LIST_FULL(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U32 eventId
    ) const
  {
    ASSERT_GT(this->eventHistory_EVAC_LIST_FULL->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event EVAC_LIST_FULL\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_EVAC_LIST_FULL->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_EVAC_LIST_FULL& e =
      this->eventHistory_EVAC_LIST_FULL->at(__index);
    ASSERT_EQ(eventId, e.eventId)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument eventId at index "
      << __index
      << " in history of event EVAC_LIST_FULL\n"
      << "  Expected: " << eventId << "\n"
      << "  Actual:   " << e.eventId << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: EVAC_NOT_FOUND
  // ----------------------------------------------------------------------

  void EventActionGTestBase ::
    assertEvents_EVAC_NOT_FOUND_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_EVAC_NOT_FOUND->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event EVAC_NOT_FOUND\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_EVAC_NOT_FOUND->size() << "\n";
  }

  void EventActionGTestBase ::
    assertEvents_EVAC_NOT_FOUND(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U32 eventId
    ) const
  {
    ASSERT_GT(this->eventHistory_EVAC_NOT_FOUND->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event EVAC_NOT_FOUND\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_EVAC_NOT_FOUND->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_EVAC_NOT_FOUND& e =
      this->eventHistory_EVAC_NOT_FOUND->at(__index);
    ASSERT_EQ(eventId, e.eventId)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument eventId at index "
      << __index
      << " in history of event EVAC_NOT_FOUND\n"
      << "  Expected: " << eventId << "\n"
      << "  Actual:   " << e.eventId << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: EVAC_ALREADY_REGISTERED
  // ----------------------------------------------------------------------

  void EventActionGTestBase ::
    assertEvents_EVAC_ALREADY_REGISTERED_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_EVAC_ALREADY_REGISTERED->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event EVAC_ALREADY_REGISTERED\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_EVAC_ALREADY_REGISTERED->size() << "\n";
  }

  void EventActionGTestBase ::
    assertEvents_EVAC_ALREADY_REGISTERED(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U32 eventId,
        const char *const sequence
    ) const
  {
    ASSERT_GT(this->eventHistory_EVAC_ALREADY_REGISTERED->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event EVAC_ALREADY_REGISTERED\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_EVAC_ALREADY_REGISTERED->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_EVAC_ALREADY_REGISTERED& e =
      this->eventHistory_EVAC_ALREADY_REGISTERED->at(__index);
    ASSERT_EQ(eventId, e.eventId)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument eventId at index "
      << __index
      << " in history of event EVAC_ALREADY_REGISTERED\n"
      << "  Expected: " << eventId << "\n"
      << "  Actual:   " << e.eventId << "\n";
    ASSERT_STREQ(sequence, e.sequence.toChar())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument sequence at index "
      << __index
      << " in history of event EVAC_ALREADY_REGISTERED\n"
      << "  Expected: " << sequence << "\n"
      << "  Actual:   " << e.sequence.toChar() << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: EVAC_DUMP
  // ----------------------------------------------------------------------

  void EventActionGTestBase ::
    assertEvents_EVAC_DUMP_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_EVAC_DUMP->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event EVAC_DUMP\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_EVAC_DUMP->size() << "\n";
  }

  void EventActionGTestBase ::
    assertEvents_EVAC_DUMP(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const char *const sequence,
        const U32 eventId
    ) const
  {
    ASSERT_GT(this->eventHistory_EVAC_DUMP->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event EVAC_DUMP\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_EVAC_DUMP->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_EVAC_DUMP& e =
      this->eventHistory_EVAC_DUMP->at(__index);
    ASSERT_STREQ(sequence, e.sequence.toChar())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument sequence at index "
      << __index
      << " in history of event EVAC_DUMP\n"
      << "  Expected: " << sequence << "\n"
      << "  Actual:   " << e.sequence.toChar() << "\n";
    ASSERT_EQ(eventId, e.eventId)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument eventId at index "
      << __index
      << " in history of event EVAC_DUMP\n"
      << "  Expected: " << eventId << "\n"
      << "  Actual:   " << e.eventId << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: EVAC_RUN
  // ----------------------------------------------------------------------

  void EventActionGTestBase ::
    assertEvents_EVAC_RUN_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_EVAC_RUN->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event EVAC_RUN\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_EVAC_RUN->size() << "\n";
  }

  void EventActionGTestBase ::
    assertEvents_EVAC_RUN(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U32 eventId,
        const char *const message
    ) const
  {
    ASSERT_GT(this->eventHistory_EVAC_RUN->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event EVAC_RUN\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_EVAC_RUN->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_EVAC_RUN& e =
      this->eventHistory_EVAC_RUN->at(__index);
    ASSERT_EQ(eventId, e.eventId)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument eventId at index "
      << __index
      << " in history of event EVAC_RUN\n"
      << "  Expected: " << eventId << "\n"
      << "  Actual:   " << e.eventId << "\n";
    ASSERT_STREQ(message, e.message.toChar())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument message at index "
      << __index
      << " in history of event EVAC_RUN\n"
      << "  Expected: " << message << "\n"
      << "  Actual:   " << e.message.toChar() << "\n";
  }

  // ----------------------------------------------------------------------
  // From ports
  // ----------------------------------------------------------------------

  void EventActionGTestBase ::
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
  // From port: seqRun
  // ----------------------------------------------------------------------

  void EventActionGTestBase ::
    assert_from_seqRun_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->fromPortHistory_seqRun->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for from_seqRun\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->fromPortHistory_seqRun->size() << "\n";
  }

} // end namespace App
