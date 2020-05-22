#include <iostream>
#include "Heap.h"

using namespace std;

int main()
{
    Heap heap(20);
    heap.insertKey(1);
    heap.insertKey(2);
    heap.insertKey(3);
    heap.insertKey(4);
    heap.insertKey(5);
    heap.insertKey(6);
    heap.insertKey(7);
    heap.display();

    heap.sort();
    heap.display();

    return 0;
}
