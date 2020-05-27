/*In this program we get the details of a certain number of students, for each student we get an ID number, first name, last name. 
first the user enters the amount of students whose details he is going to write, after writing this number and students as that number, he writes a Certain value (K).
The program sorts the students data according to their IDs and prints all students whose ID is smaller than the chosen K, in three different ways according to the following functions :
1. NaivePrint
2. BSTPrint
3. PrintBySort
You can see their description below.
In addition, each function counts the number of comparisons it has had to make in order to do this.
Output of the program: 
1. Print student data whose ID is less than K 3 times(each function also prints student data sorted to the same K value)
2. The number of comparisons each program had to make in order to sort and print the result.
*/

#include <stdlib.h>
#include <iostream>
#include "List.h"
#include <time.h>

#include "BSTree.h"

using namespace std;

void FreeArray(Student** arr, int size);// Deletes the array of students we have allocated
Student** getData(int& size, long& val); // Receives the information from the user

//In the function below we will create a list that contains all students whose IDs are less than the K value we received in the input, 
//this function will call the function that will print the new list 
//and return the number of comparisons made to create this list
int NaivePrint(Student** arr, int n, int k);

//This function Receives the list and a student and inserts it into the list according to its ID value
int insertSortedList(List *studentList, Student *student);
void printList(ListNode* node);// prints the list, we use it in the NaivePrint function

//In the function below we will create a binary search tree that contains all of the students
//and prints the tree Inorder until the ID is greater than or equal to k.
//and return the number of comparisons made to create this tree and to print the students
int BSTPrint(Student** studentsArray, int n, int k);
//We pass all the tree values ​​to a vector in Inorder
// print all the students whose IDs are less than the K value
int PrintAllPepoleBelowID(vector<Student> students, long IDToCompare);
//The function below sorts the array in quick sort 
//Then prints the Students details until it encounters a ID greater than or equal to k.
int PrintBySort(Student** studentsArray, int n, long k);
void QuickSort(Student** arr, int low, int high, int &numOfCompares);
Student** MakeCopy(Student** studentsArray, int size);// make a copy of the student array
int Partition(Student** arr, int left, int right, int &numOfCompares);

int main()
{
	srand(time(nullptr));
	srand(time(nullptr));
	int size;
	long val;
	cin >> size;
	cin.ignore();

	Student** arr = getData(size, val);

	cout << "NaivePrint:" << endl;
	int NaivePrintCounter = NaivePrint(arr, size, val);
	cout << "BSTPrint:" << endl;
	int BSTPrintCounter = BSTPrint(arr, size, val);
	cout << "PrintBySort:" << endl;
	int PrintBySortCounter = PrintBySort(arr, size, val);

	cout << "NaivePrint: " << NaivePrintCounter << " comparisons" << endl;
	cout << "BSTPrint: " << BSTPrintCounter << " comparisons" << endl;
	cout << "PrintBySort: " << PrintBySortCounter << " comparisons" << endl;

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
					if (PArray[j]->getId() == stol(id))//Check that the user does not put in certificates
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
	studentList->deleteList();
	delete studentList;
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

int BSTPrint(Student** studentsArray, int n, int k) {

	int numOfCompares = 0;
	BSTree * peopleBinarySearchTree = new BSTree();

	for (int i = 0; i < n; i++) {
		peopleBinarySearchTree->Insert(studentsArray[i]->getId(), *studentsArray[i], numOfCompares);
	}

	vector<Student> PeopleInOrder;
	peopleBinarySearchTree->Inorder(PeopleInOrder);

	numOfCompares = numOfCompares + PrintAllPepoleBelowID(PeopleInOrder, k);
	peopleBinarySearchTree->makeEmpty();
	return numOfCompares;
}

int PrintAllPepoleBelowID(vector<Student> students, long IDToCompare) {
	vector<Student>::iterator ptr = students.begin();
	int numOfCompares = 0;
	while (ptr->getId() <= IDToCompare) {
		cout << ptr->getId() << " " << ptr->getFirstName() << " " << ptr->getLastName() << endl;
		ptr++;
		numOfCompares++;
	}
	return numOfCompares;
}

void PrintAllPepoleBelowID(Student ** students, int size, long IDToCompare) {

	for (int i = 0; i < size; i++) {
		if (students[i]->getId() > IDToCompare) {
			break;
		}

		cout << students[i]->getId() << " " << students[i]->getFirstName() << " " << students[i]->getLastName() << endl;
	}
}

int PrintBySort(Student** studentsArray, int n, long k) {
	Student ** temp = MakeCopy(studentsArray, n);
	int numOfCompares = 0;
	QuickSort(temp, 0, n - 1, numOfCompares);
	PrintAllPepoleBelowID(temp, n, k);
	FreeArray(temp,n);
	return numOfCompares;
}

int Partition(Student** arr, int left, int right, int &numOfCompares)
{
	Student* pivot = arr[right];
	int i = left;

	for (int j = left; j < right; j++)
	{
		if (*arr[j] < *pivot)
		{
			swap(arr[i], arr[j]);
			i++;
		}
		numOfCompares++;
	}
	swap(arr[i], arr[right]);
	return (i);
}

void QuickSort(Student** arr, int low, int high, int &numOfCompares)
{
	int pi;
	if (low < high)
	{
		pi = Partition(arr, low, high, numOfCompares);

		QuickSort(arr, low, pi - 1, numOfCompares);
		QuickSort(arr, pi + 1, high, numOfCompares);
	}
}

Student** MakeCopy(Student** studentsArray, int size)
{
	Student** temp = new Student*[size];
	for (int i = 0; i < size; i++)
		temp[i] = studentsArray[i];
	return temp;
}