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
	TreeNode* searchBST(TreeNode* root, int val) {
		TreeNode* res = new TreeNode(-1);
		recursive_search(root, val, res);
		return res;
	}
	void recursive_search(TreeNode* root, int val, TreeNode* &res) {
		if (root == nullptr) {
			res = NULL;
			return;
		}
		else if (val == root->val) {
			res = root;
			return;
		}
		else if (val < root->val)
			recursive_search(root->left, val, res);
		else
			recursive_search(root->right, val, res);
	}
};
int main() {
	Solution s;
	auto root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	int val = 2;
	auto x = s.searchBST(root, val);
	return 0;
}