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
public:
    Node<T> *head;
    Node<T> *tail;
    int size;

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
            addLast(temp->data);
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
};

int main()
{
    LinkedList<int> list; // Assuming you are working with a LinkedList of integers
    int choice, value, key;

    do
    {
        cout << "Menu:\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Delete at Head\n";
        cout << "4. Delete at Tail\n";
        cout << "5. Insert After\n";
        cout << "6. Delete Before\n";
        cout << "7. Delete After\n";
        cout << "8. Search\n";
        cout << "9. Print List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtHead(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtTail(value);
            break;
        case 3:
            if (list.deleteAtHead())
                cout << "Head deleted.\n";
            else
                cout << "List is empty.\n";
            break;
        case 4:
            if (list.deleteAtTail())
                cout << "Tail deleted.\n";
            else
                cout << "List is empty.\n";
            break;
        case 5:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter key value: ";
            cin >> key;
            if (list.insertAfter(value, key))
                cout << "Value inserted after " << key << ".\n";
            else
                cout << "Key not found.\n";
            break;
        case 6:
            cout << "Enter key value: ";
            cin >> key;
            if (list.deleteBefore(key))
                cout << "Node before " << key << " deleted.\n";
            else
                cout << "Key not found or no node before it.\n";
            break;
        case 7:
            cout << "Enter key value: ";
            cin >> key;
            if (list.deleteAfter(key))
                cout << "Node after " << key << " deleted.\n";
            else
                cout << "Key not found or no node after it.\n";
            break;
        case 8:
        {
            cout << "Enter value to search: ";
            cin >> value;
            Node<int> *result = list.search(value);
            if (result != NULL)
                cout << "Value found in the list.\n";
            else
                cout << "Value not found in the list.\n";
            break;
            }
        case 9:
        {
            // Print the linked list
            Node<int> *temp = list.head;
            while (temp != NULL)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
            break;
            }
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

// int main()
// {
//     LinkedList<int> list;

//     // Insert elements at the head
//     list.insertAtHead(5);
//     list.insertAtHead(10);
//     list.insertAtHead(15);

//     // Insert elements at the tail
//     list.insertAtTail(20);
//     list.insertAtTail(25);

//     // Print initial list
//     cout << "Initial List: ";
//     Node<int> *temp = list.getNode(0);
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;

//     // Test insertAfter function
//     list.insertAfter(12, 10); // Insert 12 after 10
//     cout << "List after inserting 12 after 10: ";
//     temp = list.getNode(0);
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;

//     // Test deleteBefore function
//     list.deleteBefore(20); // Delete element before 20
//     cout << "List after deleting element before 20: ";
//     temp = list.getNode(0);
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;

//     // Test deleteAfter function
//     list.deleteAfter(10); // Delete element after 10
//     cout << "List after deleting element after 10: ";
//     temp = list.getNode(0);
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;

//     // Test search function
//     int searchElement = 15;
//     Node<int> *searchResult = list.search(searchElement);
//     if (searchResult != NULL)
//     {
//         cout << searchElement << " found in the list." << endl;
//     }
//     else
//     {
//         cout << searchElement << " not found in the list." << endl;
//     }

//     // Print final list size
//     cout << "Final List Size: " << list.getSize() << endl;

//     // Cleanup: The destructor will automatically be called when the list goes out of scope
//     return 0;
// }
