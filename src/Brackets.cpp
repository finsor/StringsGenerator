#include "Brackets.h"

#ifdef DEBUG
#include <iostream>
#endif // DEBUG

#include <string>

#include "BracketsContentProcessor.h"
#include "IMultiplier.h"
#include "IRegexParser.h"


std::string
Regex::Brackets::Process(
    const std::string&              regularExpression,
    std::string::const_iterator&    regexIterator,
    const Regex::IRegexParser&      parser,
    const Regex::IMultiplier        *multiplier)
const
{
    std::string parsedContent = BracketsContentProcessor::Process(
                                    regularExpression,
                                    regexIterator,
                                    parser,
                                    multiplier);

    if( nullptr == multiplier || multiplier->Trigger() != *regexIterator )
        return ( parsedContent );

    return ( multiplier->Process(regularExpression,
                                 regexIterator,
                                 parser,
                                 parsedContent) );
}
