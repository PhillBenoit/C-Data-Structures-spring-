#include "ShakerSort.h"
#include "MergeSort.h"
#include "Util.h"

void loadArray(int array[])
{
	array[0] = 90;
	array[1] = 30;
	array[2] = 70;
	array[3] = 80;
	array[4] = 60;
	array[5] = 20;
	array[6] = 40;
	array[7] = 50;
	array[8] = 10;
}

int main()
{
	setbuf(stdout, NULL);
	printStart();
	printf("This program sorts an array two different ways.\n");
	printf("***********************************************\n");
	
	int testArray[9];
	loadArray(testArray);
	printSeparator("Starting Array");
	printArray(testArray, lengthOf(testArray));
	
	printSeparator("Shaker Sort Start");
	shakerSort(testArray, lengthOf(testArray));
	printSeparator("Shaker Sort Result");
	printArray(testArray, lengthOf(testArray));

	loadArray(testArray);
	printSeparator("Merge Sort Start");
	mergeSort(testArray, lengthOf(testArray));
	printSeparator("Merge Sort Result");
	printArray(testArray, lengthOf(testArray));

	printEnd();
	return 0;
}