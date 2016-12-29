#pragma once

#include <string>

#include "IRegexParser.h"
#include "IMultiplier.h"


namespace Regex
{
class IDelimiterProcessor
{
public:

    IDelimiterProcessor() {}
    virtual ~IDelimiterProcessor() {}

    // Function to get the starter delimiter.
    virtual char Trigger() const = 0;

    // Function processes delimiter and returns result.
    // Increments $regexIterator as it processes.
    virtual std::string Process(const std::string&              regularExpression,
                                std::string::const_iterator&    regexIterator,
                                const Regex::IRegexParser&      parser,
                                const Regex::IMultiplier        *multiplier)
    const = 0;

};
}
