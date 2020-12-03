

#include <App/Config/ADCSCfg.hpp>
#include <App/ADCS/ADCSHelper.hpp>

namespace App {

ADCSHelper::ADCSHelper() {
        for (U8 i = 0; i < 256; i++) {
            U8 val = i;
            for (int j = 0; j < 8; j++) {
                if (val & 1) val ^= CRC_POLY;
                val >>= 1;
            }
            CRC8Table[i] = val;
        }
    }
    ADCSHelper::~ADCSHelper(){  
    }

    U8 ADCSHelper::getCrc(Fw::Buffer packet){
        U32 len = packet.getSize();
        U8* buffer = packet.getData();
        if (len == 0) return 0xff;
        U8 crc = 0;
        for (U16 i = 0; i < len; i++)
        crc = CRC8Table[crc ^ buffer[i]];
        return crc;

    }

}  // namespace App