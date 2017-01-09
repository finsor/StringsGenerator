#include <iostream>
#include <stdexcept>
#include <cstring>

#include "main.h"
#include "Formatter.h"
#include "RegexClient.h"
#include "SequenceCreationClient.h"

#include <cstdlib>
#include <time.h>

int main(int argc, char *argv[])
{
#ifdef DEBUG
    return ( DMain() );
#else
    try
    {
        return ( RMain(argc, argv) );
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;

        return ( 1 );
    }
#endif // DEBUG
}

#ifndef DEBUG
int RMain(int argc, char *argv[])
{
    if( 3 == argc || 2 == argc )
    {
        if( 0 == strcmp(argv[1], "regex") )
            return ( RegexMain(argc-2, argv+2) );

        if( 0 == strcmp(argv[1], "sequence") )
            return ( SequenceMain(argc-2, argv+2) );
    }

    PrintGeneralUsage();

    return ( 1 );
}

int RegexMain(int argc, char *argv[])
{
    Regex::RegexClient client;

    if( 1 != argc )
    {
        std::cerr << client.UsageString() << std::endl;

        return ( 1 );
    }
    else // if ( 1 == argc )
    {
        std::cout << client.Generate(argv[0]) << std::endl;

        return ( 0 );
    }
}

int SequenceMain(int argc, char *argv[])
{
    if( 1 != argc )
    {
        PrintSequenceUsage();

        return ( 1 );
    }

    Regex::RegexClient regexClient;
    std::vector<std::string> params = StringHelper::Split(argv[0], ':');

    for(std::vector<std::string>::iterator iter = params.begin(); iter != params.end(); ++iter)
    {
        *iter = regexClient.Generate(*iter);
    }

    std::string before, start, separator, stop, after, difference;

    switch( params.size() )
    {
    case 3:
        before      = "";
        start       = params[0];
        separator   = "\n";
        stop        = params[1];
        after       = "";
        difference  = params[2];

        break;

    case 4:
        before      = "";
        start       = params[0];
        separator   = params[1];
        stop        = params[2];
        after       = "";
        difference  = params[3];

        break;

    case 6:
        before      = params[0];
        start       = params[1];
        separator   = params[2];
        stop        = params[3];
        after       = params[4];
        difference  = params[5];

        break;

    default:

        PrintSequenceUsage();

        return ( 1 );

    }

    int int_difference;

    if( !StringHelper::IsNumber(difference) )
        throw std::domain_error(StringHelper::Formatter() << "Invalid difference ! Received " << difference << " but expected number.");
    else
        int_difference = atoi(difference.c_str());

    start       = regexClient.Generate(start);
    stop        = regexClient.Generate(stop);
    separator   = regexClient.Generate(separator);

    Sequence::SequenceCreationClient client(start,
                                            stop,
                                            int_difference,
                                            before,
                                            separator,
                                            after);
    const char * str;

    while( nullptr != (str = client.Next()) )
    {
        std::cout << str;
    }

    return ( 0 );
}

void PrintGeneralUsage()
{
    std::cerr << "\
Program Usage:\n\
\n\
stg regex       [regular expression]\n\
stg sequence    [before:start:separator:stop:after[:absolute difference]]\
" << std::endl;
}

void PrintSequenceUsage()
{
    std::cerr << "[before:]start:[separator:]stop:[after:]difference" << std::endl;
}

#else // #ifdef DEBUG

int DMain()
{
//    return ( DebugRegex() );
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
    std::string start = "1";
    std::string stop = "5";
    std::string before = "char string[] = { \'";
    std::string after = "\' };";
    std::string separator = "', '";
    int         difference = 3;

    try
    {
        Sequence::SequenceCreationClient client(start,
                                                stop,
                                                difference,
                                                before,
                                                separator,
                                                after);

        const char * str;

        while( nullptr != (str = client.Next()) )
        {
            std::cout << str;
        }

        return ( 0 );

    }
    catch (const std::exception& ex)
    {

        std::cerr << ex.what() << std::endl;

        return ( 1 );

    }
}

#endif // DEBUG




