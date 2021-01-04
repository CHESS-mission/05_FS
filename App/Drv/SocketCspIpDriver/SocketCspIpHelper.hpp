#ifndef DRV_SOCKETCSPIPDRIVER_SOCKETHELPER_HPP_
#define DRV_SOCKETCSPIPDRIVER_SOCKETHELPER_HPP_

#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <App/Drv/SocketCspIpDriver/ScoketCspDriverType.hpp>
#include <App/Config/SocketCspIpDriverCfg.hpp>
#include "csp/csp.h"
#include <csp/arch/csp_thread.h>
#include <csp/interfaces/csp_if_zmqhub.h>


namespace Drv {

    class SocketCspIpHelper {
        public:

            SocketCspIpHelper();
            virtual ~SocketCspIpHelper();
            SocketCspStatus configure(
                        I32 address,
                        const char* zmqHost
                    );
            SocketCspStatus open(I32 server_address);
            SocketCspStatus send(U8* data, const U32 size, Fw::Buffer& back_data); //Forwards to sendto, which on some OSes requires a non-const data pointer
            SocketCspStatus send_transaction(U8 port,U8* data, const U32 size, Fw::Buffer& back_data); //Forwards to sendto, which on some OSes requires a non-const data pointer

            void close(void);

        PRIVATE:

            csp_conf_t csp_conf;
            char m_zmq_host[MAX_HOSTNAME_SIZE]; //!< Hostname to supply
            I32  m_port; 
            U8   m_address;
            
            I32 error;             //!< IP address port used
            csp_iface_t* default_iface;
            csp_conn_t * conn;

    };

}

#endif /* DRV_SOCKETIPDRIVER_SOCKETHELPER_HPP_ */
