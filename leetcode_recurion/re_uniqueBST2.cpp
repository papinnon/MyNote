#include <iostream>
#include <vector>
using std::vector;
struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x):val(x), left(NULL), right(NULL){}
};


vector<TreeNode * > generateTrees(int n)
{
	vector<TreeNode *>acc;
	if(n==1 || n==0)
	{
		TreeNode * p = new TreeNode(n);
		acc.push_back(p);
		return acc;
	}
	for(int i=1 ; i <= n; ++i)
	{
		vector<TreeNode *>lefts = generateTrees(i-1);
		vector<TreeNode *>rights= generateTrees(n-i); // wrong
		for(auto  l : lefts)
			for(auto  r : rights)
			{
				TreeNode *  node = new TreeNode(i);
				node->left =  l;
				node->right = r;
				acc.push_back( node );
			}
	}
	return acc;
}

vector<TreeNode *>gen(int start, int end) // [start, end]
{
	int eleCount = end- start +1 	; 
	vector<TreeNode *> result 	;
	if(start > end)
		return result;
	if( eleCount == 1)
	{
		TreeNode * node = new TreeNode(start);
		result.push_back(node);
		return result;
	}
	for(int i =0; i< eleCount; ++i)
	{
		vector<TreeNode *> lefts =  gen(start, start+i-1 );
		vector<TreeNode *> rights = gen( start+i+1, end);
		if(lefts.size()!=0 && rights.size() !=0)
			for(auto l : lefts)
				for(auto r: rights )
				{
					TreeNode * p = new TreeNode(start+i);
					p->left = l;
					p->right =r;
					result.push_back(p);
				}
		else if(lefts.size() )
		{
			for(auto l: lefts)
			{
				TreeNode * p  =new TreeNode(start+i);
				p->left = l;
				result.push_back(p);
			}
		}
		else
		{
			for(auto r: rights)
			{
				TreeNode * p = new TreeNode(start+i);
				p->right = r;
				result.push_back(p);
			}
		}
	}
	return result;
}
void traverse(TreeNode * root)
{
	if(root == NULL)
		return;
	std::cout<<root->val;
	traverse(root->left);
	traverse(root->right);
	return;
}
int main()
{
	auto vec  =	gen(1,3);
	for(auto i : vec)
	{
		traverse(i);
		std::cout << '\n';
	}
}
