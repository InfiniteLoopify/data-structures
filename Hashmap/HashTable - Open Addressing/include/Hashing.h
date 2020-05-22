#include "Data.h"

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable
{
    public:
        HashTable(int size);
        ~HashTable();

        void reHash();
        bool isFull();

        int getNextPrime(int num);
        int isPrime(int num);

        int hash1(int data);
        int hash2(int data);

        void insertKey(int data);
        void deleteKey(int data);
        void display();

    private:
        int m_size;
        int m_capacity;
        Data *m_table;
};

#endif // HASHTABLE_H
