#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *creattree(Node *root)
{
    cout << "Enter data: " << endl;
    int d = 0;
    cin >> d;
    root = new Node(d);

    // base case for stoping the tree
    if (d == -1)
    {
        return NULL;
    }

    // creating left node of tree
    cout << "Enter data for the left of " << d << ": " << endl;
    root->left = creattree(root->left);

    // creating right nodes of tree

    cout << "enter data for the right of " << d << ": " << endl;
    root->right = creattree(root->right);

    return root;
}

void level_order_traversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}


void inorder(Node *root) // LNR
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


void inorderIterative(Node *root)
{
    if (root == nullptr)
        return;

    std::stack<Node *> nodeStack;
    Node *current = root;

    while (current != nullptr || !nodeStack.empty())
    {
        while (current != nullptr)
        {
            nodeStack.push(current);
            current = current->left;
        }

        current = nodeStack.top();
        nodeStack.pop();

        std::cout << current->data << " ";

        current = current->right;
    }
}

void preorder(Node *root) // NLR
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) // LRN
{
    if (root == nullptr)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void build_From_Level_Order(Node*& root) {
    queue<Node*> q;
    cout << "Enter data for the root: " << endl;
    int data;
    cin >> data;

    if (data == -1) {
        root = nullptr; // The root is empty (null).
        return;
    }

    root = new Node(data);
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left node of: " << temp->data << endl;
        int left_data = 0;
        cin >> left_data;

        if (left_data != -1) {
            temp->left = new Node(left_data);
            q.push(temp->left);
        }

        cout << "Enter the right node of: " << temp->data << endl;
        int right_data = 0;
        cin >> right_data;

        if (right_data != -1) {
            temp->right = new Node(right_data);
            q.push(temp->right);
        }
    }
}


int main()
{
    Node *root = NULL;
    root = creattree(root);
    // build_From_Level_Order(root);
    level_order_traversal(root);




    // cout << "Inorder data: " << endl;
    // inorder(root);
    // cout << endl
    //      << "Iterative: " << endl;
    // inorderIterative(root);

    // cout<<endl<<"pre order data: "<<endl;
    // preorder(root);
    // cout<<endl<<"post order data: "<<endl;
    // postorder(root);

    /*
    // 5 6 7 -1 15 -1 -1 -1 18 16 -1 -1 19 -1 -1
    // 1 3 7 -1 -1  11 -1 -1 5 17 -1 -1 -1
    */
    return 0;
}