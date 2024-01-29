#include <iostream>

using namespace std;

template <class T>
class Stack;
template <class T>
class StackNode
{
    T info;
    StackNode<T> *link;
    friend class Stack<T>;

public:
    StackNode()
    {
        link = nullptr;
    }
    StackNode(T Element)
    {
        info = Element;
        link = nullptr;
    }
    ~StackNode()
    {
        delete link;
        link = nullptr;
    }
};
template <class T>
class Stack
{
private:
    StackNode<T> *Top;
    int capacity;

public:
    Stack()
    {
        Top = nullptr;
        capacity = 0;
    }
    ~Stack()
    {
        delete Top;
        Top = nullptr;
        capacity = 0;
    }
    Stack(const Stack<T> &orig)
    {
        this->Top = nullptr;
        this->capacity = 0;
        StackNode<T> *temp = orig.Top;
        while (temp != nullptr)
        {
            this->push(temp->info);
            temp = temp->link;
        }
    }
    int getTop()
    {
        return Top->info;
    }
    int pop()
    {
        if (Top == nullptr)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else if (capacity == 1)
        {
            int info = Top->info;
            delete Top;
            Top = nullptr;
            capacity--;
            return info;
        }
        else
        {
            StackNode<T> *temp = Top;
            while (temp->link->link != nullptr)
            {
                temp = temp->link;
            }
            int info = temp->link->info;
            delete temp->link;
            temp->link = nullptr;
            capacity--;
            return info;
        }
    }
    void push(int Element)
    {
        if (Top == nullptr)
        {
            Top = new StackNode<T>(Element);
            capacity++;
        }
        else
        {
            StackNode<T> *temp = Top;
            while (temp->link != nullptr)
            {
                temp = temp->link;
            }
            temp->link = new StackNode<T>(Element);
            capacity++;
        }
    }
    int currSize()
    {
        return capacity;
    }
    bool isEmpty()
    {
        if (capacity == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        return false;
    }
    T Peek(int nodeNumber)
    {
        StackNode<T> *temp = Top;
        for (int i = 0; i < nodeNumber; i++)
        {
            temp = temp->link;
        }
        return temp->info;
    }
};

int main()
{
    Stack<int> stack;
    int choice = 0, element, nodeNumber;
    while (choice != 5)
    {
        cout << "\n\n1. Push Element in stack" << endl;
        cout << "2. Pop Element from stack" << endl;
        cout << "3. Get Current capacity of stack" << endl;
        cout << "4. Peek at nodeNumber" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter element to push: ";
            cin >> element;
            stack.push(element);
            cout << element << " pushed to stack" << endl;
        }
        else if (choice == 2)
        {
            element = stack.pop();
            if (element != -1)
            {
                cout << element << " popped from stack" << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "Current capacity of stack: " << stack.currSize() << endl;
        }
        else if (choice == 4)
        {
            cout << "Enter node number to peek: ";
            cin >> nodeNumber;
            if (nodeNumber >= 0 && nodeNumber < stack.currSize())
            {
                cout << "Element at node " << nodeNumber << ": " << stack.Peek(nodeNumber) << endl;
            }
            else
            {
                cout << "Invalid node number" << endl;
            }
        }
        else if (choice == 5)
        {
            cout << "You chose to exit" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice Try again" << endl;
        }
    }
    return 0;
}