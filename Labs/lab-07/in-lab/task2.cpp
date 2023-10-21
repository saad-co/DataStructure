#include <iostream>
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
public:
    myQueue(int n)
    {
        rearIndex = frontIndex = numberOfElements = 0;
        queueCapacity = n;
        queueData = new T[queueCapacity];
    }

    ~myQueue()
    {
        if (this->queueData)
        {
            delete[] this->queueData;
            queueData = nullptr;
        }
    }

    void enqueue(const T element) // Add an element to the back of the queue
    {
        queueData[frontIndex++] = element;
        if (frontIndex >= queueCapacity)
        {
            frontIndex = 0;
            numberOfElements = 0;
        }
        numberOfElements++;
    }
    void print()
    {
        for (int i = 0; i < queueCapacity; i++)
        {
            cout << "enter the data of queue: " << endl;
            cout << queueData[i] << " " << endl;
        }
    }

    int fun(int arr[3], int newnmbr)
    {
        int cnt = 0;
        bool flag = false;
        for (int i = 0; i < 3; i++)
        {
            if (arr[i] == newnmbr)
            {
                cnt++;
                return 1;
            }
        }
        if (flag = false)
        {
            return -1;
        }
    }
};

int main()
{
    myQueue<int> q(3);
    int n = 0;
    cout << "enter the number of page you want to read: " << endl;
    cin >> n;
    int hit = 0, fault = 3;
    cout << "enter the three initial page numbers you want to read: " << endl;
    int cnt[3]{0};
    for (int i = 0; i < 3; i++)
    {
        cin >> cnt[i];
    }

    for (int i = 0; i < 3; i++)
    {
        q.enqueue(cnt[i]);
    }
    for (int l = 0; l < n - 3; l++)
    {
        cout << "enter the next number: " << endl;

        int val = 0;
        cin >> val;
        if (q.fun(cnt, val) == 1)
        {
            hit++;
        }
        else
        {
            fault++;
            q.enqueue(val);
            // q.dequeue();
            // q.print();
        }
    }

    cout << "value of hit is: " << hit << endl;
    cout << "value of fault is: " << fault << endl;
}