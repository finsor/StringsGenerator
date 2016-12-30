#pragma once

#include <vector>
#include <iostream>

#include "IProcessorsHandler.h"
#include "IDelimiterProcessor.h"
#include "IRegexParser.h"


namespace Regex
{
class ProcessorsHandler : public IProcessorsHandler
{
public:
    ProcessorsHandler(IMultiplier* multiplyProcessor = nullptr) :
        _multiplyProcessor(multiplyProcessor)
    {}

    virtual ~ProcessorsHandler() {}

    bool AddProcessor(IDelimiterProcessor*          delimiterProcessor);
    bool DelProcessor(char                          trigger);

    std::string Process(const std::string&              regularExpression,
                        std::string::const_iterator&    regexIterator,
                        const IRegexParser&             parser,
                        std::string&                    destination)
    const;

private:
    // Processors container
    std::vector<IDelimiterProcessor*>           _delimitersProcessors;

    IMultiplier*                                _multiplyProcessor;

    // Function returns a pointer to a processor of
    // requested delimiter
    // $c - requested delimiter
    IDelimiterProcessor* GetProcessorByTrigger(char trigger) const;

    // Function returns an iterator to location of
    // processor of requested delimiter
    // $c - requested delimiter
    std::vector<IDelimiterProcessor*>::const_iterator
    GetProcessorReferenceByTrigger(char trigger) const;

};
}
