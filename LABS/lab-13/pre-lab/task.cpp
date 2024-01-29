#include <iostream>
using namespace std;

template <class T>
class BSTNode;

template <class T>
class AVL;

template <class T>
class BST
{
protected:
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
    virtual void insert(T value)
    {
    }
    virtual void deleteNode(T value);
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
};

template <class T>
class BSTNode
{
    friend class BST<T>;
    friend class AVL<T>;
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
class AVL : public BST<T>
{
private:
    int getBalanceFactor(BSTNode<T> *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    BSTNode<T> *rotateRight(BSTNode<T> *y)
    {
        BSTNode<T> *x = y->left;
        BSTNode<T> *T2 = x->right;

        x->right = y;
        y->left = T2;

        return x;
    }

    BSTNode<T> *rotateLeft(BSTNode<T> *x)
    {
        BSTNode<T> *y = x->right;
        BSTNode<T> *T2 = y->left;

        y->left = x;
        x->right = T2;

        return y;
    }

    BSTNode<T> *insert(BSTNode<T> *node, T value)
    {
        if (node == nullptr)
        {
            BSTNode<T> *newNode = new BSTNode<T>(value);
            return newNode;
        }

        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insert(node->right, value);
        }
        else
        {
            // Duplicate values are not allowed in AVL trees
            return node;
        }

        // Update height of current node
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        node->height = 1 + max(leftHeight, rightHeight);

        // Get the balance factor and perform rotations if needed
        int balance = getBalanceFactor(node);

        // Left Heavy
        if (balance > 1)
        {
            if (value < node->left->data)
            {
                // Left-Left case
                return rotateRight(node);
            }
            else
            {
                // Left-Right case
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        // Right Heavy
        if (balance < -1)
        {
            if (value > node->right->data)
            {
                // Right-Right case
                return rotateLeft(node);
            }
            else
            {
                // Right-Left case
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    BSTNode<T> *minValueNode(BSTNode<T> *node)
    {
        BSTNode<T> *current = node;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    BSTNode<T> *deleteNode(BSTNode<T> *root, T key)
    {
        // Perform standard BST delete
        if (root == nullptr)
        {
            return root;
        }

        if (key < root->data)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // Node with only one child or no child
            if (root->left == nullptr || root->right == nullptr)
            {
                BSTNode<T> *temp = root->left ? root->left : root->right;

                // No child case
                if (temp == nullptr)
                {
                    temp = root;
                    root = nullptr;
                }
                else // One child case
                {
                    *root = *temp; // Copy the contents of the non-empty child
                }

                delete temp;
            }
            else
            {
                // Node with two children, get the inorder successor
                BSTNode<T> *temp = minValueNode(root->right);

                // Copy the inorder successor's data to this node
                root->data = temp->data;

                // Delete the inorder successor
                root->right = deleteNode(root->right, temp->data);
            }
        }

        // If the tree had only one node then return
        if (root == nullptr)
        {
            return root;
        }

        // Update height of current node
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // Get the balance factor and perform rotations if needed
        int balance = getBalanceFactor(root);

        // Left Heavy
        if (balance > 1)
        {
            if (getBalanceFactor(root->left) >= 0)
            {
                // Left-Left case
                return rotateRight(root);
            }
            else
            {
                // Left-Right case
                root->left = rotateLeft(root->left);
                return rotateRight(root);
            }
        }

        // Right Heavy
        if (balance < -1)
        {
            if (getBalanceFactor(root->right) <= 0)
            {
                // Right-Right case
                return rotateLeft(root);
            }
            else
            {
                // Right-Left case
                root->right = rotateRight(root->right);
                return rotateLeft(root);
            }
        }
        return root;
    }

public:
    void insert(T value) override
    {
        this->root = insert(this->root, value);
    }

    void deleteNode(T value) override
    {
        this->root = deleteNode(this->root, value);
    }
};
