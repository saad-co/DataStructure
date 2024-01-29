#include <iostream>
using namespace std;

class CDLLD;
class DNode
{
public:
    friend class CDLLD;
    DNode()
    {
    }
    DNode(int val)
    {
        this->data = val;
        this->next = nullptr;
        this->prev = nullptr;
    }

private:
    int data;
    DNode *next;
    DNode *prev;
};

class CDLLD
{
private:
    DNode head; // Dummy header node
public:
    CDLLD()
    {
        head.next = nullptr;
        head.prev = nullptr;
        head.data = -1;
    }
    ~CDLLD()
    {
        DNode *temp = head.next;
        while (temp != nullptr && temp != &head)
        {
            DNode *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    bool insertAtStart(int val)
    {
        DNode *temp = new DNode(val);
        if (head.next == nullptr)
        {
            head.next = temp;
            temp->next = &head;
            head.prev = temp;
            temp->prev = &head;
            return true;
        }
        else
        {
            temp->next = head.next;
            temp->prev = &head;
            head.next->prev = temp;
            head.next = temp;
            return true;
        }
    }
    bool insertAtEnd(int val)
    {
        if (head.next == nullptr)
        {
            insertAtStart(val);
            return true;
        }
        else
        {
            DNode *temp = head.prev;
            DNode *newNode = new DNode(val);
            temp->next = newNode;
            newNode->next = &head;
            newNode->prev = temp;
            head.prev = newNode;
            return true;
        }
    }
    void display()
    {
        DNode *temp = head.next;
        do
        {
            cout << temp->data << " -> ";
            // cout << "\n--------------------------------\n\n";
            // cout << "next: " << temp->next->data << endl;
            // cout << "prev: " << temp->prev->data << endl;
            // cout << "--------------------------------\n\n";

            temp = temp->next;
        } while (temp != &head);
        cout << endl;
    }
    int countNodes()
    {
        DNode *temp = head.next;
        int n = 0;
        do
        {
            n++;
            temp = temp->next;
        } while (temp != &head);
        return n;
    }
    bool isSorted() const
    {
        DNode *temp = head.next;
        while (temp->next != &head)
        {
            if (temp->data > temp->next->data) // 10 20 30 40 50
            {
                return false;
            }
            temp = temp->next;
        }
        return true;
    }
    bool removeLastNode(int &val)
    {
        if (head.next == nullptr)
        {
            return false;
        }
        else
        {
            DNode *temp = head.prev;
            val = temp->data;
            temp->prev->next = &head;
            temp->prev = nullptr;
            temp->next = nullptr;
            delete temp;
        }
    }
    bool removeSecondLastNode(int &val)
    {
        if (head.next == nullptr || head.next->next == &head)
        {
            // List contains fewer than two nodes
            return false;
        }
        else
        {
            DNode *temp = head.prev->prev;
            val = temp->data;
            // cout << val << endl;
            temp->prev->next = temp->next;
            temp->next->prev = temp;
            temp->prev = nullptr;
            temp->next = nullptr;
            // delete temp;
            return true;
        }
    }
    bool removeKthNode(int k, int &val)
    {
        if (head.next == nullptr || k <= 0)
        {
            // List is empty or k is invalid
            return false;
        }
        else
        {
            DNode *temp = head.next;
            for (int i = 1; i < k && temp->next != &head; ++i)
            {
                temp = temp->next;
            }

            if (temp->next == &head)
            {
                // List contains fewer than k elements
                return false;
            }
            else
            {
                val = temp->data;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp->prev = nullptr;
                temp->next = nullptr;
                // delete temp;
                return true;
            }
        }
    }
};
int main()
{
    CDLLD list1, list2, list3;

    // Insert elements into list1
    list1.insertAtEnd(10);
    list1.insertAtEnd(20);
    list1.insertAtEnd(30);

    // Insert elements into list2
    list1.insertAtEnd(40);
    list1.insertAtEnd(50);
    list1.insertAtEnd(60);

    // Display original lists
    cout << "Original List 1: ";
    list1.display();

    // Test isSorted function
    if (list1.isSorted())
        cout << "List 1 is sorted.\n";
    else
        cout << "List 1 is not sorted.\n";

    // Test removeLastNode function
    int removedValue = 0;
    if (list1.removeLastNode(removedValue))
    {
        cout << "After removing last node, value removed: " << removedValue << endl;
        cout << "Updated List 3: ";
        list1.display();
    }
    else
    {
        cout << "List 3 is empty, cannot remove the last node.\n";
    }

    // Test removeSecondLastNode function
    int x = 0;
    if (list1.removeSecondLastNode(x))
    {
        cout << "After removing second last node, value removed: " << removedValue << endl;
        cout << "Updated List 3: ";
        list1.display();
    }
    else
    {
        cout << "List 3 has fewer than two nodes, cannot remove the second last node.\n";
    }

    // Test removeKthNode function
    int k = 2;
    if (list1.removeKthNode(k, removedValue))
    {
        cout << "After removing kth node (" << k << "), value removed: " << removedValue << endl;
        cout << "Updated List 3: ";
        list1.display();
    }
    else
    {
        cout << "List 3 has fewer than " << k << " elements, cannot remove the kth node.\n";
    }

    return 0;
}
