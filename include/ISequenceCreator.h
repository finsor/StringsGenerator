#pragma once

#include <cstring>
#include <cstdint>


namespace Sequence
{
class ISequenceCreator
{
public:
    ISequenceCreator(const char *start, const char *stop, int difference) :
        _start(start), _stop(stop), _difference(difference)
    {
        _startLength = strlen(_start);
        _stopLength  = strlen(_stop);
    }

    virtual ~ISequenceCreator() {}

    virtual const char * GetNext() = 0;
    virtual bool End() const = 0;

protected:
    const char *_start, *_stop;
    uint32_t _startLength, _stopLength;
    int _difference;
};
}
