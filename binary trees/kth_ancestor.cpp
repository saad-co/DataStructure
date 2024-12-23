#include<iostream>
#include "first_tree.cpp"
using namespace std;


Node* solve(Node* root,int& k,int node)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data == node)
    {
        return root;
    }
    
    // recursive calls
   Node* leftAns =  solve(root->left,k,node);
    
   Node* rightAns = solve(root->right,k,node);
   
   if(leftAns != NULL && rightAns == NULL)
   {
       k--;
       if(k<=0)
       {
        //   k = INT_MAX;
           return root;
       }
       return leftAns;
   }
   
   if(leftAns == NULL && rightAns != NULL)
   {
       k--;
       if(k<=0)
       {
           k = INT_MAX;
           return root;
       }
       return rightAns;
   }
   return NULL;
}


int kthAncestor(Node *root, int k, int node)
{
    Node* l = solve(root,k,node);
    
    if(l==NULL || l->data == node)
    {
        return -1;
    
    }
    else
    {
        return l->data;
    }

}
