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

namespace App {

  class EventActionComponentImpl :
    public EventActionComponentBase
  {

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
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object EventAction
      //!
      ~EventActionComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for seqResp
      //!
      void seqResp_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwOpcodeType opCode, /*!< Command Op Code*/
          U32 cmdSeq, /*!< Command Sequence*/
          Fw::CommandResponse response /*!< The command response argument*/
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for EVAC_RUN command handler
      //! Run sequence
      void EVAC_RUN_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );


    };

} // end namespace App

#endif
