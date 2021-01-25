    /**
     *  @file     main_gs.c
     *  @brief    Simple GS with PUS support for testing purpose
     */

    /**
    To compile GS mdb:
    ../../bin/poconfig.exe mdb_gs.xml mdb_gs.c

    To compile GS:
    > cmake .
    > make
    **/
    //-- Includes -- 

    #include <stdio.h>
    #include <string>
    #include <byteswap.h>
    #include <assert.h>

    #include "clientserver.h"

    #include "pusopen.h"
    #include "hk_param.h"

    #include <Fw/Com/ComBuffer.hpp>
    #include <Fw/Log/LogPacket.hpp>
    #include <Fw/Types/BasicTypes.hpp>

    // Chose what is sent to 
    //#define SEND_TC_17_1
    //#define SEND_TC_17_3
    #define SEND_TC_8_1_NOOP
    //#define SEND_TC_8_1_ADCS

    using namespace std;

    struct s_PARAM hk_param;

    U8 stop = 0;

    // PUSopen(R) callback for telemetry (TM) reception 
    po_result_t pususr_tm(po_tmdesc_t * tm) {
        U16 i = 0U;

        printf("TM[%2u,%2u] Dest APID: %2u, flags: %u, count: %4u, payload: %2u bytes \n",
            tm->service, tm->subservice, tm->destid, tm->pktSeqFlags, tm->pktSeqCount, tm->dataLen);

        if(tm->service == 3 && tm->subservice == 25) {  // TM[3, 25] Hk Report
            /*/ Print raw data
            for (i = 0U; i < tm->dataLen; i++) {
                printf("%02x ", tm->data[i]);
            }
            printf("\n");
            //*/

            if(tm->data[0] == 1) {   // HK report 1
                U32* dataPtr = (U32*)&tm->data[1]; 
                U32* structPtr = (U32*)&hk_param;

                // Put received data in local hk structure
                U16 i = 0;
                for (i = 0; i < PO_PARAM_SIZE; i++) {
                    *(structPtr + i) = *(dataPtr + i);
                }

                // Reverse endianness
                hk_param.PR_NumPings = 
                    __bswap_32(hk_param.PR_NumPings);
                hk_param.CommandsDispatched = 
                    __bswap_32(hk_param.CommandsDispatched);
                hk_param.CommandErrors = 
                    __bswap_32(hk_param.CommandErrors);
                hk_param.PingLateWarnings = 
                    __bswap_32(hk_param.PingLateWarnings);
                hk_param.BD_Cycles = 
                    __bswap_32(hk_param.BD_Cycles);
                hk_param.EPS_Voltage_battery_mV = 
                    __bswap_32(hk_param.EPS_Voltage_battery_mV);
                hk_param.EPS_Battery_mode = 
                    __bswap_32(hk_param.EPS_Battery_mode);
                hk_param.EPS_Temp_Battery_Celsuis = 
                    __bswap_32(hk_param.EPS_Temp_Battery_Celsuis);

                printf("\t======= Report #1 =======\n");
                printf("\tPR_NumPings=%u \n", hk_param.PR_NumPings);
                printf("\tCommandsDispatched=%u \n", hk_param.CommandsDispatched);
                printf("\tCommandErrors=%u \n", hk_param.CommandErrors);
                printf("\tPingLateWarnings=%u \n", hk_param.PingLateWarnings);
                printf("\tBD_Cycles=%u \n", hk_param.BD_Cycles);
                printf("\tEPS_Voltage_battery_mV=%u \n", hk_param.EPS_Voltage_battery_mV);
                printf("\tEPS_Battery_mode=%u \n", hk_param.EPS_Battery_mode);
                printf("\tEPS_Temp_Battery_Celsuis=%u \n", hk_param.EPS_Temp_Battery_Celsuis);
                printf("\t=========================\n");
            }
        } else if(tm->service == 5) {   // TM[5,x] Event report
            string severity[4] = { "PUS5_EVT_INFO", "PUS5_EVT_LOW" ,"PUS5_EVT_MEDIUM" ,"PUS5_EVT_HIGH" };

            // Get comBuffer and extract logPkt
            Fw::ComBuffer comBuffer(tm->data, tm->dataLen-2);   // @todo Serializabled or not ?? 

            Fw::LogPacket logPkt;
            Fw::SerializeStatus stat = logPkt.deserialize(comBuffer);

            if (stat != Fw::FW_SERIALIZE_OK) {
                printf("\tError deserializing : %u\n", stat);
                assert(0);
            } else {
                U32 eventId = logPkt.getId();
                Fw::LogBuffer logBuffer(logPkt.getLogBuffer());

                printf("\n\t======= EVENT REPORT =======\n");
                printf("\tSeverity=%s\n", severity[tm->subservice - 1].c_str());
                printf("\tId=%u (0x%x)\n", eventId, eventId);

                U8 argU8;
                U32 argU32;
                I32 argI32;
                switch(eventId) {
                    case 0x16:  // RateGroupCycleSlip
                        printf("\tEvent=RateGroupCycleSlip\n");
                        logBuffer.deserialize(argU32);
                        printf("\t\tcycle: %u\n", argU32);
                        break;
                    case 0x2a:  // PR_PingReceived
                        printf("\tEvent=PR_PingReceived\n");
                        logBuffer.deserialize(argU32);
                        printf("\t\tcode: %u\n", argU32);
                        break;
                    case 0x7a:  // OpCodeDispatched
                        printf("\tEvent=OpCodeDispatched\n");
                        logBuffer.deserialize(argU32);
                        printf("\t\tOpcode: %u\n", argU32);
                        logBuffer.deserialize(argI32);
                        printf("\t\tport: %d\n", argI32);
                        break;
                    case 0x7b:  // OpCodeCompleted
                        printf("\tEvent=OpCodeCompleted\n");
                        logBuffer.deserialize(argU32);
                        printf("\t\tOpcode: %u\n", argU32);
                        break;
                    case 0x169: // HLTH_PING_WARN
                        printf("\tEvent=HLTH_PING_WARN\n");
                        printf("\t\tentry: -- string not supported --\n");
                    case 0x431: // MS_CMD_ERROR
                        printf("\tEvent=MS_CMD_ERROR\n");
                        logBuffer.deserialize(argU8);
                        printf("\t\tport: %u\n", argU8);
                        logBuffer.deserialize(argU8);
                        printf("\t\tcmd: %u\n", argU8);
                        logBuffer.deserialize(argU8);
                        printf("\t\tstatus: %u\n", argU8);
                        break;
                    default:
                        printf("\tEvent= -- Uknown -- \n");
                }

            }
            printf("\t============================\n");

        } else {
            printf("\n");
        }

        return PO_SUCCESS;
    }

    int main(int argc, const char* argv[])
    {
        // Received byte 
        U8 data;

        // Transmission buffer 
        U8 buf[128];
        U16 len;
        U8 dataCMDNOOPPUS8[] = {
                1U,         /* 1st byte = Function ID */
                0xde,       /* 2nd byte onward = custom data */
                0xad,
                0xbe,
                0xef,
                0x00,
                0x00,
                0x00,
                0x08,
                0x00,
                0x00,
                0x00,
                0x00,
                0x00,
                0x00,
                0x00,
                0x79,
                0xca,
                0xfe,
                0xca,
                0xfe};

        U8 dataADCSTMPUS8[] = {
                1U,         /* 1st byte = Function ID */
                0xde,       /* 2nd byte onward = custom data */
                0xad,
                0xbe,
                0xef,
                0x00,
                0x00,
                0x00,
                0x09,
                0x00,
                0x00,
                0x00,
                0x00,
                0x00,
                0x00,
                0x04,
                0x1a,
                0x80,
                0xca,
                0xfe,
                0xca,
                0xfe};

        // Info 
        printf("CHESS PUS GS \n");
        printf("APID: %u\n\n", CURRENT_APID);

        // Open socket 
        server();

        // Initialize PUSopen(R) stack 
        po_initPus1();
        po_initPusUsr();
        po_initPs();
        po_initFess();

    #ifdef SEND_TC_17_1
        // Send TC[17,1] to server 
        po_sendTc(17U, 1U,   // TC[17,1] 
                &data,     // TC payload 
                0U,        // TC payload length 
                1U);       // Destination APID 

        // Retrieve created TC[17,1] from stack and send it 
        (void) po_frame(buf, &len);

        printf("Send PUS [17,1]\n");
        server_send((char*)buf, (int)len);
    #endif  // SEND_TC_17_1

        sleep_ms(100);

    #ifdef SEND_TC_17_3
        // Send TC[17,3] to server 
        po_sendTc(17U, 3U,   // TC[17,1] 
                &data,     // TC payload 
                0U,        // TC payload length 
                1U);       // Destination APID 

        // Retrieve created TC[17,3] from stack and send it 
        (void) po_frame(buf, &len);

        printf("Send PUS [17,3]\n");
        server_send((char*)buf, (int)len);
    #endif // SEND_TC_17_3

        sleep_ms(100);

    #ifdef SEND_TC_8_1_NOOP
        // Function TC[8,1] NO-OP
        po_sendTc(8U, 1U,   // TC[8,1] 
                dataCMDNOOPPUS8,    // TC payload 
                21U,       // TC payload length 
                1U);      // Destination APID 

        // Retrieve created TC[8,1] byte stream from PUSopen(R) stack and send it 
        (void) po_frame(buf, &len);

        printf("Send PUS [8,1] with CMD_NOOP command in payload \n");
        server_send((char*)buf, (int)len);
    #endif // SEND_TC_8_1_NOOP

        sleep_ms(100);

    #ifdef SEND_TC_8_1_ADCS
        // Function TC[8,1]  ADCS
        po_sendTc(8U, 1U,   // TC[8,1] 
                dataADCSTMPUS8,    // TC payload 
                22U,       // TC payload length 
                1U);      // Destination APID 

        // Retrieve created TC[8,1] byte stream from PUSopen(R) stack and send it 
        (void) po_frame(buf, &len);
        printf("Send PUS [8,1] with ADCS_GET_TM id=128, command in payload \n");
        server_send((char*)buf, (int)len);
    #endif // SEND_TC_8_1_ADCS

        // Main loop - wait for reception of TM from server
        while (stop == 0U) {

            // Push received data byte-by-byte into PUSopen(R) stack 
            while (client_recv((char*)&data, 1) == 1) {
                po_accept(data);
            }

            // Trigger stack to process received TM

            // Unwrap TM from received CCSDS packet 
            po_triggerPs();

            // Forward TM to PUS User 
            po_triggerPus1();

            sleep_ms(100);
        }

        client_close();
        return 0;
    }
