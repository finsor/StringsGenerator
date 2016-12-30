#pragma once

#include <string>

#include "IDelimiterProcessor.h"
#include "IMultiplier.h"
#include "IRegexParser.h"


namespace Regex
{
class Or : public IDelimiterProcessor
{
public:

    Or(char delimiter) :
        _delimiter(delimiter)
    {}

    virtual ~Or() {}

    char Trigger() const;

    std::string Process(const std::string&              regularExpression,
                        std::string::const_iterator&    regexIterator,
                        const Regex::IRegexParser&      parser,
                        const Regex::IMultiplier        *multiplier,
                        std::string&                    destination)
    const;

private:

    char _delimiter;

    std::string RandomalyChoose(const std::string& optionOne,
                                const std::string& optionTwo)
    const;

    std::string ParseNext(const std::string&            regularExpression,
                          std::string::const_iterator&  regexIterator,
                          const Regex::IRegexParser& parser)
    const;
};
}
