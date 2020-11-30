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

    for (U32 slot = 0; slot < FW_NUM_ARRAY_ELEMENTS(this->m_eventActionTable);
         slot++) {
        this->m_eventActionTable[slot].id = 0;
        this->m_eventActionTable[slot].used = false;
        this->m_eventActionTable[slot].sequence = nullptr;
    }
}

EventActionComponentImpl ::~EventActionComponentImpl(void) {
    for (U32 slot = 0; slot < FW_NUM_ARRAY_ELEMENTS(this->m_eventActionTable);
         slot++) {
        if (this->m_eventActionTable[slot].sequence != nullptr) {
            delete this->m_eventActionTable[slot].sequence;
        }
    }
}

// ----------------------------------------------------------------------
// Handler implementations for user-defined typed input ports
// ----------------------------------------------------------------------

void EventActionComponentImpl ::seqResp_handler(const NATIVE_INT_TYPE portNum,
                                                FwOpcodeType opCode, U32 cmdSeq,
                                                Fw::CommandResponse response) {
    // @todo read response and send event
}

void EventActionComponentImpl ::logRecv_handler(const NATIVE_INT_TYPE portNum,
                                                FwEventIdType id,
                                                Fw::Time &timeTag,
                                                Fw::LogSeverity severity,
                                                Fw::LogBuffer &args) {
    // @todo Avoid event-sequence loop by detecting if an event triggers a
    // sequence that could emit the same event !
    for (U32 slot = 0; slot < FW_NUM_ARRAY_ELEMENTS(this->m_eventActionTable);
         slot++) {
        if ((this->m_eventActionTable[slot].used) and
            (this->m_eventActionTable[slot].id == id)) {
            Fw::LogStringArg log(
                this->m_eventActionTable[slot].sequence->toChar());
            this->log_ACTIVITY_HI_EVAC_RUN(id, log);
            Fw::EightyCharString file(
                this->m_eventActionTable[slot].sequence->toChar());
            this->seqRun_out(0, file);
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

    // make sure ID is not zero. Zero is reserved for ID filter.
    FW_ASSERT(id != 0);

    // check that event is not already registered
    for (U32 slot = 0; slot < FW_NUM_ARRAY_ELEMENTS(this->m_eventActionTable);
         slot++) {
        if ((this->m_eventActionTable[slot].id == id) and
            (this->m_eventActionTable[slot].used == true)) {
            Fw::LogStringArg seq(
                this->m_eventActionTable[slot].sequence->toChar());
            this->log_WARNING_HI_EVAC_ALREADY_REGISTERED(id, seq);
            this->cmdResponse_out(opCode, cmdSeq, Fw::COMMAND_EXECUTION_ERROR);
            return;
        }
    }

    // Try to add event in entries list
    for (U32 slot = 0; slot < FW_NUM_ARRAY_ELEMENTS(this->m_eventActionTable);
         slot++) {
        if ((not this->m_eventActionTable[slot].used) and (not slotFound)) {
            this->m_eventActionTable[slot].id = id;
            if (this->m_eventActionTable[slot].sequence != nullptr) {
                delete this->m_eventActionTable[slot].sequence;
            }
            this->m_eventActionTable[slot].sequence =
                new Fw::EightyCharString(sequence.toChar());
            this->m_eventActionTable[slot].used = true;

            slotFound = true;
        }
    }

    if (not slotFound) {
        this->log_WARNING_LO_EVAC_LIST_FULL(id);
        this->cmdResponse_out(opCode, cmdSeq, Fw::COMMAND_EXECUTION_ERROR);
        return;
    }

    Fw::LogStringArg seqLog(sequence.toChar());
    this->log_ACTIVITY_HI_EVAC_ADDED(seqLog, id);
    this->cmdResponse_out(opCode, cmdSeq, Fw::COMMAND_OK);
}

void EventActionComponentImpl ::EVAC_REMOVE_cmdHandler(
    const FwOpcodeType opCode, const U32 cmdSeq, U32 id) {
    for (U32 slot = 0; slot < FW_NUM_ARRAY_ELEMENTS(this->m_eventActionTable);
         slot++) {
        if ((this->m_eventActionTable[slot].used) and
            (this->m_eventActionTable[slot].id == id)) {
                //  @todo Ensure actionLogger will not access pointer after delete !
            Fw::LogStringArg seq(
                this->m_eventActionTable[slot].sequence->toChar());
            this->log_ACTIVITY_HI_EVAC_REMOVED(seq, id);

            // Clear slot
            this->m_eventActionTable[slot].id = 0;
            this->m_eventActionTable[slot].used = false;
            delete this->m_eventActionTable[slot].sequence;
            this->m_eventActionTable[slot].sequence = nullptr;

            this->cmdResponse_out(opCode, cmdSeq, Fw::COMMAND_OK);
            return;
        }
    }

    this->log_WARNING_LO_EVAC_NOT_FOUND(id);
    this->cmdResponse_out(opCode, cmdSeq, Fw::COMMAND_EXECUTION_ERROR);
}

void EventActionComponentImpl ::EVAC_DUMP_cmdHandler(const FwOpcodeType opCode,
                                                     const U32 cmdSeq) {
    for (U32 slot = 0; slot < FW_NUM_ARRAY_ELEMENTS(this->m_eventActionTable);
         slot++) {
        if (this->m_eventActionTable[slot].used) {
            Fw::LogStringArg seq(
                this->m_eventActionTable[slot].sequence->toChar());
            this->log_ACTIVITY_HI_EVAC_DUMP(seq,
                                            this->m_eventActionTable[slot].id);
        }
    }
    this->cmdResponse_out(opCode, cmdSeq, Fw::COMMAND_OK);
}

}  // end namespace App
