// ======================================================================
// \title  EventAction/test/ut/Tester.hpp
// \author jonathan
// \brief  hpp file for EventAction test harness implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef TESTER_HPP
#define TESTER_HPP

#include "App/EventAction/EventActionComponentImpl.hpp"
#include "GTestBase.hpp"

namespace App {

class Tester : public EventActionGTestBase {
    #define MAX_EVENT_ARRAY_SIZE 2

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
    //! Add one entry to trigger sequence seq on event id
    void testAdd(U32 id, Fw::CmdStringArg &seq);
    //! Add one entry and remove it
    void testRemoveExisting(void);
    //! Remove an unexisting id (variant 1: list empty, 2: list filled)
    void testRemoveEmpty(void);
    void testRemoveUnexisting(void);
    //! Dump event-sequence entries (variant 1: empty, 2: 2 events registered)
    void testDumpEmpty(void);
    void testDump(void);
    //! Add new event but list is full
    void testAddFull(U32 maxSize);
    //! Add already existing id
    void testAddSame(void);
    //! Register sequence and received requested event
    void testEventSequence(void);

   private:
    // ----------------------------------------------------------------------
    // Handlers for typed from ports
    // ----------------------------------------------------------------------

    //! Handler for from_seqRun
    //!
    void from_seqRun_handler(
        const NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::EightyCharString &filename /*!< The sequence file*/
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
    EventActionComponentImpl component;
};

}  // end namespace App

#endif
