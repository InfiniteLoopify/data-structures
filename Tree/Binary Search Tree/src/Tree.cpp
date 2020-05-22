#include <iostream>
#include "Tree.h"

Tree::Tree() : m_root(nullptr), m_nodeCount(0) {}
Tree::~Tree(){}

Node*& Tree::getsetRoot() {return m_root;}
Node* Tree::getRoot() {return m_root;}

int Tree::find(int key)
{
    Node *iter = m_root;
    while(true)
    {
        if(iter == nullptr)
            return -1;

        if(key < iter->m_data)
            iter = iter->m_left;
        else if(key > iter->m_data)
            iter = iter->m_right;
        else
            return iter->m_data;
    }
}

Node* Tree::find(Node* iter, int key)
{
    if(iter == nullptr)
        return nullptr;
    else
    {
        if(key < iter->m_data)
            return find(iter->m_left, key);
        else if(key > iter->m_data)
            return find(iter->m_right, key);
        else
            return iter;
    }
}
void Tree::insert(int key)
{
    Node* newNode = new Node(key);

    if(m_root == nullptr)
        m_root = newNode;
    else
    {
        Node *iter = m_root;
        Node *prev = m_root;
        while(true)
        {
            if(key < iter->m_data)
            {
                iter = iter->m_left;
                if(iter == nullptr)
                {
                    prev->m_left = newNode;
                    return;
                }
            }
            else
            {
                iter = iter->m_right;
                if(iter == nullptr)
                {
                    prev->m_right = newNode;
                    return;
                }
            }
            prev = iter;
        }
    }
}

Node* Tree::insert(Node* iter, int key)
{
    if(iter == nullptr)
        iter = new Node(key);
    else
    {
        if(key < iter->m_data)
            iter->m_left = insert(iter->m_left, key);
        else
            iter->m_right = insert(iter->m_right, key);
    }
    return iter;
}

Node* Tree::remove(Node *iter, int key)
{
    if(iter == nullptr)
        return nullptr;
    else
    {
        if(key < iter->m_data)
            iter->m_left = remove(iter->m_left, key);
        else if(key > iter->m_data)
            iter->m_right = remove(iter->m_right, key);
        else
        {
            if(iter->m_left == nullptr && iter->m_right == nullptr)
            {
                delete iter;
                return nullptr;
            }
            else if ( (iter->m_left == nullptr && iter->m_right != nullptr) ||
                      (iter->m_left != nullptr && iter->m_right == nullptr) )
            {
                Node *temp;
                if(iter->m_left != nullptr)
                    temp = iter->m_left;
                else
                    temp = iter->m_right;

                delete iter;
                iter = temp;
                return iter;
            }
            else
            {
                Node* min = getMin(iter->m_right);
                iter->m_data = min->m_data;
                iter->m_right = remove(iter->m_right, iter->m_data);
                return iter;
            }
        }
    }
}

void Tree::print_inOrder(Node *iter)
{
    if(iter == nullptr)
        return;
    else
    {
        print_inOrder(iter->m_left);
        std::cout << iter->m_data << " ";
        print_inOrder(iter->m_right);
    }
}
void Tree::print_preOrder(Node *iter)
{
    if(iter == nullptr)
        return;
    else
    {
        std::cout << iter->m_data << " ";
        print_preOrder(iter->m_left);
        print_preOrder(iter->m_right);
    }
}
void Tree::print_postOrder(Node *iter)
{
    if(iter == nullptr)
        return;
    else
    {
        print_postOrder(iter->m_left);
        print_postOrder(iter->m_right);
        std::cout << iter->m_data << " ";
    }
}

Node* Tree::getMin(Node *iter)
{
    if(iter == nullptr)
        return nullptr;
    if(iter->m_left == nullptr)
        return iter;
    else
        return getMin(iter->m_left);
}
Node* Tree::getMax(Node *iter)
{
    if(iter == nullptr)
        return nullptr;
    if(iter->m_right == nullptr)
        return iter;
    else
        return getMax(iter->m_right);
}

