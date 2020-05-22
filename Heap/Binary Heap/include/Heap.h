#ifndef HEAP_H
#define HEAP_H


class Heap
{
    private:
        int *m_arr;
        int m_capacity;
        int m_size;

    private:
        void swap(int &a, int &b);

    public:
        Heap(int cap);
        ~Heap();

        void maxHeapify(int size, int index);
        void sort();
        int extractMax();
        void increaseKey(int index, int value);
        void deleteKey(int index);
        void insertKey(int value);

        int getParent(int i) {return (i - 1)/2;}
        int getLeft(int i) {return i*2 + 1;}
        int getRight(int i) {return i*2 + 2;}
        int getMax(int i) {return m_arr[0];}
        bool inBound(int i) {return (i >= 0 && i < m_size);}


        void display();
};

#endif // HEAP_H
