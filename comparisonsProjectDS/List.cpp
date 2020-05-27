#include "List.h"

List::List()
{
	head = NULL;
	//tail = NULL;
	size = 0;

}

List::~List()
{
}

ListNode * List::getHead()
{
	return head;
}

void List::setHead(ListNode * newHead)
{
	this->head = newHead;
}

//ListNode * List::getTail()
//{
//	return tail;
//}

//void List::setTail(ListNode * newTail)
//{
//	this->tail = newTail;
//}
void List::insertAfter(ListNode* prevNode, Student * newStudent)
{
	//TODO: 
	/*1. check if the given prev_node is NULL */
	if (prevNode == NULL) {
		printf("the given previous node cannot be NULL");
		return;
	}

	/* 2. allocate new node */
	ListNode* newNode = new ListNode(newStudent, NULL, NULL);

	/* 4. Make next of new node as next of prev_node */

	newNode->setNext(prevNode->getNext());
	/* 5. Make the next of prev_node as new_node */
	prevNode->setNext(newNode);

	/* 6. Make prev_node as previous of new_node */
	newNode->setPrev(prevNode);

	/* 7. Change previous of new_node's next node */
	if (newNode->getNext() != NULL)
		newNode->getNext()->setPrev(newNode);
}

void List::insertBefore(ListNode* currNode, Student * newStudent)
{
	//TODO: 
	/*1. check if the given prev_node is NULL */
	if (currNode == NULL) {
		printf("the given previous node cannot be NULL");
		return;
	}

	/* 2. allocate new node */
	ListNode* newNode = new ListNode(newStudent, NULL, NULL);

	/* 4. Make next of new node as next of prev_node */

	newNode->setNext(currNode);
	if (currNode->getPrev() != NULL)
	{
		newNode->setPrev(currNode->getPrev());

		currNode->getPrev()->setNext(newNode);
		/* 5. Make the next of prev_node as new_node */
		currNode->setPrev(newNode);
	}
	else
	{
		currNode->setPrev(newNode);
		this->head = newNode;
	}

}

void List::deleteList()
{
	ListNode *curr=head;
	ListNode *temp;
	while (curr != NULL)
	{
		temp = curr->getNext();
		delete curr;
		curr = temp;
	}
	size = 0;
}
