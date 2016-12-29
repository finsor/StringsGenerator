#include <iostream>
#include <stdexcept>
#include <cstring>

#include "main.h"
#include "RegexClient.h"


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
}

int DebugRegex()
{
//    std::string reg = "1|(A{2}[A-Z]){3}";
//    std::string reg = "1|2|3";
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

//    std::string reg = "\\[]";
//    std::string reg = "[]";
//    std::string reg = "[^]";
//    std::string reg = "[";

    // expected: xxxabcxxxabcxxxabcxxxabcxxxabcxxxabcxxxabcxxxabc
    std::string reg = "((/d){3}/D{3}){2}{2}{2}";

    Regex::RegexClient client;

    std::cout << client.Generate(reg) << std::endl;
//    std::cout << client.UsageString() << std::endl;

    return ( 0 );
}

#endif // DEBUG




