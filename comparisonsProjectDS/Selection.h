#ifndef SELECTION_SELECTION_H
#define SELECTION_SELECTION_H

#include "Heap.h"
#include "BSTree.h"
#include <time.h>
#include <fstream>
#include "Student.h"
#include "List.h"
#include <vector>
#include <iostream>

using namespace std;

class Selection
{
private:
    int size;
    Student** studentsArray;
    int valueNumber;
    int numOfCompares;

public:
	
	Selection(int _size,Student** array, long value);
	

    void RandSelection();
    void selectHeap();
	void BST();


    //Student* SelectionFunc(Student** studentsArray,int left,int right,int k) ;
    int Partition(Student** studentsArray,int left, int right);
    Student** MakeCopy();
    void Reset();
    bool SetNewValue(int value);
    void Print(int type,Student* Student);
	void PrintAllPepoleBelowID(vector<Student> students, long IDToCompare);
};

#endif //SELECTION_SELECTION_H