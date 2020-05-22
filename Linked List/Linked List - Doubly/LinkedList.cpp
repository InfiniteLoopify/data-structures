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
    newNode->prev = nullptr;
    
    if(m_head != nullptr)
        m_head->prev = newNode;
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
        newNode->prev = m_tail;
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
        newNode->next->prev = newNode;
        newNode->prev = iter;
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
    else
        m_head->prev = nullptr;

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
        deleter->next->prev = iter;
        delete deleter;
        --m_listSize;
    }
    return 0;
}
template <class T> int LinkedList<T>::reverse()
{
    Node *iter = m_head;
    Node *temp = nullptr;
    while(iter != nullptr)
    {
        temp = iter->next;
        iter->next = iter->prev;
        iter->prev = temp;
        iter = iter->prev;
    }
    temp = m_head;
    m_head = m_tail;
    m_tail = temp;
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

template <class T> int LinkedList<T>::displayRev()
{
    
    //if list is empty
    if(m_tail == nullptr)
    {
        std::cout << "-\n";
        return -1;
    }

    //iterate and display the complete list
    Node *iter = m_tail;
    while(iter != nullptr)
    {
        std::cout << iter->data << " ";
        iter = iter->prev;
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
    std::cout << "(" << m_head << ") ";
    
    std::cout << iter << " ";
    while(iter != nullptr)
    {
        std::cout << iter->next << " ";
        iter = iter->next;
    }
    std::cout << " (" << m_tail << ")";
    std::cout << std::endl;
    return 0;
}

template <class T> int LinkedList<T>::displayMemRev()
{
    //if list is empty
    if(m_tail == nullptr)
    {
        std::cout << "-\n";
        return -1;
    }
    
    //iterate and display the memory of the complete list
    Node *iter = m_tail;
    std::cout << "(" << m_tail << ") ";
    
    std::cout << iter << " ";
    while(iter != nullptr)
    {
        std::cout << iter->prev << " ";
        iter = iter->prev;
    }
    std::cout << " (" << m_head << ")";
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
        std::cout << "Invalid Index (" << index << ")\n";
    else
    {
        Node *iter = m_head;
        for(int i = 0; i < index; ++i)
            iter = iter->next;
        return iter->data;
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
    
    if(n1+1 == n2)
    {
        if(n1 == 0)
            m_head = cur2;
        else
            prev1->next = cur2;
        
        if(n2 == m_listSize-1)
        {
            m_tail = cur1;
            cur1->next = nullptr;
        }
        else
        {
            cur1->next = cur2->next;
            cur1->next->prev = cur1;
        }
        cur2->prev = prev1;
        cur1->prev = cur2;
        cur2->next = cur1;
    }
    else
    {
        Node *temp = cur1->next;
        if(n1 == 0)
            m_head = cur2;
        else
            prev1->next = cur2;
        
        if(n2 == m_listSize-1)
        {
            m_tail = cur1;
            cur1->next = nullptr;
        }
        else
        {
            cur1->next = cur2->next;
            cur1->next->prev = cur1;
        }
        cur2->prev = prev1;
        
        cur2->next = temp;
        temp->prev = cur2;
        prev2->next = cur1;
        cur1->prev = prev2;
    }
}

#endif
