// Phillip Benoit
// CIS269
// Homework 4
// ListObject.h - Defines a link list object.
//                Includes variables and functions needed to create a list.
//                Also includes functions for the homework assignment.

#ifndef __LISTOBJECT_H__
#define __LISTOBJECT_H__

#include "stdio.h"
#include "ListNode.h"

class ListObject
{
public:
	ListNode * head; //first item on the list
	ListNode * tail; //last item on the list
	int size; //used to keep track of the amount of items in the list

	ListObject(); //constructor
	void print(); //display contents of the list and a count
	void add(int newValue); //add item to the list (sorted)
	void add(int array[], int size); //add values from an array
	void merge(ListObject passedList); //merge 2 ordered linked lists
	bool compare(ListObject passedList); //compare 2 lists to see if they have the same values
};

#endif // __LISTOBJECT_H__

//constructor
inline ListObject::ListObject()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

//display contents of the list and a count
inline void ListObject::print()
{
	//executes as long as there is something in the list
	if (head != nullptr)
	{
		ListNode * cursor = head;
		printf("The %d items in this list are:\n", size);
		do
		{
			printf("%d\n",cursor->value);
			cursor = cursor->next;
		} while (cursor != nullptr);
	}
	else  //nothing in the list
	{
		printf("There is nothing in the list.\n");
	}
}

//add item to the list (sorted)
inline void ListObject::add(int newValue)
{
	//new link for the list
	ListNode * newLink = new ListNode(newValue);
	
	//if there is nothing in head, it initializes the list
	if (head == 0)
	{
		head = newLink;
		tail = newLink;
	}
	else
	{
		//if the new link is the largest item, it is the new tail
		if (newValue >= tail->value)
		{
			tail->next = newLink;
			tail = newLink;
			//printf("New Tail: %d\n", tail->value);  //used to show how often this method is actually applied
		}
		else
		{
			//if new link is the smallest item, it is the new head
			if (head->value >= newValue)  
			{
				newLink->next = head;
				head = newLink;
				//printf("New Head: %d\n", head->value);  //used to show how often this method is actually applied
			}
			else
			{
				ListNode * cursor = head;
				//steps through the list to find where new link belongs
				while (cursor->next->value < newValue)
				{
					cursor = cursor->next;
				}
				//assigns the new link
				newLink->next = cursor->next;
				cursor->next = newLink;
			}
		}
	}
	//increases the size counter once link has been added
	size++;
}

//add values from an array
inline void ListObject::add(int array[], int size)
{
	//loops through passed array to add values one at a time
	for (int step = 0; step < size; step++)
	{
		add(array[step]);
	}
}

//merge 2 ordered linked lists.  Passed list is merged in to the existing object.
inline void ListObject::merge(ListObject passedList)
{
	//first cursor is coppied so its value isn't changed by assigning a new head
	ListNode * cursorA = new ListNode(head->value);
	cursorA->next = head->next;
	
	//standard second cursor created from the list that was passed
	ListNode * cursorB = passedList.head;

	//new dimensions for the list
	head = cursorA->value < cursorB->value ? cursorA : cursorB;
	tail = tail->value > passedList.tail->value ? tail : passedList.tail;
	size += passedList.size;
	
	//final cursor used for assignment
	ListNode * newCursor = head;

	//steps up cursor used for new head
	if (cursorA->value < cursorB->value)
	{
		cursorA = cursorA->next;
	}
	else
	{
		cursorB = cursorB->next;
	}

	//steps through the lists as long as neither is null
	while (cursorA != nullptr && cursorB != nullptr)
	{
		//assigns lowest value to the list and steps the cursor with that value
		if (cursorA->value < cursorB->value)
		{
			newCursor->next = cursorA;
			cursorA = cursorA->next;
		}
		else
		{
			newCursor->next = cursorB;
			cursorB = cursorB->next;
		}
		//steps up the cursor for the new list
		newCursor = newCursor->next;
	}

	//adds the last of the remaining cursor's list
	newCursor->next = (cursorA != nullptr) ? cursorA : cursorB;
}

//compare 2 lists to see if they have the same values
inline bool ListObject::compare(ListObject passedList)
{
	//simple check to see if they're not the same size
	if (size != passedList.size) return false;

	//standard cursors created from the lists
	ListNode * cursorA = head;
	ListNode * cursorB = passedList.head;
	
	//loop to check values
	while (cursorA != nullptr) //only need to check one thanks to previous check
	{
		//return false if the values aren't the same
		if (cursorA->value != cursorB->value) return false;
		
		//step up cursors
		cursorA = cursorA->next;
		cursorB = cursorB->next;
	}

	//all items have been tested
	return true;
}
