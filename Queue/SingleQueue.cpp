#include <iostream>
using namespace std;

class Queue {
  int* Arr;
  int qfront;
  int rear;
  int size;
public:
    Queue() {
        // Implement the Constructor
        size = 10000;
        Arr = new int[size];
        qfront=0;
        rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront == rear)
          return true;
        else
          return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear == size)
          cout<<"queue is full :"<<endl;
        Arr[rear++] = data;
        
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty())
          return -1;
        return Arr[qfront++];
    }

    int front() {
        // Implement the front() function
        if(isEmpty())
          return -1;
        return Arr[qfront];
    }
};