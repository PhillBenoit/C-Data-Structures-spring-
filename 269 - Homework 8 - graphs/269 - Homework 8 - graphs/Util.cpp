// Phillip Benoit
// CIS269
// Util.cpp - Utilities for C++ I plan to reuse

#include "Util.h"

void printStart()
{
	printSeparator("Program Start");
}

void printEnd()
{
	printSeparator(" Program End ");
	pause();
}

void printSeparator(char * heading)
{
	printf(SEPARATOR, heading);
}

void clearScreen()
{
	if (system("CLS")) system("clear");
}

int getInt(char * msg)
{
	string input = getString(msg);
	int number = atoi(input.c_str());
	
	//loops while number is 0 and input string isn't a single 0 character
	while (number == 0 && !(input.length() == 1 && input.at(0) == '0'))
	{
		//error message
		printf(PARSE_MSG, input.c_str(), "a valid integer");
		
		input = getString(msg);
		number = atoi(input.c_str());
	} 
	return number;
}

int getInt(char * msg, int min, int max)
{
	int number = getInt(msg);
	
	//loops wile below min / above max
	while (number < min || number > max)
	{
		//error messages
		if (number < min) printf(MIN_MSG, number, min);
		if (number > max) printf(MAX_MSG, number, max); 
		
		number = getInt(msg);
	}
	return number;
}

string getString(char * msg)
{
	string input;
	printf(msg);
	try
	{
		getline(cin, input);
	}
	catch (const std::exception&)
	{
		printf("Fatal error reading from keyboard\n");
		exit(0);
	}
	printf("You entered: {%s}\n", input.c_str());
	return input;
}

string silentGetString(char * msg)
{
	string input;
	printf(msg);
	try
	{
		getline(cin, input);
	}
	catch (const std::exception&)
	{
		printf("Fatal error reading from keyboard\n");
		exit(0);
	}
	return input;
}

char getChar(char * msg)
{
	string inputString = getString(msg);
	
	//loops while the string is not a single character
	while (inputString.length() != 1)
	{
		//error message
		printf(PARSE_MSG, inputString.c_str(), "a signle character"); 
		
		inputString = getString(msg);
	} 
	return inputString.at(0);
}

bool getYN(char * msg)
{
	char input = getChar(msg);
	
	//loops while single character isn't Y or N
	while (input != 'y' && input != 'Y' && input != 'n' && input != 'N')
	{
		//error message
		printf(PARSE_MSG, string(1, input).c_str(), "Y or N");
		
		input = getChar(msg);
	}
	
	if (input == 'y' || input == 'Y') return true;
	return false;
}

void pause()
{
	string hold = silentGetString("Press <enter> or <return> to continue . . .");
}
