#ifndef __POSSIBLELIST_H__
#define __POSSIBLELIST_H__

class PossibleNode
{
public:
	short value;  //value
	PossibleNode * next; //pointer to next node
	PossibleNode();  //default constructor
	PossibleNode(short passedValue);  //constructor with value passed
};

class PossibleList
{
public:
	
	PossibleNode * head;
	PossibleNode * tail;
	short size;
	
	PossibleList();
	
	void add(short value);
	void addList(bool possible[], short possibleSize);
	short mergePair(PossibleList * first, PossibleList * second);
};

#endif // __POSSIBLELIST_H__