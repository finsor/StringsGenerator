#pragma once


#ifndef DEBUG
// Main used for release version
int RMain(int argc, char *argv[]);

// Function used to parse CMD arguments
int RegexCMDParser(int argc, char *argv[]);

#else // ifdef DEBUG

// Main used for debug version
int DMain(int argc, char *argv[]);

//
int DebugRegex();

//
int DebugRange();
#endif // DEBUG

