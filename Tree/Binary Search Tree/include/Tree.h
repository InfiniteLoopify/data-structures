#ifndef TREE_H
#define TREE_H

#include "Node.h"

class Tree
{
    public:
        Tree();
        ~Tree();

        Node *&getsetRoot();
        Node *getRoot();

        int find(int key);
        Node* find(Node* iter, int key);

        void insert(int key);
        Node* insert(Node* iter, int key);

        Node* remove(Node *iter, int key);

        Node* getMin(Node *iter);
        Node* getMax(Node *iter);

        void print_inOrder(Node *iter);
        void print_preOrder(Node *iter);
        void print_postOrder(Node *iter);

    public:
        Node *m_root;
    private:
        int m_nodeCount;
};

#endif // TREE_H
