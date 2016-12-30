#include <iostream>
#include <stdexcept>
#include <cstring>


#include "main.h"
#include "RegexClient.h"
#include "SequenceCreator.h"
#include "SequenceCreationClient.h"

#include <cstdlib>
#include <time.h>

int main(int argc, char *argv[])
{
#ifdef DEBUG
    return ( DMain(argc, argv) );
#else
//    return ( RMain(argc, argv) );

    time_t b = clock();

    std::string start = "aaa123";
    std::string stop  =  "1";
    int difference = -1;

    Sequence::SequenceCreator s(start, stop, difference);

    while( !s.End() )
        std::cout << s.GetNext() << std::endl;



//    Sequence::SequenceCreationClient client;

//    if( !client.Sign(start, stop, difference) )
//    {
//        std::cerr << "invalid sequence" << std::endl;
//        return ( 0 );
//    }
//    else
//    {
//        std::cout << start << std::endl;
//
//        while( !client.End() )
//        {
//            std::cout << client.Next() << std::endl;
//        }
//
//    }

    time_t e = clock();

    std::cout << "time in seconds: " << (double)(e-b)/(CLOCKS_PER_SEC) << std::endl;

    system("pause");

    return ( 0 );
#endif // DEBUG
}

#ifndef DEBUG
int RMain(int argc, char *argv[])
{
    return ( 0 );
}

int RegexCMDParser(int argc, char *argv[])
{

    return ( 0 );
}
#else
int DMain(int argc, char *argv[])
{
    return ( DebugRange() );
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
//    std::string reg = "(http:\\/\\/)/?www\\.google\\.com";
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
    std::string reg = "[A\\-Z]";
//    std::string reg = "\\[AZ";
//
//    std::string reg = "A-Z";
//
//    std::string reg = "-";
//    std::string reg = ".{}";

    Regex::RegexClient client;

    std::cout << client.Generate(reg) << std::endl;
//    std::cout << client.UsageString() << std::endl;

    return ( 0 );
}

int DebugRange()
{
    char str[] = "original";

    StringHelper::ShiftLeft(str);

    std::cout << str << std::endl;

    return 0;
    std::string start = "123";
    std::string stop  =  "1";
    int difference = -1;

    Sequence::SequenceCreationClient client;

    if( !client.Sign(start, stop, difference) )
    {
        std::cerr << "invalid sequence" << std::endl;
        return ( 0 );
    }
    else
    {
        std::cout << start << std::endl;

        while( !client.End() )
        {
            std::cout << client.Next() << std::endl;
        }

    }

    return ( 0 );
}

#endif // DEBUG




