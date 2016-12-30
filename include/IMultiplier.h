#pragma once

#include <string>

#include "IRegexParser.h"


namespace Regex
{
class IMultiplier
{
public:

    IMultiplier() {}
    virtual ~IMultiplier() {}

    // Function gets a regular expression
    // and returns a translated result
    virtual std::string Process(const std::string&              regularExpression,
                                std::string::const_iterator&    regexIterator,
                                const Regex::IRegexParser&      parser,
                                const std::string&              destination)
    const = 0;

    virtual uint32_t GetMultiplier(const std::string&              regularExpression,
                                   std::string::const_iterator&    regexIterator,
                                   const Regex::IRegexParser&      parser)
    const = 0;

    virtual std::string Multiply(const std::string& src,
                                 uint32_t times)
    const = 0;

    virtual char Trigger() const = 0;

};
}

