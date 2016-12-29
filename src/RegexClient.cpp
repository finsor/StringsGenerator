#include "RegexClient.h"

#include <string>
#include <stdexcept>

#include "Brackets.h"
#include "Collection.h"
#include "Multiplier.h"
//#include "Or.h"
#include "ProcessorsHandler.h"
//#include "RandomString.h"
//#include "Range.h"
#include "RegexParser.h"
#include "Replacer.h"

std::string
Regex::RegexClient::Generate(std::string& regularExpression)
{
    std::string newRegex = Preprocessor(regularExpression);
    std::string result   = Processor   (newRegex);

#ifdef DEBUG
    std::cout << "newRegex=" << newRegex << std::endl;
#endif // DEBUG

    return ( result );
}

std::string
Regex::RegexClient::UsageString()
{
    return (
"\
 \\ Literal - escape any of the following.\n\
( ) Brackets that contain a regular expression. Used for Ordering.\n\
[ ] Brackets that contain a regular expression that represents a characters collection.\n\
    Randomly returns a character from result, or not from result if used with '^'.\n\
{ } Brackets that contain a regular expression of a number that multiplies last expression.\n\
 -  Represents a range of characters of same type. For example, 0-3 translates to 0123 .\n\
 |  Logical 'OR' - Randomly returns either of its arguments.\n\
 .  Turns into a randomly chosen printable character.\n\
 *  Turns into a random string in a size between 0 and 255.\n\
 /  Replaces an expression with another expression before processing:\n\
    /? stands for {[01]}\n\
    /A stands for [A-Z]\n\
    /D stands for [^0-9]\n\
    /N stands for [^A-Z]\n\
    /W stands for [^0-9a-zA-Z_]\n\
    /a stands for [a-z]\n\
    /d stands for [0-9]\n\
    /n stands for [^a-z]\n\
    /w stands for [0-9a-zA-Z_]\
"
    );
}

/* private */

std::string
Regex::RegexClient::Preprocessor(const std::string& regularExpression)
{
    Replacer replacer;
    replacer.Add("/d", "[0-9]");
    replacer.Add("/D", "[^0-9]");
    replacer.Add("/a", "[a-z]");
    replacer.Add("/A", "[A-Z]");
    replacer.Add("/n", "[^a-z]");
    replacer.Add("/N", "[^A-Z]");
    replacer.Add("/w", "[0-9a-zA-Z_]");
    replacer.Add("/W", "[^0-9a-zA-Z_]");
    replacer.Add("/?", "{[01]}");

    return ( replacer.GetReplaced(regularExpression) );

//    return regularExpression;
}

std::string
Regex::RegexClient::Processor(const std::string& regularExpression)
{
    Regex::Brackets brackets ( '(', ')' );
    Regex::Collection collection ( '[', ']', '^' );
    Regex::Multiplier multiplier ( '{', '}', ',' );
//    Regex::Range range( '-' );
//    Regex::Or or_( '|' );
//    Regex::RandomString randChar ( '.', 1, 1 );
//    Regex::RandomString randString ( '*', 0, 255 );

    Regex::ProcessorsHandler processorsHandler(&multiplier);
    processorsHandler.AddProcessor(&brackets);
    processorsHandler.AddProcessor(&collection);
//    delimitersHandler.AddProcessor(&range);
//    delimitersHandler.AddProcessor(&or_);
//    delimitersHandler.AddProcessor(&randChar);
//    delimitersHandler.AddProcessor(&randString);

    Regex::RegexParser parser( &processorsHandler );

    return ( parser.Parse(regularExpression) );
}
