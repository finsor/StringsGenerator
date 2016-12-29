#include "ProcessorsHandler.h"

#include <stdexcept>

#include "IDelimiterProcessor.h"
#include "IRegexParser.h"
#include "Formatter.h"


std::string
Regex::ProcessorsHandler::Process(const std::string& regularExpression,
                                  std::string::const_iterator& regexIterator,
                                  const IRegexParser& parser,
                                  const std::string& secondOperand)
const
{
    IDelimiterProcessor *processor = GetProcessorByTrigger(*regexIterator);

    if( nullptr == processor )
        return ( std::string(1, *regexIterator++) );
    else
        return ( processor->Process(regularExpression,
                                    regexIterator,
                                    parser,
                                    _multiplyProcessor) );
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
    std::vector<IDelimiterProcessor*>::const_iterator pos = ProcessorReferenceByTrigger(trigger);
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
Regex::ProcessorsHandler::GetProcessorByTrigger(char c) const
{
    std::vector<IDelimiterProcessor*>::const_iterator pos = ProcessorReferenceByTrigger(c);

    if( _delimitersProcessors.end() == pos )
        return ( nullptr );

    return ( *pos );
}

std::vector<Regex::IDelimiterProcessor*>::const_iterator
Regex::ProcessorsHandler::ProcessorReferenceByTrigger(char trigger) const
{
    for(std::vector<IDelimiterProcessor*>::const_iterator iter = _delimitersProcessors.begin();
            iter != _delimitersProcessors.end();
            ++iter)
    {
        if( trigger == (*iter)->Trigger() )
            return ( iter );
    }

    return ( _delimitersProcessors.end() );
}

//std::string
//Regex::ProcessorsHandler::Process(const std::string& regularExpression,
//                                  std::string::const_iterator& regexIterator,
//                                  const IRegexParser& parser,
//                                  std::string& dst,
//                                  const std::string& lastResult)
//const
//{
//    // Get matching processor
//    std::vector<IDelimiterProcessor*>::const_iterator processor = Find(*regexIterator);
//
//    // If no processor found, just copy, ignoring $LITERAL
//    if( processor == _delimitersProcessors.end() )
//        return ( CopyIgnoringLiteral(regularExpression, regexIterator) );
//
//    // Else, return processed result
//    else
//        return ( (*processor)->Process(regularExpression, regexIterator, parser, dst, lastResult) );
//}
//
//std::string
//Regex::ProcessorsHandler::CopyIgnoringLiteral(const std::string& regularExpression,
//        std::string::const_iterator& regexIterator) const
//{
//    std::string result;
//
//    if( LITERAL == *regexIterator )
//        HandleLiteral(regularExpression, regexIterator);
//
//    result = std::string(1, *regexIterator++);
//
//    if( regexIterator != regularExpression.end() )
//        return ( multiplier->Process(regularExpression, regexIterator) );
//
//    return ( result );
//}
//
//void
//Regex::ProcessorsHandler::HandleLiteral(const std::string& regularExpression,
//        std::string::const_iterator& regexIterator) const
//{
//    ++regexIterator;
//
//    if( regularExpression.end() == regexIterator )
//    {
//        std::string ex = Error::Formatter() <<
//        "Error: Unexpected end of regex at" << regularExpression << "[" << regexIterator - regularExpression.begin() << "]";
//
//        throw std::runtime_error(ex);
//    }
//}
