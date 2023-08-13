#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
    ~Node()
    {
        int val = this->data;
        if (this->next != nullptr)
        {
            delete next;
            next = nullptr;
        }
        cout << "Memory is free for : " << val << endl;
    }
};

void deleteNode(Node *&head, Node *&t, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
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
    prev->next = curr->next;
    curr->next = nullptr;
    delete curr;
    if (prev->next == nullptr)
    {
        t = prev;
    }
}

void insert_at_head(Node *&head, int new_data)
{
    // first creat a new node
    Node *temp = new Node(new_data);
    temp->next = head;
    head = temp;
}

void insert_at_tail(Node *&tail, int new_data)
{

    Node *temp = new Node(new_data);
    tail->next = temp;
    tail = tail->next;
}

void insert_At_position(Node *&head, Node *&tail, int pos, int new_data)
{
    if (pos == 1)
    {
        insert_at_head(head, new_data);
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
        insert_at_tail(tail, new_data);
    }
    else
    {
        Node *nodeToInsert = new Node(new_data);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    }
}

void printLL(Node *&head)
{
    // cout<<"-----------------------------\n";
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *detectCycle(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    Node *slow = head;
    Node *fast = head;
    while (slow != nullptr && fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            cout << "cycle exist at: " << slow->data << endl;
            return slow;
        }
    }
    return nullptr;
}

Node *starting_node_of_loop(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    Node *point_of_intersection = detectCycle(head);
    Node *slow = head;
    while (slow != point_of_intersection)
    {
        slow = slow->next;
        point_of_intersection = point_of_intersection->next;
    }

    return slow;
}

void remove_loop(Node *head)
{
    if (head == nullptr)
    {
        cout << "LL is empty: " << endl;
    }
    Node *starting_node = starting_node_of_loop(head);
    Node *temp = starting_node;
    while (temp->next != starting_node)
    {
        temp = temp->next;
    }
    temp->next = nullptr;
}

int main()
{
    Node *n = new Node(10);
    Node *head = n;
    Node *tail = n;

    insert_at_tail(tail, 30);
    insert_at_tail(tail, 90);
    insert_at_tail(tail, 77);
    insert_at_tail(tail, 89);

    // insert_At_position(head, tail, 4, 20);
    // insert_At_position(head, tail, 2, 77);

    tail->next = head->next;
    if (detectCycle(head))
    {
        cout << "Cycle exist: " << endl;
    }
    else
    {
        cout << "no cycle exist; " << endl;
    }
    Node *temp = starting_node_of_loop(head);
    cout << "starting node of loop is: " << temp->data << endl;

    // remove_loop(head);
    // if (detectCycle(head))
    // {
    //     cout << "Cycle exist: " << endl;
    // }
    // else
    // {
    //     cout << "no cycle exist; " << endl;
    // }
    // printLL(head);

    // cout<<"_________________________________________\n";
    //     printLL(head);
    //     deleteNode(head,tail,5);
    //     // deleteNode(head,4);
    // cout<<"_________________________________________\n";
    //     printLL(head);
    // cout<<"_________________________________________\n";

    //     cout<<"data of head: "<<head->data<<endl;
    //     cout<<"data of tail: "<<tail->data<<endl;
    // cout<<"_________________________________________\n";

    return 0;
}