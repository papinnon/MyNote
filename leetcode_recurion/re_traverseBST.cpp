#include <iostream>
struct TreeNode{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode * searchBST(TreeNode * root, int val)
{
	if(root == NULL || root->val == val)
		return root;
	if(root->val > val)
		return searchBST(root->left, val);
	else
		return searchBST(root->right, val);
}

TreeNode * insertBST(TreeNode * node, int val)
{
	if(node == NULL)
		return new TreeNode(val);
	if(node->val == val)
		exit(1);
	if(node->val > val)
		node->left = insertBST(node->left, val);
	else
		node->right= insertBST(node->right, val);
	return node;
}

void displayBST(TreeNode * root)
{
	if(root == NULL)
		return;
	displayBST(root->left);
	std::cout << root->val << ",";
	displayBST(root->right);
}

int MaxDepth(TreeNode *root)
{
	if(root == NULL)
		return 0;
	int left = MaxDepth(root->left);
	int right = MaxDepth(root->right);
	return left> right ? left+1: right +1;
}
int main()
{
	TreeNode * root= NULL;	
	root =insertBST(root, 3);
	insertBST(root, 5);
	insertBST(root, 1);
	insertBST(root, 2);
	insertBST(root, 9);
	insertBST(root, 11);
	displayBST(root);

}
