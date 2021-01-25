/**
 *  PUSopen(R) Mission Database
 *  
 *  THIS FILE HAS BEEN AUTOGENERATED.
 *  ANY MANUAL MODIFICATIONS MAY BE OVERWRITTEN.
 */

/* Include files */
#include "pusopen.h"

/* Included PUSopen(R) modules */

#define PUS1_PROVIDER
#define PUS3_PROVIDER
#define PUS5_PROVIDER
#define PUS8_PROVIDER
/* #define PUS13_PROVIDER */
#define PUS17_PROVIDER
/* #define PUS_USR */

/* PUSopen(R) configuration */

/* PUS 1 - Size of reception buffer (in bytes) */
#define PUS1_RECV_BUF_SIZE		2048

/* PUS 1 - Virtual Channel for TM[1,x] */
#define PUS1_VCID		1

/* PUS 3 - Size of buffer in which TM[3,25] report is composed (in bytes) */
#define PUS3_REPORT_BUF_SIZE		2048

/* PUS 17 - Virtual Channel for TM[17,x] */
#define PUS17_VCID		0

#define PS_LAYER

/* PS - Max size of sent packet (in bytes) */
#define PS_MAX_SEND_PACKET_SIZE		2048

/* PS - Max size of received packet (in bytes) */
#define PS_MAX_RECV_PACKET_SIZE		2048

/* PS - Checksum type */
#define PS_PKT_CHECKSUM_TYPE		PKT_ISO16

/* PS - Checksum length (in bytes) */
#define PS_PKT_CHECKSUM_LEN		2

#define FESS_LAYER

/* FESS - Size of send buffer (in bytes) */
#define FESS_SEND_BUF_SIZE		2048

/* FESS - Size of reception buffer (in bytes) */
#define FESS_RECV_BUF_SIZE		2048

/* FESS - Size of FESS temporary buffers (in bytes) */
#define FESS_TEMP_BUF_SIZE		2048

/* FESS - Attached Synchronization Mark (ASM) */
#define FESS_ASM		FESS_DEF_ASM

/* FESS - Length of ASM */
#define FESS_ASM_LEN		3

/* FESS - Frame encoding algorithm */
#define FESS_ENCODING		SLIP

/* FESS - Frame encryption algorithm */
#define FESS_ENCRYPTION		NOENCRYPTION

/* FESS - AES128 encryption key */
#define FESS_AES_KEY		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

/* FESS - AES128 initial vector */
#define FESS_AES_IV		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

/* PUS Service providers and user */

#ifdef PUS1_PROVIDER
PUS1_PROVIDER_INIT(pus1, PUS1_RECV_BUF_SIZE, PUS1_VCID);
#endif

#ifdef PUS3_PROVIDER
PUS3_PROVIDER_INIT(pus3, PUS3_REPORT_BUF_SIZE);
#endif

#ifdef PUS5_PROVIDER
PUS5_PROVIDER_INIT(pus5);
#endif

#ifdef PUS8_PROVIDER
PUS8_PROVIDER_INIT(pus8);
#endif

#ifdef PUS17_PROVIDER
PUS17_PROVIDER_INIT(pus17, PUS17_VCID);
#endif

/* Packet Services */

#ifdef PS_LAYER
PS_INIT(ps, PS_MAX_SEND_PACKET_SIZE, PS_MAX_RECV_PACKET_SIZE, PS_PKT_CHECKSUM_TYPE, PS_PKT_CHECKSUM_LEN);
#endif


/* FESS Layer */

#ifdef FESS_LAYER
FESS_INIT(fess, FESS_ASM, FESS_ASM_LEN, FESS_ENCODING, FESS_ENCRYPTION, FESS_SEND_BUF_SIZE, FESS_RECV_BUF_SIZE, FESS_TEMP_BUF_SIZE, FESS_TEMP_BUF_SIZE, FESS_TEMP_BUF_SIZE, FESS_TEMP_BUF_SIZE, FESS_AES_KEY, FESS_AES_IV);
#endif

/* User Code */


#include "hk_param.h"

extern po_result_t UserPus8Fn(uint8_t fid, uint8_t *data, uint16_t len);

extern struct s_PARAM PARAM;
  

/* On-board Events */

po_evt_t evt[] = {
   {
       .id = 1U,
       .level = PUS5_EVT_INFO,
       .desc = "Information event",
       .dataLen = 1102U,
       .vcid = 1U
   },
   {
       .id = 2U,
       .level = PUS5_EVT_LOW,
       .desc = "Low severity anomaly",
       .dataLen = 1102U,
       .vcid = 1U
   },
   {
       .id = 3U,
       .level = PUS5_EVT_MEDIUM,
       .desc = "Medium severity anomaly",
       .dataLen = 1102U,
       .vcid = 1U
   },
   {
       .id = 4U,
       .level = PUS5_EVT_HIGH,
       .desc = "High severity anomaly",
       .dataLen = 1102U,
       .vcid = 1U
   }
};

/* User Functions */
extern po_result_t UserPus8Fn(uint8_t functionid, uint8_t *data, uint16_t len);

po_fnc_t fnc[] = {
   {
       .id = 1U,
       .name = "Test function",
       .desc = "Example test function",
       .addr = &UserPus8Fn
   }
};

/* HK Parameters */

po_obparam_t obparams[] = {
#ifdef FESS_LAYER
PO_MDB_PARAMS_FESS
#endif
#ifdef PS_LAYER
PO_MDB_PARAMS_PS
#endif
#ifdef VC_LAYER
PO_MDB_PARAMS_VC
#endif
#ifdef PUS1_PROVIDER
PO_MDB_PARAMS_PUS1
#endif
#ifdef PUS3_PROVIDER
PO_MDB_PARAMS_PUS3
#endif
#ifdef PUS5_PROVIDER
PO_MDB_PARAMS_PUS5
#endif
#ifdef PUS8_PROVIDER
PO_MDB_PARAMS_PUS8
#endif
#ifdef PUS13_PROVIDER
PO_MDB_PARAMS_PUS13
#endif
#ifdef PUS17_PROVIDER
PO_MDB_PARAMS_PUS17
#endif
#ifdef PUS_USR
PO_MDB_PARAMS_PUSUSR
#endif
   {
       .id = 41U,
       .name = "PR_NumPings",
       .desc = "Number of pings received",
       .type = PO_UINT32,
       .addr = &PARAM.PR_NumPings
   },
   {
       .id = 121U,
       .name = "CommandsDispatched",
       .desc = "Number of commands dispatched",
       .type = PO_UINT32,
       .addr = &PARAM.CommandsDispatched
   },
   {
       .id = 122U,
       .name = "CommandErrors",
       .desc = "Number of command errors",
       .type = PO_UINT32,
       .addr = &PARAM.CommandErrors
   },
   {
       .id = 361U,
       .name = "PingLateWarnings",
       .desc = "Number of overrun warnings",
       .type = PO_UINT32,
       .addr = &PARAM.PingLateWarnings
   },
   {
       .id = 481U,
       .name = "BD_Cycles",
       .desc = "Driver cycle count",
       .type = PO_UINT32,
       .addr = &PARAM.BD_Cycles
   },
   {
       .id = 1071U,
       .name = "EPS_Voltage_battery_mV",
       .desc = "Voltage",
       .type = PO_UINT32,
       .addr = &PARAM.EPS_Voltage_battery_mV
   },
   {
       .id = 1072U,
       .name = "EPS_Battery_mode",
       .desc = "Battery mode",
       .type = PO_UINT32,
       .addr = &PARAM.EPS_Battery_mode
   },
   {
       .id = 1073U,
       .name = "EPS_Temp_Battery_Celsuis",
       .desc = "Battery Temp",
       .type = PO_UINT32,
       .addr = &PARAM.EPS_Temp_Battery_Celsuis
   }
};

/* HK Reports */

po_hkreport_t hkreps[] = {
   {
       .id = 1U,
       .name = "Report #1",
       .desc = "Report #1 description",
       .enabled = POTRUE,
       .interval = 5U,
       .sinceLast = 0U,
       .destApid = 3U,
       .vcid = 0U,
       .numHk = 8U,
       .obparams = { 41,121,122,361,481,1071,1072,1073 }
   }
};

/* PUSopen(R) Mission Database */

po_mdbapid_t po_mdb_apid = {
    .apid = 1,
    .apuid = 2,

    .pus1  = POADDR(pus1),
    .pus3  = POADDR(pus3),
    .pus5  = POADDR(pus5),
    .pus8  = POADDR(pus8),
    .pus13 = PONULL,
    .pus17  = POADDR(pus17),
    .pusUsr = PONULL,
    .ps  = POADDR(ps),
    .vc = PONULL,
    .fess  = POADDR(fess),

    .numevt = 4U,
    .numparams = 49U,
    .numreports = 1U,
    .numfct = 1U,
    .events = evt,
    .obparams = obparams,
    .func = fnc,
    .hkreports = hkreps
};

/**
 *  Default implementation of pususr_tm to satisfy
 *  dependencies if PUS Service User is not used.
 */
#ifndef PUS_USR
EMPTY_PUSUSR_TM
#endif

/**
 *  Default implementation of po_time to satisfy
 *  dependencies if user does not implement po_time.
 */
#ifndef PUS_CUSTOM_TIME
EMPTY_PO_TIME
#endif

/**
 *  Default implementation of po_tc to satisfy
 *  dependencies if user does not implement po_tc.
 */
#ifndef PUS_CUSTOM_SERVICES
EMPTY_PO_TC
#endif

/**
 *  Default implementation of pus13_tc to satisfy
 *  dependencies if user does not implement pus13_tc.
 */
#ifndef PUS13_PROVIDER
EMPTY_PUS13_TC
#endif

/**
 *  Default implementation Subnetwork functions
 *  to satisfy libps dependencies.
 */
#ifdef NO_SUBNET
EMPTY_SUBNET
#endif

/* MDB format version */
#define MDB_VERSION		1
