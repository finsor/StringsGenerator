#pragma once

#include "string"

#include "BracketsContentProcessor.h"
#include "IMultiplier.h"
#include "IRegexParser.h"


namespace Regex
{
class Brackets : public BracketsContentProcessor
{
public:
    Brackets(char start, char stop) :
        BracketsContentProcessor(start, stop)
    {}

    virtual ~Brackets() {}

    std::string Process(const std::string&              regularExpression,
                        std::string::const_iterator&    regexIterator,
                        const Regex::IRegexParser&      parser,
                        const Regex::IMultiplier        *multiplier,
                        std::string&                    destination)
    const;

};
}
