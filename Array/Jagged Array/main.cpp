#include <iostream>
#include "Jagged.h"
using namespace std;

int main()
{
    Jagged j;
    j.insert(1);
    j.insert(2);
    
    j.addRow();
    j.insert(3);
    j.insert(4);
    j.insert(5);
    
    j.addRow();
    j.insert(6);
    
    j.addRow();
    j.insert(7);
    j.insert(8);
    j.insert(9);
    j.insert(10); 
    
    j.display();
    return 0;
}