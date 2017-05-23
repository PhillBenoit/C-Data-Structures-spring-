// Phillip Benoit
// CIS269
// Homework 7
// Searches.cpp - Code to run Searches as per ex1 on pg298

#include "Searches.h"

int * BreadthSearch(BST<int> * tree, int target)
{
	Queue<BSTNode<int>*> queue;
	BSTNode<int> *p = tree->root;
	if (p != 0) {
		queue.enqueue(p);
		while (!queue.empty()) {
			p = queue.dequeue();
			tree->visit(p);
			//returns address if a match is found durring traversal
			if (p->el == target)
				return &p->el;
			if (p->left != 0)
				queue.enqueue(p->left);
			if (p->right != 0)
				queue.enqueue(p->right);
		}
	}
	return nullptr;
}

int * DepthSearch(BST<int> * tree, int target, BSTNode<int> * p)
{
	int * searchPointer = nullptr;
	if (p != 0) {
		searchPointer = DepthSearch(tree, target, p->left);  //call stack
		if (searchPointer != nullptr) return searchPointer;
		tree->visit(p);
		//returns pointer up the call stack
		if (p->el == target) return &p->el;
		searchPointer = DepthSearch(tree, target, p->right); //call stack
		if (searchPointer != nullptr) return searchPointer;
	}
	return searchPointer;
}

int * IterativeSearch(BST<int> * tree, int target)
{
	Stack<BSTNode<int>*> travStack;
	BSTNode<int> *p = tree->root;
	while (p != 0) {
		while (p != 0) {                 
			if (p->right)                
				travStack.push(p->right); 
			travStack.push(p);
			p = p->left;
		}
		p = travStack.pop();             
		while (!travStack.empty() && p->right == 0) { 
			tree->visit(p);              
			//returns address if a match is found durring traversal
			if (p->el == target)
				return &p->el;
			p = travStack.pop();
		}
		tree->visit(p);                       
		//returns address if a match is found durring traversal
		if (p->el == target)
			return &p->el;
		if (!travStack.empty())          
			p = travStack.pop();
		else p = 0;
	}
	return nullptr;
}

int * MorrisSearch(BST<int>* tree, int target)
{
	//used to hold an address for the return statement
	//the full tree must be traversed as navigating it changes the shape
	int * returnInt = nullptr;
	
	BSTNode<int> *p = tree->root, *tmp;
	while (p != 0)
		if (p->left == 0) {
			tree->visit(p);
			//if a match is found, returnInt points to it;
			if (p->el == target)
				returnInt = &p->el;
			p = p->right;
		}
		else {
			tmp = p->left;
			while (tmp->right != 0 &&
				tmp->right != p)  
				tmp = tmp->right;   
			if (tmp->right == 0) {   
				tmp->right = p;     
				p = p->left;        
			}
			else {                   
				tree->visit(p);
				//if a match is found, returnInt points to it;
				if (p->el == target)
					returnInt = &p->el;
				tmp->right = 0;     
				p = p->right;       
			}                       
		}
	return returnInt;
}