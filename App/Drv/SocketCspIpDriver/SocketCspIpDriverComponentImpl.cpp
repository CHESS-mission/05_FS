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

   SocketCspStatus SocketCspIpDriverComponentImpl::openSocket(I32 server_address){
        this->m_helper.open(server_address);
   }
      void SocketCspIpDriverComponentImpl::closeSocket(void){
        this->m_helper.close();
   }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void SocketCspIpDriverComponentImpl ::
    send_handler(
        const NATIVE_INT_TYPE portNum,
        U8 port,
        Fw::Buffer &data,
        U8 isSched
    )
  {
      U32 sizeBuffer = data.getSize();
      U8* dataBuffer = data.getData();
      FW_ASSERT(dataBuffer);

      this->m_helper.send_transaction(port,dataBuffer,sizeBuffer,outBuffer);
      recv_out(0, port, outBuffer,isSched);

  }

} // end namespace Drv
