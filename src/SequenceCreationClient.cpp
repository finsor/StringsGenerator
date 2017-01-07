#include "SequenceCreationClient.h"

#include <iostream>
#include <cstring>

#include "SequenceCreator.h"
#include "StaticSequenceFunctions.h"
#include "StringHelperStaticFunctions.h"


Sequence::SequenceCreationClient::~SequenceCreationClient()
{
    delete ( _sequenceCreator );
}

std::string
Sequence::SequenceCreationClient::UsageString()
{
    return (
""
            );
}

bool
Sequence::SequenceCreationClient::GenerateSequence(
    std::string start,
    std::string stop,
    uint32_t differenceMultiplication,
    std::string before,
    std::string separator,
    std::string after)
{
    if( !RememberRequest(start, stop, differenceMultiplication) )
        return ( false );

    std::cout << before << start;
    PrintSequence(separator);
    std::cout << after;

    return ( true );
}

/* private */

void
Sequence::SequenceCreationClient::PrintSequence(std::string& separator)
{
    while( !_sequenceCreator->End() )
    {
//        std::cout << separator << _sequenceCreator->GetNext();
    }
}

int
Sequence::SequenceCreationClient::Difference(
    std::string& start,
    std::string& stop,
    uint32_t differenceMultiplication)
const
{
    return ( differenceMultiplication * Sequence::Compare(start.c_str(), stop.c_str()) );
}

bool
Sequence::SequenceCreationClient::RememberRequest(
    std::string& start,
    std::string& stop,
    uint32_t differenceMultiplication)
{
    int difference = Difference(start, stop, differenceMultiplication);

    bool success   = Register(start, stop, difference);

    return ( success );
}

bool
Sequence::SequenceCreationClient::Register(
    std::string& start,
    std::string& stop,
    int difference)
{
    if( IsValidSequence(start, stop, difference) )
    {
        delete ( _sequenceCreator );

//        _sequenceCreator = new Sequence::SequenceCreator(start.c_str(), stop.c_str(), difference);

        return ( true );
    }
    else
        return ( false );
}

bool
Sequence::SequenceCreationClient::IsValidSequence(
    std::string& start,
    std::string& stop,
    int difference)
const
{
    return(
              !start.empty()             &&
              !stop.empty()              &&
              CheckValues(start, stop)
          );
}

bool
Sequence::SequenceCreationClient::CheckValues(
    std::string& a,
    std::string& b)
const
{
    return (
               Sequence::AllAlphaNumeric(a.c_str(), a.size())  &&
               Sequence::AllAlphaNumeric(b.c_str(), b.size())  &&
//               a != "0"                                        &&
//               b != "0"                                        &&
               StringHelper::Reverse_SameTypeCharacters(a, b)
           );
}
