#ifndef SELECTION_SELECTION_H
#define SELECTION_SELECTION_H

#include "Heap.h"
#include "BSTree.h"
#include <time.h>
#include <fstream>

class Selection
{
private:
    int size;
    Person** Arr;
    int valueNumber;
    int numOfCompares;

public:
    Selection(int _size,Person** array, long value);

    void RandSelection();
    void selectHeap();
	void BST();


    Person* SelectionFunc(Person** arr,int left,int right,int k) ;
    int Partition(Person** arr,int left, int right);
    Person** MakeCopy();
    void Reset();
    bool SetNewValue(int value);
    void Print(int type,Person* person);
	void PrintAllPepoleBelowID(vector<Person> people, long IDToCompare);
};

#endif //SELECTION_SELECTION_H