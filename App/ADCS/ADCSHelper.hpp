
#ifndef APP_ADCS_ADCSHELPER_HPP_
#define APP_ADCS_ADCSHELPER_HPP_

#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Buffer/Buffer.hpp>


namespace App {

    class ADCSHelper {
        public:

            ADCSHelper();
            virtual ~ADCSHelper();
            U8 getCrc(U8* ,NATIVE_UINT_TYPE);

        private:
        
        U8 CRC8Table[256];
            
    };

}

#endif /* APP_ADCS_ADCSHELPER_HPP_*/
