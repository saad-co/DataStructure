#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack {
private:
    T *ptr;
    int size;
    int maxSize;

    void resize() {
        maxSize = maxSize ? maxSize * 2 : 1;
        T *temp = new T[maxSize];
        for (int i = 0; i < size; i++) {
            temp[i] = ptr[i];
        }
        delete[] ptr;
        ptr = temp;
        temp = nullptr;
    }

    void shrink() {
        maxSize /= 2;
        T *temp = new T[maxSize];
        for (int i = 0; i < size; i++) {
            temp[i] = ptr[i];
        }
        delete[] ptr;
        ptr = temp;
        temp = nullptr;
    }

public:
    Stack() {
        size = 0;
        maxSize = 0;
        ptr = nullptr;
    }

    int getCapacity() {
        return maxSize;
    }

    int getNumberOfElements() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == maxSize;
    }

    void push(T var) {
        if (isFull()) {
            resize();
        }
        ptr[size++] = var;
    }

    void pop() {
        if (!isEmpty()) {
            size--;
            if (size == maxSize / 4) {
                shrink();
            }
        }
    }

    T top() {
        if (isEmpty()) {
            throw runtime_error("There is no element in the Stack to return");
        }
        return ptr[size - 1];
    }

    ~Stack() {
        if (ptr != nullptr) {
            delete[] ptr;
            ptr = nullptr;
        }
        size = 0;
        maxSize = 0;
    }
};
