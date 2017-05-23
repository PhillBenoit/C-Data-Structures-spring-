// Phillip Benoit
// CIS269
// Homework 7
// Balance.h - Code to run Searches as per ex3 on pg298

#include "genBST.h"

#ifndef BALANCE
#define BALANCE

bool isBalanced(BST<int> * tree);
int countDepth(BST<int> * tree, int searchValue);
void getLeaves(BST<int> * tree, stack<int> * leafList, stack<BSTNode<int>*> * singlePinterList);

#endif