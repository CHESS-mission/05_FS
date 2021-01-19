
#ifndef APP_EPS_EPSHKANALYSYER_HPP_
#define APP_EPS_EPSHKANALYSYER_HPP_

#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Buffer/Buffer.hpp>

namespace App {

    class EPSHkAnalyser {
        public:
            EPSHkAnalyser(Fw::Buffer&);
            virtual ~EPSHkAnalyser();
            U8 getCmd();
            I8 getStatus();
            U16 getvBatt();
            U8 getbattMode();
            U16 getTemp();

        private:

            U32 to32LittleEndian(U16 start);
            U16 to16LittleEndian(U16 start);

            U8* payload;
            U32 size;
    };
}

#endif /* APP_EPS_EPSHELPER_HPP_*/
