// ======================================================================
// \title  EventAction/test/ut/TesterBase.hpp
// \author Auto-generated
// \brief  hpp file for EventAction component test harness base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef EventAction_TESTER_BASE_HPP
#define EventAction_TESTER_BASE_HPP

#include <App/EventAction/EventActionComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <stdio.h>
#include <Fw/Port/InputSerializePort.hpp>

namespace App {

  //! \class EventActionTesterBase
  //! \brief Auto-generated base class for EventAction component test harness
  //!
  class EventActionTesterBase :
    public Fw::PassiveComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Initialization
      // ----------------------------------------------------------------------

      //! Initialize object EventActionTesterBase
      //!
      virtual void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

    public:

      // ----------------------------------------------------------------------
      // Connectors for 'to' ports
      // Connect these output ports to the input ports under test
      // ----------------------------------------------------------------------

      //! Connect cmdDisp to to_cmdDisp[portNum]
      //!
      void connect_to_cmdDisp(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::InputCmdPort *const cmdDisp /*!< The port*/
      );

      //! Connect seqResp to to_seqResp[portNum]
      //!
      void connect_to_seqResp(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::InputCmdResponsePort *const seqResp /*!< The port*/
      );

      //! Connect logRecv to to_logRecv[portNum]
      //!
      void connect_to_logRecv(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::InputLogPort *const logRecv /*!< The port*/
      );

    public:

      // ----------------------------------------------------------------------
      // Getters for 'from' ports
      // Connect these input ports to the output ports under test
      // ----------------------------------------------------------------------

      //! Get the port that receives input from cmdRegOut
      //!
      //! \return from_cmdRegOut[portNum]
      //!
      Fw::InputCmdRegPort* get_from_cmdRegOut(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from cmdResponseOut
      //!
      //! \return from_cmdResponseOut[portNum]
      //!
      Fw::InputCmdResponsePort* get_from_cmdResponseOut(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from eventOut
      //!
      //! \return from_eventOut[portNum]
      //!
      Fw::InputLogPort* get_from_eventOut(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

#if FW_ENABLE_TEXT_LOGGING == 1
      //! Get the port that receives input from txtEventOut
      //!
      //! \return from_txtEventOut[portNum]
      //!
      Fw::InputLogTextPort* get_from_txtEventOut(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );
#endif

      //! Get the port that receives input from tlmOut
      //!
      //! \return from_tlmOut[portNum]
      //!
      Fw::InputTlmPort* get_from_tlmOut(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from seqRun
      //!
      //! \return from_seqRun[portNum]
      //!
      Svc::InputCmdSeqInPort* get_from_seqRun(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from Time
      //!
      //! \return from_Time[portNum]
      //!
      Fw::InputTimePort* get_from_Time(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

    protected:

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

      //! Construct object EventActionTesterBase
      //!
      EventActionTesterBase(
#if FW_OBJECT_NAMES == 1
          const char *const compName, /*!< The component name*/
          const U32 maxHistorySize /*!< The maximum size of each history*/
#else
          const U32 maxHistorySize /*!< The maximum size of each history*/
#endif
      );

      //! Destroy object EventActionTesterBase
      //!
      virtual ~EventActionTesterBase(void);

      // ----------------------------------------------------------------------
      // Test history
      // ----------------------------------------------------------------------

    protected:

      //! \class History
      //! \brief A history of port inputs
      //!
      template <typename T> class History {

        public:

          //! Create a History
          //!
          History(
              const U32 maxSize /*!< The maximum history size*/
          ) :
              numEntries(0),
              maxSize(maxSize)
          {
            this->entries = new T[maxSize];
          }

          //! Destroy a History
          //!
          ~History() {
            delete[] this->entries;
          }

          //! Clear the history
          //!
          void clear() { this->numEntries = 0; }

          //! Push an item onto the history
          //!
          void push_back(
              T entry /*!< The item*/
          ) {
            FW_ASSERT(this->numEntries < this->maxSize);
            entries[this->numEntries++] = entry;
          }

          //! Get an item at an index
          //!
          //! \return The item at index i
          //!
          T at(
              const U32 i /*!< The index*/
          ) const {
            FW_ASSERT(i < this->numEntries);
            return entries[i];
          }

          //! Get the number of entries in the history
          //!
          //! \return The number of entries in the history
          //!
          U32 size(void) const { return this->numEntries; }

        private:

          //! The number of entries in the history
          //!
          U32 numEntries;

          //! The maximum history size
          //!
          const U32 maxSize;

          //! The entries
          //!
          T *entries;

      };

      //! Clear all history
      //!
      void clearHistory(void);

    protected:

      // ----------------------------------------------------------------------
      // Handler prototypes for typed from ports
      // ----------------------------------------------------------------------

      //! Handler prototype for from_seqRun
      //!
      virtual void from_seqRun_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::EightyCharString &filename /*!< The sequence file*/
      ) = 0;

      //! Handler base function for from_seqRun
      //!
      void from_seqRun_handlerBase(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::EightyCharString &filename /*!< The sequence file*/
      );

    protected:

      // ----------------------------------------------------------------------
      // Histories for typed from ports
      // ----------------------------------------------------------------------

      //! Clear from port history
      //!
      void clearFromPortHistory(void);

      //! The total number of from port entries
      //!
      U32 fromPortHistorySize;

      //! Push an entry on the history for from_seqRun
      void pushFromPortEntry_seqRun(
          Fw::EightyCharString &filename /*!< The sequence file*/
      );

      //! A history entry for from_seqRun
      //!
      typedef struct {
          Fw::EightyCharString filename;
      } FromPortEntry_seqRun;

      //! The history for from_seqRun
      //!
      History<FromPortEntry_seqRun>
        *fromPortHistory_seqRun;

    protected:

      // ----------------------------------------------------------------------
      // Invocation functions for to ports
      // ----------------------------------------------------------------------

      //! Invoke the to port connected to seqResp
      //!
      void invoke_to_seqResp(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwOpcodeType opCode, /*!< Command Op Code*/
          U32 cmdSeq, /*!< Command Sequence*/
          Fw::CommandResponse response /*!< The command response argument*/
      );

      //! Invoke the to port connected to logRecv
      //!
      void invoke_to_logRecv(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwEventIdType id, /*!< Log ID*/
          Fw::Time &timeTag, /*!< Time Tag*/
          Fw::LogSeverity severity, /*!< The severity argument*/
          Fw::LogBuffer &args /*!< Buffer containing serialized log entry*/
      );

    public:

      // ----------------------------------------------------------------------
      // Getters for port counts
      // ----------------------------------------------------------------------

      //! Get the number of to_cmdDisp ports
      //!
      //! \return The number of to_cmdDisp ports
      //!
      NATIVE_INT_TYPE getNum_to_cmdDisp(void) const;

      //! Get the number of from_cmdRegOut ports
      //!
      //! \return The number of from_cmdRegOut ports
      //!
      NATIVE_INT_TYPE getNum_from_cmdRegOut(void) const;

      //! Get the number of from_cmdResponseOut ports
      //!
      //! \return The number of from_cmdResponseOut ports
      //!
      NATIVE_INT_TYPE getNum_from_cmdResponseOut(void) const;

      //! Get the number of from_eventOut ports
      //!
      //! \return The number of from_eventOut ports
      //!
      NATIVE_INT_TYPE getNum_from_eventOut(void) const;

#if FW_ENABLE_TEXT_LOGGING == 1
      //! Get the number of from_txtEventOut ports
      //!
      //! \return The number of from_txtEventOut ports
      //!
      NATIVE_INT_TYPE getNum_from_txtEventOut(void) const;
#endif

      //! Get the number of from_tlmOut ports
      //!
      //! \return The number of from_tlmOut ports
      //!
      NATIVE_INT_TYPE getNum_from_tlmOut(void) const;

      //! Get the number of from_seqRun ports
      //!
      //! \return The number of from_seqRun ports
      //!
      NATIVE_INT_TYPE getNum_from_seqRun(void) const;

      //! Get the number of to_seqResp ports
      //!
      //! \return The number of to_seqResp ports
      //!
      NATIVE_INT_TYPE getNum_to_seqResp(void) const;

      //! Get the number of to_logRecv ports
      //!
      //! \return The number of to_logRecv ports
      //!
      NATIVE_INT_TYPE getNum_to_logRecv(void) const;

      //! Get the number of from_Time ports
      //!
      //! \return The number of from_Time ports
      //!
      NATIVE_INT_TYPE getNum_from_Time(void) const;

    protected:

      // ----------------------------------------------------------------------
      // Connection status for to ports
      // ----------------------------------------------------------------------

      //! Check whether port is connected
      //!
      //! Whether to_cmdDisp[portNum] is connected
      //!
      bool isConnected_to_cmdDisp(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Check whether port is connected
      //!
      //! Whether to_seqResp[portNum] is connected
      //!
      bool isConnected_to_seqResp(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Check whether port is connected
      //!
      //! Whether to_logRecv[portNum] is connected
      //!
      bool isConnected_to_logRecv(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      // ----------------------------------------------------------------------
      // Functions for sending commands
      // ----------------------------------------------------------------------

    protected:

      // send command buffers directly - used for intentional command encoding errors
      void sendRawCmd(FwOpcodeType opcode, U32 cmdSeq, Fw::CmdArgBuffer& args);

      //! Send a EVAC_ADD command
      //!
      void sendCmd_EVAC_ADD(
          const NATIVE_INT_TYPE instance, /*!< The instance number*/
          const U32 cmdSeq, /*!< The command sequence number*/
          U32 id, 
          const Fw::CmdStringArg& sequence 
      );

      //! Send a EVAC_REMOVE command
      //!
      void sendCmd_EVAC_REMOVE(
          const NATIVE_INT_TYPE instance, /*!< The instance number*/
          const U32 cmdSeq, /*!< The command sequence number*/
          U32 id 
      );

      //! Send a EVAC_DUMP command
      //!
      void sendCmd_EVAC_DUMP(
          const NATIVE_INT_TYPE instance, /*!< The instance number*/
          const U32 cmdSeq /*!< The command sequence number*/
      );

    protected:

      // ----------------------------------------------------------------------
      // Command response handling
      // ----------------------------------------------------------------------

      //! Handle a command response
      //!
      virtual void cmdResponseIn(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          const Fw::CommandResponse response /*!< The command response*/
      );

      //! A type representing a command response
      //!
      typedef struct {
        FwOpcodeType opCode;
        U32 cmdSeq;
        Fw::CommandResponse response;
      } CmdResponse;

      //! The command response history
      //!
      History<CmdResponse> *cmdResponseHistory;

    protected:

      // ----------------------------------------------------------------------
      // Event dispatch
      // ----------------------------------------------------------------------

      //! Dispatch an event
      //!
      void dispatchEvents(
          const FwEventIdType id, /*!< The event ID*/
          Fw::Time& timeTag, /*!< The time*/
          const Fw::LogSeverity severity, /*!< The severity*/
          Fw::LogBuffer& args /*!< The serialized arguments*/
      );

      //! Clear event history
      //!
      void clearEvents(void);

      //! The total number of events seen
      //!
      U32 eventsSize;

#if FW_ENABLE_TEXT_LOGGING

    protected:

      // ----------------------------------------------------------------------
      // Text events
      // ----------------------------------------------------------------------

      //! Handle a text event
      //!
      virtual void textLogIn(
          const FwEventIdType id, /*!< The event ID*/
          Fw::Time& timeTag, /*!< The time*/
          const Fw::TextLogSeverity severity, /*!< The severity*/
          const Fw::TextLogString& text /*!< The event string*/
      );

      //! A history entry for the text log
      //!
      typedef struct {
        U32 id;
        Fw::Time timeTag;
        Fw::TextLogSeverity severity;
        Fw::TextLogString text;
      } TextLogEntry;

      //! The history of text log events
      //!
      History<TextLogEntry> *textLogHistory;

      //! Print a text log history entry
      //!
      static void printTextLogHistoryEntry(
          const TextLogEntry& e,
          FILE* file
      );

      //! Print the text log history
      //!
      void printTextLogHistory(FILE *const file);

#endif

    protected:

      // ----------------------------------------------------------------------
      // Event: EVAC_ADDED
      // ----------------------------------------------------------------------

      //! Handle event EVAC_ADDED
      //!
      virtual void logIn_ACTIVITY_HI_EVAC_ADDED(
          Fw::LogStringArg& sequence, 
          U32 eventId 
      );

      //! A history entry for event EVAC_ADDED
      //!
      typedef struct {
        Fw::LogStringArg sequence;
        U32 eventId;
      } EventEntry_EVAC_ADDED;

      //! The history of EVAC_ADDED events
      //!
      History<EventEntry_EVAC_ADDED>
        *eventHistory_EVAC_ADDED;

    protected:

      // ----------------------------------------------------------------------
      // Event: EVAC_REMOVED
      // ----------------------------------------------------------------------

      //! Handle event EVAC_REMOVED
      //!
      virtual void logIn_ACTIVITY_HI_EVAC_REMOVED(
          Fw::LogStringArg& sequence, 
          U32 eventId 
      );

      //! A history entry for event EVAC_REMOVED
      //!
      typedef struct {
        Fw::LogStringArg sequence;
        U32 eventId;
      } EventEntry_EVAC_REMOVED;

      //! The history of EVAC_REMOVED events
      //!
      History<EventEntry_EVAC_REMOVED>
        *eventHistory_EVAC_REMOVED;

    protected:

      // ----------------------------------------------------------------------
      // Event: EVAC_LIST_FULL
      // ----------------------------------------------------------------------

      //! Handle event EVAC_LIST_FULL
      //!
      virtual void logIn_WARNING_LO_EVAC_LIST_FULL(
          U32 eventId 
      );

      //! A history entry for event EVAC_LIST_FULL
      //!
      typedef struct {
        U32 eventId;
      } EventEntry_EVAC_LIST_FULL;

      //! The history of EVAC_LIST_FULL events
      //!
      History<EventEntry_EVAC_LIST_FULL>
        *eventHistory_EVAC_LIST_FULL;

    protected:

      // ----------------------------------------------------------------------
      // Event: EVAC_NOT_FOUND
      // ----------------------------------------------------------------------

      //! Handle event EVAC_NOT_FOUND
      //!
      virtual void logIn_WARNING_LO_EVAC_NOT_FOUND(
          U32 eventId 
      );

      //! A history entry for event EVAC_NOT_FOUND
      //!
      typedef struct {
        U32 eventId;
      } EventEntry_EVAC_NOT_FOUND;

      //! The history of EVAC_NOT_FOUND events
      //!
      History<EventEntry_EVAC_NOT_FOUND>
        *eventHistory_EVAC_NOT_FOUND;

    protected:

      // ----------------------------------------------------------------------
      // Event: EVAC_ALREADY_REGISTERED
      // ----------------------------------------------------------------------

      //! Handle event EVAC_ALREADY_REGISTERED
      //!
      virtual void logIn_WARNING_HI_EVAC_ALREADY_REGISTERED(
          U32 eventId, 
          Fw::LogStringArg& sequence 
      );

      //! A history entry for event EVAC_ALREADY_REGISTERED
      //!
      typedef struct {
        U32 eventId;
        Fw::LogStringArg sequence;
      } EventEntry_EVAC_ALREADY_REGISTERED;

      //! The history of EVAC_ALREADY_REGISTERED events
      //!
      History<EventEntry_EVAC_ALREADY_REGISTERED>
        *eventHistory_EVAC_ALREADY_REGISTERED;

    protected:

      // ----------------------------------------------------------------------
      // Event: EVAC_DUMP
      // ----------------------------------------------------------------------

      //! Handle event EVAC_DUMP
      //!
      virtual void logIn_ACTIVITY_HI_EVAC_DUMP(
          Fw::LogStringArg& sequence, 
          U32 eventId 
      );

      //! A history entry for event EVAC_DUMP
      //!
      typedef struct {
        Fw::LogStringArg sequence;
        U32 eventId;
      } EventEntry_EVAC_DUMP;

      //! The history of EVAC_DUMP events
      //!
      History<EventEntry_EVAC_DUMP>
        *eventHistory_EVAC_DUMP;

    protected:

      // ----------------------------------------------------------------------
      // Event: EVAC_RUN
      // ----------------------------------------------------------------------

      //! Handle event EVAC_RUN
      //!
      virtual void logIn_ACTIVITY_HI_EVAC_RUN(
          U32 eventId, 
          Fw::LogStringArg& message 
      );

      //! A history entry for event EVAC_RUN
      //!
      typedef struct {
        U32 eventId;
        Fw::LogStringArg message;
      } EventEntry_EVAC_RUN;

      //! The history of EVAC_RUN events
      //!
      History<EventEntry_EVAC_RUN>
        *eventHistory_EVAC_RUN;

    protected:

      // ----------------------------------------------------------------------
      // Telemetry dispatch
      // ----------------------------------------------------------------------

      //! Dispatch telemetry
      //!
      void dispatchTlm(
          const FwChanIdType id, /*!< The channel ID*/
          const Fw::Time& timeTag, /*!< The time*/
          Fw::TlmBuffer& val /*!< The channel value*/
      );

      //! Clear telemetry history
      //!
      void clearTlm(void);

      //! The total number of telemetry inputs seen
      //!
      U32 tlmSize;

    protected:

      // ----------------------------------------------------------------------
      // Channel: EVAC_CHA
      // ----------------------------------------------------------------------

      //! Handle channel EVAC_CHA
      //!
      virtual void tlmInput_EVAC_CHA(
          const Fw::Time& timeTag, /*!< The time*/
          const U32& val /*!< The channel value*/
      );

      //! A telemetry entry for channel EVAC_CHA
      //!
      typedef struct {
        Fw::Time timeTag;
        U32 arg;
      } TlmEntry_EVAC_CHA;

      //! The history of EVAC_CHA values
      //!
      History<TlmEntry_EVAC_CHA>
        *tlmHistory_EVAC_CHA;

    protected:

      // ----------------------------------------------------------------------
      // Test time
      // ----------------------------------------------------------------------

      //! Set the test time for events and telemetry
      //!
      void setTestTime(
          const Fw::Time& timeTag /*!< The time*/
      );

    private:

      // ----------------------------------------------------------------------
      // To ports
      // ----------------------------------------------------------------------

      //! To port connected to cmdDisp
      //!
      Fw::OutputCmdPort m_to_cmdDisp[1];

      //! To port connected to seqResp
      //!
      Fw::OutputCmdResponsePort m_to_seqResp[1];

      //! To port connected to logRecv
      //!
      Fw::OutputLogPort m_to_logRecv[1];

    private:

      // ----------------------------------------------------------------------
      // From ports
      // ----------------------------------------------------------------------

      //! From port connected to cmdRegOut
      //!
      Fw::InputCmdRegPort m_from_cmdRegOut[1];

      //! From port connected to cmdResponseOut
      //!
      Fw::InputCmdResponsePort m_from_cmdResponseOut[1];

      //! From port connected to eventOut
      //!
      Fw::InputLogPort m_from_eventOut[1];

#if FW_ENABLE_TEXT_LOGGING == 1
      //! From port connected to txtEventOut
      //!
      Fw::InputLogTextPort m_from_txtEventOut[1];
#endif

      //! From port connected to tlmOut
      //!
      Fw::InputTlmPort m_from_tlmOut[1];

      //! From port connected to seqRun
      //!
      Svc::InputCmdSeqInPort m_from_seqRun[1];

      //! From port connected to Time
      //!
      Fw::InputTimePort m_from_Time[1];

    private:

      // ----------------------------------------------------------------------
      // Static functions for output ports
      // ----------------------------------------------------------------------

      //! Static function for port from_cmdRegOut
      //!
      static void from_cmdRegOut_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwOpcodeType opCode /*!< Command Op Code*/
      );

      //! Static function for port from_cmdResponseOut
      //!
      static void from_cmdResponseOut_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwOpcodeType opCode, /*!< Command Op Code*/
          U32 cmdSeq, /*!< Command Sequence*/
          Fw::CommandResponse response /*!< The command response argument*/
      );

      //! Static function for port from_eventOut
      //!
      static void from_eventOut_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwEventIdType id, /*!< Log ID*/
          Fw::Time &timeTag, /*!< Time Tag*/
          Fw::LogSeverity severity, /*!< The severity argument*/
          Fw::LogBuffer &args /*!< Buffer containing serialized log entry*/
      );

#if FW_ENABLE_TEXT_LOGGING == 1
      //! Static function for port from_txtEventOut
      //!
      static void from_txtEventOut_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwEventIdType id, /*!< Log ID*/
          Fw::Time &timeTag, /*!< Time Tag*/
          Fw::TextLogSeverity severity, /*!< The severity argument*/
          Fw::TextLogString &text /*!< Text of log message*/
      );
#endif

      //! Static function for port from_tlmOut
      //!
      static void from_tlmOut_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwChanIdType id, /*!< Telemetry Channel ID*/
          Fw::Time &timeTag, /*!< Time Tag*/
          Fw::TlmBuffer &val /*!< Buffer containing serialized telemetry value*/
      );

      //! Static function for port from_seqRun
      //!
      static void from_seqRun_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::EightyCharString &filename /*!< The sequence file*/
      );

      //! Static function for port from_Time
      //!
      static void from_Time_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Time &time /*!< The U32 cmd argument*/
      );

    private:

      // ----------------------------------------------------------------------
      // Test time
      // ----------------------------------------------------------------------

      //! Test time stamp
      //!
      Fw::Time m_testTime;

  };

} // end namespace App

#endif
