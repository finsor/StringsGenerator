#pragma once

#include <cmath>
#include <cstring>

#include "ISequenceCreator.h"
#include "StringHelperStaticFunctions.h"


namespace Sequence
{
class SequenceCreator : public ISequenceCreator
{
public:

    SequenceCreator(const char * start, const char * stop, int difference);

    virtual ~SequenceCreator();

    const char * GetNext();

    inline bool End() const;

private:
    char * _current;
    uint32_t _currentLength;
    uint32_t _absDifference;
    int _sign;
    bool _end;

    void ChangeCurrentByDifference();
    void ChangeCurrentBy(int sign);
    inline void ShiftLeft(char * buffer);
    inline void ShiftRight(char * buffer);

    char HighestOfChar(char c, int sign) const;
    char LowestOfChar (char c, int sign) const;
    char DecadeOfChar (char c, int sign) const;
};
}
