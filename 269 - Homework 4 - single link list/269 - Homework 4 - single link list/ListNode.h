// Phillip Benoit
// CIS269
// Homework 4
// ListNode.h - Defines a node in a linked list

#ifndef __LISTNODE_H__
#define __LISTNODE_H__

class ListNode
{
public:
	int value;  //value
	ListNode * next; //pointer to next node
	ListNode();  //default constructor
	ListNode(int passedValue);  //constructor with value passed
};

#endif // __LISTNODE_H__

inline ListNode::ListNode()
{
	value = 0;
	next = nullptr;
}

inline ListNode::ListNode(int passedValue)
{
	value = passedValue;
	next = nullptr;
}
