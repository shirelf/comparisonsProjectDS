#include "Selection.h"
Selection::Selection(int _size, Student** studentsArray, long value)
    :size(_size), valueNumber(value), numOfCompares(0), studentsArray(studentsArray){}

//void Selection::RandSelection()
//{
//    ///Wrost case: θ(n^2)
//    ///Average case: θ(n)
//    Reset();
//	Student** studentsArray = MakeCopy();
//	Student* student;
//	student = SelectionFunc(studentsArray,0,size-1,valueNumber);
//    Print(1, student);
//    delete[] studentsArray;
//}

//void Selection::selectHeap()
//{
//    ///Wrost case: θ(nlogn)
//    ///Average case: θ(nlogn)
//    Reset();
//	Student** array = MakeCopy();
//    Heap heap(array,size,numOfCompares);
//	Student* person;
//
//    // Deletes all the k-1 minimum values
//    for(int i = 0 ; i < valueNumber-1; i++)
//    {
//        person = heap.DeleteMin(numOfCompares);
//    }
//
//    // Deletes from the heap the k value of its size and returns it.
//    person = heap.DeleteMin(numOfCompares);
//
//    cout<< person->ID() << " " << person->FirstName() << " " << person->LastName() << endl;
//    Print(2,person);
//    delete[] array;
//}

void Selection::BST()
{
    ///Wrost case: θ(n^2)
    ///Average case: θ(nlogn)
	Reset();
	Student** array = MakeCopy();
	BSTree * peopleBinarySearchTree = new BSTree();

	for (int i = 0; i < size; i++) {
		peopleBinarySearchTree->Insert(array[i]->getId(), *array[i], numOfCompares);
	}

	vector<Student> PeopleInOrder;
	peopleBinarySearchTree->Inorder(PeopleInOrder);

	//Print(3, &PeopleInOrder[valueNumber  - 1]);
	PrintAllPepoleBelowID(PeopleInOrder, valueNumber);
	delete[] array;
}

int Selection::Partition(Student** arr,int left, int right)
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
        numOfCompares++;
    }
    swap(arr[i], arr[right]);
    return (i);
}

//Student * Selection::SelectionFunc(Person** arr,int left,int right,int k)
//{
//    // In case the requested value was not found till the point we were left with 1 value for check after all
//    // partitions made inan even size of A[].
//    if(right == left)
//        return arr[right];
//
//    // Generate a random number in between left and right
//    int pivot = left + rand() % (right - left);
//
//    // Swap A[pivot] with A[right]
//    Person::Swap(&arr[pivot], &arr[right]);
//
//    // Gets pivot's correct location after partition.
//    pivot = Partition(arr,left, right);
//
//    // Amount of values on the left side of the pivot and it self, in the bordered array we have sent.
//    int leftPart = pivot-left+1;
//
//    if(k == leftPart)
//        return arr[pivot];
//    if(k < leftPart)
//        return SelectionFunc(arr,left,pivot-1,k);
//    else
//        return SelectionFunc(arr,pivot+1,right,k-leftPart);
//}


Student** Selection::MakeCopy()
{
	Student** temp = new Student*[size];
    for (int i = 0; i < size; i++)
        temp[i] = studentsArray[i];
    return temp;
}

void Selection::Reset()
{
    numOfCompares = 0;
}

bool Selection::SetNewValue(int value)
{
    if(value <= size && value >= 0)
    {
        valueNumber = value;
        return true;
    }
    return false;
}

void Selection::Print(int type, Student* person)
{
    switch(type)
    {
        case 1:
            cout<< "RandSelection: ";
            break;

        case 2:
            cout<<"selectHeap: ";
            break;
        case 3:
            cout<<"BST: ";
            break;
        default:
            cout<<"ERROR!";
            exit(1);
    }
    cout<< numOfCompares << " comparisons    " << person->getId() << endl;

}

void Selection::PrintAllPepoleBelowID(vector<Student> students, long IDToCompare) {
	vector<Student>::iterator ptr = students.begin();

	while (ptr->getId() <= IDToCompare) {
		cout << ptr->getId() << " " << ptr->getFirstName() << " " << ptr->getLastName() << endl;
		ptr++;
	}
}
