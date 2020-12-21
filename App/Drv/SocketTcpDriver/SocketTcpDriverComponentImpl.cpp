// ======================================================================
// \title  SocketTcpDriverComponentImpl.cpp
// \author root
// \brief  cpp file for SocketTcpDriver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <App/Drv/SocketTcpDriver/SocketTcpDriverComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include <Fw/Types/Assert.hpp>
#include <Fw/Logger/Logger.hpp>

namespace Drv {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  SocketTcpDriverComponentImpl ::
    SocketTcpDriverComponentImpl(
        const char *const compName
    ) : SocketTcpDriverComponentBase(compName),
     outBuffer(outBufferData, sizeof(outBuffer))
  {

  }

  void SocketTcpDriverComponentImpl ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    SocketTcpDriverComponentBase::init(instance);
  }

  SocketTcpDriverComponentImpl ::
    ~SocketTcpDriverComponentImpl(void)
  {

  }

    SocketIpStatus SocketTcpDriverComponentImpl :: configure(
          const char* hostname,
          U16 port,
          const U32 timeout_seconds,
          const U32 timeout_microseconds
          ) {
      return this->m_helper.configure(hostname,port,timeout_seconds,timeout_microseconds);
  }

   SocketIpStatus SocketTcpDriverComponentImpl :: openSocket(void){
     return this->m_helper.open();
   }

   void SocketTcpDriverComponentImpl :: closeSocket(void){
           this->m_helper.close();
   }
  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void SocketTcpDriverComponentImpl ::
    send_handler(
        const NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
      U32 size = fwBuffer.getSize();
      U8* data = fwBuffer.getData();
      FW_ASSERT(data);
      this->m_helper.send(data,size,outBuffer);
      recv_out(0, outBuffer);
  }

} // end namespace Drv
