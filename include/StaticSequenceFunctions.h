#pragma once

#include <cctype>
#include <cstdint>
#include <cstring>

namespace Sequence
{
// Returns sign of $i if $i != 0 else 0
extern int Sign(int i);

// An strcmp that takes strings' length into account.
extern int Compare(const char * a, const char * b);

// Returns whether $str is alphanumeric or not
extern bool AllAlphaNumeric( const char * str, uint32_t len );

extern char HighestOfChar( char c, int sign );

extern char LowestOfChar( char c, int sign );

extern char DecadeOfChar( char c, int sign );
}


