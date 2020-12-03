// ======================================================================
// \title  ADCSComponentImpl.hpp
// \author root
// \brief  hpp file for ADCS component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef ADCS_HPP
#define ADCS_HPP

#include "App/ADCS/ADCSComponentAc.hpp"

namespace App {

  class ADCSComponentImpl :
    public ADCSComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object ADCS
      //!
      ADCSComponentImpl(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object ADCS
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object ADCS
      //!
      ~ADCSComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for DataIn
      //!
      void DataIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Buffer &fwBuffer 
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for MS_GET_TM command handler
      //! Send telemetry to ADCS
      void MS_GET_TM_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          U8 id /*!< The telemetry id*/
      );


      Fw::Buffer dataSendTmBuffer; /*< buffer to send data to Driver */
      U8* TmPacket;

    };

} // end namespace App

#endif
