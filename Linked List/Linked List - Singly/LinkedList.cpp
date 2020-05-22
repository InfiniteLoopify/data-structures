#include <iostream>
#include "LinkedList.h"


#ifndef LIST_IMPL__
#define LIST_IMPL__


template <class T> LinkedList<T>::LinkedList() : m_head(nullptr), m_tail(nullptr), m_listSize(0) {}
template <class T> LinkedList<T>::~LinkedList() {LinkedList::clear();}
template <class T> LinkedList<T>::LinkedList(const LinkedList &lst)
{
    m_head = nullptr; 
    m_tail = nullptr; 
    m_listSize = 0;
    
    Node *iter = lst.m_head;
    while(iter != nullptr)
    {
        this->push_back(iter->data);
        iter = iter->next;
    }
}

template <class T> int LinkedList<T>::clear()
{
    if(m_head == nullptr)
        return 0;
    
    Node *deleter = m_head;
    Node *iter = m_head->next;
    while(iter != nullptr)
    {
        delete deleter;
        deleter = iter;
        iter = iter->next;
    }
    delete deleter;
    m_head = nullptr;
    m_tail = nullptr;
    m_listSize = 0;
    return 0;
}

template <class T> int LinkedList<T>::push_front(T data)
{
    ++m_listSize;
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = m_head;
    m_head = newNode;
    
    if(m_tail == nullptr)
        m_tail = newNode;
    
    return 0;
}

template <class T> int LinkedList<T>::push_back(T data)
{
    if(m_head == nullptr)
        push_front(data);
    else
    {
        ++m_listSize;
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        m_tail->next = newNode;
        m_tail = newNode;
    }
    return 0;
}

template <class T> int LinkedList<T>::insert(T data, int index)
{
    if(index < 0 || index > m_listSize)
    {
        std::cout << "Index is out of Bound (" << index << ")\n";
        return -1;
    }
    
    if(index == 0)
        push_front(data); 
    else if(index == m_listSize)
        push_back(data);
    else
    {
        ++m_listSize;
        Node *newNode = new Node;
        newNode->data = data;
        
        Node *iter = m_head;
        for(int i = 0; i < index - 1; ++i)
            iter = iter->next;
       
        newNode->next = iter->next;
        iter->next = newNode;
    }
}

template <class T> int LinkedList<T>::removeStart()
{
    if(m_head == nullptr)
        return 0;
    
    Node *deleter = m_head;
    m_head = m_head->next;
    delete deleter;

    if(m_head == nullptr)
        m_tail = nullptr;

    --m_listSize;
}

template <class T> int LinkedList<T>::removeEnd()
{
    if(m_head == nullptr)
        return 0;
    
    if(m_listSize == 1)
    {
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
        m_listSize = 0;
    }
    else
    {
        Node *iter = m_head;
        for(int i = 1; i <= m_listSize-2; ++i)
            iter = iter->next;
        delete m_tail;
        iter->next = nullptr;
        m_tail = iter;
        --m_listSize;
    }
}

template <class T> int LinkedList<T>::remove(int index)
{
    if(m_listSize == 0)
    {
        std::cout << "List is already Empty\n";
        return 0;    
    }  
    if(index < 0 || index >= m_listSize)
    {
        std::cout << "Index is out of Bound (" << index << ")\n";
        return -1;
    }
    
    if(index == 0)
        removeStart();
    else if(index == m_listSize-1)
        removeEnd();
    else
    {
        Node *iter = m_head;
        for(int i = 0; i < index-1; ++i)
            iter = iter->next;
        
        Node *deleter = iter->next;
        iter->next = deleter->next;
        delete deleter;
        --m_listSize;
    }
    return 0;
}
template <class T> int LinkedList<T>::reverse()
{
        //if list is empty or has 1 node, then do nothing
    if(m_head == nullptr || m_head->next == nullptr)
        return 0;

    //3 pointer to nodes to save address
    Node *prev = nullptr;   //starting node will now point to null, not head to 1st node
    Node *cur = m_head;
    Node *next = m_head->next;

    //traverse list until end
    while(next != nullptr)
    {
        //link current node to previous
        cur->next = prev;
        prev = cur;
        cur = next;
        next = next->next;
    }
    cur->next = prev;
    m_tail = m_head;
    m_head = cur; //link head node to the last node
    return 0;
}

template <class T> int LinkedList<T>::reverse(LinkedList<T>::Node *iter)
{
    if(iter->next == nullptr)
    {
        m_tail = m_head;
        m_head = iter;
        return 0;
    }
    
    reverse(iter->next);
    iter->next->next = iter;
    iter->next = nullptr;
}
    

template <class T> int LinkedList<T>::copy(const LinkedList &lst)
{
    if(this == &lst)
        return 0;
    
    this->clear();
    
    Node *iter = lst.m_head;
    while(iter != nullptr)
    {
        push_back(iter->data);
        iter = iter->next;
    }
    return 0;
}

template <class T> LinkedList<T>& LinkedList<T>::operator = (LinkedList &lst)
{
    copy(lst);
    return *this;
}

template <class T> int LinkedList<T>::display()
{
    //if list is empty
    if(m_head == nullptr)
    {
        std::cout << "-\n";
        return -1;
    }

    //iterate and display the complete list
    Node *iter = m_head;
    while(iter != nullptr)
    {
        std::cout << iter->data << " ";
        iter = iter->next;
    }
    std::cout << std::endl;
    return 0;
}
template <class T> int LinkedList<T>::displayMem()
{
    //if list is empty
    if(m_head == nullptr)
    {
        std::cout << "-\n";
        return -1;
    }
    
    //iterate and display the memory of the complete list
    Node *iter = m_head;
    while(iter != nullptr)
    {
        std::cout << iter->next << " ";
        iter = iter->next;
    }
    std::cout << std::endl;
    return 0;
}

template <class T> int LinkedList<T>::display(Node *iter)
{
    if(iter == nullptr)
        return 0;
    
    std::cout << iter->data << " ";
    display(iter->next);
}        

template <class T> int LinkedList<T>::search(T data)
{
    Node *iter = m_head;
    int index = 0;
    while(iter != nullptr)
    {
        if(iter->data == data)
            return index;
        
        index++;
        iter = iter->next;
    }
    return -1;
}
template <class T> T & LinkedList<T>::operator [] (int index)
{
    if(index < 0 || index >= m_listSize)
    {}
    else
    {
        Node *iter = m_head;
        for(int i = 0; i < index; ++i)
            iter = iter->next;
        return iter->data;
    }
}

template <class T> typename LinkedList<T>::Node * LinkedList<T>::getNode(int index)
{
    if(index < 0 || index >= m_listSize)
        std::cout << "Invalid Index (" << index << ")\n";
    else
    {
        Node *iter = m_head;
        for(int i = 0; i < index; ++i)
            iter = iter->next;
        return iter;
    }
}

template <class T> int LinkedList<T>::swap(int n1, int n2)
{
    if(n1 < 0 || n2 < 0 || n1 >= m_listSize || n2 >= m_listSize)
        return -1;
    
    if(n1 == n2)
        return 0;
    
    if(n1 > n2)
    {
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
    
    Node *prev1 = nullptr;
    Node *cur1 = m_head;    
    for(int i = 0; i < n1; ++i)
    {
        prev1 = cur1;
        cur1 = cur1->next;
    }

    Node *prev2 = nullptr;
    Node *cur2 = m_head;    
    for(int i = 0; i < n2; ++i)
    {
        prev2 = cur2;
        cur2 = cur2->next;
    }
    
    Node *temp = cur1->next;
    
    if(n1 == 0)
        m_head = cur2;
    else
        prev1->next = cur2;

    if(n2 == m_listSize - 1)
    {
        cur1->next = nullptr;
        m_tail = cur1;
    }
    else
        cur1->next = cur2->next;

    if(n1 + 1 == n2)
        cur2->next = cur1;
    else
    {
        cur2->next = temp;
        prev2->next = cur1;
    }
}

template <class T> int LinkedList<T>::bubbleSort()
{
    for(int i = 0; i < m_listSize-1; ++i)
    {
        bool doSwap = false;
        for(int j = 0; j < m_listSize-i-1; ++j)
        {
            Node *temp = getNode(j);
            if(temp->data < temp->next->data)
            {
                swap(j, j+1);
                doSwap = true;
            }
        }
        if(!doSwap)
            return 0;
    }
}
template <class T> int LinkedList<T>::selectionSort()
{
    for(int i = 0; i < m_listSize-1; ++i)
    {
        bool doSwap = false;
        int index = i;
        for(int j = i+1; j < m_listSize; ++j)
        {
            if(operator[](index) < operator[](j))
            {
                index = j;
                doSwap = true;
            }
        }
        if(doSwap)
            swap(i, index);
    }
}
template <class T> int LinkedList<T>::insertionSort()
{
    for(int i = 1; i < m_listSize; ++i)
    {
        T key = operator[](i);
        int j = i-1;
        while(key > operator[](j) && j >= 0)
        {
            operator[](j+1) = operator[](j);
            --j;
        }
        operator[](j+1) = key;
    }
}


#endif
