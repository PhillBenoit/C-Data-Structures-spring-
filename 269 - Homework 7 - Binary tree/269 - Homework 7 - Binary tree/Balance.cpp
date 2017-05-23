// Phillip Benoit
// CIS269
// Homework 7
// Balance.cpp - Code to run Searches as per ex3 on pg298

// A TREE IS CONSIDERED PERFECTLY BALANCED IF IT IS BALANCED AND ALL LEAVES
// CAN BE FOUND ON ONE OR TWO LEVELS -- PG250

#include "Balance.h"

bool isBalanced(BST<int>* tree)
{
	//used to store depth levels of leaves
	Queue<int> depths = Queue<int>();  
	
	//stores leaves of the tree
	stack<int> * leaves = new stack<int>();
	
	//used to store nodes with only one child route
	stack<BSTNode<int>*> * singleLinks = new stack<BSTNode<int>*>();
	
	//populates list of leaves and single links
	getLeaves(tree, leaves, singleLinks);
	
	//steps through leaves
	while (!leaves->empty())
	{
		//find the depth level of the leaf
		int depth = countDepth(tree, leaves->top());

		//add depth to the list of depths if it's empty
		if (depths.empty()) depths.enqueue(depth);
		
		if (depth != depths.front())
		{
			//if there are already 2 depth values and it finds a third, it is not perfectly balanced
			if (depths.size() == 2 && depth != depths.back()) return false;
			
			//adds depth to the list if there is only 1 on the list
			if (depths.size() == 1) depths.enqueue(depth);

			int levelDifference = 0;

			//subtracts the difference in the depth levels
			levelDifference = depths.back() - depths.front();

			//if the level difference is more than 1, it is not perfectly balanced
			if (levelDifference > 1 || levelDifference < -1) return false;
		}
		leaves->pop();
	}
		
	//if all leaves are on the same level, add the previous level to the depths list
	if (depths.size() == 1) depths.enqueue(depths.front() - 1);

	//steps through single links
	while (!singleLinks->empty())
	{
		//finds the depth of a node with a single link
		int depth = countDepth(tree, singleLinks->top()->el);
		//if that depth is not on the depths list, the tree is not perfectly balanced
		if (depth != depths.back() && depth != depths.front()) return false;
		singleLinks->pop();
	}
	//returns true if it passes all test cases
	return true;
}

int countDepth(BST<int> * tree, int searchValue)
{
	BSTNode<int> * cursor = new BSTNode<int>();
	cursor = tree->root;
	int stepCounter = -1;
	while (cursor != 0)
	{
		//steps up counter each time through the loop
		stepCounter++;

		//returns the step counter once the search result is found
		if (searchValue == cursor->el) return stepCounter;
		
		//goes to next node in the path
		else if (searchValue < cursor->el) cursor = cursor->left;
		else cursor = cursor->right;
	}
	return stepCounter;
}

void getLeaves(BST<int>* tree, stack<int>* leafList, stack<BSTNode<int>*> * singlePinterList)
{
	Queue<BSTNode<int>*> queue;
	BSTNode<int> *p = tree->root;
	if (p != 0) {
		queue.enqueue(p);
		while (!queue.empty()) {
			p = queue.dequeue();
			tree->visit(p);
			//adds value to leaf list if node is null left and right
			if (p->right == 0 && p->left == 0)
				leafList->push(p->el);
			if (p->left != 0)
			{
				queue.enqueue(p->left);
				//adds single path node if found
				if (p->right == 0) singlePinterList->push(p);
			}
			if (p->right != 0)
			{
				queue.enqueue(p->right);
				//adds single path node if found
				if (p->left == 0) singlePinterList->push(p);
			}
		}
	}
}