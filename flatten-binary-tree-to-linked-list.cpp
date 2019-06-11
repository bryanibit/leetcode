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
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void toVector(TreeNode* root, vector<int>& res) {
		res.push_back(root->val);
		if ((root->left == nullptr) && (root->right == nullptr)) {
			return;
		}
		if (root->left != nullptr){
			toVector(root->left, res);
		}
		if (root->right != nullptr) {
			toVector(root->right, res);
		}
	}
	void vectorToTree(vector<int>& res, TreeNode* tree) {
		tree->val = res[0];
		res.erase(res.begin());

		if (res.size() == 0)
			return;

		tree->right = new TreeNode(-1);
		vectorToTree(res, tree->right);
	}
	void flatten(TreeNode* root) {
		vector<int> res;
		toVector(root, res);
		TreeNode* tree = new TreeNode(-1);
		vectorToTree(res, tree);
		root = tree;
		return;
	}
};
int main() {
	auto left4 = new TreeNode(4);
	auto left9 = new TreeNode(9);
	auto left0 = new TreeNode(0);
	auto left5 = new TreeNode(5);
	auto left1 = new TreeNode(1);
	left4->left = left9;
	left4->right = left0;
	left9->left = left5;
	left9->right = left1;
	Solution s;
	s.flatten(left4);
	return 0;
}