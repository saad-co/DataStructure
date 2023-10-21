#include <iostream>

using namespace std;

template <typename T>
class myQueue
{
    int rearIndex;
    int frontIndex;
    int queueCapacity;
    int numberOfElements;
    T *queueData;
    void resize(int newSize)
    {
        T *temp = new T[newSize];
        for (int i = 0; i < numberOfElements; i++)
        {
            temp[i] = queueData[i];
        }
        delete[] queueData;
        queueData = temp;
        queueCapacity = newSize;
        temp = nullptr;
    }

public:
    myQueue()
    {
        rearIndex = frontIndex = numberOfElements = 0;
        queueCapacity = 1;
        queueData = new T[queueCapacity];
    }
    ~myQueue()
    {
        delete[] queueData;
        queueData = nullptr;
        rearIndex = frontIndex = numberOfElements = queueCapacity = 0;
    }
    void enqueueAtFront(const T element)
    {
        if (isFull())
        {
            resize(queueCapacity * 2);
        }
        if (frontIndex == 0)
        {
            frontIndex = (queueCapacity - 1);
            queueData[frontIndex] = element;
        }
        else
        {
            frontIndex--;
            queueData[frontIndex] = element;
        }
        numberOfElements++;
    }
    void enqueueAtEnd(const T element)
    {
        if (isFull())
        {
            resize(queueCapacity * 2);
        }
        if (rearIndex == (queueCapacity - 1))
        {
            rearIndex = 0;
            queueData[rearIndex] = element;
        }
        else
        {
            rearIndex++;
            queueData[rearIndex] = element;
        }
        numberOfElements++;
    }
    T dequeueFromFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        if (numberOfElements == 1)
        {
            T temp = queueData[frontIndex];
            frontIndex = rearIndex = 0;
            numberOfElements--;
            return temp;
        }
        if (frontIndex == (queueCapacity - 1))
        {
            T temp = queueData[frontIndex];
            frontIndex = 0;
            numberOfElements--;
            return temp;
        }
        else
        {
            T temp = queueData[frontIndex];
            frontIndex++;
            numberOfElements--;
            return temp;
        }
    }
    T dequeueFromEnd()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        if (numberOfElements == 1)
        {
            T temp = queueData[rearIndex];
            frontIndex = rearIndex = 0;
            numberOfElements--;
            return temp;
        }
        if (rearIndex == 0)
        {
            T temp = queueData[rearIndex];
            rearIndex = (queueCapacity - 1);
            numberOfElements--;
            return temp;
        }
        else
        {
            T temp = queueData[rearIndex];
            rearIndex--;
            numberOfElements--;
            return temp;
        }
    }
    bool isEmpty() const
    {
        if (numberOfElements == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull() const
    {
        if (numberOfElements == queueCapacity)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int size() const
    {
        return numberOfElements;
    }
    int getCapacity() const
    {
        return queueCapacity;
    }
};

int main()
{
    myQueue<int> q1;

    q1.enqueueAtFront(5);
    q1.enqueueAtEnd(10);
    q1.enqueueAtFront(2);

    cout << "size of deque: " << q1.size() << endl;
    cout << q1.dequeueFromFront() << endl;
    cout << q1.dequeueFromEnd() << endl;
    q1.enqueueAtEnd(7);

    cout << "size of deque: " << q1.size() << endl;

    return 0;
}