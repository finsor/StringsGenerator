#include "RandomString.h"

#ifdef DEBUG
#include <iostream>
#endif

#include <string>

#include "PrintableCharacters.h"
#include "CSRandom.h"

char
Regex::RandomString::Trigger() const
{
    return ( _delimiter );
}

std::string
Regex::RandomString::Process(
    const std::string&              regularExpression,
    std::string::const_iterator&    regexIterator,
    const Regex::IRegexParser&      parser,
    const Regex::IMultiplier        *multiplier,
    std::string&                    destination)
const
{
    ++regexIterator;

    std::string randomString = GenerateRandomString(regularExpression,
                               regexIterator,
                               parser,
                               multiplier);

    return ( randomString );
}

/* private */

std::string
Regex::RandomString::GenerateRandomString(const std::string&              regularExpression,
        std::string::const_iterator&    regexIterator,
        const Regex::IRegexParser&      parser,
        const Regex::IMultiplier        *multiplier)
const
{
    uint32_t times = 1;

    if( multiplier->Trigger() == *regexIterator )
        times = multiplier->GetMultiplier(regularExpression,
                                          regexIterator,
                                          parser);

    return ( MultipleRandomStrings(times) );
}

std::string
Regex::RandomString::MultipleRandomStrings(uint32_t times)
const
{
    std::string result;
    Random::CSRandom randomizer;

    while( times-- > 0 )
    {
        result +=
            Regex::PrintableCharacters::GetRandomCharacters(
                randomizer.Generate(
                    _minLength, _maxLength));
    }

    return ( result );
}
