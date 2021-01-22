#include <Components.hpp>
#include <Fw/Types/Assert.hpp>
#include <Os/Task.hpp>
#include <Fw/Logger/Logger.hpp>
#include <Os/Log.hpp>
#include <Fw/Types/MallocAllocator.hpp>
#include <Os/Mutex.hpp>
#include "hk_param.h"

#if (defined TGT_OS_TYPE_LINUX) || (defined TGT_OS_TYPE_DARWIN)
#include <getopt.h>
#include <stdlib.h>
#include <ctype.h>
#endif

// List of context IDs
enum
{
    DOWNLINK_PACKET_SIZE = 500,
    DOWNLINK_BUFFER_STORE_SIZE = 2500,
    DOWNLINK_BUFFER_QUEUE_SIZE = 5,
    UPLINK_BUFFER_STORE_SIZE = 3000,
    UPLINK_BUFFER_QUEUE_SIZE = 30
};

Os::Log osLogger;

#ifdef _PUS
Os::Mutex PO_STACK_MUTEX; /*!< Protect access to PUSOpen stack */

s_PARAM PARAM;
#endif

// Registry
#if FW_OBJECT_REGISTRATION == 1
static Fw::SimpleObjRegistry simpleReg;
#endif

// Component instance pointers
static NATIVE_INT_TYPE rgDivs[Svc::RateGroupDriverImpl::DIVIDER_SIZE] = {1, 2, 4};
Svc::RateGroupDriverImpl rateGroupDriver(FW_OPTIONAL_NAME("RGDvr"), rgDivs, FW_NUM_ARRAY_ELEMENTS(rgDivs));

static NATIVE_UINT_TYPE rg1Context[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
Svc::ActiveRateGroupImpl rateGroup1(FW_OPTIONAL_NAME("RG1"), rg1Context, FW_NUM_ARRAY_ELEMENTS(rg1Context));

static NATIVE_UINT_TYPE rg2Context[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
Svc::ActiveRateGroupImpl rateGroup2(FW_OPTIONAL_NAME("RG2"), rg2Context, FW_NUM_ARRAY_ELEMENTS(rg2Context));

static NATIVE_UINT_TYPE rg3Context[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
Svc::ActiveRateGroupImpl rateGroup3(FW_OPTIONAL_NAME("RG3"), rg3Context, FW_NUM_ARRAY_ELEMENTS(rg3Context));

// Command Components
Svc::GroundInterfaceComponentImpl groundIf(FW_OPTIONAL_NAME("GNDIF"));

// Driver Component
Drv::BlockDriverImpl blockDrv(FW_OPTIONAL_NAME("BDRV"));

#if FW_ENABLE_TEXT_LOGGING
Svc::ConsoleTextLoggerImpl textLogger(FW_OPTIONAL_NAME("TLOG"));
#endif

Svc::ActiveLoggerImpl eventLogger(FW_OPTIONAL_NAME("ELOG"));

Svc::LinuxTimeImpl linuxTime(FW_OPTIONAL_NAME("LTIME"));

Svc::TlmChanImpl chanTlm(FW_OPTIONAL_NAME("TLM"));

Svc::CommandDispatcherImpl cmdDisp(FW_OPTIONAL_NAME("CMDDISP"));

Fw::MallocAllocator seqMallocator;
Svc::CmdSequencerComponentImpl cmdSeq(FW_OPTIONAL_NAME("CMDSEQ"));

Svc::PrmDbImpl prmDb(FW_OPTIONAL_NAME("PRM"), "PrmDb.dat");

Ref::PingReceiverComponentImpl pingRcvr(FW_OPTIONAL_NAME("pingRcvr"));

Drv::SocketIpDriverComponentImpl socketIpDriver(FW_OPTIONAL_NAME("socketIpDriver"));

Svc::FileUplink fileUplink(FW_OPTIONAL_NAME("fileUplink"));

Svc::FileDownlink fileDownlink(FW_OPTIONAL_NAME("fileDownlink"), DOWNLINK_PACKET_SIZE);

Svc::FileManager fileManager(FW_OPTIONAL_NAME("fileManager"));

Svc::BufferManager fileDownlinkBufferManager(FW_OPTIONAL_NAME("fileDownlinkBufferManager"), DOWNLINK_BUFFER_STORE_SIZE, DOWNLINK_BUFFER_QUEUE_SIZE);

Svc::BufferManager fileUplinkBufferManager(FW_OPTIONAL_NAME("fileUplinkBufferManager"), UPLINK_BUFFER_STORE_SIZE, UPLINK_BUFFER_QUEUE_SIZE);

Svc::HealthImpl health(FW_OPTIONAL_NAME("health"));

Svc::AssertFatalAdapterComponentImpl fatalAdapter(FW_OPTIONAL_NAME("fatalAdapter"));

Svc::FatalHandlerComponentImpl fatalHandler(FW_OPTIONAL_NAME("fatalHandler"));

App::EventActionComponentImpl eventAction(FW_OPTIONAL_NAME("eventAction"));

App::ADCSComponentImpl ADCS(FW_OPTIONAL_NAME("ADCS"));

Drv::SocketTcpDriverComponentImpl socketTcpDriverADCS(FW_OPTIONAL_NAME("SocketTcpDriverADCS"));

App::EPSComponentImpl EPS(FW_OPTIONAL_NAME("EPS"));

Drv::SocketCspIpDriverComponentImpl socketCspIpDriverEPS(FW_OPTIONAL_NAME("SocketCspIpDriverEPS"));


const char* getHealthName(Fw::ObjBase& comp) {
   #if FW_OBJECT_NAMES == 1
       return comp.getObjName();
   #else
      return "[no object name]"
   #endif
}

bool constructApp(bool dump, U32 port_number, char *hostname)
{

#if FW_PORT_TRACING
    Fw::PortBase::setTrace(false);
#endif

    // Initialize rate group driver
    rateGroupDriver.init();

    // Initialize the rate groups
    rateGroup1.init(10, 0);

    rateGroup2.init(10, 1);

    rateGroup3.init(10, 2);

    // Initialize block driver
    blockDrv.init(10);

#if FW_ENABLE_TEXT_LOGGING
    textLogger.init();
#endif

    eventLogger.init(10, 0);

    linuxTime.init(0);

    chanTlm.init(10, 0);

    cmdDisp.init(20, 0);

    cmdSeq.init(10, 0);
    cmdSeq.allocateBuffer(0, seqMallocator, 5 * 1024);

    prmDb.init(10, 0);

    groundIf.init(0);
    socketIpDriver.init(0);

    socketTcpDriverADCS.init(0);
    
    socketCspIpDriverEPS.init(0);

    fileUplink.init(30, 0);
    fileDownlink.init(30, 0);
    fileManager.init(30, 0);
    fileUplinkBufferManager.init(0);
    fileDownlinkBufferManager.init(1);

    fatalAdapter.init(0);
    fatalHandler.init(0);
    health.init(25, 0);
    pingRcvr.init(10);

    eventAction.init(10);
    ADCS.init(10,0);
    EPS.init(10,0);

    // Connect rate groups to rate group driver
    constructAppArchitecture();

    // dump topology if requested
    if (dump)
    {
#if FW_OBJECT_REGISTRATION == 1
        simpleReg.dump();
#endif
        return true;
    }

    /* Register commands */
    cmdSeq.regCommands();
    cmdDisp.regCommands();
    eventLogger.regCommands();
    prmDb.regCommands();
    fileDownlink.regCommands();
    fileManager.regCommands();
	health.regCommands();
	pingRcvr.regCommands();
    eventAction.regCommands();
    ADCS.regCommands();
    EPS.regCommands();

    // read parameters
    // prmDb.readParamFile();

    // set health ping entries
    // warnCycles, fatalCycles, entryName
    Svc::HealthImpl::PingEntry pingEntries[] = {// health PingSend/PingReturn port number
        {3, 5, getHealthName(rateGroup1)},      // 0
        {3, 5, getHealthName(rateGroup2)},      // 1
        {3, 5, getHealthName(rateGroup3)},      // 2
        {3, 5, getHealthName(cmdDisp)},         // 3
        {3, 5, getHealthName(eventLogger)},     // 4
        {3, 5, getHealthName(cmdSeq)},          // 5
        {3, 5, getHealthName(chanTlm)},         // 6
        {3, 5, getHealthName(prmDb)},           // 7
        {3, 5, getHealthName(fileUplink)},      // 8
        {3, 5, getHealthName(fileDownlink)},    // 9
        {3, 5, getHealthName(pingRcvr)},        // 10
        {3, 5, getHealthName(blockDrv)},        // 11
        {3, 5, getHealthName(fileManager)},     // 12
        {3, 5, getHealthName(EPS)},             // 13
    };

    // register ping table
    health.setPingEntries(pingEntries, FW_NUM_ARRAY_ELEMENTS(pingEntries), 0x123);

    // Active component startup
    // start rate groups
    rateGroup1.start(0, 120, 10 * 1024);
    rateGroup2.start(0, 119, 10 * 1024);
    rateGroup3.start(0, 118, 10 * 1024);
    // start driver
    blockDrv.start(0, 140, 10 * 1024);
    // start dispatcher
    cmdDisp.start(0, 101, 10 * 1024);
    // start sequencer
    cmdSeq.start(0, 100, 10 * 1024);
    // start telemetry
    eventLogger.start(0, 98, 10 * 1024);
    chanTlm.start(0, 97, 10 * 1024);
    prmDb.start(0, 96, 10 * 1024);

    fileDownlink.start(0, 100, 10 * 1024);
    fileUplink.start(0, 100, 10 * 1024);
    fileManager.start(0, 100, 10 * 1024);

    pingRcvr.start(0, 100, 10 * 1024);

    eventAction.start(0, 100, 10*1024);

    ADCS.start(0, 100, 10*1024);
    EPS.start(0, 100, 0*1024);

    // Initialize socket server if and only if there is a valid specification
    if (hostname != NULL && port_number != 0)
    {
        socketIpDriver.startSocketTask(100, 10 * 1024, hostname, port_number);
    }

    socketTcpDriverADCS.configure("127.0.0.1",5005,1,0);
    socketTcpDriverADCS.openSocket();

    socketCspIpDriverEPS.configure(10,"localhost");
    socketCspIpDriverEPS.openSocket(27);

    return false;
}

void exitTasks(void)
{
    rateGroup1.exit();
    rateGroup2.exit();
    rateGroup3.exit();
    blockDrv.exit();
    cmdDisp.exit();
    eventLogger.exit();
    chanTlm.exit();
    prmDb.exit();
    fileUplink.exit();
    fileDownlink.exit();
    fileManager.exit();
    cmdSeq.exit();
    pingRcvr.exit();
    eventAction.exit();
    ADCS.exit();
    EPS.exit();
    // join the component threads with NULL pointers to free them
    (void) rateGroup1.ActiveComponentBase::join(NULL);
    (void) rateGroup2.ActiveComponentBase::join(NULL);
    (void) rateGroup3.ActiveComponentBase::join(NULL);
    (void) blockDrv.ActiveComponentBase::join(NULL);
    (void) cmdDisp.ActiveComponentBase::join(NULL);
    (void) eventLogger.ActiveComponentBase::join(NULL);
    (void) chanTlm.ActiveComponentBase::join(NULL);
    (void) prmDb.ActiveComponentBase::join(NULL);
    (void) fileUplink.ActiveComponentBase::join(NULL);
    (void) fileDownlink.ActiveComponentBase::join(NULL);
    (void) fileManager.ActiveComponentBase::join(NULL);
    (void) cmdSeq.ActiveComponentBase::join(NULL);
    (void) pingRcvr.ActiveComponentBase::join(NULL);
    (void) eventAction.ActiveComponentBase::join(NULL);
    (void) ADCS.ActiveComponentBase::join(NULL);
    (void) EPS.ActiveComponentBase::join(NULL);
    socketIpDriver.exitSocketTask();
    (void)socketIpDriver.joinSocketTask(NULL);
    cmdSeq.deallocateBuffer(seqMallocator);
    socketTcpDriverADCS.closeSocket();
    socketCspIpDriverEPS.closeSocket();
}
