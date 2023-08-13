#include <iostream>
#include "first_tree.cpp"
using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *left;
//     Node *right;
//     Node(int val)
//     {
//         data = val;
//         left = right = NULL;
//     }
// };

class Solution
{
private:
    int height(struct Node *node)
    {
        // base case
        if (node == NULL)
        {
            return 0;
        }

        int left = height(node->left);
        int right = height(node->right);

        return max(left, right) + 1;
    }

public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node *root)
    {
        // Your code here
        if (root == NULL)
        {
            return 0;
        }

        int opt1 = diameter(root->left);
        int opt2 = diameter(root->right);
        int opt3 = height(root->left) + height(root->right) + 1;

        int ans = max(opt1, max(opt2, opt3));
        return ans;
    }
};
