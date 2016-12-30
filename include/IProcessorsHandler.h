#pragma once

#include <string>

#include "IDelimiterProcessor.h"

#include "IRegexParser.h"


namespace Regex
{
class IProcessorsHandler
{
public:

    IProcessorsHandler() {}
    virtual ~IProcessorsHandler() {}

    // Function to add a delimiter processor.
    // Returns $true for success, else $false
    // $false cases: <Item already exists>,
    virtual bool AddProcessor(IDelimiterProcessor*          processor) = 0;

    // Function to remove a delimiter processor.
    // Returns $true for success, else $false
    // $false cases: <Item already exists>,
    virtual bool DelProcessor(char prcessorsDelimiter) = 0;

    // Function processes delimiter $*pos and increments $pos
    virtual std::string Process(const std::string&              regularExpression,
                                std::string::const_iterator&    regexIterator,
                                const IRegexParser&             parser,
                                std::string&                    destination)
    const = 0;

};
}

