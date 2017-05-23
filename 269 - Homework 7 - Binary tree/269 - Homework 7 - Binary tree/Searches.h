// Phillip Benoit
// CIS269
// Homework 7
// Searches.h - Code to run Searches as per ex1 on pg298

#include "genBST.h"
#include <queue>

#ifndef SEARCHES
#define SEARCHES


int * BreadthSearch(BST<int> * tree, int target);
int * DepthSearch(BST<int> * tree, int target, BSTNode<int> * p);
int * IterativeSearch(BST<int> * tree, int target);
int * MorrisSearch(BST<int> * tree, int target);

#endif