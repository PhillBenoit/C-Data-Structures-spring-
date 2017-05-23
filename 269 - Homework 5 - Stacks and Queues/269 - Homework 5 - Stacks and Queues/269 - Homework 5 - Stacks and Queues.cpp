// Phillip Benoit
// CIS269
// Homework 5
// 269 - Homework 5 - Stacks and Queues.cpp : Defines the entry point for the console application.

#include "Ex1.h"
#include "Assignment1.h"
#include "Util.h"

void manualMode()
{
	stack<int> testStack;
	int stackSize = getInt("How many items would you like in your stack? (0-20) ", 0, 20);
	
	//fills stack
	while (stackSize > 0)
	{
		printf("Stack element %d. ", stackSize);
		testStack.push( getInt("Please enter a valid integer to add to the stack: ") );
		stackSize--;
	}

	//runs tests with the created stack
	Ex1 part1 = Ex1();
	part1.runTests(testStack);

	//runs palindrome test
	printSeparator("Palindrome Test");
	assignment1( getString("Please enter a string to see if it's a palindrome: ") );
}

void autoMode()
{
	//test array of integers to stack in exercise 1
	int testArray[] = { 1, 2, 3, 4, 5 };

	//makes the object for part 1 then runs tests using the array
	Ex1 part1 = Ex1();
	part1.runTests(testArray, lengthOf(testArray));

	//passes strings to the assignment to see if they are palindromes
	printSeparator("Palindrome Tests");
	assignment1("noon");
	assignment1("level");
	assignment1("spike");
}

int main()
{
	setbuf(stdout, NULL);
	printStart();
	printf("This program reverses a stack several ways and tests a string to see if it is a palindrome.\n");
	printf("*******************************************************************************************\n");
	
	if (getYN("Would you like to start in auto mode? [Y/N] ")) autoMode();
	else manualMode();
	
	printEnd();
	return 0;
}