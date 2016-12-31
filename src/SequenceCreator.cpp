#include "SequenceCreator.h"

#ifdef DEBUG
#include <iostream>
#include <cstdlib>
#endif // DEBUG

#include <cstring>

#include "StaticSequenceFunctions.h"
#include "StringHelperStaticFunctions.h"

Sequence::SequenceCreator::SequenceCreator(const char * start, const char * stop, int difference) :
    ISequenceCreator(start, stop, difference), _end( std::strcmp(start, stop) == 0 )
{
    _current = new char[std::max(strlen(start), strlen(stop)) + 1];

    strcpy(_current, _start);
    _currentLength = strlen(_current);

    _absDifference = std::abs(difference);
    _sign = Sequence::Sign(difference);
}

Sequence::SequenceCreator::~SequenceCreator()
{
    delete [] _current;
}

const char *
Sequence::SequenceCreator::GetNext()
{
    ChangeCurrentByDifference();

    return ( _current );
}

inline bool
Sequence::SequenceCreator::End()
const
{
    return ( _end );
}

/* private */

void
Sequence::SequenceCreator::ChangeCurrentByDifference()
{
    uint32_t times = _absDifference;

    while( !(_end = ( 0 == std::strcmp(_current, _stop) ) ) && times-- > 0 )
    {
        ChangeCurrentBy(_sign);
    }
}

void
Sequence::SequenceCreator::ChangeCurrentBy(int sign)
{
    int index = _currentLength - 1;

    while ( index > -1 &&
            _current[index] == HighestOfChar(_current[index], sign) )
    {
        _current[index] = LowestOfChar(_current[index], sign);
        --index;
    }

    if(index >= 0 )
    {
        _current[index] += sign;
    }
    else if (sign > 0)
    {
        ShiftRight(_current);
        _currentLength++;

        _current[0] = DecadeOfChar(_stop[_stopLength - _currentLength], sign);
    }
    else if (sign < 0)
    {
        ShiftLeft(_current);
        --_currentLength;
    }

    while( _current[0] == '0' )
    {
        ShiftLeft(_current);
        --_currentLength;
    }
}

inline void
Sequence::SequenceCreator::ShiftLeft(char * buffer)
{
    while( *buffer++ = *buffer );
}

inline void
Sequence::SequenceCreator::ShiftRight(char * buffer)
{
    char *iter = buffer + strlen(buffer) + 1;

    while( iter!= buffer )
        *iter-- = *iter;
}

char
Sequence::SequenceCreator::HighestOfChar(char c, int sign)
const
{
    if(isupper(c))
    {
        if(sign > 0)
            return ( 'Z' );
        return 'A';
    }
    if(islower(c))
    {
        if(sign > 0)
            return ( 'z' );
        return ( 'a' );
    }
    if(isdigit(c))
    {
        if(sign > 0)
            return ( '9' );
        return ( '0' );
    }

    return ( 0 );
}

char
Sequence::SequenceCreator::LowestOfChar(char c, int sign)
const
{
    return ( HighestOfChar(c, -sign) );
}

char
Sequence::SequenceCreator::DecadeOfChar(char c, int sign)
const
{
    if(isalpha(c))
        return (LowestOfChar(c, sign));

    if(sign > 0)
        return '1';
    return '9';
}


