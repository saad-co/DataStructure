#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int dat)
    {
        this->data = dat;
        this->next = nullptr;
    }
    ~node()
    {
        int dat = this->data;
        if (this->next != nullptr)
        {
            delete next;
            this->next = nullptr;
        }
        cout << "memory free for: " << dat << endl;
    }
};

void insert_at_head(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void insert_at_tail(node *&tail, int val)
{
    node *temp = new node(val);
    tail->next = temp;
    tail = temp;
}

void inserting_in_middle(node *&head, node *&tail, int pos, int data)
{
    if (pos == 1)
    {
        insert_at_head(head, data);
        return;
    }
    node *nodetoinsert = new node(data);
    node *t = head;
    for (int i = 0; i < pos - 1; i++)
    {
        t = t->next;
    }
    // cout << "our pointer is at: " << t->data << endl;

    if (t->next == nullptr)
    {
        // inserting at last position
        insert_at_tail(tail, data);
        return;
    }
    nodetoinsert->next = t->next;
    t->next = nodetoinsert;
}
void print(node *&n)
{
    node *temp = n;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deletePos(node *&head, node *&tail, int pos)
{

    if (pos == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        return;
    }
    else
    {
        node *curr = head;
        node *prev = nullptr;
        for (size_t i = 0; i < pos - 1; i++)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr->next == nullptr)
        {
            // cout << "inside\n";
            prev->next = nullptr;
            tail = prev; // Update the tail pointer
            delete curr;
        }
        else
        {
            // cout << "inside1\n";
            prev->next = curr->next;
            curr->next = nullptr;
            delete curr;
        }
    }
}

int main()
{
    node *head = new node(20);
    node *tail = head;
    insert_at_head(head, 30);
    insert_at_head(head, 40);
    insert_at_head(head, 70);
    print(head);

    cout << "inserting at tail" << endl;
    insert_at_tail(tail, 140);
    insert_at_tail(tail, 150);
    insert_at_tail(tail, 190);
    print(head);

    cout << "inserting at certain position: " << head->data << endl;
    inserting_in_middle(head, tail, 2, -1);
    print(head);
    cout << "checking the postion of head:" << head->data << endl
         << endl;
    cout << "checking the postion of tail:" << tail->data << endl;

    deletePos(head, tail, 8);
    print(head);
    cout << "checking the postion of head:" << head->data << endl
         << endl;
    cout << "checking the postion of tail:" << tail->data << endl;

    return 0;
}