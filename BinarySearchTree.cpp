#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *leftchild;
    Node *rightchild;

    // Constructor for the node calss
    Node()
    {
        leftchild = nullptr; /// Initialize left child to null
        rightchild = nullptr; // initialize right child to null
    }
};

class BinaryTree
