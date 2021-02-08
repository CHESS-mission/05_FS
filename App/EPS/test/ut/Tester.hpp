// ======================================================================
// \title  EPS/test/ut/Tester.hpp
// \author root
// \brief  hpp file for EPS test harness implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef TESTER_HPP
#define TESTER_HPP

#include "GTestBase.hpp"
#include "App/EPS/EPSComponentImpl.hpp"

namespace App {

  class Tester :
    public EPSGTestBase
  {

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

    public:

      //! Construct object Tester
      //!
      Tester(void);

      //! Destroy object Tester
      //!
      ~Tester(void);

    public:

      // ----------------------------------------------------------------------
      // Tests
      // ----------------------------------------------------------------------

      //! To do
      //!
      void cmdCmdGoodpayloadGoodPort(void);
      void cmdCmdbadPayload(void);
      /*void cmdCmdbadPort(void);*/
      void portStatusOKSched(void);
      void portStatusOKNoSched(void);
      void portStatusNOK(void);
      void portTestLowVolt(void);
      void portTestHighTemp(void);
      void portChangeMode(void);

      void portPingIn(void);
      void portPingOk(void);
      void portPingNOK(void);

    private:

      // ----------------------------------------------------------------------
      // Handlers for typed from ports
      // ----------------------------------------------------------------------

      //! Handler for from_DataOut
      //!
      void from_DataOut_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U8 port, 
          Fw::Buffer &data, 
          U8 isSched 
      );

      //! Handler for from_PingOut
      //!
      void from_PingOut_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 key /*!< Value to return to pinger*/
      );

    private:

      // ----------------------------------------------------------------------
      // Helper methods
      // ----------------------------------------------------------------------

      //! Connect ports
      //!
      void connectPorts(void);

      //! Initialize components
      //!
      void initComponents(void);

    private:

      // ----------------------------------------------------------------------
      // Variables
      // ----------------------------------------------------------------------

      //! The component under test
      //!
      EPSComponentImpl component;

  };

} // end namespace App

#endif
