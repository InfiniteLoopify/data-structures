#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue<int, 10> q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    cout << q.seekFront() << " " << q.seekRear() << "- ";
    q.display();
    return 0;
}
