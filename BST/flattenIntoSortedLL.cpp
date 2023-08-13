void inorder(TreeNode<int>* root, vector<TreeNode<int>*>& in) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, in);
    in.push_back(root);
    inorder(root->right, in);
}

TreeNode<int>* flatten(TreeNode<int>* root) {
    vector<TreeNode<int>*> inorder;
    inorder(root, inorder);
    for (int i = 0; i < inorder.size() - 1; i++) {
        inorder[i]->left = NULL;
        inorder[i]->right = inorder[i + 1];
    }
    inorder[inorder.size() - 1]->left = NULL;
    inorder[inorder.size() - 1]->right = NULL;
    return inorder[0];
}
