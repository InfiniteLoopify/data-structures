#ifndef QUEUE_H
#define QUEUE_H

template <class T, int N>
class Queue
{
    public:
        Queue();
        ~Queue();
        T enQueue(T num);
        T deQueue();
        T seekFront();
        T seekRear();
        bool isEmpty();
        bool isFull();
        void display();

    private:
        int wrapAround();

    private:
        int m_array[N];
        const int m_maxSize = N;
        int m_front;
        int m_rear;
        int m_size;
};

#include "../src/Queue.cpp"

#endif // QUEUE_H
