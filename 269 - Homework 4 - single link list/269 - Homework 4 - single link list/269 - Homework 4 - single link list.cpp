// Phillip Benoit
// CIS269
// Homework 4
// 269 - Homework 4 - single link list.cpp : Defines the entry point for the console application.

#include "Exercises.h"

int main()
{
	//arrays used for static testing
	int firstSet[] = { 2, 2, 2, 2, 2 };
	int secondSet[] = { 1, 1, 1, 1, 1 };

	//Passes arrays for merging
	Ex4(firstSet, sizeof(firstSet) / sizeof(int),
		secondSet, sizeof(secondSet) / sizeof(int));

	//Passes arrays for comparing
	Ex10(firstSet, sizeof(firstSet) / sizeof(int),
		secondSet, sizeof(secondSet) / sizeof(int));
	
	//Demonstrates efficienciency by generating large lists then
	//merging / comparing them.  Events are timed.
	//Number passed is the size of the generated lists.
	bulkTest(30000);

	return 0;
}