#include "Replacer.h"

#ifdef DEBUG
#include <iostream>
#endif // DEBUG

#include <algorithm>
#include <stdexcept>
#include <map>

//#include "Formatter.h"


bool
Replacer::Add(std::string key, std::string value)
{
    if( Exists(key) )
        return ( false );

    _dictionary[key] = value;

    return ( true );
}

bool
Replacer::Remove(const std::string& key)
{
    return ( 1 == _dictionary.erase(key) );
}

std::string
Replacer::GetReplaced(const std::string& src) const
{
    std::string result;
    std::string::const_iterator iter = src.begin();
    std::pair<std::string, std::string> temporaryPair;

    while( iter < src.end() )
    {
        temporaryPair = GetMatchingPair(src, iter);

        result += temporaryPair.second;
        iter   += temporaryPair.first.size();
    }

    return ( result );
}

/* private */

std::pair<std::string, std::string>
Replacer::GetMatchingPair(const std::string& src, std::string::const_iterator& iter) const
{
    std::pair<std::string, std::string> *p =
        GetPairFromString(src, iter - src.begin());

    if( nullptr == p )
        return ( std::pair<std::string, std::string>(std::string(1, *iter), std::string(1, *iter)) );
    else
        return ( *p );
}


std::pair<std::string, std::string>*
Replacer::GetPairFromString(const std::string& src, size_t start) const
{
    std::map<std::string, std::string>::const_iterator iter;
    std::string key;

    // For each key
    for(iter = _dictionary.begin(); iter != _dictionary.end(); ++iter)
    {
        // If src[start]...src[start+keylen] is key
        // then return true

        key = iter->first;
        if( !src.compare(start, key.size(), key) )
            return ( (std::pair<std::string, std::string>*)&(*iter) );
    }

    return ( nullptr );
}

bool
Replacer::Exists(const std::string& key) const
{
    return ( _dictionary.end() != _dictionary.find(key) );
}
