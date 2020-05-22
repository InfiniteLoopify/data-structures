#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue<int, 6> q;
    q.enQueue(6);
    q.enQueue(5);
    q.enQueue(4);

    cout << q.seekFront() << " " << q.seekRear() << "- ";
    q.display();
    return 0;
}
