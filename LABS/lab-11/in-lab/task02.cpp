#include <iostream>
using namespace std;

template <class T>
class LinkedBinaryTree;
template <class T>
class Node
{
    friend LinkedBinaryTree<T>;
    T info;
    Node<T> *left;
    Node<T> *right;
};
template <class T>
class LinkedBinaryTree
{
    Node<T> *root;
    Node<T> *findNode(T obj, Node<T> *roti)
    {
        if (roti == nullptr)
        {
            return nullptr;
        }
        if (roti->info == obj)
        {
            return roti;
        }
        Node<T> *left = findNode(obj, roti->left);
        Node<T> *right = findNode(obj, roti->right);
        if (left != nullptr)
        {
            return left;
        }
        if (right != nullptr)
        {
            return right;
        }
        return nullptr;
    }
    void preOrderTraversal(Node<T> *root)
    {
        if (root == nullptr)
        {
            return;
        }
        cout << root->info << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
    void inOrderTraversal(Node<T> *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inOrderTraversal(root->left);
        cout << root->info << " ";
        inOrderTraversal(root->right);
    }
    void postOrderTraversal(Node<T> *root)
    {
        if (root == nullptr)
        {
            return;
        }
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->info << " ";
    }

    int isMirror(root, obj.root)
    {
        if (root == nullptr && obj.root == nullptr)
        {
            return 1;
        }
        if (root == nullptr || obj.root == nullptr)
        {
            return 0;
        }
        if (root->info != obj.root->info)
        {
            return 0;
        }
        return isMirror(root->left, obj.root->right) && isMirror(root->right, obj.root->left);
    }

public:
    LinkedBinaryTree()
    {
        root = new Node<T>;
        root->info = -1;
        root->left = nullptr;
        root->right = nullptr;
    }
    ~LinkedBinaryTree()
    {
        delete root;
    }
    LinkedBinaryTree(const LinkedBinaryTree &other)
    {
        root = other.root;
    }
    void setLeftChild(T parentKey, T value)
    {
        Node<T> *parent = findNode(parentKey, root);
        if (parent == nullptr)
        {
            cout << "Parent not found" << endl;
            return;
        }
        if (parent->left != nullptr)
        {
            cout << "Parent already has a left child" << endl;
            return;
        }
        Node<T> *newNode = new Node<T>;
        newNode->info = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        parent->left = newNode;
        // cout << "parent key: " << parent->info << endl;
        // cout << "setted left child: " << parent->left->info << endl;
    }
    void setRightChild(T parentKey, T value)
    {
        Node<T> *parent = findNode(parentKey, root);
        if (parent == nullptr)
        {
            cout << "Parent not found" << endl;
            return;
        }
        if (parent->right != nullptr)
        {
            cout << "Parent already has a right child" << endl;
            return;
        }
        Node<T> *newNode = new Node<T>;
        newNode->info = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        parent->right = newNode;
        // cout << "parent key: " << parent->info << endl;
        // cout << "setted right child: " << parent->right->info << endl;
    }

    void preOrder()
    {
        preOrderTraversal(root);
        cout << endl;
    }
    void postOrder()
    {
        postOrderTraversal(root);
        cout << endl;
    }
    void inOrder()
    {
        inOrderTraversal(root);
        cout << endl;
    }
    T getParent(T obj)
    {
        Node<T> *node = findNode(obj, root);
        if (node == nullptr)
        {
            cout << "Node not found" << endl;
            return -1;
        }
        if (node == root)
        {
            cout << "Root has no parent" << endl;
            return -1;
        }
        Node<T> *parent = findNode(obj, node);
        if (parent == nullptr)
        {
            cout << "Parent not found" << endl;
            return -1;
        }
        return parent->info;
    }
    int isMirror(LinkedBinaryTree<T> &obj)
    {
        return isMirror(root, obj.root);
    }
    T lowestCommonAncestor(T a, T b)
    {
        Node<T> *nodeA = findNode(a, root);
        Node<T> *nodeB = findNode(b, root);
        if (nodeA == nullptr || nodeB == nullptr)
        {
            cout << "Node not found" << endl;
            return -1;
        }
        if (nodeA == root || nodeB == root)
        {
            cout << "Root has no parent" << endl;
            return -1;
        }
        Node<T> *parentA = findNode(a, nodeA);
        Node<T> *parentB = findNode(b, nodeB);
        if (parentA == nullptr || parentB == nullptr)
        {
            cout << "Parent not found" << endl;
            return -1;
        }
        if (parentA == parentB)
        {
            return parentA->info;
        }
        return lowestCommonAncestor(parentA->info, parentB->info);
    }
    int findBalanceFactor(T val)
    {
        Node<T> *node = findNode(val, root);
        if (node == nullptr)
        {
            cout << "Node not found" << endl;
            return -1;
        }
        if (node->left == nullptr && node->right == nullptr)
        {
            return 0;
        }
        if (node->left == nullptr)
        {
            return node->right->info + 1;
        }
        if (node->right == nullptr)
        {
            return node->left->info + 1;
        }
        return node->left->info - node->right->info;
    }
    void remove(T node)
    {
        Node<T> *nodeToRemove = findNode(node, root);
        if (nodeToRemove == nullptr)
        {
            cout << "Node not found" << endl;
            return;
        }
        if (nodeToRemove->left == nullptr && nodeToRemove->right == nullptr)
        {
            delete nodeToRemove;
            return;
        }
        if (nodeToRemove->left == nullptr)
        {
            Node<T> *temp = nodeToRemove->right;
            nodeToRemove->info = temp->info;
            nodeToRemove->left = temp->left;
            nodeToRemove->right = temp->right;
            delete temp;
            return;
        }
        if (nodeToRemove->right == nullptr)
        {
            Node<T> *temp = nodeToRemove->left;
            nodeToRemove->info = temp->info;
            nodeToRemove->left = temp->left;
            nodeToRemove->right = temp->right;
            delete temp;
            return;
        }
        Node<T> *temp = nodeToRemove->left;
        while (temp->right != nullptr)
        {
            temp = temp->right;
        }
        nodeToRemove->info = temp->info;
        delete temp;
    }
};

int main()
{
    LinkedBinaryTree<int> ins;
    ins.setLeftChild(-1, 10);
    ins.setRightChild(-1, 20);
    ins.setRightChild(10, 50);
    ins.setRightChild(50, 100);
    cout << ins.getParent(10);
    ins.preOrder();
    ins.postOrder();
    ins.inOrder();
    return 0;
}
