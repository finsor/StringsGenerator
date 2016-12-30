#include "Literal.h"

#ifdef DEBUG
#include <iostream>
#endif // DEBUG

#include <stdexcept>
#include <string>

#include "IMultiplier.h"
#include "IRegexParser.h"
#include "Formatter.h"


char
Regex::Literal::Trigger()
const
{
    return ( _delimiter );
}

std::string
Regex::Literal::Process(
    const std::string&              regularExpression,
    std::string::const_iterator&    regexIterator,
    const Regex::IRegexParser&      parser,
    const Regex::IMultiplier        *multiplier,
    std::string&                    destination)
const
{
    ++regexIterator;

    if( regexIterator >= regularExpression.end() )
        throw std::runtime_error(StringHelper::Formatter() <<
                                 "Unexpected end of regex");
    else
        return ( std::string(1, *regexIterator++) );
}
