#ifndef DATA_H
#define DATA_H

class Data
{
    public:
        Data();
        ~Data();

        bool isEmpty();
        int getKey();
        int insertKey(int key);
        int deleteKey();

    private:
        int m_key;
        bool m_full;
};

#endif // DATA_H
