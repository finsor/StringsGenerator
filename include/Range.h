#pragma once

#include "IDelimiterProcessor.h"
#include "IMultiplier.h"
#include "IRegexParser.h"

#include <string>


namespace Regex
{
class Range : public IDelimiterProcessor
{
public:
    Range(char delimiter) :
        _delimiter(delimiter)
    {}

    virtual ~Range() {}

    char Trigger() const;

    std::string Process(const std::string&              regularExpression,
                        std::string::const_iterator&    regexIterator,
                        const Regex::IRegexParser&      parser,
                        const Regex::IMultiplier        *multiplier)
    const;

private:
    char _delimiter;

    // Function returns whether range limits are of same type
    // For example, both are digits, or lower case letters.
    bool IsSameType(char a, char b) const;

    // Function gets range limits
    // Returns +1 for increasing range
    //    else -1
    uint32_t GetAddition(char start, char stop) const;

    // Function gets range limits and returns everything between them
    std::string CreateRange(char start, char stop, uint32_t addition) const;
};
}
