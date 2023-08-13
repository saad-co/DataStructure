#include <iostream>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        size = 0;
        arr[size] = -1;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void del()
    {
        if (size == 0)
        {
            cout << "Heap is empty: " << endl;
            return;
        }

        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int leftChild = 2 * i;
            int rightChild = leftChild + 1;
            if (leftChild < size && arr[leftChild] > arr[i])
            {
                swap(arr[leftChild], arr[i]);
                i = leftChild;
            }
            else if (rightChild < size && arr[rightChild] > arr[i])
            {
                swap(arr[rightChild], arr[i]);
                i = rightChild;
            }
            else
            {
                return;
            }
        }
    }
};

void heapify(int arr[], int i, int n)
{
    int largest = i;
    int leftChild = i * 2;
    int rightChild = leftChild + 1;

    if (leftChild < n && arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }
     if (rightChild < n && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, largest, n);
    }
}
  
int main()
{
    // heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.print();

    // h.del();
    // h.print(); 

    cout << "heapify algorithm: " << endl
         << endl;
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    for (int i = 0; i <= 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;

    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, i, n);
    }

    cout << "print the heap converted array: " << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}