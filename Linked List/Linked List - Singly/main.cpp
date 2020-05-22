#include <iostream>
#include <list>
#include "LinkedList.h"
//#include <algorithm>

int main()
{
    LinkedList <int> li;

    li.push_back(rand()%20 +1);
    li.push_back(rand()%20 +1);
    li.push_back(rand()%20 +1);
    li.push_back(rand()%20 +1);
    li.push_back(rand()%20 +1);
    li.push_back(rand()%20 +1);
    li.push_back(rand()%20 +1);

    li.display();
    
    li.insertionSort();
    li.display();
}
