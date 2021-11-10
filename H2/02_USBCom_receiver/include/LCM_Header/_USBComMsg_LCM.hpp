/** THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
 * BY HAND!!
 *
 * Generated by lcm-gen
 **/

#ifndef ___USBComMsg_LCM_hpp__
#define ___USBComMsg_LCM_hpp__

#include <lcm/lcm_coretypes.h>

#include "_ParkingSpace_LCM.hpp"
#include "_ParkingSpace_LCM.hpp"
#include "_ParkingSpaceDspID.hpp"
#include "_ParkingSpaceDspID.hpp"
#include "_ParkingSpaceDspID.hpp"
#include "_ParkingSpaceDspID.hpp"
#include "_AIPilotObjDsp_Dsp.hpp"
#include "_AIPilotObjDsp_Dsp.hpp"
#include "_SpeedControl_FICM2IECU_LCM.hpp"
#include "_SpeedControl_FICM2IECU_LCM.hpp"
#include "_SpeedControl_IECU2FICM_LCM.hpp"
#include "_SpeedControl_IECU2FICM_LCM.hpp"
#include "_IECUNavigationInfo_LCM.hpp"
#include "_IECUNavigationInfo_LCM.hpp"


class _USBComMsg_LCM
{
    public:
        _ParkingSpace_LCM ParkingSpace_RTE_Recv[8];

        _ParkingSpace_LCM ParkingSpace_SOCK_Send[8];

        _ParkingSpaceDspID ParkingSpaceDsp_TgtParkngSpaceID_RTE_Recv;

        _ParkingSpaceDspID ParkingSpaceDsp_TgtParkngSpaceID_SOCK_Send;

        _ParkingSpaceDspID ParkingSpaceDsp_TgtParkingChosed_SOCK_Recv;

        _ParkingSpaceDspID ParkingSpaceDsp_TgtParkingChosed_RTE_Send;

        _AIPilotObjDsp_Dsp AIPilotObj_RTE_Recv;

        _AIPilotObjDsp_Dsp AIPilotObj_SOCK_Send;

        _SpeedControl_FICM2IECU_LCM SpeedControl_FICM2IECU_SOCK_Recv;

        _SpeedControl_FICM2IECU_LCM SpeedControl_FICM2IECU_RTE_Send;

        _SpeedControl_IECU2FICM_LCM SpeedControl_IECU2FICM_RTE_Recv;

        _SpeedControl_IECU2FICM_LCM SpeedControl_IECU2FICM_SOCK_Send;

        _IECUNavigationInfo_LCM IECUNavigationInfo_RTE_Recv;

        _IECUNavigationInfo_LCM IECUNavigationInfo_SOCK_Send;

    public:
        /**
         * Encode a message into binary form.
         *
         * @param buf The output buffer.
         * @param offset Encoding starts at thie byte offset into @p buf.
         * @param maxlen Maximum number of bytes to write.  This should generally be
         *  equal to getEncodedSize().
         * @return The number of bytes encoded, or <0 on error.
         */
        inline int encode(void *buf, int offset, int maxlen) const;

        /**
         * Check how many bytes are required to encode this message.
         */
        inline int getEncodedSize() const;

        /**
         * Decode a message from binary form into this instance.
         *
         * @param buf The buffer containing the encoded message.
         * @param offset The byte offset into @p buf where the encoded message starts.
         * @param maxlen The maximum number of bytes to read while decoding.
         * @return The number of bytes decoded, or <0 if an error occured.
         */
        inline int decode(const void *buf, int offset, int maxlen);

        /**
         * Retrieve the 64-bit fingerprint identifying the structure of the message.
         * Note that the fingerprint is the same for all instances of the same
         * message type, and is a fingerprint on the message type definition, not on
         * the message contents.
         */
        inline static int64_t getHash();

        /**
         * Returns "_USBComMsg_LCM"
         */
        inline static const char* getTypeName();

        // LCM support functions. Users should not call these
        inline int _encodeNoHash(void *buf, int offset, int maxlen) const;
        inline int _getEncodedSizeNoHash() const;
        inline int _decodeNoHash(const void *buf, int offset, int maxlen);
        inline static uint64_t _computeHash(const __lcm_hash_ptr *p);
};

int _USBComMsg_LCM::encode(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;
    int64_t hash = getHash();

    tlen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->_encodeNoHash(buf, offset + pos, maxlen - pos);
    if (tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int _USBComMsg_LCM::decode(const void *buf, int offset, int maxlen)
{
    int pos = 0, thislen;

    int64_t msg_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &msg_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (msg_hash != getHash()) return -1;

    thislen = this->_decodeNoHash(buf, offset + pos, maxlen - pos);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int _USBComMsg_LCM::getEncodedSize() const
{
    return 8 + _getEncodedSizeNoHash();
}

int64_t _USBComMsg_LCM::getHash()
{
    static int64_t hash = static_cast<int64_t>(_computeHash(NULL));
    return hash;
}

const char* _USBComMsg_LCM::getTypeName()
{
    return "_USBComMsg_LCM";
}

int _USBComMsg_LCM::_encodeNoHash(void *buf, int offset, int maxlen) const
{
    int pos = 0, tlen;

    for (int a0 = 0; a0 < 8; a0++) {
        tlen = this->ParkingSpace_RTE_Recv[a0]._encodeNoHash(buf, offset + pos, maxlen - pos);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    for (int a0 = 0; a0 < 8; a0++) {
        tlen = this->ParkingSpace_SOCK_Send[a0]._encodeNoHash(buf, offset + pos, maxlen - pos);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    tlen = this->ParkingSpaceDsp_TgtParkngSpaceID_RTE_Recv._encodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->ParkingSpaceDsp_TgtParkngSpaceID_SOCK_Send._encodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->ParkingSpaceDsp_TgtParkingChosed_SOCK_Recv._encodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->ParkingSpaceDsp_TgtParkingChosed_RTE_Send._encodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->AIPilotObj_RTE_Recv._encodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->AIPilotObj_SOCK_Send._encodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->SpeedControl_FICM2IECU_SOCK_Recv._encodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->SpeedControl_FICM2IECU_RTE_Send._encodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->SpeedControl_IECU2FICM_RTE_Recv._encodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->SpeedControl_IECU2FICM_SOCK_Send._encodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->IECUNavigationInfo_RTE_Recv._encodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->IECUNavigationInfo_SOCK_Send._encodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int _USBComMsg_LCM::_decodeNoHash(const void *buf, int offset, int maxlen)
{
    int pos = 0, tlen;

    for (int a0 = 0; a0 < 8; a0++) {
        tlen = this->ParkingSpace_RTE_Recv[a0]._decodeNoHash(buf, offset + pos, maxlen - pos);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    for (int a0 = 0; a0 < 8; a0++) {
        tlen = this->ParkingSpace_SOCK_Send[a0]._decodeNoHash(buf, offset + pos, maxlen - pos);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    tlen = this->ParkingSpaceDsp_TgtParkngSpaceID_RTE_Recv._decodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->ParkingSpaceDsp_TgtParkngSpaceID_SOCK_Send._decodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->ParkingSpaceDsp_TgtParkingChosed_SOCK_Recv._decodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->ParkingSpaceDsp_TgtParkingChosed_RTE_Send._decodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->AIPilotObj_RTE_Recv._decodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->AIPilotObj_SOCK_Send._decodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->SpeedControl_FICM2IECU_SOCK_Recv._decodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->SpeedControl_FICM2IECU_RTE_Send._decodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->SpeedControl_IECU2FICM_RTE_Recv._decodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->SpeedControl_IECU2FICM_SOCK_Send._decodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->IECUNavigationInfo_RTE_Recv._decodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->IECUNavigationInfo_SOCK_Send._decodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    return pos;
}

int _USBComMsg_LCM::_getEncodedSizeNoHash() const
{
    int enc_size = 0;
    for (int a0 = 0; a0 < 8; a0++) {
        enc_size += this->ParkingSpace_RTE_Recv[a0]._getEncodedSizeNoHash();
    }
    for (int a0 = 0; a0 < 8; a0++) {
        enc_size += this->ParkingSpace_SOCK_Send[a0]._getEncodedSizeNoHash();
    }
    enc_size += this->ParkingSpaceDsp_TgtParkngSpaceID_RTE_Recv._getEncodedSizeNoHash();
    enc_size += this->ParkingSpaceDsp_TgtParkngSpaceID_SOCK_Send._getEncodedSizeNoHash();
    enc_size += this->ParkingSpaceDsp_TgtParkingChosed_SOCK_Recv._getEncodedSizeNoHash();
    enc_size += this->ParkingSpaceDsp_TgtParkingChosed_RTE_Send._getEncodedSizeNoHash();
    enc_size += this->AIPilotObj_RTE_Recv._getEncodedSizeNoHash();
    enc_size += this->AIPilotObj_SOCK_Send._getEncodedSizeNoHash();
    enc_size += this->SpeedControl_FICM2IECU_SOCK_Recv._getEncodedSizeNoHash();
    enc_size += this->SpeedControl_FICM2IECU_RTE_Send._getEncodedSizeNoHash();
    enc_size += this->SpeedControl_IECU2FICM_RTE_Recv._getEncodedSizeNoHash();
    enc_size += this->SpeedControl_IECU2FICM_SOCK_Send._getEncodedSizeNoHash();
    enc_size += this->IECUNavigationInfo_RTE_Recv._getEncodedSizeNoHash();
    enc_size += this->IECUNavigationInfo_SOCK_Send._getEncodedSizeNoHash();
    return enc_size;
}

uint64_t _USBComMsg_LCM::_computeHash(const __lcm_hash_ptr *p)
{
    const __lcm_hash_ptr *fp;
    for(fp = p; fp != NULL; fp = fp->parent)
        if(fp->v == _USBComMsg_LCM::getHash)
            return 0;
    const __lcm_hash_ptr cp = { p, _USBComMsg_LCM::getHash };

    uint64_t hash = 0x48e5336d0642b7d1LL +
         _ParkingSpace_LCM::_computeHash(&cp) +
         _ParkingSpace_LCM::_computeHash(&cp) +
         _ParkingSpaceDspID::_computeHash(&cp) +
         _ParkingSpaceDspID::_computeHash(&cp) +
         _ParkingSpaceDspID::_computeHash(&cp) +
         _ParkingSpaceDspID::_computeHash(&cp) +
         _AIPilotObjDsp_Dsp::_computeHash(&cp) +
         _AIPilotObjDsp_Dsp::_computeHash(&cp) +
         _SpeedControl_FICM2IECU_LCM::_computeHash(&cp) +
         _SpeedControl_FICM2IECU_LCM::_computeHash(&cp) +
         _SpeedControl_IECU2FICM_LCM::_computeHash(&cp) +
         _SpeedControl_IECU2FICM_LCM::_computeHash(&cp) +
         _IECUNavigationInfo_LCM::_computeHash(&cp) +
         _IECUNavigationInfo_LCM::_computeHash(&cp);

    return (hash<<1) + ((hash>>63)&1);
}

#endif
