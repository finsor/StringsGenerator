#include "SequenceType.h"

#include <ostream>
#include <stdexcept>
#include <string>

#include "ISequenceType.h"
#include "Formatter.h"
#include "StaticSequenceFunctions.h"
#include "StringHelperStaticFunctions.h"


Sequence::SequenceType::SequenceType(std::string variable) :
    _var(variable)
{
    if( variable.empty() || !Sequence::AllAlphaNumeric(variable.c_str(), variable.size()) )
        throw std::domain_error(StringHelper::Formatter() << "Bad sequence type input: " << variable);
}

Sequence::SequenceType::SequenceType(const ISequenceType& other)
{
    _var = other.operator std::string();
}

Sequence::SequenceType&
Sequence::SequenceType::operator =(const ISequenceType& other)
{
    _var = other.operator std::string();

    return ( *this );
}

Sequence::SequenceType::operator std::string()
const
{
    return ( _var );
}

Sequence::SequenceType::operator const char*()
const
{
    return ( _var.c_str() );
}

void
Sequence::SequenceType::operator ++()
{
    Add(+1);
}

void
Sequence::SequenceType::operator --()
{
    Add(-1);
}

void
Sequence::SequenceType::operator +=(int n)
{
    if( n < 0 )
        operator-=(-n);

    else
    {
        while( n-- > 0 )
        {
            operator++();
        }
    }
}

void
Sequence::SequenceType::operator -=(int n)
{
    if( n < 0 )
        operator+=(n);

    else
    {
        while( n-- > 0 )
        {
            operator--();
        }
    }
}

bool
Sequence::SequenceType::operator ==(const ISequenceType& other)
const
{
    return ( 0 == _var.compare(other.operator std::string()) );
}

bool
Sequence::SequenceType::operator <=(const ISequenceType& other)
const
{
    return ( (*this == other) || (*this < other) );
}

bool
Sequence::SequenceType::operator >=(const ISequenceType& other)
const
{
    return ( (*this == other) || (*this > other) );
}

bool
Sequence::SequenceType::operator  >(const ISequenceType& other)
const
{
    return ( Sequence::Compare(other, *this) == +1 );
}

bool
Sequence::SequenceType::operator  <(const ISequenceType& other)
const
{
    return ( Sequence::Compare(other, *this) == -1 );
}

/* private */

void
Sequence::SequenceType::Add(int sign)
{
    std::string::iterator iter = _var.end() - 1;

    while( iter >= _var.begin() && *iter == Sequence::HighestOfChar(*iter, sign) )
    {
        *iter = Sequence::LowestOfChar(*iter, sign);
        --iter;
    }

    if( iter >= _var.begin() )
    {
        *iter += sign;
    }
    else // iter < _var.begin()
        if( sign > 0 )
        {
            _var = StringHelper::ShiftRight(_var);
            _var[0] = Sequence::DecadeOfChar(_var[0], sign);
        }
        else if( sign < 0 )
        {
            _var = StringHelper::ShiftLeft(_var);
        }

    StripZeroes();
}

void
Sequence::SequenceType::StripZeroes()
{
    while( _var.size() > 1 && _var[0] == '0' )
        _var = StringHelper::ShiftLeft(_var);
}
