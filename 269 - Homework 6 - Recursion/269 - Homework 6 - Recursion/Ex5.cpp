// Phillip Benoit
// CIS269
// Homework 6
// Ex5.cpp - Code used for Exercise 5 on pg207

#include "Ex5.h"

void printOdd(int number)
{
	if (number % 2 == 1) printf("%d\n", number);
}

void countUp(int * max)
{
	if (*max >= 0)
	{
		*max -= 1;
		countUp(max);
		*max += 1;
		printOdd(*max);
	}
}

void countDown(int * counter)
{
	if (*counter >= 1)
	{
		printOdd(*counter);
		*counter -= 1;
		countDown(counter);
	}
}