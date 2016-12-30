#include "RegexParser.h"

#ifdef DEBUG
#include <iostream>
#endif // DEBUG

#include <sstream>

std::string
Regex::RegexParser::Parse(const std::string& regularExpression) const
{
    std::string result;

    std::string::const_iterator iter = regularExpression.begin();
    while ( iter < regularExpression.end() )
    {
        result += _processorsHandler->Process(
                         regularExpression,
                         iter,
                         *this,
                         result);
    }

    return ( result );
}
