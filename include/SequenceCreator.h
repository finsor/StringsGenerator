#pragma once

#include <cmath>
#include <cstring>

#include "ISequenceCreator.h"
#include "ISequenceType.h"
#include "SequenceType.h"
#include "StringHelperStaticFunctions.h"


namespace Sequence
{
class SequenceCreator : public ISequenceCreator
{
public:

    SequenceCreator(const std::string& start,
                    const std::string& stop,
                    int difference);

    SequenceCreator(const char * start,
                    const char * stop,
                    int difference);

    virtual ~SequenceCreator() {}

    void CalculateNext();
    const char * Get();
    bool End();

private:

    SequenceType _start;
    SequenceType _current;
    SequenceType _stop;

    uint32_t _absDifference;
    int _difference;
    int _sign;

    void Create(int difference);
};
}
