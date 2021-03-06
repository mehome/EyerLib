#ifndef EYERLIB_EYERANNEXB_HPP
#define EYERLIB_EYERANNEXB_HPP

#include "EyerCore/EyerCore.hpp"
#include "EyerNALU.hpp"

namespace Eyer{
    class EyerAnnexB {
    public:
        EyerAnnexB();
        ~EyerAnnexB();

        int Open(EyerString & path);
        int Close();

        int Reset();

        int GetAnnexBNALU(EyerNALU & nalu);
    private:
        int getChunk();
        unsigned char getfbyte();
        int FindStartCode (unsigned char * Buf, int zeros_in_startcode);

        FILE * bitStreamFile = nullptr;
        unsigned char * iobuffer = nullptr;
        unsigned char * iobufferread = nullptr;
        int bytesinbuffer = 0;
        bool is_eof = false;
        int ioBufferSize;

        int isFirstByteStreamNALU;
        int nextstartcodebytes;

        unsigned char * buf = nullptr;
    };
}

#endif //EYERLIB_EYERANNEXB_HPP
