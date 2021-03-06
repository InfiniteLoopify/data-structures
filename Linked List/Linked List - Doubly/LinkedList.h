#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class LinkedList
{
    private:
        struct Node
        {
            T data;
            Node *next;
            Node *prev;
        };
        Node *m_head;
        Node *m_tail;
        int m_listSize;

    public:
        LinkedList();
        LinkedList(const LinkedList &lst);
        ~LinkedList();

        Node *getHead(){return m_head;}
        Node *getTail(){return m_tail;}
        int getSize(){return m_listSize;}
        
        int push_front(T data);
        int push_back(T data);
        int insert(T data, int index);
        
        int clear();
        int remove(int index);
        int removeStart();
        int removeEnd();
        int copy(const LinkedList &lst);
        
        int reverse();
        int reverse(Node *iter);
        
        int search(T data);
        
        LinkedList &operator = (LinkedList &lst);
        T &operator [] (int index);
        
        int swap(int i, int j);
        
        int display();
        int displayRev();
        int display(Node *iter);
        int displayMem();
        int displayMemRev();
};

#include "LinkedList.cpp"
#endif // LINKEDLIST_H

