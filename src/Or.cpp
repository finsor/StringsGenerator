#include "Or.h"

#ifdef DEBUG
#include <iostream>
#endif // DEBUG

#include <algorithm>

#include "IRegexParser.h"
#include "CSRandom.h"
#include "Formatter.h"


char
Regex::Or::Trigger() const
{
    return ( _delimiter );
}

std::string
Regex::Or::Process(
    const std::string&              regularExpression,
    std::string::const_iterator&    regexIterator,
    const Regex::IRegexParser&      parser,
    const Regex::IMultiplier        *multiplier,
    std::string&                    destination)
const
{
    ++regexIterator;

    std::string optionOne = destination;
    std::string optionTwo = ParseNext(regularExpression,
                                      regexIterator,
                                      parser);

    destination.clear();

    return ( RandomalyChoose(optionOne, optionTwo) );
}

/* private */

std::string
Regex::Or::RandomalyChoose(const std::string& optionOne,
                           const std::string& optionTwo)
const
{
    Random::CSRandom randomizer;

    if(randomizer.Generate() % 2 == 0)
        return ( optionOne );
    else
        return ( optionTwo );
}

std::string
Regex::Or::ParseNext(const std::string& regularExpression,
                     std::string::const_iterator& regexIterator,
                     const Regex::IRegexParser& parser)
const
{
    std::string tmpRegex = regularExpression.substr(regexIterator - regularExpression.begin());
    regexIterator += tmpRegex.size();

    return ( parser.Parse(tmpRegex) );
}
