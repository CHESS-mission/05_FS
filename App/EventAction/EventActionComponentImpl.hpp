// ======================================================================
// \title  EventActionComponentImpl.hpp
// \author jonathan
// \brief  hpp file for EventAction component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef EventAction_HPP
#define EventAction_HPP

#include "App/EventAction/EventActionComponentAc.hpp"
#include "EventActionImpCfg.hpp"

namespace App {

class EventActionComponentImpl : public EventActionComponentBase {
   public:
    // ----------------------------------------------------------------------
    // Construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct object EventAction
    //!
    EventActionComponentImpl(
        const char *const compName /*!< The component name*/
    );

    //! Initialize object EventAction
    //!
    void init(const NATIVE_INT_TYPE queueDepth,  /*!< The queue depth*/
              const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

    //! Destroy object EventAction
    //!
    ~EventActionComponentImpl(void);

    PRIVATE :

        // ----------------------------------------------------------------------
        // Handler implementations for user-defined typed input ports
        // ----------------------------------------------------------------------

        //! Handler implementation for seqResp
        //!
        void
        seqResp_handler(
            const NATIVE_INT_TYPE portNum, /*!< The port number*/
            FwOpcodeType opCode,           /*!< Command Op Code*/
            U32 cmdSeq,                    /*!< Command Sequence*/
            Fw::CommandResponse response   /*!< The command response argument*/
        );

    //! Handler implementation for logRecv
    //!
    void logRecv_handler(
        const NATIVE_INT_TYPE portNum, /*!< The port number*/
        FwEventIdType id,              /*!< Log ID*/
        Fw::Time &timeTag,             /*!< Time Tag*/
        Fw::LogSeverity severity,      /*!< The severity argument*/
        Fw::LogBuffer &args /*!< Buffer containing serialized log entry*/
    );

    PRIVATE :

        // ----------------------------------------------------------------------
        // Command handler implementations
        // ----------------------------------------------------------------------

        //! Implementation for EVAC_ADD command handler
        //! Add event action
        void
        EVAC_ADD_cmdHandler(const FwOpcodeType opCode, /*!< The opcode*/
                            const U32 cmdSeq, /*!< The command sequence number*/
                            U32 id, const Fw::CmdStringArg &sequence);

    //! Implementation for EVAC_REMOVE command handler
    //! Remove sequence for a specific envent id
    void EVAC_REMOVE_cmdHandler(
        const FwOpcodeType opCode, /*!< The opcode*/
        const U32 cmdSeq,          /*!< The command sequence number*/
        U32 id);

    //! Implementation for EVAC_DUMP command handler
    //! Dump event action list
    void EVAC_DUMP_cmdHandler(
        const FwOpcodeType opCode, /*!< The opcode*/
        const U32 cmdSeq           /*!< The command sequence number*/
    );
    // ----------------------------------------------------------------------
    // Custom code
    // ----------------------------------------------------------------------
    struct EventActionEntry {
        bool used;                       //!< if entry has been used yet
        FwEventIdType id;                //!< event id to detect
        Fw::EightyCharString *sequence;  //!< sequence to launch
    } m_eventActionTable[EVENT_ACTION_TABLE_SIZE];  //!< table of event action
                                                    //!< entries
};

}  // end namespace App

#endif
