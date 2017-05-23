// Phillip Benoit
// CIS269
// Homework 5
// Ex1.h - Code used for Exercise 1 on pg165

#include <queue>
#include <stack>
#include "stdio.h"
#include "Util.h"

using namespace std;

#ifndef __EX1_H__
#define __EX1_H__

class Ex1
{
public:
	stack<int> S;

	Ex1();
	static void printStack(stack<int> passedStack);
	static void transferStack(stack<int> * sourceStack, stack<int> * destinationStack);
	static void invertedTransfer(stack<int> * sourceStack, stack<int> * destinationStack);
	
	void runTests(int values[], int size);
	void runTests(stack<int> passedStack);
	void testA();
	void testB();
	void testC();
};

#endif // __EX1_H__