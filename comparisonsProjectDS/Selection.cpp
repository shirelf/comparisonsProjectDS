#include "Selection.h"

Selection::Selection(int _size,Person** array, long value)
    :size(_size),valueNumber(value),numOfCompares(0),Arr(array){}

void Selection::RandSelection()
{
    ///Wrost case: θ(n^2)
    ///Average case: θ(n)
    Reset();
    Person** arr = MakeCopy();
    Person* person;
    person = SelectionFunc(arr,0,size-1,valueNumber);
    Print(1,person);
    delete[] arr;
}

void Selection::selectHeap()
{
    ///Wrost case: θ(nlogn)
    ///Average case: θ(nlogn)
    Reset();
    Person** array = MakeCopy();
    Heap heap(array,size,numOfCompares);
    Person* person;

    // Deletes all the k-1 minimum values
    for(int i = 0 ; i < valueNumber-1; i++)
    {
        person = heap.DeleteMin(numOfCompares);
    }

    // Deletes from the heap the k value of its size and returns it.
    person = heap.DeleteMin(numOfCompares);

    cout<< person->ID() << " " << person->FirstName() << " " << person->LastName() << endl;
    Print(2,person);
    delete[] array;
}

void Selection::BST()
{
    ///Wrost case: θ(n^2)
    ///Average case: θ(nlogn)
	Reset();
	Person** array = MakeCopy();
	BSTree * peopleBinarySearchTree = new BSTree();

	for (int i = 0; i < size; i++) {
		peopleBinarySearchTree->Insert(array[i]->ID(), *array[i], numOfCompares);
	}

	vector<Person> PeopleInOrder;
	peopleBinarySearchTree->Inorder(PeopleInOrder);

	//Print(3, &PeopleInOrder[valueNumber  - 1]);
	PrintAllPepoleBelowID(PeopleInOrder, valueNumber);
	delete[] array;
}

int Selection::Partition(Person** arr,int left, int right)
{
    Person* pivot = arr[right]; // pivot
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

Person* Selection::SelectionFunc(Person** arr,int left,int right,int k)
{
    // In case the requested value was not found till the point we were left with 1 value for check after all
    // partitions made inan even size of A[].
    if(right == left)
        return arr[right];

    // Generate a random number in between left and right
    int pivot = left + rand() % (right - left);

    // Swap A[pivot] with A[right]
    Person::Swap(&arr[pivot], &arr[right]);

    // Gets pivot's correct location after partition.
    pivot = Partition(arr,left, right);

    // Amount of values on the left side of the pivot and it self, in the bordered array we have sent.
    int leftPart = pivot-left+1;

    if(k == leftPart)
        return arr[pivot];
    if(k < leftPart)
        return SelectionFunc(arr,left,pivot-1,k);
    else
        return SelectionFunc(arr,pivot+1,right,k-leftPart);
}


Person** Selection::MakeCopy()
{
    Person** temp = new Person*[size];
    for (int i = 0; i < size; i++)
        temp[i] = Arr[i];
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

void Selection::Print(int type,Person* person)
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
    cout<< numOfCompares << " comparisons    " << person->ID() << endl;

}

void Selection::PrintAllPepoleBelowID(vector<Person> people, long IDToCompare) {
	vector<Person>::iterator ptr = people.begin();

	while (ptr->ID() <= IDToCompare) {
		cout << ptr->ID() << " " << ptr->FirstName() << " " << ptr->LastName() << endl;
		ptr++;
	}

}
