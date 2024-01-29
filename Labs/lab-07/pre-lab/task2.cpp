#include <iostream>
using namespace std;

template <typename T>
class node
{
public:
	T val;
	int p = 0;


	void set(T d, int pr)
	{
		val = d;
		p = pr;
	}
};

template <typename T>
class priorityQ
{
private:
	int numberOfElements;
	int capacity;
	node<T>* queueData;

	void resize(int newSize)
	{
		capacity = newSize;
		node<T>* temp = new node<T>[capacity];
		for (int i = 0; i < numberOfElements; i++)
		{
			temp[i] = queueData[i];
		}
		delete[] queueData;
		queueData = temp;
		temp = nullptr;
	}

public:
	priorityQ() // Constructor to initialize the priority queue
	{
		numberOfElements = 0;
		capacity = 1;
		queueData = new node<T>[capacity];
	}
	~priorityQ() // Destructor to free memory if necessary
	{
		if (this->queueData)
		{
			delete[] queueData;
			queueData = nullptr;
		}
	}
	void enqueue(const T& data, int priority) // Function to enqueue an element with a given priority
	{
		if (isFull())
		{
			resize(capacity * 2);
		}

		node<T> temp;
		temp.set(data, priority);
		queueData[numberOfElements++] = temp;
	}
	T dequeue()
	{
		if (isEmpty())
		{
			throw "Queue is empty: ";
		}
		else
		{
			int minP = this->queueData[0].p;
			int cnt = 0;
			T temp;
			for (int i = 0; i < numberOfElements; ++i)
			{
				if (this->queueData[i].p < minP)
				{
					minP = this->queueData[i].p;
					cnt = i;
				}
			}

			temp = queueData[cnt].val;
			// Replace the element at index cnt with the last element
			this->queueData[cnt] = this->queueData[numberOfElements - 1];
			numberOfElements--;
			return temp;
		}
	}
	bool isEmpty() const // Function to check if the priority queue is empty
	{
		return numberOfElements == 0;
	}
	bool isFull() const // Function to check if the priority queue is full
	{
		return numberOfElements == capacity;
	}
	int size() const // Function to get the size of the priority queue
	{
		return capacity;
	}
};

int main()
{
	priorityQ<int> q;
	q.enqueue(50, 5);
	q.enqueue(10, 3);
	q.enqueue(30, 1);
	q.enqueue(720, 4);
	q.enqueue(100, 1);
	q.enqueue(-50, 10);

	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;

	return 0;
}