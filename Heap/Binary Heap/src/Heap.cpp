#include <iostream>
#include "Heap.h"

Heap::Heap(int cap)
{
    m_capacity = cap;
    m_size = 0;
    m_arr = new int[m_capacity];
}
Heap::~Heap()
{
    if(m_arr != nullptr)
        delete[] m_arr;
}

void Heap::maxHeapify(int size, int index)
{
    int largest = index;
    int left = getLeft(index);
    int right = getRight(index);

    if(left < size && m_arr[left] > m_arr[largest])
        largest = left;
    if(right < size && m_arr[right] > m_arr[largest])
        largest = right;

    if(largest != index)
    {
        swap(m_arr[largest], m_arr[index]);
        maxHeapify(size, largest);
    }
}

int Heap::extractMax()
{
    if(m_size <= 0)
        return -1;

    if(m_size == 1)
    {
        --m_size;
        return m_arr[0];
    }

    int max = m_arr[0];
    m_arr[0] = m_arr[m_size - 1];
    --m_size;
    maxHeapify(m_size, 0);

    return max;
}
void Heap::increaseKey(int index, int value)
{
    if(!inBound(index))
        return;

    m_arr[index] = value;
    while(index >= 0 && m_arr[index] > m_arr[getParent(index)])
    {
        swap(m_arr[index], m_arr[getParent(index)]);
        index = getParent(index);
    }
}
void Heap::deleteKey(int index)
{
    if(!inBound(index))
        return;

    increaseKey(index, 999999);
    extractMax();
}
void Heap::insertKey(int value)
{
    if(m_size >= m_capacity)
        return;

    m_arr[m_size] = value;
    ++m_size;

    int i = m_size - 1;
    while(i >= 0 && m_arr[i] > m_arr[getParent(i)])
    {
        swap(m_arr[i], m_arr[getParent(i)]);
        i = getParent(i);
    }
}

void Heap::swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Heap::display()
{
    for(int i = 0; i < m_size; ++i)
        std::cout << m_arr[i] << " ";
    std::cout << std::endl;
}

void Heap::sort()
{
    for(int i = m_size / 2 - 1; i >= 0; --i)
        maxHeapify(m_size, i);

    for(int i = m_size - 1; i >= 0; --i)
    {
        swap(m_arr[0], m_arr[i]);
        maxHeapify(i, 0);
    }
}
