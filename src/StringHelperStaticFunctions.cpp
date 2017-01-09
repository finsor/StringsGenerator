#include "StringHelperStaticFunctions.h"

#include <cctype>
#include <sstream>

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

std::vector<std::string>
StringHelper::Split(const std::string& str, char delimiter)
{
    std::vector<std::string> result;

    if( str.empty() )
        return ( result );

    std::string::const_iterator last = str.begin();
    std::string::const_iterator iter = str.begin() + 1;

    while( iter != str.end() )
    {
        if( '\\' != *(iter - 1) && delimiter == *iter )
        {
            std::string tmp(last, iter);
            result.push_back(tmp);

            last = iter + 1;
        }

        ++iter;
    }

    std::string tmp(last, iter);
    result.push_back(tmp);

    return ( result );
//
//    std::stringstream test(str);
//    std::string segment;
//    std::vector<std::string> seglist;
//
//    while(std::getline(test, segment, delimiter))
//    {
//       seglist.push_back(segment);
//    }
//
//    return ( seglist );
}

bool
StringHelper::IsNumber(const std::string& str)
{
    std::string::const_iterator iter = str.begin();

    if ( str.size() > 1 && *iter == '-' )
        ++iter;

    while( iter != str.end() && isdigit(*iter) )
        ++iter;

    return ( iter == str.end() );
}
