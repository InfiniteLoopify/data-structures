#include <iostream>
#include <list>
#include "LinkedList.h"
//#include <algorithm>

int main()
{
    LinkedList <int> li;
    li.push_back(1);
    li.push_back(2);
    li.push_back(3);
    li.push_back(4);
    li.push_back(5);
    
    int n = 0;
    li.swap(n, n+3);
    
    li.display();
    li.displayMem();
    
    li.displayRev();
    li.displayMemRev();
    
}
