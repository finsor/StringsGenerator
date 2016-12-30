#pragma once

#include <string>

#include "IDelimiterProcessor.h"
#include "IMultiplier.h"
#include "IRegexParser.h"

namespace Regex
{
class Literal : public IDelimiterProcessor
{
public:

    Literal(char delimiter) :
        _delimiter(delimiter)
    {}

    virtual ~Literal() {}

    char Trigger() const;

    std::string Process(const std::string&              regularExpression,
                        std::string::const_iterator&    regexIterator,
                        const Regex::IRegexParser&      parser,
                        const Regex::IMultiplier        *multiplier,
                        std::string&                    destination)
    const;

private:

    char _delimiter;

};
}
