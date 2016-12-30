#include "SequenceCreationClient.h"

#include <string>

#include "SequenceCreator.h"
#include "StringHelperStaticFunctions.h"


Sequence::SequenceCreationClient::~SequenceCreationClient()
{
    delete ( _sequenceCreator );
}

bool
Sequence::SequenceCreationClient::IsValidSequence(
    std::string& start,
    std::string& stop,
    int difference)
const
{
    return( !start.empty() &&
            !stop.empty()  &&
            StringHelper::Reverse_SameTypeCharacters(start, stop) );
}

bool
Sequence::SequenceCreationClient::Sign(
    std::string start,
    std::string stop,
    int difference)
{
    if( IsValidSequence(start, stop, difference) )
    {
        delete ( _sequenceCreator );

        _sequenceCreator = new Sequence::SequenceCreator(start, stop, difference);

        return ( true );
    }
    else
    {
        return ( false );
    }
}

std::string
Sequence::SequenceCreationClient::Next()
{
    return ( _sequenceCreator->GetNext() );
}

bool
Sequence::SequenceCreationClient::End()
const
{
    return ( _sequenceCreator->End() );
}
