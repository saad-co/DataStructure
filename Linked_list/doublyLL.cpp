#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
    ~Node()
    {
        int val = this->data;
        if (this->next != nullptr)
        {
            delete next;
            next = nullptr;
            // prev = nullptr;
        }
        cout << "Memory is free for : " << val << endl;
    }
};

void deleteNode(Node *&head, Node *&t, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        temp->next->prev = nullptr;
        head = temp->next;
        temp->next = nullptr;
        delete temp;
        return;
    }

    Node *curr = head;
    Node *prev = nullptr;
    int cnt = 1;
    while (cnt < pos)
    {
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    curr->prev = nullptr;
    prev->next = curr->next;
    curr->next = nullptr;
    delete curr;
    if (prev->next == nullptr)
    {
        t = prev;
    }
}

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    if (tail == nullptr)
    {
        Node *temp = new Node(val);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *t = new Node(val);
        tail->next = t;
        t->prev = tail;
        tail = t;
    }
}

void insert_at_head(Node *&head, Node *&tail, int val)
{
    if (head == nullptr)
    {
        Node *temp = new Node(val);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(val);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insert_At_position(Node *&head, Node *&tail, int pos, int new_data)
{
    if (pos == 1)
    {
        insert_at_head(head, tail, new_data);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == nullptr)
    {
        insert_at_tail(head, tail, new_data);
    }
    else
    {
        Node *nodeToInsert = new Node(new_data);
        nodeToInsert->next = temp->next;
        temp->next->prev = nodeToInsert;
        temp->next = nodeToInsert;
        nodeToInsert->prev = temp;
    }
}

void printLL(Node *head, Node *tail)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getLen(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp != nullptr)
    {
        // cout<<temp->data<<" ";
        len++;
        temp = temp->next;
    }
    // cout<<endl;
    return len;
}

int main()
{
    Node *first = new Node(10);
    Node *head = first;
    Node *tail = nullptr;

    insert_at_tail(head, tail, 20);
    printLL(head, tail);

    insert_at_tail(head, tail, 50);
    printLL(head, tail);

    insert_At_position(head, tail, 2, 100);
    printLL(head, tail);

    insert_At_position(head, tail, 1, 100);
    printLL(head, tail);

    insert_At_position(head, tail, 5, 100);
    printLL(head, tail);


    // deleteNode(head,tail,5);
    // printLL(head,tail);

    // cout<<"print: "<<endl;

    // deleteNode(head,tail,2);
    // printLL(head,tail);

    deleteNode(head,tail,1);
    printLL(head,tail);
    // cout << "lenght of LL is: " << getLen(head) << endl;
    cout << "head pointing at: " << head->data << endl;
    cout << "tail pointing at: " << tail->data << endl;

    return 0;
}