// ======================================================================
// \title  EventAction/test/ut/GTestBase.hpp
// \author Auto-generated
// \brief  hpp file for EventAction component Google Test harness base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef EventAction_GTEST_BASE_HPP
#define EventAction_GTEST_BASE_HPP

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
// Macros for event history assertions
// ----------------------------------------------------------------------

#define ASSERT_EVENTS_SIZE(size) \
  this->assertEvents_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_EVAC_ADDED_SIZE(size) \
  this->assertEvents_EVAC_ADDED_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_EVAC_ADDED(index, _sequence, _eventId) \
  this->assertEvents_EVAC_ADDED(__FILE__, __LINE__, index, _sequence, _eventId)

#define ASSERT_EVENTS_EVAC_REMOVED_SIZE(size) \
  this->assertEvents_EVAC_REMOVED_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_EVAC_REMOVED(index, _sequence, _eventId) \
  this->assertEvents_EVAC_REMOVED(__FILE__, __LINE__, index, _sequence, _eventId)

#define ASSERT_EVENTS_EVAC_LIST_FULL_SIZE(size) \
  this->assertEvents_EVAC_LIST_FULL_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_EVAC_LIST_FULL(index, _eventId) \
  this->assertEvents_EVAC_LIST_FULL(__FILE__, __LINE__, index, _eventId)

#define ASSERT_EVENTS_EVAC_NOT_FOUND_SIZE(size) \
  this->assertEvents_EVAC_NOT_FOUND_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_EVAC_NOT_FOUND(index, _eventId) \
  this->assertEvents_EVAC_NOT_FOUND(__FILE__, __LINE__, index, _eventId)

#define ASSERT_EVENTS_EVAC_ALREADY_REGISTERED_SIZE(size) \
  this->assertEvents_EVAC_ALREADY_REGISTERED_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_EVAC_ALREADY_REGISTERED(index, _eventId, _sequence) \
  this->assertEvents_EVAC_ALREADY_REGISTERED(__FILE__, __LINE__, index, _eventId, _sequence)

#define ASSERT_EVENTS_EVAC_DUMP_SIZE(size) \
  this->assertEvents_EVAC_DUMP_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_EVAC_DUMP(index, _sequence, _eventId) \
  this->assertEvents_EVAC_DUMP(__FILE__, __LINE__, index, _sequence, _eventId)

#define ASSERT_EVENTS_EVAC_RUN_SIZE(size) \
  this->assertEvents_EVAC_RUN_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_EVAC_RUN(index, _eventId, _sequence) \
  this->assertEvents_EVAC_RUN(__FILE__, __LINE__, index, _eventId, _sequence)

// ----------------------------------------------------------------------
// Macros for typed user from port history assertions
// ----------------------------------------------------------------------

#define ASSERT_FROM_PORT_HISTORY_SIZE(size) \
  this->assertFromPortHistory_size(__FILE__, __LINE__, size)

#define ASSERT_from_seqRun_SIZE(size) \
  this->assert_from_seqRun_size(__FILE__, __LINE__, size)

#define ASSERT_from_seqRun(index, _filename) \
  { \
    ASSERT_GT(this->fromPortHistory_seqRun->size(), static_cast<U32>(index)) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Index into history of from_seqRun\n" \
    << "  Expected: Less than size of history (" \
    << this->fromPortHistory_seqRun->size() << ")\n" \
    << "  Actual:   " << index << "\n"; \
    const FromPortEntry_seqRun& _e = \
      this->fromPortHistory_seqRun->at(index); \
    ASSERT_EQ(_filename, _e.filename) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument filename at index " \
    << index \
    << " in history of from_seqRun\n" \
    << "  Expected: " << _filename << "\n" \
    << "  Actual:   " << _e.filename << "\n"; \
  }

namespace App {

  //! \class EventActionGTestBase
  //! \brief Auto-generated base class for EventAction component Google Test harness
  //!
  class EventActionGTestBase :
    public EventActionTesterBase
  {

    protected:

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

      //! Construct object EventActionGTestBase
      //!
      EventActionGTestBase(
#if FW_OBJECT_NAMES == 1
          const char *const compName, /*!< The component name*/
          const U32 maxHistorySize /*!< The maximum size of each history*/
#else
          const U32 maxHistorySize /*!< The maximum size of each history*/
#endif
      );

      //! Destroy object EventActionGTestBase
      //!
      virtual ~EventActionGTestBase(void);

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
      // Events
      // ----------------------------------------------------------------------

      void assertEvents_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: EVAC_ADDED
      // ----------------------------------------------------------------------

      void assertEvents_EVAC_ADDED_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_EVAC_ADDED(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const char *const sequence, 
          const U32 eventId 
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: EVAC_REMOVED
      // ----------------------------------------------------------------------

      void assertEvents_EVAC_REMOVED_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_EVAC_REMOVED(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const char *const sequence, 
          const U32 eventId 
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: EVAC_LIST_FULL
      // ----------------------------------------------------------------------

      void assertEvents_EVAC_LIST_FULL_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_EVAC_LIST_FULL(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const U32 eventId 
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: EVAC_NOT_FOUND
      // ----------------------------------------------------------------------

      void assertEvents_EVAC_NOT_FOUND_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_EVAC_NOT_FOUND(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const U32 eventId 
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: EVAC_ALREADY_REGISTERED
      // ----------------------------------------------------------------------

      void assertEvents_EVAC_ALREADY_REGISTERED_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_EVAC_ALREADY_REGISTERED(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const U32 eventId, 
          const char *const sequence 
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: EVAC_DUMP
      // ----------------------------------------------------------------------

      void assertEvents_EVAC_DUMP_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_EVAC_DUMP(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const char *const sequence, 
          const U32 eventId 
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: EVAC_RUN
      // ----------------------------------------------------------------------

      void assertEvents_EVAC_RUN_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_EVAC_RUN(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const U32 eventId, 
          const char *const sequence 
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
      // From port: seqRun
      // ----------------------------------------------------------------------

      void assert_from_seqRun_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

  };

} // end namespace App

#endif
