#include "Multiplier.h"

#ifdef DEBUG
#include <iostream>
#endif // DEBUG

#include <string>
#include <stdexcept>
#include <cstdlib>

#include "IRegexParser.h"
#include "BracketsContentProcessor.h"
#include "Formatter.h"
#include "CSRandom.h"


std::string
Regex::Multiplier::Multiply(const std::string& src,
                            uint32_t times)
const
{
    std::string result;

    while(times-- > 0)
        result += src;

    return ( result );
}


std::string
Regex::Multiplier::Process(const std::string&              regularExpression,
                           std::string::const_iterator&    regexIterator,
                           const Regex::IRegexParser&      parser,
                           const std::string&              stringToMultiply)
const
{
    uint32_t multiplier = GetMultiplier(regularExpression,
                                        regexIterator,
                                        parser);


    std::string result = Multiply(stringToMultiply, multiplier);

    if( Trigger() == *regexIterator )
        return ( Process(regularExpression,
                         regexIterator,
                         parser,
                         result) );
    else
        return ( result );
}

uint32_t
Regex::Multiplier::GetMultiplier(const std::string&              regularExpression,
                                 std::string::const_iterator&    regexIterator,
                                 const Regex::IRegexParser&      parser)
const
{
    std::string bracketsParsedContent = BracketsContentProcessor::GetContent(
                                            regularExpression,
                                            regexIterator);

    uint32_t multiplier = GetMultiplier(bracketsParsedContent);

    return ( multiplier );
}

/* private */

uint32_t
Regex::Multiplier::GetMultiplier(const std::string& str)
const
{
    std::string::const_iterator result_iter = str.begin();

    int minimum = GetNextNumber(str, result_iter);

    if( str.end() == result_iter )
        return ( minimum );

    else
    {
        int maximum = GetNextNumber(str, ++result_iter);

        if( minimum > maximum )
        {
            std::string ex = StringHelper::Formatter() <<
                             "Unacceptable range " << minimum << "," << maximum << " inside multiplier.";

            throw std::runtime_error(ex);
        }

        Random::CSRandom rand;

        return ( rand.Generate(minimum, maximum) );
    }
}

uint32_t
Regex::Multiplier::GetNextNumber(const std::string& str,
                                 std::string::const_iterator& iter)
const
{
    uint32_t number = IncrementingAtoi(str, iter);

    if( str.end() ==  iter || _separator == *iter )
        return ( number );

    else
    {
        throw std::runtime_error(StringHelper::Formatter() <<
                                 "Unexpected character '" << *iter << "' inside multiplier.");
    }
}

uint32_t
Regex::Multiplier::IncrementingAtoi(const std::string& str,
                                    std::string::const_iterator& iter)
const
{
    uint32_t number = 0;

    while( iter < str.end() && isdigit(*iter) )
    {
        number = number * 10 + (*iter - '0');
        iter++;
    }

    return ( number );
}
