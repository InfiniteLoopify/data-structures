#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
    Tree tr;
    Node *&root = tr.getsetRoot();

    root = tr.insert(root, 10);
    root = tr.insert(root, 5);
    root = tr.insert(root, 15);
    root = tr.insert(root, 4);
    root = tr.insert(root, 6);
    root = tr.insert(root, 14);
    root = tr.insert(root, 16);

    tr.print_inOrder(root);
    cout << endl;
    cout  << tr.getsetRoot() << " " << root << endl;

    root = tr.remove(root, 10);
    root = tr.remove(root, 5);
    root = tr.remove(root, 15);
    root = tr.remove(root, 4);
    root = tr.remove(root, 6);
    root = tr.remove(root, 14);
    root = tr.remove(root, 16);

    tr.print_inOrder(root);
    cout << endl;
    cout  << tr.getsetRoot() << " " << root << endl;

//    cout << tempRoot->m_data << endl;

//    if(tempRoot != nullptr)
//        cout << "found";
//    else
//        cout << "No";

    return 0;
}
