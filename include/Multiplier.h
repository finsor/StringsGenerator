#pragma once

#include <string>

#include "BracketsContentProcessor.h"
#include "IMultiplier.h"

namespace Regex
{
class Multiplier : public IMultiplier, public BracketsContentProcessor
{
public:

    Multiplier(char start, char stop, char separator) :
        BracketsContentProcessor(start, stop), _separator(separator)
    {}

    virtual ~Multiplier() {}

    char Trigger() const
    {
        return ( BracketsContentProcessor::Trigger() );
    }

    virtual std::string Process(const std::string&              regularExpression,
                                std::string::const_iterator&    regexIterator,
                                const Regex::IRegexParser&      parser,
                                const std::string&              stringToMultiply)
    const;

    uint32_t GetMultiplier(const std::string&              regularExpression,
                                std::string::const_iterator&    regexIterator,
                                const Regex::IRegexParser&      parser)
    const;

    std::string Multiply(const std::string& src,
                         uint32_t times)
    const;

private:

    char _separator;

    // Function returns a random number from requested range.
    // $str - result of regex inside brackets (result of brackets' content)
    // Errors:
    //      unexpected character (not \0 or $_separator)
    //      min > max
    uint32_t GetMultiplier(const std::string& str) const;

    // Function returns next number
    // If stopped at \0 or $_separator
    // Errors:
    //      unexpected character (not \0 or $_separator)
    uint32_t GetNextNumber(const std::string& str,
                           std::string::const_iterator& iter)
    const;

    // Function returns number starting at $iter
    // Basically same as atoi but increments iterator
    uint32_t IncrementingAtoi(const std::string& str,
                              std::string::const_iterator& iter)
    const;


};
}
