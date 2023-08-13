#include <iostream>
#include<utility>

template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};


pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    BinaryTreeNode<int> *temp = root;
    int pred = -1;
    int succ = -1;

    while (temp->data != key)
    {
        if (temp->data > key)
        {
            // right part ma jana hai
            succ = temp->data;
            temp = temp->left;
        }
        else
        {
            pred = temp->data;
            temp = temp->right;
        }
    }

    // now i have found the key and i want to find the pred so i will travel in
    // teh left part of the tree
    BinaryTreeNode<int> *lefttree = temp->left;
    while (lefttree != NULL)
    {
        pred = lefttree->data;
        lefttree = lefttree->right;
    }

    // now finding the succ

    BinaryTreeNode<int> *righttree = temp->right;
    while (righttree != NULL)
    {
        succ = righttree->data;
        righttree = righttree->left;
    }

    pair<int, int> ans = make_pair(pred, succ);
    return {pred,succ};
}
