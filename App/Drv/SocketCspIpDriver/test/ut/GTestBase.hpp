// ======================================================================
// \title  SocketCspIpDriver/test/ut/GTestBase.hpp
// \author Auto-generated
// \brief  hpp file for SocketCspIpDriver component Google Test harness base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef SocketCspIpDriver_GTEST_BASE_HPP
#define SocketCspIpDriver_GTEST_BASE_HPP

#include "TesterBase.hpp"
#include "gtest/gtest.h"

// ----------------------------------------------------------------------
// Macros for typed user from port history assertions
// ----------------------------------------------------------------------

#define ASSERT_FROM_PORT_HISTORY_SIZE(size) \
  this->assertFromPortHistory_size(__FILE__, __LINE__, size)

#define ASSERT_from_recv_SIZE(size) \
  this->assert_from_recv_size(__FILE__, __LINE__, size)

#define ASSERT_from_recv(index, _port, _data, _isSched) \
  { \
    ASSERT_GT(this->fromPortHistory_recv->size(), static_cast<U32>(index)) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Index into history of from_recv\n" \
    << "  Expected: Less than size of history (" \
    << this->fromPortHistory_recv->size() << ")\n" \
    << "  Actual:   " << index << "\n"; \
    const FromPortEntry_recv& _e = \
      this->fromPortHistory_recv->at(index); \
    ASSERT_EQ(_port, _e.port) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument port at index " \
    << index \
    << " in history of from_recv\n" \
    << "  Expected: " << _port << "\n" \
    << "  Actual:   " << _e.port << "\n"; \
    ASSERT_EQ(_data, _e.data) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument data at index " \
    << index \
    << " in history of from_recv\n" \
    << "  Expected: " << _data << "\n" \
    << "  Actual:   " << _e.data << "\n"; \
    ASSERT_EQ(_isSched, _e.isSched) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument isSched at index " \
    << index \
    << " in history of from_recv\n" \
    << "  Expected: " << _isSched << "\n" \
    << "  Actual:   " << _e.isSched << "\n"; \
  }

namespace Drv {

  //! \class SocketCspIpDriverGTestBase
  //! \brief Auto-generated base class for SocketCspIpDriver component Google Test harness
  //!
  class SocketCspIpDriverGTestBase :
    public SocketCspIpDriverTesterBase
  {

    protected:

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

      //! Construct object SocketCspIpDriverGTestBase
      //!
      SocketCspIpDriverGTestBase(
#if FW_OBJECT_NAMES == 1
          const char *const compName, /*!< The component name*/
          const U32 maxHistorySize /*!< The maximum size of each history*/
#else
          const U32 maxHistorySize /*!< The maximum size of each history*/
#endif
      );

      //! Destroy object SocketCspIpDriverGTestBase
      //!
      virtual ~SocketCspIpDriverGTestBase(void);

    protected:

      // ----------------------------------------------------------------------
      // From ports
      // ----------------------------------------------------------------------

      void assertFromPortHistory_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // From port: recv
      // ----------------------------------------------------------------------

      void assert_from_recv_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

  };

} // end namespace Drv

#endif
