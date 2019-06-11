#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	//void dfs(TreeNode* root, int& count) {
	//	if (root->left != nullptr)
	//		dfs(root->left, count);
	//	if (root->right != nullptr)
	//		dfs(root->right, count);
	//	if (root->left == nullptr && root->right == nullptr && root->val == 0) {
	//		count = 1;
	//		//delete root;
	//		root = NULL;
	//	}
	//}
	TreeNode* pruneTree(TreeNode* root) {
		if (!root)
			return root;
		if (root->left != nullptr)
			root->left = (root->left);
		if (root->right != nullptr)
			root->right = pruneTree(root->right);
		if (root->left == nullptr && root->right == nullptr && root->val == 0)
			return nullptr;
		return root;
	}
};
int main() {
	Solution s;
	auto root = new TreeNode(1);
	root->left = new TreeNode(0);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(0);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(1);
	auto x = s.pruneTree(root);
	return 0;
}