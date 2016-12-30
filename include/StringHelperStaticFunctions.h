#pragma once

#ifdef DEBUG
#include <iostream>
#endif // DEBUG

#include <algorithm>
#include <string>


namespace StringHelper
{

// Function returns whether range limits are of same type
// For example, both are digits, or lower case letters.
static bool IsSameType(char a, char b);

// Checks if first n of strings are of same type
// Checks until either one's end if n is too big
// For example, following returns true:
//      one = "A1b2a1A"
//      two = "G6k3"
//      n   = 5
//  following returns false:
//      one = "1234a"
//      two = "1234A"
//      n   = 5
static bool SameTypeCharacters(std::string& one, std::string& two, uint32_t n = 0);

// Same as SameTypeCharacters in reverse.
static bool Reverse_SameTypeCharacters(std::string one, std::string two, uint32_t n = 0);

// Function returns $outStr as $inStr left shifted once
// For example, for input "ABCDE", output is "BCDE".
static std::string ShiftLeft(const std::string& str);

// Function returns $outStr as $inStr left shifted once
// For example, for input "ABCDE", output is "BCDE".
static std::string ShiftRight(const std::string& str);

// Function gets a string and a char
// Returns a new string, which is $str without leftest c's
// For example, for input "000ABC",'0' , output is "ABC".
static std::string StripFromLeft(const std::string& str, char c);

}

static bool
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

static bool
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

static bool
StringHelper::Reverse_SameTypeCharacters(
    std::string one,
    std::string two,
    uint32_t n)
{
    std::reverse(one.begin(), one.end());
    std::reverse(two.begin(), two.end());

    return ( SameTypeCharacters(one, two, n) );
}

static std::string
StringHelper::ShiftLeft(const std::string& str)
{
    return ( str.substr(1, str.size()) );
}

static std::string
StringHelper::ShiftRight(const std::string& str)
{
    return ( " " + str );
}

static std::string
StringHelper::StripFromLeft(const std::string& str, char c)
{
    std::string::size_type pos = str.find_first_not_of(c);

    return ( str.substr(pos, str.size()) );
}
