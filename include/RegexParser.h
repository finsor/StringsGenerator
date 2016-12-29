#pragma once

#ifdef DEBUG
#include <iostream>
#endif // DEBUG

#include <string>
#include <ostream>

#include "IRegexParser.h"
#include "IProcessorsHandler.h"

namespace Regex
{
class RegexParser : public IRegexParser
{
public:

    // Constructor's arguments:
    // $delimitersHandler - an object that handles parsing of specific delimiters
    RegexParser(IProcessorsHandler *processorsHandler) :
        _processorsHandler(processorsHandler)
    {}

    virtual ~RegexParser() {}

    // Function implements IRegexParser::Parse
    std::string Parse   (const std::string& regularExpression) const;

private:

    // An object that handles parsing of specific delimiters
    IProcessorsHandler *_processorsHandler;

};
}
