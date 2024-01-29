#include <iostream>

using namespace std;

template <class T>
class LinkedList;
template <class T>
class Node
{
    friend class LinkedList<T>;
    T info;
    Node<T> *next;

public:
    Node()
    {
        next = nullptr;
        info = 0;
    }
    Node(int val)
    {
        next = nullptr;
        info = val;
    }
    void setInfo(int val)
    {
        info = val;
    }
    T getInfo()
    {
        return info;
    }
    ~Node()
    {
        delete[] next;
        next = nullptr;
        info = 0;
    }
};

template <class T>
class LinkedList
{
    Node<T> *head;

public:
    LinkedList()
    {
        head = nullptr;
    }
    ~LinkedList()
    {
        if (head != nullptr)
        {
            delete[] head;
            head = nullptr;
        }
    }
    LinkedList(const LinkedList &other)
    {
        if (other.head == nullptr)
        {
            head = nullptr;
        }
        else
        {
            head = other.head;
        }
    }
    bool isEmpty()
    {
        if (head == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void insertAtHead(T value)
    {
        if (isEmpty())
        {
            Node<T> *temp = new Node<T>(value);
            head = temp;
            head->next = head;
        }
        else
        {
            Node<T> *temp = new Node<T>(value);
            temp->next = head;
            Node<T> *temp2 = head;
            do
            {
                temp2 = temp2->next;
            } while (temp2->next != head);
            temp2->next = temp;
            head = temp;
        }
    }
    void insertAtTail(T value)
    {
        if (isEmpty())
        {
            Node<T> *temp = new Node<T>(value);
            head = temp;
            head->next = head;
        }
        else
        {
            Node<T> *temp = head;
            do
            {
                temp = temp->next;
            } while (temp->next != head);
            Node<T> *temp2 = new Node<T>(value);
            temp->next = temp2;
            temp2->next = head;
        }
    }
    bool deleteAtHead()
    {
        if (isEmpty())
        {
            return false;
        }
        else if (head->next == head)
        {
            Node<T> *temp = head;
            head = nullptr;
            return true;
        }
        else
        {
            Node<T> *temp = head;
            Node<T> *temp2 = head;
            do
            {
                temp = temp->next;
            } while (temp->next != head);
            head = head->next;
            temp->next = head;
            return true;
        }
    }
    bool deleteAtTail()
    {
        if (isEmpty())
        {
            return false;
        }
        else if (head->next == head)
        {
            Node<T> *temp = head;
            head = nullptr;
            return true;
        }
        else
        {
            Node<T> *temp = head;
            do
            {
                temp = temp->next;
            } while (temp->next->next != head);
            Node<T> *temp2 = temp->next;
            temp->next = head;
            return true;
        }
    }
    void printList()
    {
        if (isEmpty())
        {
            cout << "Linked List is empty" << endl;
        }
        else
        {
            Node<T> *temp = head;
            cout << "List contains: ";
            do
            {
                cout << temp->info << " ";
                temp = temp->next;
            } while (temp != head);
            cout << endl;
        }
    }
    Node<T> *getNode(int n)
    {
        if (isEmpty())
        {
            return nullptr;
        }
        else
        {
            int count = 0;
            Node<T> *temp = head;
            do
            {
                temp = temp->next;
                count++;
            } while (temp != head);
            if (n > count)
            {
                Node<T> *temp = head;
                do
                {
                    temp = temp->next;
                } while (temp->next != head);
                return temp;
            }
            else
            {
                Node<T> *temp = head;
                for (int i = 0; i < n; i++)
                {
                    temp = temp->next;
                }
                return temp;
            }
        }
    }
    int getLength()
    {
        if (isEmpty())
        {
            return 0;
        }
        else
        {
            Node<T> *temp = head;
            int count = 0;
            do
            {
                temp = temp->next;
                count++;
            } while (temp != head);
            return count;
        }
    }
    bool insertAfter(T value, T key)
    {
        if (isEmpty())
        {
            return false;
        }
        else
        {
            Node<T> *temp = head;
            do
            {
                if (temp->info == key)
                {
                    Node<T> *temp2 = new Node<T>(value);
                    temp2->next = temp->next;
                    temp->next = temp2;
                    return true;
                }
                temp = temp->next;
            } while (temp != head);
            return false;
        }
    }
    bool insertBefore(T value, T key)
    {
        if (isEmpty())
        {
            return false;
        }
        else
        {
            Node<T> *temp = head;
            do
            {
                if (temp->next->info == key)
                {
                    Node<T> *temp2 = new Node<T>(value);
                    temp2->next = temp->next;
                    temp->next = temp2;
                    return true;
                }
                temp = temp->next;
            } while (temp != head);
            return false;
        }
    }
    bool deleteBefore(T key)
    {
        if (isEmpty())
        {
            return false;
        }
        else
        {
            if (head->info == key)
            {
                return false;
            }
            else if (head->next->info == key)
            {
                Node<T> *temp = head;
                do
                {
                    temp = temp->next;
                } while (temp->next != head);
                head = head->next;
                temp->next = head;
                return true;
            }
            else
            {
                Node<T> *temp = head;
                do
                {
                    if (temp->next->next->info == key)
                    {
                        Node<T> *temp2 = temp->next;
                        temp->next = temp->next->next;
                        return true;
                    }
                    temp = temp->next;
                } while (temp != head);
                return false;
            }
        }
    }
    bool deleteAfter(T value)
    {
        if (isEmpty())
        {
            return false;
        }
        else
        {
            Node<T> *temp = head;
            do
            {
                if (temp->info == value)
                {
                    if (temp->next == head)
                    {
                        return false;
                    }
                    else
                    {
                        if (temp->next->next == head)
                        {
                            temp->next = head;
                            return true;
                        }
                        else
                        {
                            temp->next = temp->next->next;
                            return true;
                        }
                    }
                }
                temp = temp->next;
            } while (temp != head);
            return false;
        }
    }
    Node<T> *search(T x)
    {
        if (isEmpty())
        {
            return nullptr;
        }
        else
        {
            Node<T> *temp = head;
            do
            {
                if (temp->info == x)
                {
                    return temp;
                }
                temp = temp->next;
            } while (temp != head);
            return nullptr;
        }
    }
};

