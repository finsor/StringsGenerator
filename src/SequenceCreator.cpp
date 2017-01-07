#include "SequenceCreator.h"

#ifdef DEBUG
#include <iostream>
#include <cstdlib>
#endif // DEBUG

#include <cstring>
#include <stdexcept>

#include "Formatter.h"
#include "StaticSequenceFunctions.h"
#include "StringHelperStaticFunctions.h"


Sequence::SequenceCreator::SequenceCreator(
    const std::string& start,
    const std::string& stop,
    int difference) :
    _start(start),
    _current(start),
    _stop(stop)
{
    Create(difference);
}

Sequence::SequenceCreator::SequenceCreator(
    const char * start,
    const char * stop,
    int difference) :
    _start(start),
    _current(start),
    _stop(stop)
{
    Create(difference);
}

void
Sequence::SequenceCreator::CalculateNext()
{
    uint32_t times = _absDifference;

    while( times-- > 0 )
    {
        _current += _sign;
    }
}

const char *
Sequence::SequenceCreator::Get()
{
    return ( _current );
}

bool
Sequence::SequenceCreator::End()
{
    if( _difference < 0 && _current < _stop )
        return ( true );

    if ( _difference > 0 && _current > _stop )
        return ( true );

    return ( false );
}

/* private */

void
Sequence::SequenceCreator::Create(int difference)
{
    if( !StringHelper::Reverse_SameTypeCharacters(_start, _stop, _start.operator std::string().size()) )
        throw std::domain_error(StringHelper::Formatter() << "Limits are not of same type: " << _start << ", " << _stop);


    _difference     = difference;
    _absDifference  = std::abs(_difference);
    _sign           = Sequence::Sign(_difference);
}
