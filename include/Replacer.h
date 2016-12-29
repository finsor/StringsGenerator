#pragma once

#include <map>
#include <string>


class Replacer
{
public:

    Replacer() {}
    virtual ~Replacer() {}

    // Function gets "before" and "after" values and adds it to the container
    // Returns whether successfully inserted or not
    bool Add(std::string key, std::string value);

    // Function gets a "before" value and removes it from the container
    // Returns whether successfully removed or not
    bool Remove(const std::string& key);

    // Function get a string
    // and returns a new string containing replaced values
    std::string GetReplaced(const std::string& src) const;

private:

    // Container of pairs.
    // Key is "before" value, Value is "after" value
    std::map<std::string, std::string> _dictionary;

    // Returns whether a given key exists
    bool Exists (const std::string& key) const;

    // Function gets a string and an iterator
    // Returns a corresponding pair for the key starting at $iter
    // If no corresponding pair, returns <*iterator, *iterator>
    std::pair<std::string, std::string>
    GetMatchingPair(const std::string& src,
                    std::string::const_iterator& iter) const;

    // Function gets a string and a location
    // Returns a corresponding pair for the key starting at $iter
    // If no corresponding pair, returns null
    std::pair<std::string, std::string>*
    GetPairFromString(const std::string& src,
                                size_t start) const;

};
