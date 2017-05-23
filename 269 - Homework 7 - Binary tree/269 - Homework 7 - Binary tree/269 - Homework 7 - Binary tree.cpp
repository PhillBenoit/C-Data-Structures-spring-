// Phillip Benoit
// CIS269
// Homework 7
// 269 - Homework 7 - Binary tree.cpp : Defines the entry point for the console application.

#include "genBST.h"
#include "Searches.h"
#include "Balance.h"
#include "Util.h"

//values to build tree
//int TEST_TREE_VALUES[] = {50,30,20,40,70,60,80}; //full tree pass
//int TEST_TREE_VALUES[] = { 50,40,60,30,55,70,52,57,65,75 }; //depth of single link node fail
//int TEST_TREE_VALUES[] = { 50,40,60,30,55,70 }; //depth of single link node pass
//int TEST_TREE_VALUES[] = { 50 }; //single value pass
//                                 //null pass
//int TEST_TREE_VALUES[] = {50, 40,60,55,65,70 };  //tripple depth fail
int TEST_TREE_VALUES[] = { 50, 40,60,55,65,53,57,63,67 }; //difference between leaf levels too far fail

//number of values used in the tree
int VALUES_COUNT = lengthOf(TEST_TREE_VALUES);

//builds the tree
void loadTree(BST<int> * tree)
{
	for (int step = 0; step < VALUES_COUNT; step++)
		tree->insert(TEST_TREE_VALUES[step]);
	//tree->balance(TEST_TREE_VALUES, 0, VALUES_COUNT - 1);
}

int main()
{
	setbuf(stdout, NULL);
	printStart();
	printf("This program searches a binary tree 4 different ways\n");
	printf("and demonstrates searching a binary tree for balance.\n");
	printf("*****************************************************\n");

	int * searchResult;
	BST<int> * testTree = new BST<int>();
	loadTree(testTree);

	printSeparator("Breadth Search");
	for (int step = 0; step < VALUES_COUNT; step++)
	{
		searchResult = BreadthSearch(testTree, TEST_TREE_VALUES[step]);
		if (searchResult != nullptr) printf("Found at %d\n", searchResult);
		else printf("Not Found!\n");
	}
	
	printSeparator("Depth Search");
	for (int step = 0; step < VALUES_COUNT; step++)
	{
		//starting point must be passed to the method
		BSTNode<int> * startNode = new BSTNode<int>();
		startNode = testTree->root;
		searchResult = DepthSearch(testTree, TEST_TREE_VALUES[step], startNode);
		if (searchResult != nullptr) printf("Found at %d\n", searchResult);
		else printf("Not Found!\n");
	}
	
	printSeparator("Stackless Depth Search");
	for (int step = 0; step < VALUES_COUNT; step++)
	{
		searchResult = IterativeSearch(testTree, TEST_TREE_VALUES[step]);
		if (searchResult != nullptr) printf("Found at %d\n", searchResult);
		else printf("Not Found!\n");
	}
	
	printSeparator("Morris Search");
	for (int step = 0; step < VALUES_COUNT; step++)
	{
		searchResult = MorrisSearch(testTree, TEST_TREE_VALUES[step]);
		if (searchResult != nullptr) printf("value %d found at %d\n", TEST_TREE_VALUES[step], searchResult);
		else printf("value %d not found\n", TEST_TREE_VALUES[step]);
	}
	
	printSeparator("Test Balance");
	if (isBalanced(testTree)) printf("Balanced!\n");
	else printf("Not Balanced!\n");

	printEnd();
    return 0;
}