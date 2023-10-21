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
        for (int i = frontIndex; i < rearIndex; i++)
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
    myQueue<T> &operator=(const myQueue<T> &rhs)
    {
        if (this != &rhs)
        {
            delete[] queueData;
            rearIndex = rhs.rearIndex;
            frontIndex = rhs.frontIndex;
            queueCapacity = rhs.queueCapacity;
            numberOfElements = rhs.numberOfElements;
            queueData = new T[queueCapacity];
            for (int i = 0; i < rhs.numberOfElements; i++)
            {
                queueData[i] = rhs.queueData[i];
            }
        }
        return *this;
    }
    ~myQueue()
    {
        delete[] queueData;
        queueData = nullptr;
        rearIndex = frontIndex = numberOfElements = queueCapacity = 0;
    }
    void enqueue(const T element)
    {
        if (isFull())
        {
            resize(queueCapacity * 2);
        }
        queueData[rearIndex] = element;
        rearIndex++;
        numberOfElements++;
    }
    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            T temp = queueData[frontIndex];
            frontIndex++;
            numberOfElements--;
            return temp;
        }
    }
    T getFront() const
    {
        return queueData[frontIndex];
    }
    bool isEmpty()
    {
        if (numberOfElements == 0)
        {
            frontIndex = rearIndex = 0;
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

template <typename T>
class myStack
{
    myQueue<T> queue1;
    myQueue<T> queue2;

public:
    myStack() : queue1(), queue2()
    {
    }
    ~myStack()
    {
        queue1.~myQueue();
        queue2.~myQueue();
    }
    void push(const T element)
    {
        if (queue1.isEmpty())
        {
            queue1.enqueue(element);
        }
        else
        {
            while (queue1.isEmpty() == false)
            {
                int temp = queue1.dequeue();
                queue2.enqueue(temp);
            }
            queue1.enqueue(element);
            while (queue2.isEmpty() == false)
            {
                int temp = queue2.dequeue();
                queue1.enqueue(temp);
            }
        }
        cout << element << " pushed to stack" << endl;
    }
    T pop()
    {
        if (queue1.isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            return queue1.dequeue();
        }
    }
};

int main()
{
    myStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    cout << endl;
    cout << stack.pop() << " popped from stack" << endl;
    cout << stack.pop() << " popped from stack" << endl;
    cout << stack.pop() << " popped from stack" << endl;
    cout << stack.pop() << " popped from stack" << endl;
    cout << stack.pop() << " popped from stack" << endl;

    return 0;
}