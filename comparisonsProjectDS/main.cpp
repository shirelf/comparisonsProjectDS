#include <stdlib.h>
#include <iostream>
#include "List.h"
#include "Selection.h"
#include <time.h>

using namespace std;

void FreeArray(Student** arr, int size);
Student** getData(int& size, long& val);
int NaivePrint(Student** arr, int n, int k);
int insertSortedList(List *studentList, Student *student);
void printList(ListNode* node);
void BSTPrint(Student** studentsArray, int n, int k);
void PrintAllPepoleBelowID(vector<Student> students, long IDToCompare);
void PrintBySort(Student** studentsArray, int n, int k);
void QuickSort(Student** arr, int low, int high);
Student** MakeCopy(Student** studentsArray, int size);
int Partition(Student** arr, int left, int right);

int main()
{
	srand(time(nullptr));
	int size;
	long val;
	cin >> size;
	cin.ignore();

	Student** arr = getData(size, val);
	Selection selection(size,arr,val);
   // selection.selectHeap();     //selectHeap
   // selection.RandSelection();  //RandSelection
   // selection.BST();            //BST
	BSTPrint(arr, size, val);
	PrintBySort(arr, size, val);
	int counter = NaivePrint(arr, size, val);
	PrintBySort(arr, size, val);
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

void BSTPrint(Student** studentsArray, int n, int k) {

	int numOfCompares = 0;
	BSTree * peopleBinarySearchTree = new BSTree();

	for (int i = 0; i < n; i++) {
		peopleBinarySearchTree->Insert(studentsArray[i]->getId(), *studentsArray[i], numOfCompares);
	}

	vector<Student> PeopleInOrder;
	peopleBinarySearchTree->Inorder(PeopleInOrder);

	//Print(3, &PeopleInOrder[valueNumber  - 1]);
	PrintAllPepoleBelowID(PeopleInOrder, k);
}

void PrintAllPepoleBelowID(vector<Student> students, long IDToCompare) {
	vector<Student>::iterator ptr = students.begin();

	while (ptr->getId() <= IDToCompare) {
		cout << ptr->getId() << " " << ptr->getFirstName() << " " << ptr->getLastName() << endl;
		ptr++;
	}
}

void PrintAllPepoleBelowID(Student ** students, int size, long IDToCompare) {

	for (int i = 0; i < size ; i++) {
		if (students[i]->getId() > IDToCompare) {
			break;
		}

		cout << students[i]->getId() << " " << students[i]->getFirstName() << " " << students[i]->getLastName() << endl;
	}
}

void PrintBySort(Student** studentsArray, int n, int k) {
	Student ** temp = MakeCopy(studentsArray, n);
	QuickSort(temp, 0, n - 1);
//	vector<Student> students(*temp, *(temp + n));
	PrintAllPepoleBelowID(temp, n, k);
}

int Partition(Student** arr, int left, int right)
{
	Student* pivot = arr[right]; // pivot
	int i = left;

	for (int j = left; j < right; j++)
	{
		// If current element is smaller than pivot
		if (*arr[j] < *pivot)
		{
			swap(arr[i], arr[j]);
			i++; // increment index of next place for smaller values
		}
		//numOfCompares++;
	}
		(arr[i], arr[right]);
	return (i);
}

void QuickSort(Student** arr, int low, int high)
{
	int pi;
	if (low < high)
	{
		/* pi is partitioning index, arr[pi] is now
		   at right place */
		pi = Partition(arr, low, high);

		QuickSort(arr, low, pi - 1);  // Before pi
		QuickSort(arr, pi + 1, high); // After pi
	}
}

Student** MakeCopy(Student** studentsArray, int size)
{
	Student** temp = new Student*[size];
	for (int i = 0; i < size; i++)
		temp[i] = studentsArray[i];
	return temp;
}