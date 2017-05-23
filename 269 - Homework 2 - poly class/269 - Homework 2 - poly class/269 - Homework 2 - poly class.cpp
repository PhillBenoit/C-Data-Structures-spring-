// Phillip Benoit
// CIS269
// Homework 2
// 269 - Homework 2 - poly class.cpp : Defines the entry point for the console application.

#include "Poly.h"
#include "stdio.h"

void newSet(int * counter, int a, int b, int c, int d, int e, int f)
{
	printf("-------------============= Set %d =============-------------\n", *counter);
	*counter += 1;
	Poly<int> polyOne = Poly<int>(a, b, c);
	Poly<int> polyTwo = Poly<int>(d, e, f);
	polyOne.add(polyTwo);
	polyOne.multiply(polyTwo);
}

int main()
{
	int listCounter = 1;

	newSet(&listCounter, 2, 2, 2, 3, 3, 3);
	
	newSet(&listCounter, -1, -1, -1, -1, -1, -1);
	
	newSet(&listCounter, 100, 100, 100, 100, 100, 100);
	
	newSet(&listCounter, 0, 0, 0, 1, 1, 1);
	
	newSet(&listCounter, -1, -1, -1, 1, 1, 1);
	
	newSet(&listCounter, -2147483648, 1, 1, 1, 1, 1);

	newSet(&listCounter, 2147483645, 1, 1, 1, 1, 1);

	return 0;
}