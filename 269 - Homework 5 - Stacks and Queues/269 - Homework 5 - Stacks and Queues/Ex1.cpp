// Phillip Benoit
// CIS269
// Homework 5
// Ex1.cpp - Code used for Exercise 1 on pg165

#include "Ex1.h"

Ex1::Ex1()
{
}

//print a passed stack
void Ex1::printStack(stack<int> passedStack)
{
	printf("Elements in stack: %d\n", passedStack.size());
	while (!passedStack.empty())
	{
		printf("%d\n", passedStack.top());
		passedStack.pop();
	}
}

//Transfer from source stack to destination stack.
//This transfer reverses the original order.
void Ex1::transferStack(stack<int> * sourceStack, stack<int> * destinationStack)
{
	while (!sourceStack->empty())
	{
		destinationStack->push(sourceStack->top());
		sourceStack->pop();
	}
}

//Recersivly calls itself to transfer elements from source to destination
//without changing the original order in the source.
void Ex1::invertedTransfer(stack<int> * sourceStack, stack<int> * destinationStack)
{
	//this will only be false when the source stack is empty
	if (!sourceStack->empty())
	{
		//a new temp is made every time through the loop to hold an element
		int temp = sourceStack->top();
		sourceStack->pop();
		
		//this method will call itself until the if statement above causes the calls to resolve
		invertedTransfer(sourceStack, destinationStack);
		
		//once the source stack is empty, it pushes elements on to the destination as it resolves
		destinationStack->push(temp);
	}
}

//loads test stack (auto mode)
void Ex1::runTests(int values[], int size)
{
	stack<int> testStack;
	for (int step = 0; step < size; step++)
	{
		testStack.push(values[step]);
	}
	runTests(testStack);
}

//loads S and runs tests
//auto mode calls this from the above method
//manual mode creates the stack in the driver
void Ex1::runTests(stack<int> passedStack)
{
	S = passedStack;	
	printSeparator("Starting Stack");
	printStack(S);
	
	testA();
	printSeparator("Double Stack Method");
	printStack(S);

	S = passedStack;
	testB();
	printSeparator("Queue Method");
	printStack(S);

	S = passedStack;
	testC();
	printSeparator("Reverse Resolve Method");
	printStack(S);
}

//reverse the order of a stack using 2 stacks
void Ex1::testA()
{
	stack<int> firstStack;
	stack<int> secondStack;
	
	//loads S on to first stack 
	transferStack(&S, &firstStack);

	//loads first on to second
	transferStack(&firstStack, &secondStack);

	//loads second back on S
	transferStack(&secondStack, &S);
}

//reverse the order of a stack using a queue
void Ex1::testB()
{
	queue<int> testQueue;
	
	//load stack in to queue
	while (!S.empty())
	{
		testQueue.push(S.top());
		S.pop();
	}

	//load queue in to stack
	while (!testQueue.empty())
	{
		S.push(testQueue.front());
		testQueue.pop();
	}
}

//Reverse the order of a stack by copying it in a recursive method
void Ex1::testC()
{
	stack<int> tempStack;
	
	//loads S on to temp while keeping the order of S
	invertedTransfer(&S, &tempStack);

	//loads temp stack on to S
	transferStack(&tempStack, &S);
}