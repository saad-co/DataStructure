#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    // Node()
    // {
    //     data = 0;
    //     left = nullptr;
    //     right = nullptr;
    // }
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


void Insert(Node*& root,int val)
{
    if(root==nullptr)
    {
        root = new Node(val);
        // cout<<"inserted: "<<endl;
        return;
    }
    if(val<root->data)
    {
        // insert in left side 
        // cout<<"inserting in left"<<endl;
        Insert(root->left,val);
    }
    else
    {
        // insert in right side
        // cout<<"inserting in right: "<<endl;
        Insert(root->right,val);
    }

    // return root;
}

void TakeInput(Node*& root)
{
    int inp=0;
    cin>>inp;
    while(inp!=-1)
    {
       Insert(root,inp);
        // cout<<"in loop"<<endl;
       cin>>inp;
    }
}

void level_order_traversal(Node *root)
{
    queue<Node *> q;
    // cout<<"value of root: "<<root->data<<" pushed into queue: "<<endl;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        // cout<<"in printing loop: "<<endl;
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // cout<<"pushing null if: "<<endl;
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // cout<<"else part: printing: "<<endl;
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
                // cout<<"going in left side: "<<temp->left<<endl;
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


Node* findmini(Node* root)
{
    Node* temp = root;
    while(temp!=nullptr)
    {
        temp = temp->left;
    }
    return temp;

}


Node* deleteFromBST(Node* root,int val)
{
    if(root == nullptr)
    {
        return root;
    }
    if(root->data == val)
    {
        // 0 child
        if(root->left==nullptr && root->right==nullptr)
        {
           delete root;
           return nullptr;

        }


        // 1 child
        // there is only left child
        if(root->left!=nullptr && root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // there is only a right child
        if(root->left == nullptr && root->right!=nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }


        // 2 child
        if(root->left != nullptr && root->right != nullptr)
        {
            int mini = findmini(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right,mini);
            return root;
        }
    }
    else if(root->data>val)
    {
        root->left = deleteFromBST(root->left,val);
        return root;
    }
    else
    {
        root->right = deleteFromBST(root->right,val);
        return root;
    }

}

int main()
{
    Node* root = nullptr;
    cout<<"Enter the data for binary Search Tree: "<<endl;
    TakeInput(root);

    // printing the binary tree
    level_order_traversal(root);
    deleteFromBST(root,27);
    level_order_traversal(root);
    // 10 8 21 7 27 5 4 3 -1
    // inorder(root);
    return 0;
}