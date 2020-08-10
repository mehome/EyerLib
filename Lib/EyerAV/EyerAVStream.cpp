#include "EyerAVAV.hpp"

#include "EyerAVStreamPrivate.hpp"

namespace Eyer
{
    EyerAVStream::EyerAVStream()
    {
        piml = new EyerAVStreamPrivate();
        piml->codecpar = avcodec_parameters_alloc();
    }
    
    EyerAVStream::~EyerAVStream()
    {
        if(piml->codecpar != nullptr){
            avcodec_parameters_free(&piml->codecpar);
            piml->codecpar = nullptr;
        }
        if(piml != nullptr){
            delete piml;
            piml = nullptr;
        }
    }

    EyerAVStream::EyerAVStream(const EyerAVStream & stream) : EyerAVStream()
    {
        *this = stream;
    }

    const EyerAVStream & EyerAVStream::operator = (const EyerAVStream & stream)
    {
        avcodec_parameters_copy(piml->codecpar, stream.piml->codecpar);

        piml->type = stream.piml->type;
        streamIndex = stream.streamIndex;
        duration = stream.duration;
        timebase = stream.timebase;

        return *this;
    }

    EyerAVStreamType EyerAVStream::GetStreamType()
    {
        if(piml->codecpar->codec_type == AVMediaType::AVMEDIA_TYPE_VIDEO){
            return EyerAVStreamType::STREAM_TYPE_VIDEO;
        }
        if(piml->codecpar->codec_type == AVMediaType::AVMEDIA_TYPE_AUDIO){
            return EyerAVStreamType::STREAM_TYPE_AUDIO;
        }

        return EyerAVStreamType::STREAM_TYPE_AUDIO;
    }

    int EyerAVStream::SetDuration(double _duration)
    {
        duration = _duration;
        return 0;
    }

    double EyerAVStream::GetDuration()
    {
        return duration;
    }

    int EyerAVStream::GetWidth()
    {
        return piml->codecpar->width;
    }

    int EyerAVStream::GetHeight()
    {
        return piml->codecpar->height;
    }
}
