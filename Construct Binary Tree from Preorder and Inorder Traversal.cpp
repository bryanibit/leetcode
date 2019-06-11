/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void parseVector(TreeNode* root, vector<int> &pre, vector<int> &in)
	{
		/*if ((pre.size() == 0)||(in.size() == 0)) 
			return;*/
		root->val = pre.at(0);
		auto it = std::find(in.begin(), in.end(), pre.at(0));
		//iter is size of left tree
		int iter = it - in.begin();
		//int k = iter - in.begin();
		vector<int> l_pre;
		l_pre.assign(pre.begin() + 1, pre.begin() + iter + 1);
		vector<int> l_in;
		l_in.assign(in.begin(), in.begin() + iter);

		vector<int> r_pre;
		r_pre.assign(pre.begin() + iter + 1, pre.end());
		vector<int> r_in;
		r_in.assign(in.begin() + iter + 1, in.end());

 		if ((l_pre.size() == 0) && (l_in.size() == 0) && (r_pre.size() == 0) && (r_in.size() == 0))
			return;

		if ((l_pre.size() != 0) && (l_in.size() != 0))
		{
			root->left = new TreeNode(-1);
			parseVector(root->left, l_pre, l_in);
		}
		
		if ((r_pre.size() != 0) && (r_in.size() != 0))
		{
			root->right = new TreeNode(-1);
			parseVector(root->right, r_pre, r_in);
		}
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if ((preorder.size() == 0) || (inorder.size() == 0)) {
			return nullptr;
		}
		else {
			TreeNode* root = new TreeNode(-1);
			parseVector(root, preorder, inorder);
			return root;
		}
		
	}
};
int main() {
	std::vector<int> preorder = { 1,2};
	std::vector<int> inorder = { 1,2};
	Solution s;
	auto tree = s.buildTree(preorder, inorder);
	return 0;
}