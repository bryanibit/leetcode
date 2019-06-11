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
	void parseVector(TreeNode* root, vector<int> &post, vector<int> &in)
	{
		/*if ((pre.size() == 0)||(in.size() == 0))
		return;*/
		root->val = post.back();
		auto it = std::find(in.begin(), in.end(), post.back());
		//iter is size of left tree
		int iter = it - in.begin();
		//int k = iter - in.begin();
		vector<int> l_post;
		l_post.assign(post.begin(), post.begin() + iter);
		vector<int> l_in;
		l_in.assign(in.begin(), in.begin() + iter);

		vector<int> r_post;
		r_post.assign(post.begin() + iter, post.end() - 1);
		vector<int> r_in;
		r_in.assign(in.begin() + iter + 1, in.end());

		if ((l_post.size() == 0) && (l_in.size() == 0) && (r_post.size() == 0) && (r_in.size() == 0))
			return;

		if ((l_post.size() != 0) && (l_in.size() != 0))
		{
			root->left = new TreeNode(-1);
			parseVector(root->left, l_post, l_in);
		}

		if ((r_post.size() != 0) && (r_in.size() != 0))
		{
			root->right = new TreeNode(-1);
			parseVector(root->right, r_post, r_in);
		}
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if ((postorder.size() == 0) || (inorder.size() == 0)) {
			return nullptr;
		}
		else {
			TreeNode* root = new TreeNode(-1);
			parseVector(root, postorder, inorder);
			return root;
		}

	}
};
int main() {

	std::vector<int> inorder = { 9,3,15,20,7 };
	std::vector<int> postorder = { 9,15,7,20,3 };
	Solution s;
	auto tree = s.buildTree(inorder, postorder);
	return 0;
}