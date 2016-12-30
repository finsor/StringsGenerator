#pragma once

#include <string>

#include "BracketsContentProcessor.h"
#include "IRegexParser.h"


namespace Regex
{
class Collection : public BracketsContentProcessor
{
public:
    Collection(char start, char stop, char excluder) :
        BracketsContentProcessor(start, stop), _excluder(excluder)
    {}

    virtual ~Collection() {}

    std::string Process(const std::string&              regularExpression,
                        std::string::const_iterator&    regexIterator,
                        const Regex::IRegexParser&      parser,
                        const Regex::IMultiplier        *multiplier,
                        std::string&                    destination)
    const;

private:

    // Character used to mark "Anything but following collection"
    char _excluder;

    // Function gets a collection and a length
    // Returns $times random characters out of $collection
    std::string Collect(const std::string&   collection,
                        uint32_t             times)
    const;

    // Function gets a collection
    // Returns a random character out of it
    char RandomChar(const std::string& characters) const;

    // Function gets parameters for a multiplier
    // Returns 1 if no multiplier provided
    //      else multiplier's processing result
    uint32_t GetTimes(const std::string&              regularExpression,
                      std::string::const_iterator&    regexIterator,
                      const Regex::IRegexParser&      parser,
                      const Regex::IMultiplier        *multiplier)
    const;

    // Function returns the processed result of brackets' content
    std::string CreateCollection(const std::string&              regularExpression,
                                 std::string::const_iterator&    regexIterator,
                                 const Regex::IRegexParser&      parser,
                                 const Regex::IMultiplier        *multiplier,
                                 std::string&                    destination,
                                 bool                            exclude)
    const;

    // Functions returns whether to collect from given collection
    //      or not from it
    bool ExcludeOrNot(std::string::const_iterator& regexIterator) const;

};
}
