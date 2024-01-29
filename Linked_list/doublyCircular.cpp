#include <iostream>
using namespace std;

template <typename T>
class Dlist;

template <typename T>
class DNode
{
public:
    friend Dlist<T>;
    T info;
    DNode<T> *next;
    DNode<T> *prev;

    DNode(T val)
    {
        info = val;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class Dlist
{
    DNode<T> *head;
    DNode<T> *tail;

public:
    Dlist()
    {
        head = nullptr;
        tail = nullptr;
    }
    Dlist(const Dlist &other)
    {
        head = nullptr;
        tail = nullptr;

        // Copy nodes from the other list
        DNode<T> *otherTemp = other.head;
        while (otherTemp != nullptr)
        {
            insertAtTail(otherTemp->info);
            otherTemp = otherTemp->next;
        }
    }

    ~Dlist()
    {
        DNode<T> *current = head;
        while (current != nullptr)
        {
            DNode<T> *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void insertAtHead(T val)
    {
        if (head == nullptr)
        {
            DNode<T> *temp = new DNode<T>(val);
            head = temp;
            tail = head;
            tail->next = head;
            head->prev = tail;
            return;
        }
        DNode<T> *temp = new DNode<T>(val);
        temp->next = head;
        head->prev = temp;
        head = temp;
        head->prev = tail;
        tail->next = head;
    }
    void insertAtTail(T val)
    {
        if (tail == nullptr)
        {
            insertAtHead(val);
            return;
        }
        DNode<T> *temp = new DNode<T>(val);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
        tail->next = head;
        head->prev = tail;
    }
    bool deleteAtHead()
    {
        if (head == nullptr)
        {
            return false;
        }
        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
            return true;
        }
        DNode<T> *temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        temp->next = nullptr;
        delete temp;
        return true;
    }
    bool deleteAtTail()
    {
        if (tail == nullptr)
        {
            return false;
        }
        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
            return true;
        }
        DNode<T> *temp = tail;
        tail = tail->prev;
        tail->next = head;
        temp->prev = nullptr;
        temp->next = nullptr;
        delete temp;
        return true;
    }
    void printList()
    {
        if (head == nullptr)
        {
            cout << "List is empty :) " << endl;
        }
        DNode<T> *temp = head;
        while (temp != nullptr)
        {
            cout << temp->info << " ";
            temp = temp->next;
        }
        cout << endl;
        cout << "head pointing at: " << head->info << endl;
        cout << "tail pointing at: " << tail->info << endl;
    }
    void printCircularList()
    {
        if (head == nullptr)
        {
            cout << "List is empty :)" << endl;
            return;
        }

        DNode<T> *temp = head;
        do
        {
            cout << temp->info << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
        cout << "head pointing at: " << head->info << endl;
        cout << "tail pointing at: " << tail->info << endl;
        cout << "tail next pointing at: " << tail->next->info << endl;
        cout << "head prev pointing at: " << head->prev->info << endl;
    }
    int getLength()
    {
        int count = 0;
        DNode<T> *temp = head;
        while (temp != nullptr)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
    DNode<T> *getNode(const int n)
    {
        if (head == nullptr)
        {
            cout << "List is empty :) " << endl;
        }
        if (this->getLength() <= n)
        {
            return tail;
        }
        else
        {
            DNode<T> *temp = head;
            for (int i = 1; i < n; i++)
            {
                temp = temp->next;
            }
            return temp;
        }
    }
};

int main()
{
    Dlist<int> myDList;

    // Insert elements
    myDList.insertAtTail(1);
    myDList.insertAtTail(2);
    myDList.insertAtTail(3);

    // Print the doubly circular linked list
    cout << "Doubly Circular Linked List: ";
    myDList.printCircularList();
    cout << "im back:" << endl;

    return 0;
}