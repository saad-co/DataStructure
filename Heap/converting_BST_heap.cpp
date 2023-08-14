void getInorder(BinaryTreeNode* root,vector<int>& vec)
{
	if(root == NULL)
	{
		return;
	}
	getInorder(root->left,vec);
	vec.push_back(root->data);
	getInorder(root->right,vec);
}

void fillPreorder(BinaryTreeNode* root,vector<int> inorder,int index)
{
	if(root == NULL)
	{
		return;
	}

	root->data = inorder[index++];
	fillPreorder(root->left,inorder,index);
	fillPreorder(root->right,inorder,index);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> inorder;
	getInorder(root,inorder);

	fillPreorder(root,inorder,0);

	return root;
}