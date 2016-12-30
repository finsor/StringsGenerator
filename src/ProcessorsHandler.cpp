#include "ProcessorsHandler.h"

#include <algorithm>
#include <stdexcept>

#include "IDelimiterProcessor.h"
#include "IRegexParser.h"
#include "Formatter.h"


std::string
Regex::ProcessorsHandler::Process(const std::string&              regularExpression,
                                  std::string::const_iterator&    regexIterator,
                                  const IRegexParser&             parser,
                                  std::string&                    destination)
const
{
    std::cout << "*regiter=" << *regexIterator << std::endl;
    IDelimiterProcessor *delimiterProcessor = GetProcessorByTrigger(*regexIterator);

    if( nullptr == delimiterProcessor )
    {
        std::cout << "in null" << std::endl;
        if( _multiplyProcessor->Trigger() == *regexIterator )
        {
            throw std::runtime_error(StringHelper::Formatter() <<
                                     "Unexpected multiplier.");
        }

        return ( std::string(1, *regexIterator++) );
    }
    else
    {
        std::cout << "in process" << std::endl;
        return ( delimiterProcessor->Process(regularExpression,
                                             regexIterator,
                                             parser,
                                             _multiplyProcessor,
                                             destination) );
    }
}

bool
Regex::ProcessorsHandler::AddProcessor(IDelimiterProcessor* delimiterProcessor)
{
    if( !GetProcessorByTrigger(delimiterProcessor->Trigger()) )
    {
        _delimitersProcessors.push_back(delimiterProcessor);
        return ( true );
    }
    else
        return ( false );
}

bool
Regex::ProcessorsHandler::DelProcessor(char trigger)
{
    std::vector<IDelimiterProcessor*>::const_iterator pos = GetProcessorReferenceByTrigger(trigger);

    if ( pos != _delimitersProcessors.end() )
    {
        _delimitersProcessors.erase(pos);
        return ( true );
    }
    else
        return ( false );
}

/* private */

Regex::IDelimiterProcessor*
Regex::ProcessorsHandler::GetProcessorByTrigger(
    char trigger)
const
{
    std::vector<IDelimiterProcessor*>::const_iterator pos = GetProcessorReferenceByTrigger(trigger);

    if( _delimitersProcessors.end() == pos )
        return ( nullptr );

    return ( *pos );
}

std::vector<Regex::IDelimiterProcessor*>::const_iterator
Regex::ProcessorsHandler::GetProcessorReferenceByTrigger(
    char trigger)
const
{
    std::vector<Regex::IDelimiterProcessor*>::const_iterator pos =
        std::find_if(
            _delimitersProcessors.begin(),
            _delimitersProcessors.end(),
            [=](const IDelimiterProcessor* obj) -> bool { return (obj->Trigger() == trigger); });

    return ( pos );
}
