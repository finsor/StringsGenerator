
#include <cctype>

namespace Sequence
{
// Returns sign of $i if $i != 0 else 0
static int Sign(int i);

// An strcmp that takes strings' length into account.
static int Compare(const char * a, const char * b);

// Returns whether $str is alphanumeric or not
static bool AllAlphaNumeric( const char * str, uint32_t len );
}

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
