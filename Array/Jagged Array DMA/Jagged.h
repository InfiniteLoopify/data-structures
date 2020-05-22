#ifndef JAGGED_H
#define JAGGED_H

class Jagged{

private:
    void addRow(int length);
    void addCol(int index);

public:    
    Jagged();
    ~Jagged();

    int insert(int data, int row);
    void display();

private:
    int **m_array;
    int *m_size;
    int m_totalRows;
};

#endif /* JAGGED_H */

