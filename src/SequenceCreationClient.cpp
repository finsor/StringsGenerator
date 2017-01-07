#include "SequenceCreationClient.h"

#include <iostream>
#include <cstring>

#include "SequenceCreator.h"
#include "StaticSequenceFunctions.h"
#include "StringHelperStaticFunctions.h"

Sequence::SequenceCreationClient::SequenceCreationClient(
    std::string start,
    std::string stop,
    int difference,
    std::string before,
    std::string separator,
    std::string after)
    :
    _before(before.c_str()),
    _separator(separator.c_str()),
    _after(after.c_str())
{
    _sequenceCreator =
        new SequenceCreator(start.c_str(), stop.c_str(), difference);
}

Sequence::SequenceCreationClient::~SequenceCreationClient()
{
    delete ( _sequenceCreator );
}

const char *
Sequence::SequenceCreationClient::Next()
{
#define BEFORE 0
#define CALCUL 1
#define SEPAFT 2
#define NULLPT 3

    static int state = 0;

    switch(state)
    {
    case SEPAFT:

        _sequenceCreator->CalculateNext();

        if( !_sequenceCreator->End() )
        {
            state = CALCUL;

            return ( _separator );
        }
        else // end
        {
            state = NULLPT;

            return ( _after );
        }


    case CALCUL:

        state = SEPAFT;

        return ( _sequenceCreator->Get() );


    case NULLPT:

        return ( nullptr );


    case BEFORE:

        state = CALCUL;

        return ( _before );
    }

    return ( nullptr );
}
