// Phillip Benoit
// CIS269
// Homework 4
// Exercises.h - Methods used to demonstrate assigned exercises

#include "ListObject.h"
#include "time.h"
#include "stdlib.h"

#ifndef __EXERCISES_H__
#define __EXERCISES_H__

ListObject addLoop(ListObject list, int loops);

ListObject addMerge(ListObject firsList, ListObject secondList);

void listCheck(ListObject first, ListObject second);

void Ex4(int a[], int sizeA, int b[], int sizeB);

void Ex10(int a[], int sizeA, int b[], int sizeB);

void bulkTest(int testSize);

#endif // __EXERCISES_H__