// ======================================================================
// \title  SocketCspIpDriver/test/ut/TesterBase.hpp
// \author Auto-generated
// \brief  hpp file for SocketCspIpDriver component test harness base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef SocketCspIpDriver_TESTER_BASE_HPP
#define SocketCspIpDriver_TESTER_BASE_HPP

#include <App/Drv/SocketCspIpDriver/SocketCspIpDriverComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <stdio.h>
#include <Fw/Port/InputSerializePort.hpp>

namespace Drv {

  //! \class SocketCspIpDriverTesterBase
  //! \brief Auto-generated base class for SocketCspIpDriver component test harness
  //!
  class SocketCspIpDriverTesterBase :
    public Fw::PassiveComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Initialization
      // ----------------------------------------------------------------------

      //! Initialize object SocketCspIpDriverTesterBase
      //!
      virtual void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

    public:

      // ----------------------------------------------------------------------
      // Connectors for 'to' ports
      // Connect these output ports to the input ports under test
      // ----------------------------------------------------------------------

      //! Connect send to to_send[portNum]
      //!
      void connect_to_send(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          App::InputEPSCmdPort *const send /*!< The port*/
      );

    public:

      // ----------------------------------------------------------------------
      // Getters for 'from' ports
      // Connect these input ports to the output ports under test
      // ----------------------------------------------------------------------

      //! Get the port that receives input from recv
      //!
      //! \return from_recv[portNum]
      //!
      App::InputEPSCmdPort* get_from_recv(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

    protected:

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

      //! Construct object SocketCspIpDriverTesterBase
      //!
      SocketCspIpDriverTesterBase(
#if FW_OBJECT_NAMES == 1
          const char *const compName, /*!< The component name*/
          const U32 maxHistorySize /*!< The maximum size of each history*/
#else
          const U32 maxHistorySize /*!< The maximum size of each history*/
#endif
      );

      //! Destroy object SocketCspIpDriverTesterBase
      //!
      virtual ~SocketCspIpDriverTesterBase(void);

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

      //! Handler prototype for from_recv
      //!
      virtual void from_recv_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U8 port, 
          Fw::Buffer &data, 
          U8 isSched 
      ) = 0;

      //! Handler base function for from_recv
      //!
      void from_recv_handlerBase(
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

      //! Push an entry on the history for from_recv
      void pushFromPortEntry_recv(
          U8 port, 
          Fw::Buffer &data, 
          U8 isSched 
      );

      //! A history entry for from_recv
      //!
      typedef struct {
          U8 port;
          Fw::Buffer data;
          U8 isSched;
      } FromPortEntry_recv;

      //! The history for from_recv
      //!
      History<FromPortEntry_recv>
        *fromPortHistory_recv;

    protected:

      // ----------------------------------------------------------------------
      // Invocation functions for to ports
      // ----------------------------------------------------------------------

      //! Invoke the to port connected to send
      //!
      void invoke_to_send(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U8 port, 
          Fw::Buffer &data, 
          U8 isSched 
      );

    public:

      // ----------------------------------------------------------------------
      // Getters for port counts
      // ----------------------------------------------------------------------

      //! Get the number of from_recv ports
      //!
      //! \return The number of from_recv ports
      //!
      NATIVE_INT_TYPE getNum_from_recv(void) const;

      //! Get the number of to_send ports
      //!
      //! \return The number of to_send ports
      //!
      NATIVE_INT_TYPE getNum_to_send(void) const;

    protected:

      // ----------------------------------------------------------------------
      // Connection status for to ports
      // ----------------------------------------------------------------------

      //! Check whether port is connected
      //!
      //! Whether to_send[portNum] is connected
      //!
      bool isConnected_to_send(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

    private:

      // ----------------------------------------------------------------------
      // To ports
      // ----------------------------------------------------------------------

      //! To port connected to send
      //!
      App::OutputEPSCmdPort m_to_send[1];

    private:

      // ----------------------------------------------------------------------
      // From ports
      // ----------------------------------------------------------------------

      //! From port connected to recv
      //!
      App::InputEPSCmdPort m_from_recv[1];

    private:

      // ----------------------------------------------------------------------
      // Static functions for output ports
      // ----------------------------------------------------------------------

      //! Static function for port from_recv
      //!
      static void from_recv_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U8 port, 
          Fw::Buffer &data, 
          U8 isSched 
      );

  };

} // end namespace Drv

#endif
