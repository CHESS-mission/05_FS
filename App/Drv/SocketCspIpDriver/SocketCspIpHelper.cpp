#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Assert.hpp>
#include <App/Drv/SocketCspIpDriver/SocketCspIpHelper.hpp>
#include <Fw/Logger/Logger.hpp>
#include <App/Config/SocketCspIpDriverCfg.hpp>



namespace Drv {

    // put network specific state we need to isolate here

    SocketCspIpHelper::SocketCspIpHelper() : m_port(0)
    {

    }

    SocketCspIpHelper::~SocketCspIpHelper() {
    }

    SocketCspStatus SocketCspIpHelper::configure(I32 address,const char* zmqHost){
        (void)strncpy(this->m_zmq_host,zmqHost,MAX_HOSTNAME_SIZE);
        csp_conf_get_defaults(&csp_conf);
        csp_conf.address = address;
        error = csp_init(&csp_conf);
        if (error != CSP_ERR_NONE) {
            return SOCK_INIT_FAILED;
        }
        
        csp_route_start_task(500, 0);

        default_iface = NULL;

        error = csp_zmqhub_init(csp_get_address(), "localhost", 0, &default_iface);
        if (error != CSP_ERR_NONE) {
                return SOCK_INTERFACE_ZMQ_FAILED;
            }
        csp_rtable_set(CSP_DEFAULT_ROUTE, 0, default_iface, CSP_NO_VIA_ADDRESS);
        csp_sleep_ms(1000);
        return SOCK_SUCCESS;
    }

    SocketCspStatus SocketCspIpHelper::open(I32 server_address){
        int ping = csp_ping(server_address, 1000, 100, CSP_O_NONE);
        if(ping < 0){
            return SOCK_CONNNECT_FAILED;
        }
        Fw::Logger::logMsg("Connection with EPC with CSP OK");
        conn = csp_connect(CSP_PRIO_NORM,server_address, UDPPort, 1000, CSP_O_NONE);
		if (conn == NULL) {
            return SOCK_CONNNECT_FAILED;
		}
        return SOCK_SUCCESS;
    }

    void SocketCspIpHelper::close(void){
        csp_close(conn);
    }

    SocketCspStatus SocketCspIpHelper::send(U8* data, const U32 size, Fw::Buffer& back_data){
		/* 5. Send packet */
        I32 returnSize = csp_transaction_persistent(conn,1000,data,size,back_data.getData(),-1);
		if (!returnSize){

            return SOCK_SEND_FAILED;
		}
        back_data.setSize(returnSize);
        return SOCK_SUCCESS;
    }

}