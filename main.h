#pragma once


#ifndef DEBUG
// Main used for release version
int RMain(int argc, char *argv[]);

// Function used to handle "stg regex *"
int RegexMain(int argc, char *argv[]);

// Function used to handle "stg sequence *"
int SequenceMain(int argc, char *argv[]);

// Function used to print general usage of the program
int PrintGeneralUsage(char * programName);

#else // ifdef DEBUG

// Main used for debug version
int DMain();

//
int DebugRegex();

//
int DebugRange();
#endif // DEBUG

