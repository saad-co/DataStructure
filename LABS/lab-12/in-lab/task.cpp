#include <iostream>
#include <climits>
using namespace std;

template <class T>
class BST;

template <class T>
class BSTNode
{
    friend BST<T>;
    BSTNode<T> *left;
    BSTNode<T> *right;

public:
    T data;
    BSTNode()
    {
        data = T();
        left = nullptr;
        right = nullptr;
    }
    BSTNode(T d, BSTNode<T> *l = nullptr, BSTNode<T> *r = nullptr)
    {
        data = d;
        left = l;
        right = r;
    }
};

template <class T>
class BST
{
    BSTNode<T> *root;
    void destroy(BSTNode<T> *p)
    {
        if (p != NULL)
        {
            destroy(p->left);
            destroy(p->right);
            delete p;
        }
    }
    BSTNode<T> *copy(BSTNode<T> *p)
    {
        if (p == NULL)
            return NULL;
        BSTNode<T> *q = new BSTNode<T>(p->data);
        q->left = copy(p->left);
        q->right = copy(p->right);
        return q;
    }
    void insertProper(BSTNode<T> *n, T value)
    {
        if (n->data > value)
        {
            if (n->left != nullptr)
            {
                insertProper(n->left, value);
            }
            else
            {
                n->left = new BSTNode<T>(value);
            }
        }
        if (n->data < value)
        {
            if (n->right != nullptr)
            {
                insertProper(n->right, value);
            }
            else
            {
                n->right = new BSTNode<T>(value);
            }
        }
    }
    void print(BSTNode<T> *t)
    {
        if (t != nullptr)
        {
            print(t->left);
            cout << t->data << " ";
            print(t->right);
        }
    }

    BSTNode<T> *find(BSTNode<T> *loot, const T value)
    {
        if (loot == nullptr)
        {
            return nullptr;
        }
        if (loot->data == value)
        {
            return loot;
        }
        if (loot->data > value)
        {
            find(loot->left, value);
        }
        if (loot->data < value)
        {
            find(loot->right, value);
        }
    }

    int findHeight(BSTNode<T> *loot)
    {
        if (loot == nullptr)
        {
            return 0;
        }
        else
        {
            int leftHeight = findHeight(loot->left);
            int rightHeight = findHeight(loot->right);

            return 1 + max(leftHeight, rightHeight);
        }
    }

public:
    BST() { root = nullptr; }
    ~BST()
    {
        destroy(root);
    }
    BST(const BST<T> &t)
    {
        root = copy(t.root);
    }
    void setRoot(T value)
    {
        root = new BSTNode<T>(value);
    }
    void insert(T value)
    {
        if (root == nullptr)
        {
            root = new BSTNode<T>(value);
        }
        else
        {
            insertProper(root, value);
        }
    }
    BSTNode<T> *getLeftChild(BSTNode<T> *node)
    {
        if (node == nullptr)
        {
            cout << "this is a leaf node: " << endl;
            return nullptr;
        }
        else
        {
            return node->left;
        }
    }
    BSTNode<T> *getRightChild(BSTNode<T> *node)
    {
        if (node == nullptr)
        {
            cout << "this is a leaf node: " << endl;
            return nullptr;
        }
        else
        {
            return node->right;
        }
    }
    BSTNode<T> *search(T value)
    {
        BSTNode<T> *temp = find(root, value);
        if (temp)
        {
            return temp;
        }
        else
        {
            cout << "No node found with given value" << endl;
            return nullptr;
        }
    }
    void deleteNode(BSTNode<T> *node)
    {
        if (node == nullptr)
        {
            return;
        }
        else
        {
            BSTNode<T> *current = root;
            while (current != nullptr)
            {
                if (current->data == node->data)
                {
                    if (current->left == nullptr && current->right == nullptr)
                    {
                        delete current;
                        current = nullptr;
                    }
                    else if (current->left == nullptr)
                    {
                        BSTNode<T> *replacement = current->right;
                        if (replacement->left == nullptr)
                        {
                            current->data = replacement->data;
                            current->right = replacement->right;
                        }
                        else
                        {
                            while (replacement->left->left != nullptr)
                            {
                                replacement = replacement->left;
                            }
                            current->data = replacement->left->data;
                            replacement->left = nullptr;
                        }
                    }
                    else
                    {
                        BSTNode<T> *replacement = current->left;
                        if (replacement->right == nullptr)
                        {
                            current->data = replacement->data;
                            current->left = replacement->left;
                        }
                        else
                        {
                            while (replacement->right->right != nullptr)
                            {
                                replacement = replacement->right;
                            }
                            current->data = replacement->right->data;
                            replacement->right = nullptr;
                        }
                    }
                    return;
                }
                if (node->data < current->data)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }
        }
    }
    void printNodes(T value)
    {
        BSTNode<T> *temp = find(root, value);
        if (temp)
        {
            print(temp);
            cout << endl;
        }
        else
        {
            cout << "No node found with given value" << endl;
        }
    }
    bool isBST(BSTNode<T> *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (root->left != nullptr && root->left->data > root->data)
        {
            return false;
        }
        if (root->right != nullptr && root->right->data < root->data)
        {
            return false;
        }
        if (!isBST(root->left) || !isBST(root->right))
        {
            return false;
        }
        return true;
    }
    BSTNode<T> *getroot()
    {
        return root;
    }
    bool isEqual(BSTNode<T> *r1, BSTNode<T> *r2)
    {
        if (r1 == nullptr && r2 == nullptr)
        {
            return true;
        }
        if (r1 == nullptr || r2 == nullptr)
        {
            return false;
        }
        if (r1->data != r2->data)
        {
            return false;
        }
        if (!isEqual(r1->left, r2->left) || !isEqual(r1->right, r2->right))
        {
            return false;
        }
        return true;
    }
    bool isInternalNode(BSTNode<T> *node)
    {
        // Returns true if given node is an internal node.Where, internal Node is one which has degree greater than zero.
        if (node->left != nullptr || node->right != nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int getHeight()
    {
        return findHeight(root);
    }
};

int main()
{
    BST<int> ins;
    // ----------------checking insert function
    ins.insert(50);
    ins.insert(40);
    ins.insert(60);
    ins.insert(55);
    ins.insert(65);

    // ----------------checking print function
    ins.printNodes(50);
    BSTNode<int> *t = ins.getroot();
    BSTNode<int> *t2 = ins.getroot();
    // // ----------------checking search function
    // t = ins.search(60);
    // cout << "value found is: " << t->data << endl;
    // // ----------------checking delete function
    // ins.deleteNode(t);
    // cout << "after deleting 60: " << endl;
    // ins.printNodes(50);
    // if (ins.isEqual(t, t2))
    // {
    //     cout << "okay: " << endl;
    // }
    // else
    // {
    //     cout << "not okay: " << endl;
    // }

    // int var = ins.getHeight();
    // cout << "height of the tree is: " << var << endl;

    return 0;
}