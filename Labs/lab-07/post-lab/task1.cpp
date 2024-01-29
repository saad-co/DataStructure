#include <iostream>
using namespace std;

template <typename T>
class LRU
{
private:
    int frontIndex;       // Index of the front element
    int queueCapacity;    // Maximum capacity of the queue
    int numberOfElements; // Number of elements in the queue
    T *queueData;         // Array to store queue elements
public:
    LRU(int n)
    {
        frontIndex = numberOfElements = 0;
        queueCapacity = n;
        queueData = new T[queueCapacity]{-1};
    }

    ~LRU()
    {
        if (this->queueData)
        {
            delete[] this->queueData;
            queueData = nullptr;
        }
    }

    void enqueue(const T element)
    {
        if (numberOfElements != queueCapacity)
        {
            for (int i = 0; i < queueCapacity; i++)
            {
                if (queueData[i] == element)
                {
                    int temp = queueData[i];
                    for (int l = i; l > 0; l--)
                    {
                        queueData[l] = queueData[l - 1];
                    }
                    queueData[0] = temp;
                    numberOfElements++;
                    return;
                }
            }
            queueData[frontIndex++] = element;
            numberOfElements++;
            return;
        }
        for (int i = 0; i < queueCapacity; i++)
        {
            if (queueData[i] == element)
            {
                frontIndex = 0;
                int temp = queueData[i];
                for (int l = i; l > 0; l--)
                {
                    queueData[l] = queueData[l - 1];
                }
                queueData[frontIndex] = temp;
                return;
            }
        }
        for (int i = queueCapacity - 1; i > 0; i--)
        {
            queueData[i] = queueData[i - 1];
        }
        queueData[0] = element;
    }
    void print()
    {
        for (int i = 0; i < queueCapacity; i++)
        {
            cout << queueData[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    cout << "Enter the size of the queue: " << endl;
    int n = 0;
    cin >> n;
    cout << "Enter the total number of pages: " << endl;
    int nmbr = 0;
    cin >> nmbr;
    LRU<int> q(n);
    while (nmbr > 0)
    {
        cout << "Enter the number of Page you want to read: " << endl;
        int id = 0;
        cin >> id;
        q.enqueue(id);
        cout << "state of LRU: " << endl;
        q.print();
        nmbr--;
    }
    return 0;
}