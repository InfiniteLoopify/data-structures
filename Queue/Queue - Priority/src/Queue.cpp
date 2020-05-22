#include <iostream>
#include "Queue.h"

#ifndef QUEUE_IMP
#define QUEUE_IMP

template <class T, int N> Queue<T, N>::Queue() : m_front(-1), m_size(0) {}
template <class T, int N> Queue<T, N>::~Queue(){}

template <class T, int N> T Queue<T, N>::enQueue(T num)
{
    if(!isFull())
    {
        int index = m_front;
        while(m_array[index] > num && index >= 0)
        {
            m_array[index + 1] = m_array[index];
            --index;
        }
        m_array[index + 1] = num;
        ++m_front;
        ++m_size;
        return m_front;
    }
    else
        return -1;
}

template <class T, int N> T Queue<T, N>::deQueue()
{
    if(!isEmpty())
    {
        --m_front;
        --m_size;
        return m_array[m_front + 1];
    }
    else
        return -1;
}

template <class T, int N> T Queue<T, N>::seekFront() { return isEmpty() ? -1 : m_array[0]; }
template <class T, int N> T Queue<T, N>::seekRear() { return isEmpty() ? -1 : m_array[m_front]; }
template <class T, int N> bool Queue<T, N>::isEmpty() { return (m_size == 0); }
template <class T, int N> bool Queue<T, N>::isFull() { return (m_size == m_maxSize); }

template <class T, int N> void Queue<T, N>::display()
{
        for(int i = 0; i < m_maxSize; ++i)
        {
            std::cout << m_array[i] << " ";
            if(i == m_front)
                std::cout << "^ ";
        }
}

#endif // QUEUE_IMP
