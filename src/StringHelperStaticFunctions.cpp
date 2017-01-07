#include "StringHelperStaticFunctions.h"

bool
StringHelper::IsSameType(char a, char b)
{
    return(
              (isupper(a) && isupper(b))
              ||
              (islower(a) && islower(b))
              ||
              (isdigit(a) && isdigit(b))
          );
}

bool
StringHelper::SameTypeCharacters(std::string& one, std::string& two, uint32_t n)
{
    if( one.empty() )
    {
        return ( two.empty() );
    }

    uint32_t maxIndex = std::min(one.size(), two.size());

    if( n > 0 )
        maxIndex = std::min(maxIndex, n);

    uint32_t oneIter = 0, twoIter = 0;

    while( oneIter < maxIndex &&
           twoIter < maxIndex &&
           IsSameType(one[oneIter], two[twoIter]) )
    {
        ++oneIter;
        ++twoIter;
    }

    return ( oneIter == maxIndex );
}

bool
StringHelper::Reverse_SameTypeCharacters(
    std::string one,
    std::string two,
    uint32_t n)
{
    std::reverse(one.begin(), one.end());
    std::reverse(two.begin(), two.end());

    return ( SameTypeCharacters(one, two, n) );
}

std::string
StringHelper::ShiftLeft(const std::string& str)
{
    return ( str.substr(1, str.size()) );
}

std::string
StringHelper::ShiftRight(const std::string& str)
{
    return ( " " + str );
}
