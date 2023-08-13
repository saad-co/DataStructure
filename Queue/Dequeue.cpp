#include <iostream>
using namespace std;

// I have solved the questions of queue on GFG  

class Deque {

private:
  int *Arr;
  int size;
  int qfront;
  int rear;

public:
  Deque(int n) {
    size = n;
    Arr = new int[n];
    qfront = rear = -1;
  }

  bool pushFront(int x) {
    if (isFull()) {
      return false; // queue is full
    }
    else if(isEmpty())
    {
        qfront = rear = 0;
    } 
    else if ((qfront == 0) && (rear != size - 1)) {
      qfront = size - 1; // qfront is on the first element
    } else {
      qfront--; // normal flow
    }
    Arr[qfront] = x;
    return true;
  }

  bool pushRear(int x) {
    if (isFull()) {
      return false; // queue is full
    } else if (qfront == -1) {
      rear = qfront = 0; // first element to push
    } else if ((rear == size - 1) && (qfront != 0)) {
      rear = 0; // to mantain the cyclic nature
    } else {
      rear++; // normal flow
    }
    Arr[rear] = x;
    return true;
  }

  int popFront() {
    if (qfront == -1) {
      return -1; // queue is empty
    }
    int ans = Arr[qfront];
    Arr[qfront] = -1;
    if (qfront == rear) {
      qfront = rear = -1; // only one element in the queue
    } else if (qfront == size - 1) {
      qfront = 0; // to mantain the cyclic nature
    } else {
      qfront++;
    }
    return ans;
  }

  int popRear() {
    if (qfront == -1) {
      return -1;
    }
    int ans = Arr[rear];
    Arr[rear] = -1;
    if(qfront == rear)
    {
        qfront = rear=-1;
    }
    else if(rear == 0)
    {
        rear = size-1;
    }
    else
    {
        rear--;
    }
    return ans;
  }

  // Returns the first element of the deque. If the deque is empty, it returns
  // -1.
  int getFront() {
    if(isEmpty())
    {
        return -1;
    }
    else
    {

        return Arr[qfront];
    }
  }

  int getRear() {
      if(isEmpty())
      {
          return -1;
      }
      else
      {
          return Arr[rear];
      }

  }

  // Returns true if the deque is empty. Otherwise returns false.
  bool isEmpty() {
    if(qfront == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
  }

  // Returns true if the deque is full. Otherwise returns false.
  bool isFull() {
    // Write your code here.
    if ((qfront == 0 && rear == size - 1) ||
        (qfront!=0 && rear == (qfront - 1) % (size - 1))) {
      return true; // queue is full
    }
    else{
        return false;
    }
  }
};