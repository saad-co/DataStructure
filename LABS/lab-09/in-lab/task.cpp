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
    bool insertAfter(T value, T key)
    {
        DNode<T> *temp = head;
        while (temp->next != nullptr)
        {
            if (temp->info == key)
            {
                DNode<T> *temp2 = new DNode<T>(value);
                temp2->next = temp->next;
                temp2->prev = temp;
                temp->next = temp2;
                temp2->next->prev = temp;
                return true;
            }
            temp = temp->next;
        }
        if (tail->info == key)
        {
            insertAtTail(value);
            return true;
        }
        else
        {
            cout << "Key value not prensent in the linked list " << endl;
            return false;
        }
    }
    bool insertBefore(T value, T key)
    {
        DNode<T> *temp = head;
        if (head->info == key)
        {
            insertAtHead(value);
            return true;
        }
        while (temp != nullptr)
        {
            if (temp->info == key)
            {
                DNode<T> *temp2 = new DNode<T>(value);
                temp2->prev = temp->prev;
                temp2->next = temp;
                temp->prev->next = temp2;
                temp->prev = temp2;
                return true;
            }
            temp = temp->next;
        }
        cout << "Key value not found in the linked list: " << endl;
        return false;
    }
    bool deleteBefore(T key)
    {
        if (head == nullptr)
        {
            cout << "List is empty :) " << endl;
        }
        if (head->next->info == key)
        {
            DNode<T> *temp = head;
            head = head->next;
            head->prev = nullptr;
            temp->next = nullptr;
            delete temp;
            return true;
        }
        else if (tail->info == key)
        {
            DNode<T> *temp = tail->prev;
            tail->prev = temp->prev;
            temp->prev->next = tail;
            temp->next = nullptr;
            delete temp;
            return true;
        }
        DNode<T> *temp = head->next;
        while (temp->next != nullptr)
        {
            if (temp->info == key)
            {
                DNode<T> *temp2 = temp->prev;
                temp2->prev->next = temp;
                temp->prev = temp2->prev;
                temp2->next = nullptr;
                temp2->prev = nullptr;
                delete temp2;
                return true;
            }
            temp = temp->next;
        }
        cout << "key value not found in the linked list: " << endl;
        return false;
    }
    bool deleteAfter(T value)
    {
        if (head == nullptr)
        {
            cout << "List is empty: " << endl;
            return false;
        }
        if (head->info == value) // 10 20 30 40
        {
            DNode<T> *temp = head->next;
            head->next = temp->next;
            temp->next->prev = head;
            temp->next = nullptr;
            temp->prev = nullptr;
            delete temp;
            return true;
        }
        if (tail->prev->info == value)
        {
            deleteAtTail();
        }
        DNode<T> *temp = head;
        while (temp->next != nullptr)
        {
            if (temp->info == value)
            {
                DNode<T> *temp2 = temp->next;
                temp->next = temp2->next;
                temp2->next->prev = temp;
                temp2->next = nullptr;
                temp2->prev = nullptr;
                delete temp2;
                return true;
            }
            temp = temp->next;
        }
        cout << "key value not found in the linked list: " << endl;
        return false;
    }
    DNode<T> *search(T x)
    {
        if (head == nullptr)
        {
            cout << "List is empty :) " << endl;
        }
        else if (head->info == x)
        {
            return head;
        }
        else if (tail->info == x)
        {
            return tail;
        }
        else
        {
            DNode<T> *temp = head->next;
            while (temp->next != nullptr)
            {
                if (temp->info == x)
                {
                    return temp;
                }
            }
        }
        cout << "value not found in the list :)" << endl;
        return nullptr;
    }
    void sort()
    {
        if (head == nullptr || head->next == nullptr)
        {
            cout << "List is already sorted or empty." << endl;
            return;
        }

        DNode<T> *sorted = nullptr;
        DNode<T> *current_node = head;

        while (current_node != nullptr)
        {
            DNode<T> *next_node = current_node->next;

            if (sorted == nullptr || sorted->info >= current_node->info)
            {
                // Move current_node to the beginning of the sorted list
                current_node->next = sorted;
                current_node->prev = nullptr;

                if (sorted != nullptr)
                {
                    sorted->prev = current_node;
                }

                sorted = current_node;
            }
            else
            {
                // Search for the correct position in the sorted list
                DNode<T> *temp = sorted;
                while (temp->next != nullptr && temp->next->info < current_node->info)
                {
                    temp = temp->next;
                }

                // Insert current_node after temp
                current_node->next = temp->next;
                current_node->prev = temp;

                if (temp->next != nullptr)
                {
                    temp->next->prev = current_node;
                }

                temp->next = current_node;
            }

            current_node = next_node;
        }

        // Update the head and tail pointers
        head = sorted;
        while (sorted->next != nullptr)
        {
            sorted = sorted->next;
        }
        tail = sorted;
    }
    void reverse()
    {
        DNode<T> *ptr1 = head;
        DNode<T> *ptr2 = ptr1->next;
        tail = head;
        ptr1->next = nullptr;
        ptr1->prev = ptr2;
        while (ptr2 != nullptr)
        {
            ptr2->prev = ptr2->next;
            ptr2->next = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr2->prev;
        }
        head = ptr1;
    }
};

int main()
{
    Dlist<int> myList;

    int choice;
    do
    {
        cout << "\n----- Doubly Linked List Menu -----" << endl;
        cout << "1. Insert at Head" << endl;
        cout << "2. Insert at Tail" << endl;
        cout << "3. Delete at Head" << endl;
        cout << "4. Delete at Tail" << endl;
        cout << "5. Insert Before Key" << endl;
        cout << "6. Insert After Key" << endl;
        cout << "7. Delete Before Key" << endl;
        cout << "8. Delete After Key" << endl;
        cout << "9. Sort" << endl;
        cout << "10. Print List" << endl;
        cout << "11. reverse List" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int val;
            cout << "Enter the value to insert at the head: ";
            cin >> val;
            myList.insertAtHead(val);
            break;

        case 2:
            cout << "Enter the value to insert at the tail: ";
            cin >> val;
            myList.insertAtTail(val);
            break;

        case 3:
            myList.deleteAtHead();
            break;

        case 4:
            myList.deleteAtTail();
            break;

        case 5:
            int value, key;
            cout << "Enter the value to insert: ";
            cin >> value;
            cout << "Enter the key before which to insert: ";
            cin >> key;
            myList.insertBefore(value, key);
            break;

        case 6:
            cout << "Enter the value to insert: ";
            cin >> value;
            cout << "Enter the key after which to insert: ";
            cin >> key;
            myList.insertAfter(value, key);
            break;

        case 7:
            cout << "Enter the key before which to delete: ";
            cin >> key;
            myList.deleteBefore(key);
            break;

        case 8:
            cout << "Enter the key after which to delete: ";
            cin >> key;
            myList.deleteAfter(key);
            break;

        case 9:
            myList.sort();
            cout << "List sorted successfully." << endl;
            break;

        case 10:
            cout << "Current List:" << endl;
            myList.printList();
            break;
        case 11:
            myList.reverse();
            cout << "list reversed succesfully:" << endl;
            myList.printList();
            break;
        case 0:
            cout << "Exiting the program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}