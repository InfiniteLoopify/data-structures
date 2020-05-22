#include "Hashing.h"
#include <iostream>
#include <cmath>

HashTable::HashTable(int size)
{
    m_capacity = getNextPrime(size * 2);
    m_size = 0;
    m_table = new Data[m_capacity];
}

HashTable::~HashTable()
{
    if(m_table != nullptr)
        delete[] m_table;
}

void HashTable::reHash()
{
    std::cout << "ReHashing...\n";

    int newCap = getNextPrime(m_capacity * 2);
    Data *temp = new Data[newCap];

    for(int i = 0; i < m_capacity; ++i)
    {
        if(!m_table[i].isEmpty())
        {
            int key = m_table[i].getKey();
            int index = hash1(key);
            int i = 0;
            while(!temp[index].isEmpty())
            {
                ++i;
                index = hash1(hash1(key) + i * hash2(key));
            }
            temp[index].insertKey(key);
        }
    }
    m_capacity = newCap;
    m_table = temp;
    delete[] temp;
}
bool HashTable::isFull() {return (m_capacity - m_size) <= m_size;}

int HashTable::hash1(int data) {return data % m_capacity;}
int HashTable::hash2(int data) {return 11 - (data % 11);}

void HashTable::insertKey(int data)
{
    if(isFull())
        reHash();

    int index = hash1(data);
    int i = 0;
    while(!m_table[index].isEmpty())
    {
        ++i;
        index = hash1(hash1(data) + i * hash2(data));
    }
    m_table[index].insertKey(data);
    ++m_size;
}
void HashTable::deleteKey(int data)
{
    int index = hash1(data);
    int i = 0;
    while(!m_table[index].isEmpty())
    {
        if(m_table[index].getKey() == data)
        {
            m_table[index].deleteKey();
            --m_size;
            return;
        }
        ++i;
        index = hash1(hash1(data) + i * hash2(data));
    }
    std::cout << "notFound\n";

}
void HashTable::display()
{
    for(int i = 0; i < m_capacity; ++i)
        if(!m_table[i].isEmpty())
            std::cout << m_table[i].getKey() << " ";
        else
            std::cout << "* ";
    std::cout << "\n";
}

int HashTable::getNextPrime(int num)
{
    for(int i = num; true; ++i)
        if(isPrime(i))
            return i;
}
int HashTable::isPrime(int num)
{
    for(int i = 2; i <= sqrt(num); ++i)
        if(num % i == 0)
            return false;
    return true;
}
