#include<iostream>
struct Node
{
    int value;
    Node* left;
    Node* right;


    Node(int val){}
};

class Solution{
    public:
    int find(int in[],int key,int size)
    {
        for(int i=0;i<size;i++)
        {
            if(in[i]==key)
            {
                return i;
            }
        }
        return -1;
    }
    Node* solve(int in[],int pre[],int index,int InorderIndexStart,int InorderIndexEnd,int n)
    {
        if(index>=n || InorderIndexStart > InorderIndexEnd)
        {
            return NULL;
        }
        
        int element = pre[index++];
        
        Node* root = new Node(element);
        
        int positionOfElementInorder = find(in,element,n);
        
        root->left = solve(in,pre,index,InorderIndexStart,positionOfElementInorder-1,n);
        root->right = solve(in,pre,index,positionOfElementInorder+1,InorderIndexEnd,n);
        
        return root;
        
        
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex=0;
        Node* ans = solve(in,pre,preOrderIndex,0,n-1,n);
        return ans;
    }
};