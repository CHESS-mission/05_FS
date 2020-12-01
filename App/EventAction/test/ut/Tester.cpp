// ======================================================================
// \title  EventAction.hpp
// \author jonathan
// \brief  cpp file for EventAction test harness implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include "Tester.hpp"

#define INSTANCE 0
#define MAX_HISTORY_SIZE 10
#define QUEUE_DEPTH 10

namespace App {

// ----------------------------------------------------------------------
// Construction and destruction
// ----------------------------------------------------------------------

Tester ::Tester(void)
    :
#if FW_OBJECT_NAMES == 1
      EventActionGTestBase("Tester", MAX_HISTORY_SIZE),
      component("EventAction")
#else
      EventActionGTestBase(MAX_HISTORY_SIZE),
      component()
#endif
{
    this->initComponents();
    this->connectPorts();
}

Tester ::~Tester(void) {}

// ----------------------------------------------------------------------
// Tests
// ----------------------------------------------------------------------

void Tester ::testAdd(U32 id, Fw::CmdStringArg &seq) {
    // ===== Add event =====
    this->sendCmd_EVAC_ADD(0, 10, id, seq);
    this->component.doDispatch();

    // Check that there was no port invocation
    ASSERT_FROM_PORT_HISTORY_SIZE(0);

    // Check that there was only one event, check which one and its parameters
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_EVAC_ADDED_SIZE(1);
    ASSERT_EVENTS_EVAC_ADDED(0, seq.toChar(), id);

    // Check that there was one command response
    ASSERT_CMD_RESPONSE_SIZE(1);
    ASSERT_CMD_RESPONSE(0, EventActionComponentBase::OPCODE_EVAC_ADD, 10,
                        Fw::COMMAND_OK);

    // Clear command, telemetry, events and ports histories
    this->clearHistory();
}

void Tester ::testRemoveExisting(void) {
    Fw::CmdStringArg seq("seq");
    U32 eventId = 0x80;

    this->testAdd(eventId, seq);

    // ===== Remove event =====
    this->sendCmd_EVAC_REMOVE(0, 11, eventId);
    this->component.doDispatch();

    // Check that there was no port invocation
    ASSERT_FROM_PORT_HISTORY_SIZE(0);

    // Check that there was only one event, check which one and its parameters
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_EVAC_REMOVED_SIZE(1);
    ASSERT_EVENTS_EVAC_REMOVED(0, seq.toChar(), eventId);

    // Check that there was one command response
    ASSERT_CMD_RESPONSE_SIZE(1);
    ASSERT_CMD_RESPONSE(0, EventActionComponentBase::OPCODE_EVAC_REMOVE, 11,
                        Fw::COMMAND_OK);

    // Clear command, telemetry, events and ports histories
    this->clearHistory();
}

void Tester ::testRemoveEmpty(void) {
    U32 eventId = 0x80;

    // ===== Remove event =====
    this->sendCmd_EVAC_REMOVE(0, 2, eventId);
    this->component.doDispatch();

    // Check that there was no port invocation
    ASSERT_FROM_PORT_HISTORY_SIZE(0);

    // Check that there was only one event, check which one and its parameters
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_EVAC_NOT_FOUND_SIZE(1);
    ASSERT_EVENTS_EVAC_NOT_FOUND(0, eventId);

    // Check that there was one command response
    ASSERT_CMD_RESPONSE_SIZE(1);
    ASSERT_CMD_RESPONSE(0, EventActionComponentBase::OPCODE_EVAC_REMOVE, 2,
                        Fw::COMMAND_EXECUTION_ERROR);

    // Clear command, telemetry, events and ports histories
    this->clearHistory();
}

void Tester ::testRemoveUnexisting(void) {
    Fw::CmdStringArg seq("seq");
    U32 eventId = 0x80;
    U32 eventIdUnexisting = eventId + 1;

    // Add one event
    this->testAdd(eventId, seq);

    // ===== Remove wrong event =====
    this->sendCmd_EVAC_REMOVE(0, 2, eventIdUnexisting);
    this->component.doDispatch();

    // Check that there was no port invocation
    ASSERT_FROM_PORT_HISTORY_SIZE(0);

    // Check that there was only one event, check which one and its parameters
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_EVAC_NOT_FOUND_SIZE(1);
    ASSERT_EVENTS_EVAC_NOT_FOUND(0, eventIdUnexisting);

    // Check that there was one command response
    ASSERT_CMD_RESPONSE_SIZE(1);
    ASSERT_CMD_RESPONSE(0, EventActionComponentBase::OPCODE_EVAC_REMOVE, 2,
                        Fw::COMMAND_EXECUTION_ERROR);

    // Clear command, telemetry, events and ports histories
    this->clearHistory();
}

void Tester ::testDumpEmpty(void) {
    // ===== Dump command =====
    this->sendCmd_EVAC_DUMP(0, 10);
    this->component.doDispatch();

    // Check that there was no port invocation
    ASSERT_FROM_PORT_HISTORY_SIZE(0);

    // Check that there was no event
    ASSERT_EVENTS_SIZE(0);

    // Check that there was one command response
    ASSERT_CMD_RESPONSE_SIZE(1);
    ASSERT_CMD_RESPONSE(0, EventActionComponentBase::OPCODE_EVAC_DUMP, 10,
                        Fw::COMMAND_OK);

    // Clear command, telemetry, events and ports histories
    this->clearHistory();
}

void Tester ::testDump(void) {
    U32 event1 = 0x80;
    U32 event2 = 0x81;
    Fw::CmdStringArg seq1("seq1");
    Fw::CmdStringArg seq2("seq2");

    // Add one event
    this->testAdd(event1, seq1);
    this->testAdd(event2, seq2);

    // ===== Dump command =====
    this->sendCmd_EVAC_DUMP(0, 10);
    this->component.doDispatch();

    // Check that there was no port invocation
    ASSERT_FROM_PORT_HISTORY_SIZE(0);

    // Check that there was no event
    ASSERT_EVENTS_SIZE(2);
    ASSERT_EVENTS_EVAC_DUMP_SIZE(2);
    ASSERT_EVENTS_EVAC_DUMP(0, seq1.toChar(), event1);
    ASSERT_EVENTS_EVAC_DUMP(1, seq2.toChar(), event2);

    // Check that there was one command response
    ASSERT_CMD_RESPONSE_SIZE(1);
    ASSERT_CMD_RESPONSE(0, EventActionComponentBase::OPCODE_EVAC_DUMP, 10,
                        Fw::COMMAND_OK);

    // Clear command, telemetry, events and ports histories
    this->clearHistory();
}

void Tester::testAddFull(U32 maxSize) {
    Fw::CmdStringArg seq("seq");
    U32 baseId = 0x80;

    for (U32 id = 0; id < maxSize; id++) {
        this->testAdd(baseId + id, seq);
    }

    // ===== Add event but list is full =====
    this->sendCmd_EVAC_ADD(0, 10, baseId + maxSize, seq);
    this->component.doDispatch();

    // Check that there was no port invocation
    ASSERT_FROM_PORT_HISTORY_SIZE(0);

    // Check that there was only one event, check which one and its parameters
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_EVAC_LIST_FULL_SIZE(1);
    ASSERT_EVENTS_EVAC_LIST_FULL(0, baseId + maxSize);

    // Check that there was one command response
    ASSERT_CMD_RESPONSE_SIZE(1);
    ASSERT_CMD_RESPONSE(0, EventActionComponentBase::OPCODE_EVAC_ADD, 10,
                        Fw::COMMAND_EXECUTION_ERROR);

    // Clear command, telemetry, events and ports histories
    this->clearHistory();
}

void Tester::testAddSame(void) {
    Fw::CmdStringArg seq1("seq1");
    Fw::CmdStringArg seq2("seq2");
    U32 eventId = 0x80;

    this->testAdd(eventId, seq1);

    // ===== Add same event =====
    this->sendCmd_EVAC_ADD(0, 10, eventId, seq2);
    this->component.doDispatch();

    // Check that there was no port invocation
    ASSERT_FROM_PORT_HISTORY_SIZE(0);

    // Check that there was only one event, check which one and its parameters
    ASSERT_EVENTS_SIZE(1);
    ASSERT_EVENTS_EVAC_ALREADY_REGISTERED_SIZE(1);
    ASSERT_EVENTS_EVAC_ALREADY_REGISTERED(0, eventId, seq1.toChar());

    // Check that there was one command response
    ASSERT_CMD_RESPONSE_SIZE(1);
    ASSERT_CMD_RESPONSE(0, EventActionComponentBase::OPCODE_EVAC_ADD, 10,
                        Fw::COMMAND_EXECUTION_ERROR);

    // Clear command, telemetry, events and ports histories
    this->clearHistory();
}

void Tester::testEntryCorrespondingEvent(void) {
    Fw::CmdStringArg seq("seq.bin");
    U32 eventId = 0x80;

    // Register event for a specific sequence
    this->testAdd(eventId, seq);

    Fw::Time time;
    Fw::LogBuffer logBuffer;
    this->invoke_to_logRecv(0, eventId, time, Fw::LogSeverity::LOG_ACTIVITY_HI, logBuffer);
    this->component.doDispatch();

    // Check that there was one and only one port invocation
    ASSERT_FROM_PORT_HISTORY_SIZE(1);
    ASSERT_from_seqRun_SIZE(1);
    Fw::EightyCharString seqEC(seq.toChar());
    ASSERT_from_seqRun(0, seqEC);

    this->clearHistory();
}

void Tester::testEntryNonCorrespondingEvent(void) {
    Fw::CmdStringArg seq("seq.bin");
    U32 eventId = 0x80;

    // Register event for a specific sequence
    this->testAdd(eventId, seq);

    Fw::Time time;
    Fw::LogBuffer logBuffer;
    this->invoke_to_logRecv(0, eventId + 1, time, Fw::LogSeverity::LOG_ACTIVITY_HI, logBuffer);
    this->component.doDispatch();

    // Check that there was no port invocation
    ASSERT_FROM_PORT_HISTORY_SIZE(0);

    this->clearHistory();
}

// ----------------------------------------------------------------------
// Handlers for typed from ports
// ----------------------------------------------------------------------

void Tester ::from_seqRun_handler(const NATIVE_INT_TYPE portNum,
                                  Fw::EightyCharString &filename) {
    this->pushFromPortEntry_seqRun(filename);
}

// ----------------------------------------------------------------------
// Helper methods
// ----------------------------------------------------------------------

void Tester ::connectPorts(void) {
    // cmdDisp
    this->connect_to_cmdDisp(0, this->component.get_cmdDisp_InputPort(0));

    // seqResp
    this->connect_to_seqResp(0, this->component.get_seqResp_InputPort(0));

    // logRecv
    this->connect_to_logRecv(0, this->component.get_logRecv_InputPort(0));

    // cmdRegOut
    this->component.set_cmdRegOut_OutputPort(0, this->get_from_cmdRegOut(0));

    // cmdResponseOut
    this->component.set_cmdResponseOut_OutputPort(
        0, this->get_from_cmdResponseOut(0));

    // eventOut
    this->component.set_eventOut_OutputPort(0, this->get_from_eventOut(0));

    // txtEventOut
    this->component.set_txtEventOut_OutputPort(0,
                                               this->get_from_txtEventOut(0));

    // seqRun
    this->component.set_seqRun_OutputPort(0, this->get_from_seqRun(0));

    // Time
    this->component.set_Time_OutputPort(0, this->get_from_Time(0));
}

void Tester ::initComponents(void) {
    this->init();
    this->component.init(QUEUE_DEPTH, INSTANCE);
}

}  // end namespace App
