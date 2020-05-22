#include <iostream>
#include "Stack.h"

#ifndef STACK_IMP
#define STACK_IMP

template <class T> Stack<T>::Stack() : m_maxSize(50), m_size(-1){}
template <class T> Stack<T>::~Stack(){}

template <class T> Stack<T>::Stack(const Stack& other) : m_maxSize(50)
{
    m_size = other.m_size;
    for(int i = 0; i <= m_size; ++i)
        m_array[i] = other.m_array[i];
}

template <class T> T Stack<T>::push(T num)
{
    if( !isFull() )
    {
        ++m_size;
        m_array[m_size] = num;
        return num;
    }
    else
        return -1;
}

template <class T> T Stack<T>::pop()
{
    if( !isEmpty() )
    {
        --m_size;
        return m_array[m_size + 1];
    }
    else
        return -1;
}

template <class T> T Stack<T>::peek() { return isEmpty() ? -1 : m_array[m_size]; }
template <class T> bool Stack<T>::isEmpty() { return (m_size == -1); }
template <class T> bool Stack<T>::isFull() { return (m_size == m_maxSize - 1); }

template <class T> void Stack<T>::display()
{
    std::cout << m_size << "- ";
    for(int i = 0; i <= m_size; ++i)
        std::cout << m_array[i] << " ";
    std::cout << "\n";
}
#endif // STACK_IMP
