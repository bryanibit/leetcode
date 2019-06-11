#include <vector>
#include <algorithm>
using namespace std;
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (root->left == nullptr && root->right == nullptr)
		{
			if (root->val < val)
				root->right = new TreeNode(val);
			else
				root->left = new TreeNode(val);
			return root;
		}
		if (root->val < val) {
			if (root->right == nullptr) {
				root->right = new TreeNode(val);
				return root;
			}
			else
				insertIntoBST(root->right, val);
		}
		else {
			if (root->left == nullptr) {
				root->left = new TreeNode(val);
				return root;
			}
			else
				insertIntoBST(root->left, val);
		}
		//for leetcode return rule
		return root;
	}
};
int main() {
	Solution s;
	auto root = new TreeNode(5);
	//root->left = new TreeNode(2);
	/*root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);*/
	root->right = new TreeNode(14);
	root->right->left = new TreeNode(10);
	root->right->right = new TreeNode(77);
	root->right->right->right = new TreeNode(95);
	s.insertIntoBST(root, 4);
	return 0;
}