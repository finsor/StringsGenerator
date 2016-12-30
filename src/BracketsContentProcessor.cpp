#include "BracketsContentProcessor.h"

#ifdef DEBUG
#include <iostream>
#endif // DEBUG

#include <stdexcept>
#include <string>

#include "Formatter.h"

std::string
Regex::BracketsContentProcessor::Process(
    const std::string&              regularExpression,
    std::string::const_iterator&    regexIterator,
    const Regex::IRegexParser&      parser,
    const Regex::IMultiplier        *multiplier,
    std::string&                    destination)
const
{
    std::string bracketsContent = GetContent(regularExpression, regexIterator);
    std::string parsedContent   = parser.Parse(bracketsContent);

    return ( parsedContent );
}

/* private */

std::string
Regex::BracketsContentProcessor::GetContent(
    const std::string&              regularExpression,
    std::string::const_iterator&    regexIterator)
const
{
    std::string destination;

    if( regexIterator >= regularExpression.end() || !Cut(regularExpression, ++regexIterator, destination) )
    {
        throw std::runtime_error(StringHelper::Formatter() <<
                                 "Closer not found for " << _start);
    }

    return ( destination );
}

bool
Regex::BracketsContentProcessor::Cut(const std::string&             original,
                                     std::string::const_iterator&   iter,
                                     std::string&                   destination)
const
{
    uint32_t counter = 1;

    while( iter < original.end() )
    {
        if( *iter == _start)
            ++counter;
        else if( *iter == _stop )
            --counter;
        else if( *iter == '\\' )
            destination += *iter++;


        if( counter != 0)
            destination += *iter++;
        else
        {
            ++iter;
            break;
        }
    }

    return ( 0 == counter );
}
