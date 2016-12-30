#pragma once

#include <cmath>
#include <string>


#include "ISequenceCreator.h"
#include "StringHelperStaticFunctions.h"

namespace Sequence
{
class SequenceCreator : public ISequenceCreator
{
public:

    SequenceCreator(std::string start, std::string stop, int difference) :
        ISequenceCreator(start, stop, difference), _end( start.compare(stop) == 0 )
    {
        _current = start;
        _absDifference = std::abs(difference);
    }

    virtual ~SequenceCreator();

    std::string GetNext();

    bool End() const;

private:
    std::string _current;
    uint32_t _absDifference;
    bool _end;

    void ChangeCurrentByDifference();
    void ChangeCurrentBy(int sign);

    char HighestOfChar(char c, int sign) const;
    char LowestOfChar (char c, int sign) const;
    char DecadeOfChar (char c, int sign) const;

    int Sign(int i) const;
};
}
