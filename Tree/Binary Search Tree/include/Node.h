#ifndef NODE_H
#define NODE_H

class Node
{
    public:
        Node(int data = 0, Node* left = nullptr, Node* right = nullptr);
        ~Node();

    public:
        int m_data;
        Node *m_left;
        Node *m_right;
};

#endif // NODE_H
