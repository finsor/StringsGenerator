#include "Collection.h"

#include <string>

#include "BracketsContentProcessor.h"
#include "CSRandom.h"
#include "IRegexParser.h"
#include "PrintableCharacters.h"


std::string
Regex::Collection::Process(
    const std::string&              regularExpression,
    std::string::const_iterator&    regexIterator,
    const Regex::IRegexParser&      parser,
    const Regex::IMultiplier        *multiplier,
    std::string&                    destination)
const
{
    bool exclude = ExcludeOrNot(regexIterator);

    std::string collection = CreateCollection(
                                 regularExpression,
                                 regexIterator,
                                 parser,
                                 multiplier,
                                 destination,
                                 exclude);

    if( 0 == collection.size() )
        return ( "" );

    uint32_t times = GetTimes(regularExpression,
                              regexIterator,
                              parser,
                              multiplier);

    return ( Collect(collection, times) );
}

/* private */

std::string
Regex::Collection::Collect(const std::string&   collection,
                           uint32_t             times)
const
{
    std::string result;

    while( times-- > 0 )
        result += RandomChar(collection);

    return ( result );
}


char
Regex::Collection::RandomChar(const std::string& characters)
const
{
    Random::CSRandom randomizer;

    return ( characters[randomizer.Generate(0, characters.size() - 1)] );
}

uint32_t
Regex::Collection::GetTimes(
    const std::string&              regularExpression,
    std::string::const_iterator&    regexIterator,
    const Regex::IRegexParser&      parser,
    const Regex::IMultiplier        *multiplier)
const
{
    if( regexIterator < regularExpression.end() &&
            multiplier != nullptr && multiplier->Trigger() == *regexIterator)
    {
        return ( multiplier->GetMultiplier(regularExpression,
                                           regexIterator,
                                           parser)
               );
    }
    else
        return ( 1 );
}


std::string
Regex::Collection::CreateCollection(
    const std::string&              regularExpression,
    std::string::const_iterator&    regexIterator,
    const Regex::IRegexParser&      parser,
    const Regex::IMultiplier        *multiplier,
    std::string&                    destination,
    bool                            exclude)
const
{
    std::string collection = BracketsContentProcessor::Process(
                                 regularExpression,
                                 regexIterator,
                                 parser,
                                 multiplier,
                                 destination);

    if( !exclude )
        return ( collection );
    else
        return ( Regex::PrintableCharacters::GetPrintableCharacters(collection) );
}


bool
Regex::Collection::ExcludeOrNot(std::string::const_iterator& regexIterator)
const
{
    if( _excluder == *(regexIterator+1) )
    {
        regexIterator++;
        return ( true );
    }

    return ( false );
}
