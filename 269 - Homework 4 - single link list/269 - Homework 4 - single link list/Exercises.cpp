// Phillip Benoit
// CIS269
// Homework 4
// Exercises.cpp - Methods used to demonstrate assigned exercises

#include "Exercises.h"

//Loop to generate a list with a certain amount of elements filled 
//with random integers.  Used for bulk testing.
ListObject addLoop(ListObject list, int loops)
{
	for (int step = 0; step < loops; step++)
	{
		int newValue = rand() % RAND_MAX;
		list.add(newValue);
	}
	return list;
}

//innefficiently merges lists using add function.  Added to show the difference
//between this method and the merge function in the object.  Used for bulk testing.
ListObject addMerge(ListObject firsList, ListObject secondList)
{
	ListNode * cursor = secondList.head;
	//adds values from the second list one at a time
	while (cursor != nullptr)
	{
		firsList.add(cursor->value);
		cursor = cursor->next;
		
		//progress bar
		if ( (firsList.size - secondList.size) % (secondList.size / 10) == 0)
		{
			printf("%d0%% ", (firsList.size - secondList.size) / (secondList.size / 10));
		}
	}
	//completes line from progress bar
	printf("\n");
	return firsList;
}

//if statement to show the boolean results of the compare function
//Primary function of Ex10.  Also used in bulk testing.
void listCheck(ListObject first, ListObject second)
{
	if (first.compare(second))
	{
		printf("The lists are the same.\n");
	}
	else
	{
		printf("The lists are not the same.\n");
	}
}

//Ex4 Demonstrates merging of 2 sorted lists
void Ex4(int a[], int sizeA, int b[], int sizeB)
{
	//first list created with variables passed from homework driver
	ListObject firstList = ListObject();
	firstList.add(a, sizeA);
	printf("----------========== First List ==========----------\n");
	firstList.print();

	//second list created with variables passed from homework driver
	ListObject secondList = ListObject();
	secondList.add(b, sizeB);
	printf("----------========== Second List ==========----------\n");
	secondList.print();

	//merged list
	firstList.merge(secondList);
	printf("----------========== Merged List ==========----------\n");
	firstList.print();
}

//Ex10 demonstrates a method for comparing lists
void Ex10(int a[], int sizeA, int b[], int sizeB)
{
	//first list created with variables passed from homework driver
	ListObject firstList = ListObject();
	firstList.add(a, sizeA);
	
	//second list created with variables passed from homework driver
	ListObject secondList = ListObject();
	secondList.add(b, sizeB);
	
	//compare test
	printf("----------========== Compare Lists ==========----------\n");
	listCheck(firstList, secondList);
}

//set of load tests
void bulkTest(int testSize)
{
	printf("----------========== Bulk Tests ==========----------\n");

	//timer variables
	clock_t startTime, stopTime;
	clock_t results[4];
	srand(time(NULL));
	
	//create first list
	ListObject firstList = ListObject();
	startTime = clock();
	firstList = addLoop(firstList, testSize);
	stopTime = clock();
	results[0] = stopTime - startTime;
	printf("List of %d integers created in %d clicks.\n", firstList.size, results[0]);

	//create second list
	ListObject secondList = ListObject();
	startTime = clock();
	secondList = addLoop(secondList, testSize);
	stopTime = clock();
	results[1] = stopTime - startTime;
	printf("List of %d integers created in %d clicks.\n", secondList.size, results[1]);

	//merge second list in to first list
	startTime = clock();
	firstList.merge(secondList);
	stopTime = clock();
	printf("List of %d integers merged in %d clicks.\n", firstList.size, stopTime - startTime);

	//make second list equal to fist list and step through all of their elements
	secondList = firstList;
	startTime = clock();
	listCheck(firstList, secondList);
	stopTime = clock();
	printf("List of %d integers compared in %d clicks.\n", firstList.size, stopTime - startTime);

	//restart first list
	firstList = ListObject();
	startTime = clock();
	firstList = addLoop(firstList, testSize);
	stopTime = clock();
	results[2] = stopTime - startTime;
	printf("List of %d integers created in %d clicks.\n", firstList.size, results[2]);

	//restart second list
	secondList = ListObject();
	startTime = clock();
	secondList = addLoop(secondList, testSize);
	stopTime = clock();
	results[3] = stopTime - startTime;
	printf("List of %d integers created in %d clicks.\n", secondList.size, results[3]);

	//average clicks for the 4 times it generated lists
	printf("Average clicks per %d list generated: %d\n", testSize,
		(results[0] + results[1] + results[2] + results[3])/4 );

	//merge using inefficient method
	startTime = clock();
	firstList = addMerge(firstList, secondList);
	stopTime = clock();
	printf("List of %d integers merged (slow way) in %d clicks.\n", firstList.size, stopTime - startTime);
}