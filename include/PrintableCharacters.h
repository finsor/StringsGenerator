
#pragma once

#include <string>
#include <algorithm>

#include "CSRandom.h"


namespace Regex
{
class PrintableCharacters
{
public:

    static
    void
    SetPrintableCharacters(std::string printableCharacters)
    {
        _printableCharacters = printableCharacters;
    }

    static
    std::string
    GetPrintableCharacters(std::string excluded = "")
    {
        std::string result(_printableCharacters);

        for(std::string::iterator iter = excluded.begin(); iter != excluded.end(); ++iter)
        {
            result.erase(std::remove(result.begin(), result.end(), *iter), result.end());
        }

        return ( result );
    }

    static
    std::string
    GetRandomCharacters(uint32_t amount)
    {
        std::string result;
        Random::CSRandom randomizer;

        while(amount-- > 0)
        {
            result += _printableCharacters[randomizer.Generate(0, _printableCharacters.size() -1)];
        }

        return ( result );
    }

private:
    static std::string _printableCharacters;
};
}
