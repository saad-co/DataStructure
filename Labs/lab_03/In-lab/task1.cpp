#include <iostream>
using namespace std;

class UnsortedList
{
    int *arr;
    int maxSize, currSize;
    void resize()
    {
        maxSize = maxSize * 2;
        int *temp = new int[maxSize];
        for (int i = 0; i < currSize; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        temp = nullptr;
    }

public:
    UnsortedList()
    {
        maxSize = 1;
        currSize = 0;
        arr = new int[maxSize];
    }

    ~UnsortedList()
    {
        delete[] arr;
    }

    UnsortedList(const UnsortedList &obj)
    {
        maxSize = obj.maxSize;
        currSize = obj.currSize;
        arr = new int[maxSize];
        for (int i = 0; i < currSize; i++)
        {
            arr[i] = obj.arr[i];
        }
    }

    const UnsortedList &operator=(const UnsortedList &obj)
    {
        if (this != &obj)
        {
            delete[] arr;
            maxSize = obj.maxSize;
            currSize = obj.currSize;
            arr = new int[maxSize];
            for (int i = 0; i < currSize; i++)
            {
                arr[i] = obj.arr[i];
            }
        }

        return *this;
    }

    void insert(int val)
    {
        if (isFull())
        {
            resize();
        }
        if (currSize < maxSize)
        {
            arr[currSize++] = val;
        }
    }

    bool isFull() const
    {
        return currSize == maxSize;
    }

    bool isEmpty() const
    {
        return currSize == 0;
    }

    void display() const
    {
        for (int i = 0; i < currSize; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    bool remove(int index)
    {
        if (index < 0 || index >= currSize)
        {
            return false;
        }

        for (int i = index; i < currSize - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        currSize--;

        return true;
    }
    UnsortedList intersection(const UnsortedList &list2) const;
    bool isSubset(const UnsortedList &list2) const;
    UnsortedList difference(const UnsortedList &list2) const;
};

UnsortedList UnsortedList::intersection(const UnsortedList &list2) const
{
    UnsortedList intersect;
    for (int i = 0; i < this->currSize; i++)
    {
        for (int j = 0; j < list2.currSize; j++)
        {
            if (this->arr[i] == list2.arr[j])
            {
                intersect.insert(arr[i]);
            }
        }
    }

    return intersect;
}

bool UnsortedList::isSubset(const UnsortedList &list2) const
{
    bool flag = false;
    for (size_t j = 0; j < this->currSize; j++)
    {
        for (int i = 0; i < list2.currSize; i++)
        {
            if (this->arr[j] == list2.arr[i])
            {
                flag = true;
            }
        }
        if (flag != true)
        {
            return false;
        }
    }
    return true;
}

UnsortedList UnsortedList::difference(const UnsortedList &list2) const
{
    UnsortedList temp;
    for (int i = 0; i < this->currSize; i++)
    {
        bool flag = false;
        for (int j = 0; j < list2.currSize; j++)
        {
            if (this->arr[i] == list2.arr[j])
            {
                flag = true;
            }
        }
        if (flag == false)
        {
            temp.insert(arr[i]);
        }
    }
    return temp;
}

int main()
{
    UnsortedList obj;
    obj.insert(1);
    obj.insert(2);
    obj.insert(3);
    obj.insert(4);
    // obj.display();
    obj.remove(2);
    obj.display();

    UnsortedList obj2;
    obj2.insert(10);
    obj2.insert(20);
    obj2.insert(33);
    obj2.insert(44);
    obj2.insert(1);
    obj2.insert(4);
    obj2.insert(2);
    obj2.insert(3);
    obj2.display();

    UnsortedList obj3;
    obj3 = obj2.difference(obj);
    obj3.display();
    // if (obj.isSubset(obj2))
    // {
    //     cout << "ok";
    // }
    // else
    // {
    //     cout << "not ok";
    // }
    return 0;xws
}