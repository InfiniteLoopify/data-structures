#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
    public:
        Stack();
        ~Stack();
        Stack(const Stack& other);

        T push(T num);
        T pop();
        T peek();
        bool isEmpty();
        bool isFull();
        void display();

    private:
        const int m_maxSize;
        T m_array[50];
        int m_size;
};

#include "../Source/Stack.cpp"
#endif // STACK_H
