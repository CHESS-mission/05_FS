// ======================================================================
// \title  EventActionComponentImpl.cpp
// \author jonathan
// \brief  cpp file for EventAction component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include <App/EventAction/EventActionComponentImpl.hpp>

#include "Fw/Log/LogString.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/EightyCharString.hpp"

namespace App {

// ----------------------------------------------------------------------
// Construction, initialization, and destruction
// ----------------------------------------------------------------------

EventActionComponentImpl ::EventActionComponentImpl(const char *const compName)
    : EventActionComponentBase(compName) {}

void EventActionComponentImpl ::init(const NATIVE_INT_TYPE queueDepth,
                                     const NATIVE_INT_TYPE instance) {
    EventActionComponentBase::init(queueDepth, instance);

    memset(this->m_eventActionTable, 0, sizeof(this->m_eventActionTable));
}

EventActionComponentImpl ::~EventActionComponentImpl(void) {}

// ----------------------------------------------------------------------
// Handler implementations for user-defined typed input ports
// ----------------------------------------------------------------------

void EventActionComponentImpl ::seqResp_handler(const NATIVE_INT_TYPE portNum,
                                                FwOpcodeType opCode, U32 cmdSeq,
                                                Fw::CommandResponse response) {
    // Fw::LogStringArg message("Response handler");
    // this->log_ACTIVITY_HI_EVA_EVENT(message);
}

void EventActionComponentImpl ::logRecv_handler(const NATIVE_INT_TYPE portNum,
                                                FwEventIdType id,
                                                Fw::Time &timeTag,
                                                Fw::LogSeverity severity,
                                                Fw::LogBuffer &args) {
    for (U32 slot = 0; slot < FW_NUM_ARRAY_ELEMENTS(this->m_eventActionTable);
         slot++) {
        if ((this->m_eventActionTable[slot].used) and
            (this->m_eventActionTable[slot].id == id)) {
            printf("NO_OP received\n");

            Fw::EightyCharString file("seq.bin");

            this->seqRun_out(
                0, file);  // this->m_eventActionTable[slot].sequence);
        }
    }
}

// ----------------------------------------------------------------------
// Command handler implementations
// ----------------------------------------------------------------------

void EventActionComponentImpl ::EVAC_ADD_cmdHandler(
    const FwOpcodeType opCode, const U32 cmdSeq, U32 id,
    const Fw::CmdStringArg &sequence) {
    bool slotFound = false;

    // @todo Check that event don't have another action registered
    for (U32 slot = 0; slot < FW_NUM_ARRAY_ELEMENTS(this->m_eventActionTable);
         slot++) {
        if ((not this->m_eventActionTable[slot].used) and (not slotFound)) {
            this->m_eventActionTable[slot].id = id;
            Fw::EightyCharString seq(sequence.toChar());
            this->m_eventActionTable[slot].sequence = &seq;
            this->m_eventActionTable[slot].used = true;

            slotFound = true;
        }
    }

    // @todo Display event id in 0x00
    Fw::LogStringArg seq("seq");

    if (not slotFound) {
        this->log_WARNING_LO_EVAC_LIST_FULL(id);
        this->cmdResponse_out(opCode, cmdSeq, Fw::COMMAND_EXECUTION_ERROR);
        return;
    }

    this->log_ACTIVITY_HI_EVAC_ADDED(seq, id);
    this->cmdResponse_out(opCode, cmdSeq, Fw::COMMAND_OK);
}

void EventActionComponentImpl ::EVAC_REMOVE_cmdHandler(
    const FwOpcodeType opCode, const U32 cmdSeq, U32 id) {
    bool slotFound = false;

    for (U32 slot = 0; slot < FW_NUM_ARRAY_ELEMENTS(this->m_eventActionTable);
         slot++) {
        if ((this->m_eventActionTable[slot].used) and
            (this->m_eventActionTable[slot].id == id)) {
            this->m_eventActionTable[slot].id = 0;
            this->m_eventActionTable[slot].used = false;

            slotFound = true;
        }
    }

    Fw::LogStringArg seq("seq");
    if (slotFound) {
        this->log_ACTIVITY_HI_EVAC_REMOVED(seq, id);
    } else {
        // this->log_WARNING_LO_ALOG_ID_FILTER_NOT_FOUND
    }

    this->cmdResponse_out(opCode, cmdSeq, Fw::COMMAND_OK);
}

void EventActionComponentImpl ::EVAC_DUMP_cmdHandler(const FwOpcodeType opCode,
                                                     const U32 cmdSeq) {
    for (U32 slot = 0; slot < FW_NUM_ARRAY_ELEMENTS(this->m_eventActionTable);
         slot++) {
        if (this->m_eventActionTable[slot].used) {
            Fw::LogStringArg seq("seq");
            this->log_ACTIVITY_HI_EVA_DUMP(seq, this->m_eventActionTable[slot].id);
        }
    }
    this->cmdResponse_out(opCode, cmdSeq, Fw::COMMAND_OK);
}

}  // end namespace App
