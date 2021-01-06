// ======================================================================
// \title  EPS/test/ut/TesterBase.hpp
// \author Auto-generated
// \brief  hpp file for EPS component test harness base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef EPS_TESTER_BASE_HPP
#define EPS_TESTER_BASE_HPP

#include <App/EPS/EPSComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <stdio.h>
#include <Fw/Port/InputSerializePort.hpp>

namespace App {

  //! \class EPSTesterBase
  //! \brief Auto-generated base class for EPS component test harness
  //!
  class EPSTesterBase :
    public Fw::PassiveComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Initialization
      // ----------------------------------------------------------------------

      //! Initialize object EPSTesterBase
      //!
      virtual void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

    public:

      // ----------------------------------------------------------------------
      // Connectors for 'to' ports
      // Connect these output ports to the input ports under test
      // ----------------------------------------------------------------------

      //! Connect DataIn to to_DataIn[portNum]
      //!
      void connect_to_DataIn(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          App::InputEPSCmdPort *const DataIn /*!< The port*/
      );

      //! Connect Schedin to to_Schedin[portNum]
      //!
      void connect_to_Schedin(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Svc::InputSchedPort *const Schedin /*!< The port*/
      );

      //! Connect CmdDisp to to_CmdDisp[portNum]
      //!
      void connect_to_CmdDisp(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::InputCmdPort *const CmdDisp /*!< The port*/
      );

    public:

      // ----------------------------------------------------------------------
      // Getters for 'from' ports
      // Connect these input ports to the output ports under test
      // ----------------------------------------------------------------------

      //! Get the port that receives input from DataOut
      //!
      //! \return from_DataOut[portNum]
      //!
      App::InputEPSCmdPort* get_from_DataOut(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from CmdStatus
      //!
      //! \return from_CmdStatus[portNum]
      //!
      Fw::InputCmdResponsePort* get_from_CmdStatus(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from CmdReg
      //!
      //! \return from_CmdReg[portNum]
      //!
      Fw::InputCmdRegPort* get_from_CmdReg(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from Tlm
      //!
      //! \return from_Tlm[portNum]
      //!
      Fw::InputTlmPort* get_from_Tlm(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from Time
      //!
      //! \return from_Time[portNum]
      //!
      Fw::InputTimePort* get_from_Time(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from Log
      //!
      //! \return from_Log[portNum]
      //!
      Fw::InputLogPort* get_from_Log(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

#if FW_ENABLE_TEXT_LOGGING == 1
      //! Get the port that receives input from LogText
      //!
      //! \return from_LogText[portNum]
      //!
      Fw::InputLogTextPort* get_from_LogText(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );
#endif

    protected:

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

      //! Construct object EPSTesterBase
      //!
      EPSTesterBase(
#if FW_OBJECT_NAMES == 1
          const char *const compName, /*!< The component name*/
          const U32 maxHistorySize /*!< The maximum size of each history*/
#else
          const U32 maxHistorySize /*!< The maximum size of each history*/
#endif
      );

      //! Destroy object EPSTesterBase
      //!
      virtual ~EPSTesterBase(void);

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

      //! Handler prototype for from_DataOut
      //!
      virtual void from_DataOut_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U8 port, 
          Fw::Buffer &data, 
          U8 isSched 
      ) = 0;

      //! Handler base function for from_DataOut
      //!
      void from_DataOut_handlerBase(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U8 port, 
          Fw::Buffer &data, 
          U8 isSched 
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

      //! Push an entry on the history for from_DataOut
      void pushFromPortEntry_DataOut(
          U8 port, 
          Fw::Buffer &data, 
          U8 isSched 
      );

      //! A history entry for from_DataOut
      //!
      typedef struct {
          U8 port;
          Fw::Buffer data;
          U8 isSched;
      } FromPortEntry_DataOut;

      //! The history for from_DataOut
      //!
      History<FromPortEntry_DataOut>
        *fromPortHistory_DataOut;

    protected:

      // ----------------------------------------------------------------------
      // Invocation functions for to ports
      // ----------------------------------------------------------------------

      //! Invoke the to port connected to DataIn
      //!
      void invoke_to_DataIn(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U8 port, 
          Fw::Buffer &data, 
          U8 isSched 
      );

      //! Invoke the to port connected to Schedin
      //!
      void invoke_to_Schedin(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );

    public:

      // ----------------------------------------------------------------------
      // Getters for port counts
      // ----------------------------------------------------------------------

      //! Get the number of from_DataOut ports
      //!
      //! \return The number of from_DataOut ports
      //!
      NATIVE_INT_TYPE getNum_from_DataOut(void) const;

      //! Get the number of to_DataIn ports
      //!
      //! \return The number of to_DataIn ports
      //!
      NATIVE_INT_TYPE getNum_to_DataIn(void) const;

      //! Get the number of to_Schedin ports
      //!
      //! \return The number of to_Schedin ports
      //!
      NATIVE_INT_TYPE getNum_to_Schedin(void) const;

      //! Get the number of to_CmdDisp ports
      //!
      //! \return The number of to_CmdDisp ports
      //!
      NATIVE_INT_TYPE getNum_to_CmdDisp(void) const;

      //! Get the number of from_CmdStatus ports
      //!
      //! \return The number of from_CmdStatus ports
      //!
      NATIVE_INT_TYPE getNum_from_CmdStatus(void) const;

      //! Get the number of from_CmdReg ports
      //!
      //! \return The number of from_CmdReg ports
      //!
      NATIVE_INT_TYPE getNum_from_CmdReg(void) const;

      //! Get the number of from_Tlm ports
      //!
      //! \return The number of from_Tlm ports
      //!
      NATIVE_INT_TYPE getNum_from_Tlm(void) const;

      //! Get the number of from_Time ports
      //!
      //! \return The number of from_Time ports
      //!
      NATIVE_INT_TYPE getNum_from_Time(void) const;

      //! Get the number of from_Log ports
      //!
      //! \return The number of from_Log ports
      //!
      NATIVE_INT_TYPE getNum_from_Log(void) const;

#if FW_ENABLE_TEXT_LOGGING == 1
      //! Get the number of from_LogText ports
      //!
      //! \return The number of from_LogText ports
      //!
      NATIVE_INT_TYPE getNum_from_LogText(void) const;
#endif

    protected:

      // ----------------------------------------------------------------------
      // Connection status for to ports
      // ----------------------------------------------------------------------

      //! Check whether port is connected
      //!
      //! Whether to_DataIn[portNum] is connected
      //!
      bool isConnected_to_DataIn(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Check whether port is connected
      //!
      //! Whether to_Schedin[portNum] is connected
      //!
      bool isConnected_to_Schedin(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Check whether port is connected
      //!
      //! Whether to_CmdDisp[portNum] is connected
      //!
      bool isConnected_to_CmdDisp(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      // ----------------------------------------------------------------------
      // Functions for sending commands
      // ----------------------------------------------------------------------

    protected:

      // send command buffers directly - used for intentional command encoding errors
      void sendRawCmd(FwOpcodeType opcode, U32 cmdSeq, Fw::CmdArgBuffer& args);

      //! Send a MS_SEND_CMD command
      //!
      void sendCmd_MS_SEND_CMD(
          const NATIVE_INT_TYPE instance, /*!< The instance number*/
          const U32 cmdSeq, /*!< The command sequence number*/
          EPSComponentBase::EPSOp operation, /*!< operation argument*/
          const Fw::CmdStringArg& payload /*!< The payload data*/
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
      // Event: MS_CMD_SEND_EPS
      // ----------------------------------------------------------------------

      //! Handle event MS_CMD_SEND_EPS
      //!
      virtual void logIn_ACTIVITY_LO_MS_CMD_SEND_EPS(
          U8 port, /*!< The port id*/
          U8 cmd, /*!< The cmd id*/
          Fw::LogStringArg& payload /*!< The command data*/
      );

      //! A history entry for event MS_CMD_SEND_EPS
      //!
      typedef struct {
        U8 port;
        U8 cmd;
        Fw::LogStringArg payload;
      } EventEntry_MS_CMD_SEND_EPS;

      //! The history of MS_CMD_SEND_EPS events
      //!
      History<EventEntry_MS_CMD_SEND_EPS>
        *eventHistory_MS_CMD_SEND_EPS;

    protected:

      // ----------------------------------------------------------------------
      // Event: MS_CMD_RECV_EPS
      // ----------------------------------------------------------------------

      //! Handle event MS_CMD_RECV_EPS
      //!
      virtual void logIn_ACTIVITY_LO_MS_CMD_RECV_EPS(
          U8 port, /*!< The port id*/
          U8 cmd, /*!< The command id*/
          Fw::LogStringArg& payload /*!< The command return data*/
      );

      //! A history entry for event MS_CMD_RECV_EPS
      //!
      typedef struct {
        U8 port;
        U8 cmd;
        Fw::LogStringArg payload;
      } EventEntry_MS_CMD_RECV_EPS;

      //! The history of MS_CMD_RECV_EPS events
      //!
      History<EventEntry_MS_CMD_RECV_EPS>
        *eventHistory_MS_CMD_RECV_EPS;

    protected:

      // ----------------------------------------------------------------------
      // Event: MS_CMD_ERROR
      // ----------------------------------------------------------------------

      //! Handle event MS_CMD_ERROR
      //!
      virtual void logIn_WARNING_LO_MS_CMD_ERROR(
          U8 port, /*!< The port id*/
          U8 cmd, /*!< the cmd error*/
          U8 status /*!< the status error*/
      );

      //! A history entry for event MS_CMD_ERROR
      //!
      typedef struct {
        U8 port;
        U8 cmd;
        U8 status;
      } EventEntry_MS_CMD_ERROR;

      //! The history of MS_CMD_ERROR events
      //!
      History<EventEntry_MS_CMD_ERROR>
        *eventHistory_MS_CMD_ERROR;

    protected:

      // ----------------------------------------------------------------------
      // Event: MS_BATT_VOLT_LOW
      // ----------------------------------------------------------------------

      //! Handle event MS_BATT_VOLT_LOW
      //!
      virtual void logIn_WARNING_HI_MS_BATT_VOLT_LOW(
          U16 volt /*!< Voltage*/
      );

      //! A history entry for event MS_BATT_VOLT_LOW
      //!
      typedef struct {
        U16 volt;
      } EventEntry_MS_BATT_VOLT_LOW;

      //! The history of MS_BATT_VOLT_LOW events
      //!
      History<EventEntry_MS_BATT_VOLT_LOW>
        *eventHistory_MS_BATT_VOLT_LOW;

    protected:

      // ----------------------------------------------------------------------
      // Event: MS_BATT_TEMP_HIGH
      // ----------------------------------------------------------------------

      //! Handle event MS_BATT_TEMP_HIGH
      //!
      virtual void logIn_WARNING_HI_MS_BATT_TEMP_HIGH(
          U8 temp /*!< the id error*/
      );

      //! A history entry for event MS_BATT_TEMP_HIGH
      //!
      typedef struct {
        U8 temp;
      } EventEntry_MS_BATT_TEMP_HIGH;

      //! The history of MS_BATT_TEMP_HIGH events
      //!
      History<EventEntry_MS_BATT_TEMP_HIGH>
        *eventHistory_MS_BATT_TEMP_HIGH;

    protected:

      // ----------------------------------------------------------------------
      // Event: MS_CHNG_BATT_MOD
      // ----------------------------------------------------------------------

      //! Handle event MS_CHNG_BATT_MOD
      //!
      virtual void logIn_WARNING_HI_MS_CHNG_BATT_MOD(
          U8 mode /*!< battery mode*/
      );

      //! A history entry for event MS_CHNG_BATT_MOD
      //!
      typedef struct {
        U8 mode;
      } EventEntry_MS_CHNG_BATT_MOD;

      //! The history of MS_CHNG_BATT_MOD events
      //!
      History<EventEntry_MS_CHNG_BATT_MOD>
        *eventHistory_MS_CHNG_BATT_MOD;

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
      // Channel: EPS_Voltage_battery_mV
      // ----------------------------------------------------------------------

      //! Handle channel EPS_Voltage_battery_mV
      //!
      virtual void tlmInput_EPS_Voltage_battery_mV(
          const Fw::Time& timeTag, /*!< The time*/
          const U16& val /*!< The channel value*/
      );

      //! A telemetry entry for channel EPS_Voltage_battery_mV
      //!
      typedef struct {
        Fw::Time timeTag;
        U16 arg;
      } TlmEntry_EPS_Voltage_battery_mV;

      //! The history of EPS_Voltage_battery_mV values
      //!
      History<TlmEntry_EPS_Voltage_battery_mV>
        *tlmHistory_EPS_Voltage_battery_mV;

    protected:

      // ----------------------------------------------------------------------
      // Channel: EPS_Battery_mode
      // ----------------------------------------------------------------------

      //! Handle channel EPS_Battery_mode
      //!
      virtual void tlmInput_EPS_Battery_mode(
          const Fw::Time& timeTag, /*!< The time*/
          const U8& val /*!< The channel value*/
      );

      //! A telemetry entry for channel EPS_Battery_mode
      //!
      typedef struct {
        Fw::Time timeTag;
        U8 arg;
      } TlmEntry_EPS_Battery_mode;

      //! The history of EPS_Battery_mode values
      //!
      History<TlmEntry_EPS_Battery_mode>
        *tlmHistory_EPS_Battery_mode;

    protected:

      // ----------------------------------------------------------------------
      // Channel: EPS_Temp_Battery_Celsuis
      // ----------------------------------------------------------------------

      //! Handle channel EPS_Temp_Battery_Celsuis
      //!
      virtual void tlmInput_EPS_Temp_Battery_Celsuis(
          const Fw::Time& timeTag, /*!< The time*/
          const U16& val /*!< The channel value*/
      );

      //! A telemetry entry for channel EPS_Temp_Battery_Celsuis
      //!
      typedef struct {
        Fw::Time timeTag;
        U16 arg;
      } TlmEntry_EPS_Temp_Battery_Celsuis;

      //! The history of EPS_Temp_Battery_Celsuis values
      //!
      History<TlmEntry_EPS_Temp_Battery_Celsuis>
        *tlmHistory_EPS_Temp_Battery_Celsuis;

    protected:

      // ----------------------------------------------------------------------
      // Channel: EPS_LAST_CMD_RETURN
      // ----------------------------------------------------------------------

      //! Handle channel EPS_LAST_CMD_RETURN
      //!
      virtual void tlmInput_EPS_LAST_CMD_RETURN(
          const Fw::Time& timeTag, /*!< The time*/
          const Fw::TlmString& val /*!< The channel value*/
      );

      //! A telemetry entry for channel EPS_LAST_CMD_RETURN
      //!
      typedef struct {
        Fw::Time timeTag;
        Fw::TlmString arg;
      } TlmEntry_EPS_LAST_CMD_RETURN;

      //! The history of EPS_LAST_CMD_RETURN values
      //!
      History<TlmEntry_EPS_LAST_CMD_RETURN>
        *tlmHistory_EPS_LAST_CMD_RETURN;

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

      //! To port connected to DataIn
      //!
      App::OutputEPSCmdPort m_to_DataIn[1];

      //! To port connected to Schedin
      //!
      Svc::OutputSchedPort m_to_Schedin[1];

      //! To port connected to CmdDisp
      //!
      Fw::OutputCmdPort m_to_CmdDisp[1];

    private:

      // ----------------------------------------------------------------------
      // From ports
      // ----------------------------------------------------------------------

      //! From port connected to DataOut
      //!
      App::InputEPSCmdPort m_from_DataOut[1];

      //! From port connected to CmdStatus
      //!
      Fw::InputCmdResponsePort m_from_CmdStatus[1];

      //! From port connected to CmdReg
      //!
      Fw::InputCmdRegPort m_from_CmdReg[1];

      //! From port connected to Tlm
      //!
      Fw::InputTlmPort m_from_Tlm[1];

      //! From port connected to Time
      //!
      Fw::InputTimePort m_from_Time[1];

      //! From port connected to Log
      //!
      Fw::InputLogPort m_from_Log[1];

#if FW_ENABLE_TEXT_LOGGING == 1
      //! From port connected to LogText
      //!
      Fw::InputLogTextPort m_from_LogText[1];
#endif

    private:

      // ----------------------------------------------------------------------
      // Static functions for output ports
      // ----------------------------------------------------------------------

      //! Static function for port from_DataOut
      //!
      static void from_DataOut_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U8 port, 
          Fw::Buffer &data, 
          U8 isSched 
      );

      //! Static function for port from_CmdStatus
      //!
      static void from_CmdStatus_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwOpcodeType opCode, /*!< Command Op Code*/
          U32 cmdSeq, /*!< Command Sequence*/
          Fw::CommandResponse response /*!< The command response argument*/
      );

      //! Static function for port from_CmdReg
      //!
      static void from_CmdReg_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwOpcodeType opCode /*!< Command Op Code*/
      );

      //! Static function for port from_Tlm
      //!
      static void from_Tlm_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwChanIdType id, /*!< Telemetry Channel ID*/
          Fw::Time &timeTag, /*!< Time Tag*/
          Fw::TlmBuffer &val /*!< Buffer containing serialized telemetry value*/
      );

      //! Static function for port from_Time
      //!
      static void from_Time_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Time &time /*!< The U32 cmd argument*/
      );

      //! Static function for port from_Log
      //!
      static void from_Log_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwEventIdType id, /*!< Log ID*/
          Fw::Time &timeTag, /*!< Time Tag*/
          Fw::LogSeverity severity, /*!< The severity argument*/
          Fw::LogBuffer &args /*!< Buffer containing serialized log entry*/
      );

#if FW_ENABLE_TEXT_LOGGING == 1
      //! Static function for port from_LogText
      //!
      static void from_LogText_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwEventIdType id, /*!< Log ID*/
          Fw::Time &timeTag, /*!< Time Tag*/
          Fw::TextLogSeverity severity, /*!< The severity argument*/
          Fw::TextLogString &text /*!< Text of log message*/
      );
#endif

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
