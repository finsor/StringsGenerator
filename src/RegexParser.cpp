#include "RegexParser.h"

#ifdef DEBUG
#include <iostream>
#endif // DEBUG

#include <sstream>

std::string
Regex::RegexParser::Parse(const std::string& regularExpression) const
{
    std::string result;
    std::string lastResult = "";

    std::string::const_iterator iter = regularExpression.begin();
    while ( iter < regularExpression.end() )
    {
        lastResult = _processorsHandler->Process(
                         regularExpression,
                         iter,
                         *this,
                         lastResult);

        result += lastResult;
    }

    return ( result );
}
