#include <iostream>
using namespace std;

template <typename T>
class SortedList
{
    T *arr;
    int maxSize, currSize;
    void resize()
    {
        maxSize *= 2;
        T *temp = new T[maxSize];
        for (int i = 0; i < currSize; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }

public:
    SortedList();
    ~SortedList();
    SortedList(const SortedList &);
    const SortedList &operator=(const SortedList &);
    void insert(T val);
    bool isFull() const;
    bool isEmpty() const;
    void display() const;
    bool remove(int index);
};

template <typename T>
SortedList<T>::SortedList()
{
    maxSize = 1;
    currSize = 0;
    arr = new T[maxSize];
}
template <typename T>
SortedList<T>::SortedList(const SortedList &obj) : currSize(obj.currSize), arr(new T[obj.currSize])
{
    for (int i = 0; i < obj.currSize; i++)
    {
        arr[i] = obj.arr[i];
    }
}

template <typename T>
SortedList<T>::~SortedList()
{
    if (arr)
    {
        delete[] arr;
    }
}

template <typename T>
const SortedList<T> &SortedList<T>::operator=(const SortedList &obj)
{
    if (this != &obj)
    {
        delete[] arr;
        currSize = obj.currSize;
        arr = new T[currSize];
        for (int i = 0; i < currSize; i++)
        {
            arr[i] = obj.arr[i];
        }
    }
    return *this;
}

template <typename T>
bool SortedList<T>::isEmpty() const
{
    return currSize == 0;
}

template <typename T>
bool SortedList<T>::isFull() const
{
    return currSize == maxSize;
}

template <typename T>
void SortedList<T>::insert(T val)
{
    if (isEmpty())
    {
        arr[currSize++] = val;
        return;
    }
    else if (isFull())
    {
        resize();
    }

    int i = currSize - 1;
    while (i >= 0 && arr[i] > val)
    {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = val;
    currSize++;
}

template <typename T>
void SortedList<T>::display() const
{
    for (int i = 0; i < currSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
bool SortedList<T>::remove(int index)
{
    try
    {
        if (isEmpty())
        {
            throw runtime_error("Array is Empty");
        }

        if (index < 0 || index >= currSize)
        {
            throw out_of_range("Invalid Index");
        }

        for (int i = index; i < currSize - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        currSize--;

        return true;
    }
    catch (const exception &e)
    {
        cerr << e.what() << std::endl;
        return false;
    }
}

int main()
{
    SortedList<int> myList;

    myList.insert(5);
    myList.insert(2);
    myList.insert(8);
    myList.insert(3);
    myList.insert(1);

    cout << "Original List: ";
    myList.display();

    myList.remove(2);
    cout << "List after removing element at index 2: ";
    myList.display();

    SortedList<int> newList;
    newList.insert(10);
    // newList.insert(7);

    cout << "New List: ";
    newList.display();
    cout << "adbiasi";

    myList = newList;

    cout << "List after assignment: ";
    myList.display();
    return 0;
}
