#include <iostream>

using namespace std;

template <class T>
class BST;
template <class T>
class BSTNode
{
    friend BST<T>;
    T data;
    BSTNode<T> *left;
    BSTNode<T> *right;

public:
    BSTNode()
    {
        left = nullptr;
        right = nullptr;
    }
    BSTNode(T value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
    void print()
    {
        cout << data << " ";
    }
    ~BSTNode()
    {
        delete left;
        delete right;
        left = nullptr;
        right = nullptr;
    }
};
template <class T>
class BST
{
    BSTNode<T> *root;
    void inOrderTraversal(BSTNode<T> *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
    int getHeight(BSTNode<T> *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if (leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }
        else
        {
            return rightHeight + 1;
        }
    }

public:
    BST()
    {
        root = nullptr;
    }
    ~BST()
    {
        delete root;
        root = nullptr;
    }
    BST(const BST<T> &other)
    {
        root = new BSTNode<T>;
        root->data = other.root->data;
        root->left = other.root->left;
        root->right = other.root->right;
    }
    void setRoot(T value)
    {
        root = new BSTNode<T>;
        root->data = value;
        root->left = nullptr;
        root->right = nullptr;
    }
    BSTNode<T> *getRoot()
    {
        return root;
    }
    void insert(T value)
    {
        BSTNode<T> *nodePtr = new BSTNode<T>;
        nodePtr->data = value;
        nodePtr->left = nullptr;
        nodePtr->right = nullptr;
        if (root == nullptr)
        {
            root = nodePtr;
        }
        else
        {
            BSTNode<T> *current = root;
            BSTNode<T> *parent = nullptr;
            while (current != nullptr)
            {
                parent = current;
                if (value < current->data)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }
            if (value < parent->data)
            {
                parent->left = nodePtr;
            }
            else
            {
                parent->right = nodePtr;
            }
        }
    }
    BSTNode<T> *getLeftChild(BSTNode<T> *node)
    {
        return node->left;
    }
    BSTNode<T> *getRightChild(BSTNode<T> *node)
    {
        return node->right;
    }
    BSTNode<T> *search(T value)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        BSTNode<T> *current = root;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                return current;
            }
            else
            {
                if (value < current->data)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }
        }
        return nullptr;
    }
    void printNodes(T parentKey)
    {
        BSTNode<T> *current = root;
        while (current != nullptr)
        {
            if (current->data == parentKey)
            {
                inOrderTraversal(current);
                return;
            }
            if (parentKey < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
    }
    void print()
    {
        inOrderTraversal(root);
    }
    int getHeight()
    {
        getHeight(root);
    }
    void displayDescedents(T val)
    {
        BSTNode<T> *temp = search(val);
        if (temp != nullptr)
        {
            inOrderTraversal(temp);
        }
        else
        {
            cout << "No node found with value " << val << endl;
        }
    }
    void displayAncestors(T val)
    {
        BSTNode<T> *temp = search(val);
        if (temp != nullptr)
        {
            BSTNode<T> *current = root;
            if (current->data == temp->data)
            {
                cout << "No ancestors of " << val << endl;
                return;
            }
            do
            {
                cout << current->data << " ";
                if (val < current->data)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            } while (current->data != val && current != nullptr);
        }
        else
        {
            cout << "No node found with value " << val << endl;
        }
    }
    int getNodeCount(BSTNode<T> *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return getNodeCount(node->left) + getNodeCount(node->right) + 1;
    }
    T findMin()
    {
        BSTNode<T> *current = root;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current->data;
    }
    T findMax()
    {
        BSTNode<T> *current = root;
        while (current->right != nullptr)
        {
            current = current->right;
        }
        return current->data;
    }
    BST getMirrorImage()
    {
        BST<T> temp;
        temp.root = new BSTNode<T>;
        temp.root->data = root->data;
        temp.root->left = root->right;
        temp.root->right = root->left;
        return temp;
    }
};

int main()
{
    BST<int> tree;
    tree.insert(30);
    tree.insert(20);
    tree.insert(10);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);
    tree.insert(70);

    cout << endl;
    cout << "Original binary search tree: ";
    tree.print();
    cout << endl;

    cout << endl;
    cout << "Displaying descendants of 70: ";
    tree.displayDescedents(70);
    cout << endl;

    cout << endl;
    cout << "Displaying ancestors of 50: ";
    tree.displayAncestors(50);
    cout << endl;
    
    cout << endl;
    cout << "Displaying nodes count of BST: ";
    cout << tree.getNodeCount(tree.getRoot());
    cout << endl;
    
    cout << endl;
    cout << "Minumum value in BST is: ";
    cout << tree.findMin();
    cout << endl;
    
    cout << endl;
    cout << "Maximum value in BST is: ";
    cout << tree.findMax();
    cout << endl;

    cout << endl;
    BST<int> temp = tree.getMirrorImage();
    temp.print();
    cout << endl;

    return 0;
}