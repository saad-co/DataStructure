// this program contains the first 3 tasks of in-lab and the pre-lab task(Class of linkedList) is also implemented in it.

#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class LinkedList
{
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    ~LinkedList()
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            Node<T> *next = temp->next;
            delete temp;
            temp = next;
        }
    }
    int getSize()
    {
        return size;
    }
    LinkedList(const LinkedList<T> &obj)
    {
        head = NULL;
        tail = NULL;
        size = 0;
        Node<T> *temp = obj.head;
        while (temp != NULL)
        {
            insertAtTail(temp->data);
            temp = temp->next;
        }
    }
    void insertAtHead(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    void insertAtTail(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        size++;
    }
    bool deleteAtHead()
    {
        if (head == NULL)
        {
            return false;
        }
        else if (head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
            size--;
            return true;
        }
        else
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            size--;
            return true;
        }
    }
    bool deleteAtTail()
    {
        if (head == NULL)
        {
            return false;
        }
        else if (head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
            size--;
            return true;
        }
        else
        {
            Node<T> *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = NULL;
            size--;
            return true;
        }
    }
    Node<T> *getNode(int n)
    {
        if (n <= 0)
        {
            return head;
        }
        else if (n >= size)
        {
            return tail;
        }
        else
        {
            Node<T> *temp = head;
            int count = 0;
            while (temp->next != NULL && count < n)
            {
                temp = temp->next;
                count++;
            }
            return temp;
        }
    }
    bool insertAfter(T val, T key)
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                Node<T> *newNode = new Node<T>(val);
                newNode->next = temp->next;
                temp->next = newNode;
                size++;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    bool deleteBefore(T key)
    {
        if (head == NULL || head->data == key)
        {
            return false;
        }
        else if (head->next->data == key)
        {
            deleteAtHead();
            return true;
        }
        else
        {
            Node<T> *temp = head;
            while (temp->next->next != NULL)
            {
                if (temp->next->next->data == key)
                {
                    Node<T> *temp2 = temp->next;
                    temp->next = temp->next->next;
                    delete temp2;
                    size--;
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }
    }
    bool deleteAfter(T key)
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                if (temp->next == NULL)
                {
                    return false;
                }
                else if (temp->next->next == NULL)
                {
                    deleteAtTail();
                    return true;
                }
                else
                {
                    Node<T> *temp2 = temp->next;
                    temp->next = temp->next->next;
                    delete temp2;
                    size--;
                    return true;
                }
            }
            temp = temp->next;
        }
        return false;
    }
    Node<T> *search(T x)
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            if (temp->data == x)
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
    bool removeKthNode(int k, int &val)
    {
        if (k > size)
        {
            return false;
        }
        else if (k == 1)
        {
            val = head->data;
            deleteAtHead();
        }
        else if (k == size)
        {
            val = tail->data;
            deleteAtTail();
        }
        else
        {
            Node<T> *temp = head;
            for (int i = 0; i < k - 2; i++)
            {
                temp = temp->next;
            }
            Node<T> *temp2 = temp->next;
            temp->next = temp->next->next;
            val = temp2->data;
            delete temp2;
        }
    }
    void print()
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void combine(LinkedList<T> list1, LinkedList<T> list2)
    {
        if (list1.head == nullptr && list2.head == nullptr)
        {
            return;
        }
        else if (list1.head == nullptr)
        {
            head = list2.head;
            tail = list2.tail;
            list2.head = nullptr;
        }
        else if (list2.head == nullptr)
        {
            head = list1.head;
            tail = list1.tail;
            list1.head = nullptr;
        }
        else
        {
            while (list1.head != nullptr)
            {
                this->insertAtTail(list1.head->data);
                list1.head = list1.head->next;
            }
            delete list1.head;
            while (list2.head != nullptr)
            {
                this->insertAtTail(list2.head->data);
                list2.head = list2.head->next;
            }
            delete list2.head;
        }
    }
    void shuffleMerge(LinkedList<T> list1, LinkedList<T> list2)
    {
        if (list1.head == nullptr && list2.head == nullptr)
        {
            return;
        }
        else if (list1.head == nullptr)
        {
            head = list2.head;
            tail = list2.tail;
            list2.head = nullptr;
        }
        else if (list2.head == nullptr)
        {
            head = list1.head;
            tail = list1.tail;
            list1.head = nullptr;
        }
        else
        {
            while (list1.head != nullptr && list2.head != nullptr)
            {
                this->insertAtTail(list1.head->data);
                this->insertAtTail(list2.head->data);
                list1.head = list1.head->next;
                list2.head = list2.head->next;
            }
        }
    }
};

int main()
{
    LinkedList<int> l;
    l.insertAtTail(10);
    l.insertAtTail(20);
    l.insertAtTail(30);
    cout << "______________________Task01__________________________\n\n";
    cout << "This is our original list:" << endl;
    l.print();
    int val;
    l.removeKthNode(2, val);
    cout << "This is our list after removing the 2nd node:" << endl;
    l.print();
    cout << "Vale of second Node" << val << endl;

    cout << "______________________Task02__________________________\n\n";
    LinkedList<int> l1;
    l1.insertAtTail(100);
    l1.insertAtTail(200);
    l1.insertAtTail(308);

    LinkedList<int> l2;
    l2.combine(l, l1);
    cout << "Result after combining l and l1: \n";
    l2.print();

    cout << "______________________Task03__________________________\n\n";
    LinkedList<int> l3;
    l3.shuffleMerge(l, l1);
    cout << "Result after shuffling l and l1: \n";
    l3.print();

    return 0;
}