// ======================================================================
// \title  SocketCspIpDriver/test/ut/Tester.hpp
// \author root
// \brief  hpp file for SocketCspIpDriver test harness implementation class
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
#include "App/Drv/SocketCspIpDriver/SocketCspIpDriverComponentImpl.hpp"

namespace Drv {

  class Tester :
    public SocketCspIpDriverGTestBase
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
      void testSendCmdPort7(void);
      void testSendSchedPort7(void);
      void testSendPing(void);

    private:

      // ----------------------------------------------------------------------
      // Handlers for typed from ports
      // ----------------------------------------------------------------------

      //! Handler for from_recv
      //!
      void from_recv_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U8 port, 
          Fw::Buffer &data, 
          U8 isSched 
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
      SocketCspIpDriverComponentImpl component;

  };

} // end namespace Drv

#endif