#include "SequenceCreator.h"

#ifdef DEBUG
#include <iostream>
#endif // DEBUG

#include <string>

#include "StringHelperStaticFunctions.h"

Sequence::SequenceCreator::~SequenceCreator()
{
#ifdef DEBUG
    std::cout << "~SequenceCreator" << std::endl;
#endif // DEBUG
}

std::string
Sequence::SequenceCreator::GetNext()
{
    ChangeCurrentByDifference();

    return ( _current );
}

bool
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
    int sign  = Sign(_difference);

    while( !(_end = _current.compare(_stop) == 0 ) && times > 0 )
    {
        ChangeCurrentBy(sign);
        --times;
    }
}

void
Sequence::SequenceCreator::ChangeCurrentBy(int sign)
{
    int index = _current.size() - 1;

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
        _current = StringHelper::ShiftRight(_current);
        _current[0] = DecadeOfChar(_stop[_stop.size() - _current.size()], sign);
    }
    else if (sign < 0)
    {
        _current = StringHelper::ShiftLeft(_current);
    }

    if(_current[0] == '0')
    {
        _current = StringHelper::StripFromLeft(_current, '0');
    }
}


char
Sequence::SequenceCreator::HighestOfChar(char c, int sign)
const
{
    if(isupper(c))
    {
        if(sign > 0)
            return 'Z';
        return 'A';
    }
    if(islower(c))
    {
        if(sign > 0)
            return 'z';
        return 'a';
    }
    if(isdigit(c))
    {
        if(sign > 0)
            return '9';
        return '0';
    }

    return 0;
}

char
Sequence::SequenceCreator::LowestOfChar(char c, int sign)
const
{
    return (HighestOfChar(c, -sign));
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

int
Sequence::SequenceCreator::Sign(int i)
const
{
    return ((i>0) - (i<0));
}
