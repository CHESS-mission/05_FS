#include <Fw/Com/ComBuffer.hpp>
#include <assert.h>

namespace Fw {

    ComBuffer::ComBuffer(const U8 *args, NATIVE_UINT_TYPE size) {
        SerializeStatus stat = SerializeBufferBase::setBuff(args,size);
        assert(FW_SERIALIZE_OK == stat);
    }
    
    ComBuffer::ComBuffer() {
    }

    ComBuffer::~ComBuffer() {
    }

    ComBuffer::ComBuffer(const ComBuffer& other) : Fw::SerializeBufferBase() {
        SerializeStatus stat = SerializeBufferBase::setBuff(other.m_data,other.getBuffLength());
        assert(FW_SERIALIZE_OK == stat);
    }

    const ComBuffer& ComBuffer::operator=(const ComBuffer& other) {
        SerializeStatus stat = SerializeBufferBase::setBuff(other.m_data,other.getBuffLength());
        assert(FW_SERIALIZE_OK == stat);
        return *this;
    }

    NATIVE_UINT_TYPE ComBuffer::getBuffCapacity(void) const {
        return sizeof(this->m_data);
    }

    const U8* ComBuffer::getBuffAddr(void) const {
        return this->m_data;
    }

    U8* ComBuffer::getBuffAddr(void) {
        return this->m_data;
    }

}

