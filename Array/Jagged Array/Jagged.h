#ifndef JAGGED_H
#define JAGGED_H

class Jagged{
private:
    int **m_array;
    int *m_size;
    int m_totalRows;


public:
    Jagged();
    
    void addRow();
    void addCol(int index);
    int insert(int row, int col, int data);
    int insert(int row, int data);
    int insert(int data);

    void display();
};

#endif /* JAGGED_H */

