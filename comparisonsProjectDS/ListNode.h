#ifndef _LISTNODE_H
#define _LISTNODE_H

#include "Student.h"

class ListNode
{

	Student* student;
	ListNode* next;
	ListNode* prev;

public:
	ListNode(Student* student, ListNode* next, ListNode* prev);
	~ListNode( );


	ListNode* getNext();
	ListNode* getPrev();
	void setNext(ListNode* newNext);
	void setPrev(ListNode* newPrev);

	Student* getStudent();
	void setStudent(Student* student);


};

#endif