#include "StaticSequenceFunctions.h"


int
Sequence::Sign(int i)
{
    return ((i>0) - (i<0));
}

int
Sequence::Compare(const char * a, const char * b)
{
    int lengthDifference = strlen(b) - strlen(a);

    if( 0 == lengthDifference )
        return ( Sign(strcmp(b, a)) );
    else
        return ( Sign(lengthDifference) );
}

bool
Sequence::AllAlphaNumeric( const char * str, uint32_t len )
{
    uint32_t index = 0;
    while( index < len && std::isalnum(str[index]) )
        ++index;

    return ( index == len );
}

char
Sequence::HighestOfChar( char c, int sign )
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
Sequence::LowestOfChar( char c, int sign )
{
    return ( HighestOfChar(c, -sign) );
}

char
Sequence::DecadeOfChar( char c, int sign )
{
    if(isalpha(c))
        return (LowestOfChar(c, sign));

    if(sign > 0)
        return '1';
    return '9';
}
