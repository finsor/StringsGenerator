#pragma once

#include <string>

#include "IDelimiterProcessor.h"


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

    std::string Process(const std::string& regularExpression,
                        std::string::const_iterator& regexIterator,
                        const IRegexParser& parser,
                        std::string& dst,
                        const std::string& lastResult) const;

private:
    char _delimiter;

    bool IsValid(std::string str) const;
};
}
