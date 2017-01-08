#include <iostream>
#include <stdexcept>
#include <cstring>

#include "main.h"
#include "RegexClient.h"
#include "SequenceCreationClient.h"

#include <cstdlib>
#include <time.h>

int main(int argc, char *argv[])
{
#ifdef DEBUG
    return ( DMain() );
#else
    return ( RMain(argc, argv) );
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

    return ( 0 );
}

int RegexMain(int argc, char *argv[])
{
    Regex::RegexClient client;

    if( 0 == argc )
    {
        std::cerr << client.UsageString() << std::endl;
    }
    else if ( 1 == argc )
    {
        try
        {
            std::string regularExpression(argv[0]);
            std::cout << client.Generate(regularExpression) << std::endl;
        }
        catch ( std::exception& ex )
        {
            std::cerr << ex.what() << std::endl;
        }

    }

    return ( 0 );
}

int SequenceMain(int argc, char *argv[])
{
    if( 0 == argc )
    {
        PrintSequenceUsage();
    }
    else if ( 1 == argc )
    {
        // 3: start,stop,difference
        // 4: start, separator, stop, difference
        // 6: before, start, separator, stop, after, difference

        // [before:]start:[separator:]stop:[after:]difference

        std::string start = "1";
        std::string stop = "5";
        std::string before = "";
        std::string after = "";
        std::string separator = "\n";
        std::string difference;

        std::vector<std::string> params = StringHelper::Split(argv[0], ':');

        switch( params.size() )
        {
        case 3:
            start       = params[0];
            stop        = params[1];
            difference  = params[2];

            break;

        case 4:
            start       = params[0];
            separator   = params[1];
            stop        = params[2];
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

            return ( 0 );

            break;

        }

        int int_difference;

        if( !StringHelper::IsNumber(difference) )
        {
            std::cerr << "Invalid difference ! Received " << difference << std::endl;

            return ( 0 );
        }
        else
        {
            int_difference = atoi(difference.c_str());
        }

        // RegexClient for before, separator, after

        try
        {
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
        }
        catch (const std::exception& ex)
        {
            std::cerr << ex.what() << std::endl;
        }
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
    std::cerr << "Sequence Usage" << std::endl;
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




