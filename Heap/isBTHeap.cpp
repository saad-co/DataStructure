// this is the code of checking a binary tree that is it a heap or not..
bool isCBT(BinaryTreeNode<int>* root,int index,int TotalNodes)
{
    if(root==NULL)
    {
        return true;
    }
    if(index>=TotalNodes)
    {
        return false;
    }
    else
    {

        bool left = isCBT(root->left,2*index+1,TotalNodes);

        bool right = isCBT(root->right,2*index+2,TotalNodes);

        return (left&&right);
    }
}
int countNodes(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int ans = 1+countNodes(root->left)+countNodes(root->right);
    return ans;
}

bool isMaxOrder(BinaryTreeNode<int>* root)
{
    if(root->left == NULL && root->right == NULL)
    {
        return true;
    }
    if(root->right == NULL)
    {
        return (root->data > root->left->data);
    }
    else
    {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return((left && right) && 
        (root->data >= root->left->data) && (root->data >= root->right->data));
    }
}

bool isBinaryHeapTree(BinaryTreeNode<int>* root) 
{
    int totalNodes = countNodes(root);
    if(isCBT(root,0,totalNodes) && isMaxOrder(root))
    {
        return true;
    }
    return false;
}