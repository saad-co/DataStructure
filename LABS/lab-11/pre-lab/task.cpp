#include <iostream>
using namespace std;

template <typename T>
class BT
{
private:
    T *arr;
    bool *initialized;
    int size = 0;

    void preOrderTraversal(int index = 0)
    {
        if (index < size && initialized[index])
        {
            cout << arr[index] << " ";
            preOrderTraversal(2 * index + 1);
            preOrderTraversal(2 * index + 2);
        }
    }

    void postOrderTraversal(int index = 0)
    {
        if (index < size && initialized[index])
        {
            postOrderTraversal(2 * index + 1);
            postOrderTraversal(2 * index + 2);
            cout << arr[index] << " ";
        }
    }

    void inOrderTraversal(int index = 0)
    {
        if (index < size && initialized[index])
        {
            inOrderTraversal(2 * index + 1);
            cout << arr[index] << " ";
            inOrderTraversal(2 * index + 2);
        }
    }

public:
    BT(int maxsize)
    {
        arr = new T[maxsize]{0};
        initialized = new bool[maxsize]{false};
        size = maxsize;
    }

    ~BT()
    {
        delete[] arr;
        delete[] initialized;
    }

    BT(const BT &obj) : size(obj.size)
    {
        if (arr)
        {
            delete[] arr;
            delete[] initialized;
        }
        arr = new T[size];
        initialized = new bool[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = obj.arr[i];
            initialized[i] = obj.initialized[i];
        }
    }

    void setLeftChild(T parentKey, T value)
    {
        int p_idx = 0;
        while (p_idx < size && arr[p_idx] != parentKey)
        {
            p_idx++;
        }

        if (p_idx < size)
        {
            int c_idx = 2 * p_idx + 1;
            if (c_idx < size)
            {
                arr[c_idx] = value;
                initialized[c_idx] = true;
                initialized[0] = true;
                // cout << arr[c_idx];
                return;
            }
            else
            {
                cout << "array size exceeded. Can't add the child" << endl;
            }
        }
        else
        {
            cout << "Parent key not found: " << endl;
        }
    }

    void setRightChild(T parentKey, T value)
    {
        int p_idx = 0;
        while (p_idx < size && arr[p_idx] != parentKey)
        {
            p_idx++;
        }

        if (p_idx < size)
        {
            int c_idx = 2 * p_idx + 2;
            if (c_idx < size)
            {
                arr[c_idx] = value;
                initialized[c_idx] = true;
                initialized[0] = true;
                return;
            }
            else
            {
                cout << "array size exceeded. Can't add the child" << endl;
            }
        }
        else
        {
            cout << "Parent key not found: " << endl;
        }
    }

    void preOrder()
    {
        preOrderTraversal();
        cout << endl;
    }

    void postOrder()
    {
        postOrderTraversal();
        cout << endl;
    }

    void inOrder()
    {
        inOrderTraversal();
        cout << endl;
    }
    T getParent(T childKey)
    {
        int c_idx = 0;
        while (c_idx < size && arr[c_idx] != childKey)
        {
            c_idx++;
        }

        if (c_idx < size && initialized[c_idx])
        {
            int p_idx = (c_idx - 1) / 2;
            if (p_idx >= 0 && p_idx < size && initialized[p_idx])
            {
                return arr[p_idx];
            }
            else
            {
                cout << "Parent not found for the given child key." << endl;
            }
        }
        else
        {
            cout << "Child key not found: " << endl;
        }
        return -1;
    }
};

int main()
{
    BT<int> tree(20);

    // Adding nodes to the tree
    tree.setLeftChild(0, 10);
    tree.setRightChild(0, 40);
    tree.setLeftChild(10, 20);
    tree.setRightChild(10, 30);
    tree.setLeftChild(40, 50);
    tree.setRightChild(40, 60);

    // Testing traversals
    cout << "Pre-order traversal: ";
    tree.preOrder();
    cout << endl;

    cout << "Post-order traversal: ";
    tree.postOrder();
    cout << endl;

    cout << "In-order traversal: ";
    tree.inOrder();
    cout << endl;

    // Testing getParent function
    int childKey = 60;
    int parentKey = tree.getParent(childKey);

    if (parentKey != -1)
        cout << "Parent key of " << childKey << ": " << parentKey << endl;

    return 0;
}
