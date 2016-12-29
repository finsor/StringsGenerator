#include "Range.h"

#ifdef DEBUG
#include <iostream>
#endif // DEBUG

#include <stdexcept>
#include <string>

#include "Formatter.h"
#include "IMultiplier.h"
#include "IRegexParser.h"

std::string
Regex::Range::Process(const std::string&              regularExpression,
                        std::string::const_iterator&    regexIterator,
                        const Regex::IRegexParser&      parser,
                        const Regex::IMultiplier        *multiplier)
                        const
{
    char start = *(regexIterator - 1);
    char stop  = *(regexIterator + 1);

    ++regexIterator;

    if( regularExpression.end() <= regexIterator ||
        !IsSameType(start, stop) )
    {
        throw std::runtime_error(StringHelper::Formatter() <<
                "Error: invalid range");
    }

    uint32_t addition = GetAddition(start, stop);

    return ( CreateRange(start, stop, addition) );
}

/* private */

bool
Regex::Range::IsSameType(char a, char b)
const
{
    return(
        (isupper(a) && isupper(b))
           ||
        (islower(a) && islower(b))
           ||
        (isdigit(a) && isdigit(b))
    );
}

uint32_t
Regex::Range::GetAddition(char start, char stop)
const
{
    if( start < stop )
        return ( +1 );
    else
        return ( -1 );
}

std::string
Regex::Range::CreateRange(char start, char stop, uint32_t addition)
const
{
    std::string result;
    for(char iter = start+addition; iter != stop; iter += addition)
    {
        result += iter;
    }

    return ( result );
}
