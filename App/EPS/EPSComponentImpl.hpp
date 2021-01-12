// ======================================================================
// \title  EPSComponentImpl.hpp
// \author root
// \brief  hpp file for EPS component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef EPS_HPP
#define EPS_HPP

#include "App/EPS/EPSComponentAc.hpp"

namespace App {

  class EPSComponentImpl :
    public EPSComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object EPS
      //!
      EPSComponentImpl(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object EPS
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object EPS
      //!
      ~EPSComponentImpl(void);



    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for DataIn
      //!
      void DataIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U8 port, 
          Fw::Buffer &data,
          U8 isSched
      );

      //! Handler implementation for Schedin
      //!
      void Schedin_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for MS_SEND_CMD command handler
      //! Send CMD to EPS
      void MS_SEND_CMD_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          EPSOp operation, /*!< operation argument*/
          const Fw::CmdStringArg& payload /*!< The payload data*/
      );

       //! Implementation for MS_SEND_PING command handler
      //! Send Ping to EPS
      void MS_SEND_PING_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );

      Fw::Buffer dataSendCmdBuffer;
      U8 battMode = 2;

          
      void stringToHex (const char*, U8[]);
      void hexToString (char*, U8[], U16 size);
      bool isPayloadOK(const char*,NATIVE_UINT_TYPE);
      U32 bytesToInt (U8* bytes);
    };


} // end namespace App

#endif
