//#include "Heap.h"
//
//Heap::Heap(Person** A, int n,int& NumComp)
//{
//    heapSize = maxSize = n;
//    data = A;
//    allocated = 0;
//    for (int i = (n/2-1); i >= 0 ; i--)
//        FixHeap(i,NumComp);
//}
//Heap::Heap(int max)
//{
//    data = new Person*[max];
//    maxSize = max;
//    heapSize = 0;
//    allocated = 1;
//}
//
//Heap::~Heap()
//{
//    if(allocated)
//        delete[] data;
//    data = nullptr;
//}
//
//int Heap::Parent(int node)
//{
//    return (node-1)/2;
//}
//
//int Heap::Left(int node)
//{
//    return (2*node + 1);
//}
//
//int Heap::Right(int node)
//{
//    return (2*node + 2);
//}
//
//void Heap::FixHeap(int node,int& NumComp)
//{
//    int min;
//    int left = Left(node);
//    int right = Right(node);
//
//    if((left < heapSize) && (*data[left] < *data[node]))
//        min = left;
//    else min = node;
//    if((right < heapSize) && (*data[right] < *data[min]))
//        min = right;
//
//    NumComp += 2;
//
//    if(min!=node)
//    {
//        Person::Swap(&data[node],&data[min]);
//        FixHeap(min,NumComp);
//    }
//}
//
//Person* Heap::DeleteMin(int& NumComp)
//{
//    if(heapSize < 1)
//    {
//        cout << "Error: EMPTY HEAP\n";
//        exit(1);
//    }
//    Person* min = data[0];
//    heapSize--;
//    data[0] = data[heapSize];
//    FixHeap(0,NumComp);
//    return (min);
//}
//
//void Heap::Insert(Person* item,int& NumComp)
//{
//    if(heapSize == maxSize)
//    {
//        cout << "Error: HEAP FULL\n";
//        exit(1);
//    }
//    int i = heapSize;
//    heapSize++;
//
//    while((i>0) && (data[Parent(i)] < item))
//    {
//        NumComp++;
//        data[i] = data[Parent(i)];
//        i = Parent(i);
//    }
//    data[i] = item;
//}
//
//Person* Heap::Min()
//{
//    return data[0];
//}
//
//void Heap::MakeEmpty()
//{
//    heapSize = 0;
//}
//
//bool Heap::IsEmpty()
//{
//    return (heapSize==0);
//}