#include <iostream>
using namespace std;

template <typename T>
class Dlist;

template <typename T>
class DNode
{
    friend Dlist<T>;
    T info;
    DNode<T> *next;
    DNode<T> *prev;

public:
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
        head = other.head;
        tail = other.tail;
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
            return;
        }
        DNode<T> *temp = new DNode<T>(val);
        temp->next = head;
        head->prev = temp;
        head = temp;
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
        head->prev = nullptr;
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
        tail->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return true;
    }
    void printList()
    {
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
};

int main()
{
    Dlist<int> l;
    l.insertAtHead(20);
    l.insertAtHead(10);
    l.insertAtTail(30);
    l.insertAtTail(40);
    l.printList();
    l.deleteAtHead();
    l.printList();
    l.deleteAtTail();
    l.printList();
    return 0;
}