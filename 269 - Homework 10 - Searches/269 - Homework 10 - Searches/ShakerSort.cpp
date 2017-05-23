#include "ShakerSort.h"

void printArray(int array[], int size)
{
	for (int step = 0; step < size; step++) printf("%d ", array[step]);
	printf("\n");
}

void shakerSort(int array[], int size)
{
	for (int step = 1; step < size; step++)
	{
		for (int left = step - 1; left < size - step; left++)
			if (array[left] > array[left + 1])
				swap(array, left, 1);
		
		for (int right = size - step - 1; right >= step; right--)
			if (array[right] < array[right - 1])
				swap(array, right, -1);
		printArray(array, size);
	}
}

void swap(int array[], int index, int step)
{
	int temp = array[index];
	array[index] = array[index + step];
	array[index + step] = temp;
}
