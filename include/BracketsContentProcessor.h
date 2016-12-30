#pragma once

#include "IDelimiterProcessor.h"
#include "IRegexParser.h"
#include "IMultiplier.h"


namespace Regex
{
class BracketsContentProcessor : public IDelimiterProcessor
{
public:
    BracketsContentProcessor(char start, char stop) :
        _start(start), _stop(stop)
    {}

    virtual ~BracketsContentProcessor() {}

    char Trigger() const
    {
        return ( _start );
    }

    // Function returns the parsed content of the brackets.
    virtual std::string Process(const std::string&              regularExpression,
                                std::string::const_iterator&    regexIterator,
                                const Regex::IRegexParser&      parser,
                                const Regex::IMultiplier        *multiplier,
                                std::string&                    destination)
    const;

    // Returns content if OK or throws
    std::string GetContent(const std::string&              regularExpression,
                           std::string::const_iterator&    regexIterator)
    const;



private:
    char _start, _stop;

    // Function returns brackets content from iter and on
    // Returns whether found a closer or not
    bool Cut(const std::string&             original,
             std::string::const_iterator&   iter,
             std::string&                   destination)
    const;
};
}
