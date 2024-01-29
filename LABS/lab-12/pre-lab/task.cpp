#include <iostream>
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
    BSTNode<T> *deleting(BSTNode<T> *root_add, T val)
    {
        if (root_add == nullptr)
        {
            return nullptr;
        }

        if (root_add->data > val)
        {
            root_add->left = deleting(root_add->left, val);
        }
        else if (root_add->data < val)
        {
            root_add->right = deleting(root_add->right, val);
        }
        else
        {
            // Node to be deleted is found
            if (root_add->left == nullptr)
            {
                BSTNode<T> *temp = root_add->right;
                delete root_add;
                return temp;
            }
            else if (root_add->right == nullptr)
            {
                BSTNode<T> *temp = root_add->left;
                delete root_add;
                return temp;
            }
            else
            {
                // Node with two children
                BSTNode<T> *temp = findmin(root_add->right);
                root_add->data = temp->data;
                root_add->right = deleting(root_add->right, temp->data);
            }
        }
        return root_add;
    }
    BSTNode<T> *findmin(BSTNode<T> *root_add)
    {
        if (root_add == nullptr)
        {
            return nullptr;
        }
        // Keep moving to the left child until there is no left child
        while (root_add->left)
        {
            root_add = root_add->left;
        }
        // Return the node with the minimum value (or nullptr if the tree is empty)
        return root_add;
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
    BSTNode<T> *getRoot()
    {
        return root;
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
    ins.insert(58);
    ins.printNodes(50);

    ins.deleting(ins.getRoot(), 55);
    ins.printNodes(50);

    // BSTNode<int> *temp = ins.findmin(ins.getRoot());
    // cout << temp->data << endl;

    // ----------------checking print function
    // ins.printNodes(50);
    // BSTNode<int> *t;
    // // ----------------checking search function
    // t = ins.search(60);
    // cout << "value found is: " << t->data << endl;
    // // ----------------checking delete function
    // ins.deleteNode(t);
    // cout << "after deleting 60: " << endl;
    // ins.printNodes(50);
    return 0;
}