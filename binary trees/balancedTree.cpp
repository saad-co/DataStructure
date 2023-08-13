#include<iostream>
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

class Solution{
    public:
    
    pair<bool,int> fast(Node* root)
    {
        if(root == NULL)
        {
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        pair<bool,int> left = fast(root->left);
        pair<bool,int> right = fast(root->right);
        
        bool leftANS = left.first;
        bool rightANS = right.first;
        
        bool diff = abs(left.second - right.second)<=1;
        
        pair<bool,int> ans ;
        ans.second = max(left.second,right.second)+1;
        if(leftANS && rightANS && diff)
        {
            ans.first = true;
        }
        else
        {
            ans.first = false;
        }
        
        return ans;
    }
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return fast(root).first;
    }
};