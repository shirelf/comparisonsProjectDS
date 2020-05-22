#include "ListNode.h"

ListNode::ListNode(Student * student, ListNode * next, ListNode* prev) :student(student)
{
	this->next = next;
	this->prev = prev;
}


ListNode::~ListNode()
{
	delete student;
	// delete next?
}


ListNode* ListNode::getNext()
{
	return next;
}
ListNode * ListNode::getPrev()
{
	return prev;
}
void ListNode::setNext(ListNode * newNext)
{
	this->next = newNext;
}
void ListNode::setPrev(ListNode * newPrev)
{
	this->prev = newPrev;
}
Student* ListNode::getStudent()
{
	return student;
}
void ListNode::setStudent(Student* student)
{
	this->student = student;
}
