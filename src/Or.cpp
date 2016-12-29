#include "Or.h"

#ifdef DEBUG
#include <iostream>
#endif // DEBUG

#include <algorithm>

#include "IRegexParser.h"
#include "Random.h"
#include "Formatter.h"


char
Regex::Or::Trigger() const
{
    return ( _delimiter );
}

std::string
Regex::Or::Process(const std::string& regularExpression,
                        std::string::const_iterator& regexIterator,
                        const IRegexParser& parser,
                        std::string& dst,
                        const std::string& lastResult) const
{
    ++regexIterator;

    std::string tmpRegex = regularExpression.substr(regexIterator - regularExpression.begin());
    regexIterator += tmpRegex.size();

    if( !IsValid(tmpRegex) || !IsValid(lastResult))
    {
        std::string ex = Error::Formatter() <<
        "Expected 2 options for '" << _delimiter <<
        "' at" << regexIterator - regularExpression.begin();
    }

    Random::Random randomizer;

    if(randomizer.Generate() % 2 == 0)
        return ( "" );
    else
    {
        dst.clear();

        return ( parser.Parse(tmpRegex) );
    }
}

/* private */

bool
Regex::Or::IsValid(std::string str) const
{
    return ( str.size() > 0 );
}
