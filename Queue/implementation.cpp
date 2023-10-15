#include <iostream>
using namespace std;

template <typename T>
class Queue
{
    T *arr;
    int rear;
    int front;
    int size;

public:
    Queue()
    {
        size = 2;
        arr = new T[size];
        rear = 0;
        front = 0;
    }
    bool isEmpty()
    {
        return (front == rear);
    }
    bool isfull()
    {
        return (rear == size);
    }

    void enque(int data)
    {
        if (isfull())
        {
            cout << "queue is full" << endl;
        }
        else
        {
            arr[rear++] = data;
            // size++;
        }
    }
    T deque()
    {
        if (isEmpty())
        {
            cout << "Queue is empty: " << endl;
        }
        else
        {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            // size--;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int qfront()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
};

template <typename T>
class CircularQueue
{
private:
    T *arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue()
    {
        size = 20;
        arr = new T[size]{-1};
        front = -1;
        rear = -1;
    }
    void enque(int data)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear++] = data;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear++] = data;
        }
        else
        {
            arr[rear++] = data;
        }
    }
    int deque()
    {
        if (front == -1)
        {
            cout << "Queue is empty: " << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear) // single element is present
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return ans;
    }
};

template <typename T>
class Deq
{
private:
    T *arr;
    int front;
    int rear;
    int size;

public:
    Deq(int n)
    {
        size = n;
        arr = new T[size];
        front = rear = -1;
    }
    void push_back(int val)
    {
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
        {
            cout << "queue is full" << endl;
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear++] = val;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear++] = val;
        }
        else
        {
            arr[rear++] = val;
        }
    }
    void push_front(int val)
    {
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
        {
            cout << "queue is full: " << endl;
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
            arr[front] = val;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
            arr[front] = val;
        }
        else
        {
            arr[front--] = val;
        }
    }

    int pop_Rear()
    {
        if (front == -1)
        {
            cout << "queue is empty: " << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            front = rear = 0;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
        return ans;
    }
    int pop_Front()
    {
        if (front == -1)
        {
            cout << "Queue is empty: " << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear) // single element is present
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return ans;
    }
    ~Deq()
    {
        delete[] arr;
    }
};

int main()
{
    Deq<int> deque(5); // Creating a deque of size 5

    deque.push_back(1);
    deque.push_front(2);
    deque.push_back(3);
    deque.push_front(4);

    // cout << "Popping from rear: " << deque.pop_Rear() << endl; // Expected: 3
    // cout << "Popping from front: " << deque.pop_Front() << endl;    // Expected: 4

    deque.push_back(5);
    deque.push_front(6);

    cout << "Deque elements: ";
    while (true)
    {
        int element = deque.pop_Front();
        if (element == -1) // Assuming -1 indicates an empty deque
            break;
        cout << element << " "; // Expected: 6 2 1 5
    }
    cout << endl;

    return 0;
}

// int main()
// {
//     CircularQueue<int> q;
//     q.enque(10);
//     q.enque(120);
//     q.enque(30);
//     q.enque(410);
//     cout << q.deque() << endl;
//     q.enque(410);
//     cout << q.deque() << endl;
//     cout << q.deque() << endl;
//     cout << q.deque() << endl;
//     cout << q.deque() << endl;

//     // cout<<q.qfront()<<endl;
//     // q.deque();
//     // cout<<q.qfront()<<endl;
//     // q.deque();
//     // cout<<q.qfront()<<endl;
//     // q.deque();
//     // cout<<q.qfront()<<endl;
//     // q.deque();
//     // q.deque();
// }