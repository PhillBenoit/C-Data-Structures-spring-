#include "PossibleList.h"

PossibleNode::PossibleNode()
{
	value = 0;
	next = nullptr;
}

PossibleNode::PossibleNode(short passedValue)
{
	value = passedValue;
	next = nullptr;
}

PossibleList::PossibleList()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

void PossibleList::add(short value)
{
	PossibleNode  * newNode = new PossibleNode(value);
	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	size++;
}

void PossibleList::addList(bool possible[], short possibleSize)
{
	for (short step = 0; step < possibleSize; step++)
	{
		if (possible[step])
		{
			this->add(step);
		}
	}
}

short PossibleList::mergePair(PossibleList * first, PossibleList * second)
{
	short omittedValue = -1;
	add(first->head->value);
	add(first->head->next->value);
	PossibleNode * cursor = second->head;
	while (cursor != nullptr)
	{
		if (cursor->value != head->value && cursor->value != tail->value)
		{
			PossibleNode  * newLink = new PossibleNode(cursor->value);
			size++;
			//if the new link is the largest item, it is the new tail
			if (cursor->value > tail->value)
			{
				tail->next = newLink;
				tail = newLink;
			}
			else
			{
				//if new link is the smallest item, it is the new head
				if (head->value > cursor->value)
				{
					newLink->next = head;
					head = newLink;
				}
				else
				{
					//if it's not the new head or the new tail, it's in the middle
					//or a 4th value that is just added for the sake of the count
					newLink->next = tail;
					head->next = newLink;
				}
			}
		}
		else
		{
			omittedValue = cursor->value;
		}
		cursor = cursor->next;
	}
	return omittedValue;
}
