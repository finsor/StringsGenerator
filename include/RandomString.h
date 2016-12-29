#pragma once

#include <string>

#include "IDelimiterProcessor.h"
#include "IMultiplier.h"
#include "IRegexParser.h"


namespace Regex
{
class RandomString : public IDelimiterProcessor
{
public:

    RandomString(char delimiter, uint32_t minLength, uint32_t maxLength) :
        _delimiter(delimiter), _minLength(minLength), _maxLength(maxLength)
    {}

    virtual ~RandomString() {}

    char Trigger() const;

    std::string Process(const std::string&              regularExpression,
                        std::string::const_iterator&    regexIterator,
                        const Regex::IRegexParser&      parser,
                        const Regex::IMultiplier        *multiplier)
    const;

private:

    char _delimiter;
    uint32_t _minLength, _maxLength;

    std::string GenerateRandomString(const std::string&              regularExpression,
                                     std::string::const_iterator&    regexIterator,
                                     const Regex::IRegexParser&      parser,
                                     const Regex::IMultiplier        *multiplier)
    const;

    std::string MultipleRandomStrings(uint32_t times) const;
};
}
