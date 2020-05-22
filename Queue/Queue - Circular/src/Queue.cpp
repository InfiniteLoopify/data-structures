#include <iostream>
#include "Queue.h"

#ifndef QUEUE_IMP
#define QUEUE_IMP

template <class T, int N> Queue<T, N>::Queue() : m_front(0), m_rear(0), m_size(0) {}
template <class T, int N> Queue<T, N>::~Queue(){}

template <class T, int N> int Queue<T, N>::wrapAround()
{
    if(m_rear == m_maxSize)
        m_rear = 0;
    if(m_front == m_maxSize)
        m_front = 0;
}

template <class T, int N> T Queue<T, N>::enQueue(T num)
{
    if(isEmpty())
    {
        m_front = m_rear = 0;
    }

    if(isFull())
        return -1;
    else
    {
        m_array[m_rear] = num;
        ++m_rear;
        ++m_size;
        wrapAround();
        return num;
    }
}

template <class T, int N> T Queue<T, N>::deQueue()
{
    if(isEmpty())
        return -1;
    else
    {
        T returnFront = m_front;
        ++m_front;
        --m_size;
        wrapAround();
        return m_array[m_front];
    }
}

template <class T, int N> T Queue<T, N>::seekFront() { return isEmpty() ? -1 : m_array[m_front]; }
template <class T, int N> T Queue<T, N>::seekRear()
{
    int temp = m_rear - 1;
    if(temp == - 1)
        temp = m_maxSize - 1;
    return isEmpty() ? -1 : m_array[temp];
}
template <class T, int N> bool Queue<T, N>::isEmpty() { return (m_size == 0); }
template <class T, int N> bool Queue<T, N>::isFull() { return (m_size == m_maxSize); }

template <class T, int N> void Queue<T, N>::display()
{
        for(int i = 0; i < m_maxSize; ++i)
        {
            if(i == m_rear)
                std::cout << "^";
            if(i == m_front)
                std::cout << "*";

            std::cout << m_array[i] << " ";

        }
}

#endif // QUEUE_IMP
