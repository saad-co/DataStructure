#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d) : data(d)
    {
        next = nullptr;
    }

    ~Node()
    {
        int val = data;
        if (next != nullptr)
        {
            delete next;
            next = nullptr;
        }
        cout << "memory free for: " << val << endl;
    }
};

void insertNode(Node *&tail, int element, int val)
{
    if (tail == nullptr)
    {
        Node *newNode = new Node(val);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *n = new Node(val);
        n->next = curr->next;
        curr->next = n;
    }
}

void deleteNode(Node *&tail, int val)
{
    if (tail == nullptr)
    {
        cout << "List is already empty: " << endl;
        return;
    }
    Node *prev = tail;
    Node *curr = prev->next;
    while (curr->data != val)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    // case handling for single node
    if (curr == prev)
    {
        tail = nullptr;
    }
    // case handling if there are two nodes in the linked list
    else if (tail == curr)
    {
        tail = prev;
    }
    curr->next = nullptr;
    delete curr;
}




void PrintLL(Node *tail)
{
    if (tail == nullptr)
    {
        cout << "Linked list is empty: " << endl;
        return;
    }
    Node *temp = tail;
    do
    {
        cout << temp->data << "  ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}


int getlen(Node* head)
{
    int cnt=1;
    Node* temp = head;
    while(temp->next != head)
    {
        
        // cout<<"ok"<<endl;
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

void split(Node* head,Node*&H1,Node*&H2)
{
    int len = getlen(head)/2;
        // cout<<len<<endl;
        int c=0;
        H1 = head;
        H2 = head;

    Node* temp = head;
    do
    {
        int cnt=1;
        if(cnt == len)
        {
            H1 ->next = head;
        }
        H1 = H1->next;

        
    } while (true);
    
}

int main()
{

    Node *t = nullptr;
    insertNode(t, 5, 1);
    // PrintLL(t);

    insertNode(t, 1, 14);
    insertNode(t, 14, 67);
    insertNode(t, 67, 32);
    insertNode(t,32,44);
    insertNode(t,44,85);

    // PrintLL(t);
    split(t,t,t);

    // insertNode(t, 14, 20);
    // PrintLL(t);

    // insertNode(t, 1, 99);
    // PrintLL(t);

    // insertNode(t, 14, 89);
    // PrintLL(t);

    // deleteNode(t, 14);
    // PrintLL(t);

    return 0;

    
}