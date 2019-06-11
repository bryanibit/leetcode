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
#include <cmath>
#include <limits>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
auto nul = -1;
class Solution {
public:
	bool bsf(TreeNode* node, int lower, int upper)
	{
		if (node == nullptr)
			return true;
		if (((lower != -1)) && (node->val >= lower))
			return false;
		if (((upper != -1)) && (node->val <= upper))
			return false;
		return (bsf(node->left, node->val, upper) && bsf(node->right, lower, node->val));
	}
	bool isValidBST(TreeNode* root) {
		return bsf(root, nul, nul);
	}
};
int main() {
	Solution s;
	TreeNode *root5 = new TreeNode(10);
	TreeNode *root1 = new TreeNode(5);
	TreeNode *root4 = new TreeNode(15);
	root5->left = root1;
	root5->right = root4;
	TreeNode *root3 = new TreeNode(6);
	TreeNode *root6 = new TreeNode(20);
	root4->left = root3;
	root4->right = root6;
	std::cout << s.isValidBST(root5) << std::endl;
	return 0;
}