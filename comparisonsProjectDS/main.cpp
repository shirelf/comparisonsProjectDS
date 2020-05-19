#include <stdlib.h>
#include <iostream>
#include "Person.h"
#include "Selection.h"
#include <time.h>

using namespace std;

void FreeArray(Person** arr,int size);
Person** getData(int& size, long& val);

int main()
{
    srand(time(nullptr));
    int size;
    long val;
    cin >> size;
    cin.ignore();

    Person** arr = getData(size, val);
    Selection selection(size,arr,val);
   // selection.selectHeap();     //selectHeap
   // selection.RandSelection();  //RandSelection
    selection.BST();            //BST
    FreeArray(arr,size);
	system("pause");
}

Person** getData(int& size, long& val)
{
    string name;
	string firstName;
	string lastName;
    string id;
    Person** PArray = new Person*[size];
    for (int i = 0; i < size; i++)
    {
        cin >> id;
        cin.ignore();
        getline(cin, firstName, ' ');
		getline(cin, lastName);
        try {
            Person* person = new Person(id, firstName, lastName);
            if(i != 0)
            {
                for (int j = 0; j < i; j++)
                {
                    if(PArray[j]->ID() == stol(id))
                    {
                        string ex = "bad";
                        throw ex;
                    }
                }
            }
            PArray[i] = person;
        }
        catch(string ex) {
            cout << "invalid input" << endl;
            FreeArray(PArray,i);
            exit(1);
        }
    }
    cin >> val;
    return PArray;
}

void FreeArray(Person** arr,int size)
{
    for (int i = 0; i < size; i++)
        delete arr[i];
    delete[] arr;
}