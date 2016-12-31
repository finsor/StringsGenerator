#include <iostream>
#include <stdexcept>
#include <cstring>


#include "main.h"
#include "RegexClient.h"
//#include "SequenceCreator.h"
#include "SequenceCreationClient.h"

#include <cstdlib>
#include <time.h>

int main(int argc, char *argv[])
{
#ifdef DEBUG
    return ( DMain(argc, argv) );
#else
    return ( RMain(argc, argv) );
#endif // DEBUG
}

#ifndef DEBUG
int RMain(int argc, char *argv[])
{


    time_t b = clock();

    char start[] =
    "10";
    char stop[] =
    "0";

    Sequence::SequenceCreator sc(start, stop, -1);

    while( !sc.End() )
        std::cout << sc.GetNext() << '\n';


    time_t e = clock();

    std::cerr << "time in seconds: " << (double)(e-b)/(CLOCKS_PER_SEC) << std::endl;

    return ( 0 );
}

int RegexCMDParser(int argc, char *argv[])
{

    return ( 0 );
}
#else
int DMain(int argc, char *argv[])
{
    return ( DebugRegex() );
//    return ( DebugRange() );
}

int DebugRegex()
{
//    std::string reg = "1|(A{2}[A-Z]){3}";
//    std::string reg = "1|2";
//    std::string reg = "3|1|2";
//    std::string reg = "[A-Z]{3}...";
//    std::string reg = "\\.{2}{3}";
//    std::string reg = "[\\^A\\]]";
//    std::string reg = "[(123)]";
//    std::string reg = "aaa/daaa";
//    std::string reg = "aaa/d";
//    std::string reg = "aaa[0-9]aaa";
//    std::string reg = "/W";
//    std::string reg = "[(300)]";
//    std::string reg = "123|/d{3}";
//    std::string reg = "/d{3,4}";
//    std::string reg = "/d{8,12}";
//    std::string reg = "/d/w/W{8,12}";
//    std::string reg = ".{8,12}";
//
//    std::string reg = "\\[]";
//    std::string reg = "[]";
//    std::string reg = "[^]";
//    std::string reg = "[";
//
//    // expected: xxxabcxxxabcxxxabcxxxabcxxxabcxxxabcxxxabcxxxabc
//    std::string reg = "((/d){3}/D{3}){2}{2}{2}Z-A|2|3";
//    std::string reg = "([a\\-Z]{3})";
//
//    std::string reg = "[A\\-Z]";
//    std::string reg = "\\[AZ";
//
//    std::string reg = "A-Z";
//
//    std::string reg = "-";
//    std::string reg = ".{}";

    std::string reg = "(http:\\/\\/)/?www\\.google\\.com";

//    std::string reg = "(a){[01]}";
    Regex::RegexClient client;

    std::cout << client.Generate(reg) << std::endl;
//    std::cout << client.UsageString() << std::endl;

    return ( 0 );
}


int DebugRange()
{
    char start[] = "10";
    char stop[] = "00";

    Sequence::SequenceCreationClient client;

    if( !client.GenerateSequence(start, stop, 3) )
    {
        std::cerr << "Invalid sequence !" << std::endl;
    }

    return ( 0 );
}

#endif // DEBUG




