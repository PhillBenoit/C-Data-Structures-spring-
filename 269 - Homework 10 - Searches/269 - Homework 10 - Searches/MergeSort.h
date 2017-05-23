#include "ShakerSort.h"
#include "Util.h"

#ifndef MERGESORT
#define MERGESORT

void mergeSort(int array[], int size);
void merge(int array[], int leftStart, int middle, int rightStart);

int min(int x, int y);

#endif // !MERGESORT
