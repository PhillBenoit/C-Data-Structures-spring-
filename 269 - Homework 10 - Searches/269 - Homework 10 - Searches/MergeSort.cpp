#include "MergeSort.h"

void mergeSort(int array[], int size)
{
	for (int mergeArrayLength = 1; mergeArrayLength <= size - 1; mergeArrayLength = 2 * mergeArrayLength)
		for (int leftStep = 0; leftStep<size - 1; leftStep += 2 * mergeArrayLength)
		{
			int middle = leftStep + mergeArrayLength - 1;
			int rightStep = min(leftStep + 2 * mergeArrayLength - 1, size - 1);
			merge(array, leftStep, middle, rightStep);
			printArray(array, size);
		}
}

void merge(int array[], int leftStart, int middle, int rightStart)
{
	int leftIndex, rightIndex, mergedIndex;
	int leftSize = middle - leftStart + 1;
	int rightSize = rightStart - middle;

	int * L = new int[leftSize];
	int * R = new int[rightSize];

	for (leftIndex = 0; leftIndex < leftSize; leftIndex++)
		L[leftIndex] = array[leftStart + leftIndex];
	for (rightIndex = 0; rightIndex < rightSize; rightIndex++)
		R[rightIndex] = array[middle + 1 + rightIndex];

	leftIndex = 0;
	rightIndex = 0;
	mergedIndex = leftStart;
	while (leftIndex < leftSize && rightIndex < rightSize)
	{
		if (L[leftIndex] <= R[rightIndex])
		{
			array[mergedIndex] = L[leftIndex];
			leftIndex++;
		}
		else
		{
			array[mergedIndex] = R[rightIndex];
			rightIndex++;
		}
		mergedIndex++;
	}

	while (leftIndex < leftSize)
	{
		array[mergedIndex] = L[leftIndex];
		leftIndex++;
		mergedIndex++;
	}

	while (rightIndex < rightSize)
	{
		array[mergedIndex] = R[rightIndex];
		rightIndex++;
		mergedIndex++;
	}
}

int min(int x, int y) { return (x < y) ? x : y; }
