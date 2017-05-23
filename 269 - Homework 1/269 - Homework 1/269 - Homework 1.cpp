// 269 - Homework 1.cpp : Phillip Benoit

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Adds an array.  Requires starting address and the size of the array.  Returns the total.
int hw2a(int array[], int step)
{
	int total = 0;
	do
	{
		step--;
		total += *(array + step);
	} while (step > 0);
	return total;
}

//returns a boolean indicating if a given number is odd
bool isOdd(int testInt)
{
	if (testInt % 2 == 1) return true;
	return false;
}

/*
Tests an array for odd numbers.  Requires starting address and size of the
array. Even numbers are coppied to a temporary array. Empties the original
array while it's being tested.  New array is then coppied in to the original.
The total number of even numbers found is returned for reallocation.
*/
int hw2b(int array[], int arrayStepMax)
{
	int newArraySize = arrayStepMax;  //start with both arrays the same size
	int * newArray = new int[newArraySize];  //make new array a pointer
	int newArrayStep = 0;  //used to step through new array assignments
	
	for (int arrayStep = 0; arrayStep < arrayStepMax; arrayStep++)  //steps through array
	{
		if (isOdd( *(array + arrayStep) ))
		{
			newArraySize--;
		}
		else
		{
			*(newArray + newArrayStep) = *(array + arrayStep);  //copy from array to new array
			newArrayStep++;
		};
		*(array + arrayStep) = 0; //clear location in case it needs to be reallocated
	}
		
	memcpy(array, newArray, newArraySize * sizeof(int)); //copy new array in to now empty array
	free(newArray); //free memory used by new array
	return newArraySize;  //return size for reallocation
}

int main()
{
	int arraySize = 10;  //declare size for array
	int * myIntArray;  //declare array
	myIntArray = (int*) malloc(arraySize * sizeof(int));  //allocate array
	for (int step = 0; step < arraySize; step++) *(myIntArray+step) = step + 1;  //fill array with sequential numbers

	printf("The total is: %d\n", hw2a(myIntArray, arraySize));  //executes the adding method written for part A

	int resize = hw2b(myIntArray, arraySize);  //executes method for part B
	myIntArray = (int*) realloc(myIntArray, resize * sizeof(int));  //resizes as requested

	printf("The new size is: %d\n", resize);
	for (int step = 0; step < resize; step++)
	{
		printf("Value at %d: %d\n", step, myIntArray[step]);
	}

	return 0;
}