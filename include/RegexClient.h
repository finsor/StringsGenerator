#pragma once

#include <string>
#include <memory>

#include "IRegexParser.h"


namespace Regex
{
class RegexClient
{
public:

    RegexClient() {}
    virtual ~RegexClient() {}

    std::string UsageString();
    std::string Generate(std::string& regularExpression);
    std::string Generate(const char * regularExpression);

private:

    enum Command{Usage, Process};

    std::string Preprocessor(const std::string& regularExpression);
    std::string Processor   (const std::string& regularExpression);

    // Prevents copy constructor
    RegexClient(const RegexClient& c);

    // Prevents assignment operator.
    RegexClient& operator=(const RegexClient& c);
};
}
