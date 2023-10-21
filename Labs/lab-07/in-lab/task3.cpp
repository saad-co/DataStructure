#include <iostream>
#include <queue>


using namespace std;

template <typename T>
class myQueue
{
private:
    int rearIndex;        // Index of the rear element
    int frontIndex;       // Index of the front element
    int queueCapacity;    // Maximum capacity of the queue
    int numberOfElements; // Number of elements in the queue
    T *queueData;         // Array to store queue elements

    void resize(int newSize) // resize function
    {
        queueCapacity = newSize;
        T *temp = new T[queueCapacity];
        for (int i = 0; i < numberOfElements; i++)
        {
            temp[i] = this->queueData[i];
        }
        delete[] this->queueData;
        queueData = temp;
        temp = nullptr;
    }

public:
    myQueue(){}
    myQueue(int n)
    {
        rearIndex = frontIndex = numberOfElements = 0;
        queueCapacity = n;
        queueData = new T[queueCapacity];
    }
    myQueue(const myQueue<T> &obj) // copy constructor
    {
        delete[] this->queueData;

        this->frontIndex = obj.frontIndex;
        this->rearIndex = obj.rearIndex;
        this->numberOfElements = obj.numberOfElements;
        this->queueCapacity = obj.queueCapacity;
        queueData = new T[obj.numberOfElements];
        for (size_t i = 0; i < obj.numberOfElements; i++)
        {
            this->queueData[i] = obj.queueData[i];
        }
    }

    myQueue<T> &operator=(const myQueue<T> &obj) // assignment operator
    {
        if (this == &obj) // self assignment
        {
            return *this;
        }

        delete[] this->queueData;
        this->frontIndex = obj.frontIndex;
        this->rearIndex = obj.rearIndex;
        this->numberOfElements = obj.numberOfElements;
        this->queueCapacity = obj.queueCapacity;
        queueData = new T[obj.numberOfElements];
        for (size_t i = 0; i < obj.numberOfElements; i++)
        {
            this->queueData[i] = obj.queueData[i];
        }
        return *this;
    }

    ~myQueue()
    {
        if (this->queueData)
        {
            delete[] this->queueData;
            queueData = nullptr;
        }
    }

    void push(const T element) // Add an element to the back of the queue
    {
        if (isFull())
        {
            resize(queueCapacity * 2);
        }
        queueData[rearIndex++] = element;
        numberOfElements++;
    }
    T pop() // Remove and return the front element
    {
        if (isEmpty())
        {
            throw "Queue is empty: ";
        }
        else
        {
            T elem = queueData[frontIndex];
            frontIndex++;
            numberOfElements--;
            return elem;
        }
    }

    T front() const // Get the front element without removing it
    {
        if (isEmpty())
        {
            throw "Queue is empty";
        }
        else
        {
            return queueData[frontIndex];
        }
    }
    bool isEmpty() const // Check if the queue is empty
    {
        return rearIndex == frontIndex;
    }

    bool isFull() const // Check if the queue is full
    {
        return numberOfElements == queueCapacity;
    }
    int size() const // Get the current number of elements
    {
        return numberOfElements;
    }
    int getCapacity() const // Get the maximum capacity of the queue
    {
        return queueCapacity;
    }
};
int main()
{
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    cout << "Binary numbers from 1 to " << N << " are:" << endl;
    myQueue<string> q(200);
    q.push("1");

    while (N--)
    {
        string s = q.front();
        q.pop();
        cout << s << " ";

        q.push(s + "0");
        q.push(s + "1");
    }
    return 0;
}
