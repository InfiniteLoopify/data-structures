#include "Jagged.h"
#include <cstring>
#include <iostream>

Jagged::Jagged()
{
    m_totalRows = 1;
    m_array = new int*[m_totalRows];
    m_size = new int[m_totalRows];
    m_size[0] = 0;
    m_array[0] = nullptr;
}

Jagged::~Jagged()
{
    for(int i = m_totalRows - 1; i >= 0; --i)
    {
        if(m_array[i] != nullptr)
            delete [] m_array[i];
    }
    delete [] m_array;
}

void Jagged::addRow(int length)
{
    if(length+1 > m_totalRows)
    {
        int oldRows = m_totalRows;
        m_totalRows = length+1;
        int **newRow = new int*[m_totalRows];
        std::memcpy(newRow, m_array, m_totalRows * sizeof(int));
        delete[] m_array;
        m_array = newRow;
        
        int *newSize = new int[m_totalRows];
        std::memcpy(newSize, m_size, m_totalRows * sizeof(int));
        delete[] m_size;
        m_size = newSize;
        
        for(int i = oldRows; i < m_totalRows; ++i)
        {
            m_array[i] = nullptr;
            m_size[i] = 0;
        }
    }
}

void Jagged::addCol(int index)
{
    ++m_size[index];
    int *newCol = new int[m_size[index]];
    if(m_array[index] != nullptr)
    {
        std::memcpy(newCol, m_array[index], m_size[index] * sizeof(int));
        delete[] m_array[index];
    }
    m_array[index] = newCol;
}

int Jagged::insert(int data, int row)
{
    if(row < 0)
        return -1;
    
    addRow(row);
    addCol(row);
    m_array[row][m_size[row] - 1] = data;
    return 0;
}

void Jagged::display()
{
    std::cout << "\nJagged Array:\n";
    for(int i = 0; i < m_totalRows; ++i)
    {
        for(int j = 0; j < m_size[i]; ++j)
        {
            std::cout << m_array[i][j] << " ";
        }
        if(m_size[i] == 0)
            std::cout << "-";
        std::cout << "\n";
    }
}
