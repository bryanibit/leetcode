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
	void dfs(TreeNode* root, vector<int>& preorder, int i, int j) {
		/*if (i == j)
			return;*/
		int root_start = i;
		root->val = preorder.at(root_start);
		int left_end = 0;
		int right_end = 0;
		i = root_start + 1;
		while (i < j) {
			if (preorder.at(i) < root->val) {
				++i;
			}
			else
				break;
		}
		left_end = i;
		while (i < j) {
			if (preorder.at(i) > root->val) {
				++i;
			}
			else
				break;
		}
		right_end = i;

		if (root_start + 1 < left_end) {
			root->left = new TreeNode(-1);
			dfs(root->left, preorder, root_start + 1, left_end);
		}
		if (left_end < right_end) {
			root->right = new TreeNode(-1);
			dfs(root->right, preorder, left_end, right_end);
		}
		if (root_start + 1 == left_end || left_end == right_end)
			return;
	}
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		TreeNode *root = new TreeNode(-1);
		dfs(root, preorder, 0, preorder.size());
		return root;
	}
};
int main() {
	Solution s;
	vector<int> preorder = { 8,5,1,7,10,12 };
	auto x = s.bstFromPreorder(preorder);
	return 0;
}