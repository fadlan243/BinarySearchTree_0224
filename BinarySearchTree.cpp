#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *leftchild;
    Node *rightchild;

    // Constructor for the node class
    Node()
    {
        leftchild = nullptr; /// Initialize left child to null
        rightchild = nullptr; // initialize right child to null
    }
};
class BinaryTree
{
public:
    Node *ROOT;

    BinaryTree()
    {
        ROOT = nullptr; // Initialize ROOT to null
    }

    void insert()
    {
        int x;
        cout << "Masukan nilai: ";
        cin >> x;

        // step 1: Allocate memory for the node 
        Node *newNode = new Node();

        // step 2: Assign value to the data field of new node
        newNode->info = x;

        // step 3: Make the left and the right child of the new node point to null 
        newNode->leftchild = nullptr;
        newNode->rightchild = nullptr;

        // step 4: Locate the node wich will be the parent of the node to be inserted
        Node *parent = nullptr;
        Node *currentNode = nullptr;
        search(x, parent, currentNode);

        // step 5: if parent is NULL (tree is empty)
        if (parent == nullptr)
        {
            // 5a: Mark the node ad ROOT
            ROOT = newNode;
            
            // 5b: exit
            return;
        }

        // step 6: if the value in the data field od new node is less than that of parent 
        if (x < parent->info)
        {
            // 6a: make the left of parent point to the new node
            parent->leftchild = newNode;

            // 6b: exit
            return;
        }

        // step 7: if the value in the data field of the new node is greater than that of the parent 
        else if ( x = parent->info)
        {
            // 7a: make the right child of parent pointer to the new node 
            parent->rightchild = newNode;

            // 7b: exit 
            return;
        }
    }

    void search(int element, Node *&parent, Node *&currentNode)
    {
        // this function searcher the currentNode of the specified Node as will as the current Node of its parent
        currentNode = ROOT;
        parent = nullptr;
        while ((currentNode != nullptr) && (currentNode->info != element))
        {
        parent = currentNode;
        if (element < currentNode ->info)
            currentNode = currentNode ->leftchild;
        else
            currentNode = currentNode ->rightchild;
        }
    }

    void inorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
        return;

        inorder(ptr->leftchild);
        cout << ptr->info << " ";
        inorder(ptr->rightchild);
    }

    void preorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
        return;

        cout << ptr->info << " ";
        preorder(ptr->leftchild);
        preorder(ptr->rightchild);
    }

    void postorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
        return;

        postorder(ptr->leftchild);
        postorder(ptr->rightchild);
        cout << ptr->info << " ";
    }

  bool isEmpty()
    {
        // checks if the tree is empty
        return ROOT == nullptr;
    }
};

int main()
{
    BinaryTree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        