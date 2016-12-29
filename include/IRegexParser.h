#pragma once

#include <string>


namespace Regex
{
class IRegexParser
{
public:

    IRegexParser() {}
    virtual ~IRegexParser() {}

    // Function gets a regular expression
    // and returns a translated result
    virtual std::string Parse(const std::string& regularExpression) const = 0;

};
}
