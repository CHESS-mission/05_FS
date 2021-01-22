#include <Fw/Log/LogBuffer.hpp>
#include <assert.h>

namespace Fw {

    LogBuffer::LogBuffer(const U8 *args, NATIVE_UINT_TYPE size) {
        SerializeStatus stat = SerializeBufferBase::setBuff(args,size);
        assert(FW_SERIALIZE_OK == stat);
    }
    
    LogBuffer::LogBuffer() {
    }

    LogBuffer::~LogBuffer() {
    }

    LogBuffer::LogBuffer(const LogBuffer& other) : Fw::SerializeBufferBase() {
        SerializeStatus stat = SerializeBufferBase::setBuff(other.m_data,other.getBuffLength());
        assert(FW_SERIALIZE_OK == stat);
    }

    const LogBuffer& LogBuffer::operator=(const LogBuffer& other) {
        SerializeStatus stat = SerializeBufferBase::setBuff(other.m_data,other.getBuffLength());
        assert(FW_SERIALIZE_OK == stat);
        return *this;
    }

    NATIVE_UINT_TYPE LogBuffer::getBuffCapacity(void) const {
        return sizeof(this->m_data);
    }

    const U8* LogBuffer::getBuffAddr(void) const {
        return this->m_data;
    }

    U8* LogBuffer::getBuffAddr(void) {
        return this->m_data;
    }

}

