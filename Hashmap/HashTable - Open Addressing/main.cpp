#include <iostream>
#include "Hashing.h"

using namespace std;

int main()
{
    HashTable h(6);
    h.display();

    h.insertKey(1);
    h.insertKey(1);
    h.insertKey(1);
    h.insertKey(1);
    h.insertKey(1);
    h.insertKey(1);
    h.insertKey(1);

    h.display();
    h.insertKey(24);
    h.display();
    h.deleteKey(24);
    h.display();
    h.deleteKey(1);
    h.display();
    return 0;
}
