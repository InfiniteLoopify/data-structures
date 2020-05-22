#include "Data.h"

Data::Data()
{
    m_key = 0;
    m_full = false;
}
Data::~Data(){}

bool Data::isEmpty() {return !m_full;}
int Data::getKey() {return m_key;}
int Data::insertKey(int key)
{
    m_key = key;
    m_full = true;
}
int Data::deleteKey()
{
    m_key = 0;
    m_full = false;
}
