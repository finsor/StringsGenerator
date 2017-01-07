#pragma once

#include <cstring>
#include <cstdint>


namespace Sequence
{
class ISequenceCreator
{
public:

    ISequenceCreator()          {}
    virtual ~ISequenceCreator() {}

    virtual const char *    Get()   = 0;
    virtual bool            End()    = 0;

};
}
