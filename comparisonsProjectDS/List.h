#ifndef _LIST_H
#define _LIST_H

#include "ListNode.h"


class List {

	ListNode * head;
	//ListNode * tail;
	int size;

public:
	List();
	~List();
	ListNode * getHead();
	void setHead(ListNode *newHead);
	//ListNode * getTail();
	//void setTail(ListNode *newTail);
	void insertAfter(ListNode * prevNode, Student * newStudent);
	void insertBefore(ListNode* currNode, Student * newStudent);
	void deleteList();
};

#endif