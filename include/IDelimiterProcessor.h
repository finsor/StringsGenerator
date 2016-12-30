#pragma once

#include <string>

#include "IDelimiter.h"
#include "IRegexParser.h"
#include "IMultiplier.h"


namespace Regex
{
class IDelimiterProcessor : public IDelimiter
{
public:

    IDelimiterProcessor() {}
    virtual ~IDelimiterProcessor() {}

    // Function processes delimiter and returns result.
    // Increments $regexIterator as it processes.
    virtual std::string Process(const std::string&              regularExpression,
                                std::string::const_iterator&    regexIterator,
                                const Regex::IRegexParser&      parser,
                                const Regex::IMultiplier        *multiplier,
                                std::string&                    destination)
    const = 0;
};
}
