// Phillip Benoit
// CIS269
// Homework 5
// Assignment1.cpp - Code used for Assignment 1 on pg166

#include "Assignment1.h"

//tests a string to see if it's a palindrome
//(book requests doing this reading only one string letter at a time)
bool isPalindrome(string testString)
{
	//test for an empty string
	if (testString.empty()) return false;
	
	//stack used to test against the string
	stack<char> testStack;
	
	//character pointer used to step through the string
	const char * letter = testString.c_str();
	
	//loads string in to a stack
	while (*letter != '\0')
	{
		testStack.push(*letter);
		letter++;
	}
	
	//resets the pointer used to step through the string
	letter = testString.c_str();
	
	//steps through string and stack comparing letters
	while (*letter != '\0')
	{
		//returns false if letters do not match
		if (*letter != testStack.top()) return false;
		
		//pops stack and steps up string chatacter pointer
		else testStack.pop();
		letter++;
	}
	
	//returns true if all the letters matched
	return true;
}

//text representation of the boolean method
void assignment1(string testString)
{
	if (isPalindrome(testString))
	{
		printf("{%s} is a palindrome\n", testString.c_str());
	}
	else
	{
		printf("{%s} is not a palindrome\n", testString.c_str());
	}
}