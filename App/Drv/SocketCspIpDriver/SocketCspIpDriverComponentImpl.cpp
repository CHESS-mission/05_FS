// ======================================================================
// \title  SocketCspIpDriverComponentImpl.cpp
// \author root
// \brief  cpp file for SocketCspIpDriver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <App/Drv/SocketCspIpDriver/SocketCspIpDriverComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include "csp/csp.h"
#include <csp/arch/csp_thread.h>
#include <csp/interfaces/csp_if_zmqhub.h>
#include <Fw/Types/Assert.hpp>

namespace Drv {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  SocketCspIpDriverComponentImpl ::
    SocketCspIpDriverComponentImpl(
        const char *const compName
    ) : SocketCspIpDriverComponentBase(compName), 
    outBuffer(outBufferData, sizeof(outBufferData))
  {

  }

  void SocketCspIpDriverComponentImpl ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    SocketCspIpDriverComponentBase::init(instance);
  }

  SocketCspIpDriverComponentImpl ::
    ~SocketCspIpDriverComponentImpl(void)
  {
    this->m_helper.close();
  }

  SocketCspStatus SocketCspIpDriverComponentImpl::configure(I32 address,const char* zmqHost){
      this->m_helper.configure(address,zmqHost);
    }

   SocketCspStatus SocketCspIpDriverComponentImpl::open(I32 server_address){
        this->m_helper.open(server_address);
   }
      void SocketCspIpDriverComponentImpl::close(void){
        this->m_helper.close();
   }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void SocketCspIpDriverComponentImpl ::
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
