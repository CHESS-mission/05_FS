

#include "App/EPS/EPSHkAnalyser.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "App/Config/EPSCfg.hpp"

namespace App {

    EPSHkAnalyser::EPSHkAnalyser(Fw::Buffer &data) {
        this->payload = data.getData();
        this->size = data.getSize();
    }

    EPSHkAnalyser::~EPSHkAnalyser(){  
    }

    U8 EPSHkAnalyser::getCmd(){
        return this->payload[EPSCMD];
    }
    I8 EPSHkAnalyser::getStatus(){
        return this->payload[EPSSTATUS];
    }
    U16 EPSHkAnalyser::getvBatt(){
        return this->to16LittleEndian(EPSVBATT);
    }
    U8 EPSHkAnalyser::getbattMode(){
        return this->payload[EPSBATTMODE];
    }

    U16 EPSHkAnalyser::getTemp(){
        return this->payload[EPSTEMP];
    }

    U16 EPSHkAnalyser::to16LittleEndian(U16 start){
        return (U16)this->payload[start+1] << 8 | (U16)this->payload[start];
    }

    U32 EPSHkAnalyser::to32LittleEndian(U16 start){
       return  (U32)this->payload[start+3] << 24 | (U32)this->payload[start+2] << 16 
        | (U32)this->payload[start+1] << 8 | (U32)this->payload[start];
    }



}  // namespace App