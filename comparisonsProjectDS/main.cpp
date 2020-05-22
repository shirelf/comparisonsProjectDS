#include <stdlib.h>
#include <iostream>
#include "List.h"

#include <time.h>


using namespace std;

void FreeArray(Student** arr, int size);
Student** getData(int& size, long& val);
int NaivePrint(Student** arr, int n, int k);
int insertSortedList(List *studentList, Student *student);
void printList(ListNode* node);
int main()
{
	srand(time(nullptr));
	int size;
	long val;
	cin >> size;
	cin.ignore();

	Student** arr = getData(size, val);
	//Selection selection(size,arr,val);
   // selection.selectHeap();     //selectHeap
   // selection.RandSelection();  //RandSelection
   // selection.BST();            //BST
	int counter = NaivePrint(arr, size, val);
	cout << counter << endl;
	FreeArray(arr, size);
	system("pause");
}

Student** getData(int& size, long& val)
{
	string name;
	string firstName;
	string lastName;
	string id;
	Student** PArray = new Student*[size];
	for (int i = 0; i < size; i++)
	{
		cin >> id;
		cin.ignore();
		getline(cin, firstName, ' ');
		getline(cin, lastName);
		try {
			Student* student = new Student(id, firstName, lastName);
			if (i != 0)
			{
				for (int j = 0; j < i; j++)
				{
					if (PArray[j]->getId() == stol(id))
					{
						string ex = "bad";
						throw ex;
					}
				}
			}
			PArray[i] = student;
		}
		catch (string ex) {
			cout << "invalid input" << endl;
			FreeArray(PArray, i);
			exit(1);
		}
	}
	cin >> val;
	return PArray;
}

void FreeArray(Student** arr, int size)
{
	for (int i = 0; i < size; i++)
		delete arr[i];
	delete[] arr;
}

int NaivePrint(Student** arr, int n, int k)
{
	int counter = 0;
	if (arr == NULL)
		exit(-1);

	List* studentList = new List();
	for (int i = 0; i < n; i++)
	{
		if ((arr)[i]->getId() < k)
			counter = counter + insertSortedList(studentList, (arr[i]));
		counter++;
	}
	printList(studentList->getHead());

	return counter;
}
int insertSortedList(List* studentList, Student* student)
{
	int counter = 0;

	bool flag = false;
	if (!flag && studentList->getHead() == NULL)
	{
		ListNode* newNode = new ListNode(student, NULL, NULL);
		studentList->setHead(newNode);
	}
	ListNode *curr = studentList->getHead();
	while (curr->getNext() && !flag)
	{
		if (curr->getStudent()->getId() > student->getId())
		{
			studentList->insertBefore(curr, student);
			flag = true;
		}
		curr = curr->getNext();
		counter++;

	}//if curr->next is null and flag = false it means that the new student is bigger then all the nodes before, so we'll check the last node in the list
	if (!flag && (curr->getStudent()->getId() < student->getId()))
	{
		counter++;
		studentList->insertAfter(curr, student);
		flag = true;
	}
	if (!flag && (curr->getStudent()->getId() > student->getId()))
	{
		counter++;
		studentList->insertBefore(curr, student);
		flag = true;
	}

	return counter;
}

void printList(ListNode* node) //Function to print the list forwards
{
	ListNode *curr = node; //current is the beginning value of the list
	while (curr != NULL) //Continue while current is not at the end of the list
	{
		cout << curr->getStudent()->getId() << " " << curr->getStudent()->getFirstName() << " " << curr->getStudent()->getLastName() << endl; //Print out the data of current
		curr = curr->getNext(); //Move one value along in the list
	}
}