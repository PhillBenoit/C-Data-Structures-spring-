// Phillip Benoit
// CIS269
// Util.h - Utilities for C++ I plan to reuse

#include <iostream>
#include <string>

using namespace std;

#ifndef __UTIL_H__
#define __UTIL_H__

//------------- Constant Strings -------------

//visual separator for command line code
static const char * SEPARATOR = "----------========== %s ==========----------\n";

//minimum and maximum error messages
static const char * MIN_MSG = "%d is below the minimum of: %d\n";
static const char * MAX_MSG = "%d is above the maximum of: %d\n";

//parsing error message
static const char * PARSE_MSG = "{%s} is not %s.\n";


//------------- Screen Separators -------------

//program start message
void printStart();

//program end message
void printEnd();

//prints a visual separator with a heading
void printSeparator(char * heading);

//------------- Get Input -------------
//All methods are passed a request message
//Request message prints before getting string input
//Calls are listed below their descriptions

//get an integer from string input
//calls getString
int getInt(char * msg);

//get an integer between minimum and maximum
//calls other getInt
int getInt(char * msg, int min, int max);

//get a string from input
string getString(char * msg);

//getString without a confirmation
string silentGetString(char * msg);

//get a character from string input
//calls getString
char getChar(char * msg);

//get y or n from input
//calls getChar
bool getYN(char * msg);


//------------- Utility -------------

//pause the program
void pause();

//length of an array
template <typename T,int length>
inline int lengthOf(const T(&value)[length]) { return length; }

#endif // __UTIL_H__