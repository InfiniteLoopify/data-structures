#include "Jagged.h"
#include <cstring>
#include <iostream>

Jagged::Jagged(): m_array(nullptr), m_size(nullptr), m_totalRows(0){}

void Jagged::addRow()
{
    ++m_totalRows;
    int **newRow = new int*[m_totalRows];
    if(m_array != nullptr)
    {
        std::memcpy(newRow, m_array, m_totalRows * sizeof(int));
        delete[] m_array;
    }
    m_array = newRow;
    m_array[m_totalRows - 1] = nullptr;

    int *newSize = new int[m_totalRows];
    if(m_size != nullptr)
    {
        memcpy(newSize, m_size, m_totalRows * sizeof(int));
        delete [] m_size;
    }
    m_size = newSize;
    m_size[m_totalRows - 1] = 0;
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
int Jagged::insert(int row, int col, int data)
{
    try
    {
        if(row < 0 || row > m_totalRows)
            throw -1;
        if(col < 0 || col > m_size[row])
            throw -1;

        m_array[row][col] = data;
        return m_array[row][col];
    }
    catch(int Error)
    {
        std::cout << "Index out of bound (" << row << ", " << col << ")\n";
    }
}
int Jagged::insert(int row, int data)
{
    try
    {
        if(row < 0 || row > m_totalRows)
            throw -1;
        addCol(row);
        m_array[row][m_size[row] - 1] = data;
        return m_array[row][m_size[row] - 1];
    }
    catch(int Error)
    {
        std::cout << "Index out of bound (" << row << ", " << m_size[row] - 1  << ")\n";
    }
}
int Jagged::insert(int data)
{
    if(m_array == nullptr)
        addRow();
    
    addCol(m_totalRows - 1);
    m_array[m_totalRows - 1][m_size[m_totalRows - 1] - 1] = data;
    return m_array[m_totalRows - 1][m_size[m_totalRows - 1] - 1];
}
void Jagged::display()
{
    for(int i = 0; i < m_totalRows; ++i)
    {
        for(int j = 0; j < m_size[i]; ++j)
        {
            std::cout << m_array[i][j] << " ";
        }
        std::cout << "\n";
    }
}
