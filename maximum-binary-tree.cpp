#include<vector>
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
	void constructTree(TreeNode* root, const vector<int>& nums, vector<int> &visited, int val_loc) {
		root->val = nums.at(val_loc);
		int for_right = val_loc;
		int for_left = val_loc;
		int i = for_right + 1;
		while (i < nums.size()) {
			if (visited[i] == 1)
				break;
			++i;
		}
		int right = i - 1;
		if (right != for_right) {
			auto right_max = std::max_element(nums.begin() + for_right + 1, nums.begin() + right + 1);
			visited.at(right_max - nums.begin()) = 1;
			root->right = new TreeNode(-1);
			constructTree(root->right, nums, visited, right_max - nums.begin());
		}

		int j = for_left - 1;
		while (j >= 0) {
			if (visited[j] == 1)
				break;
			--j;
		}
		int left = j + 1;
		if (left != for_left) {
			auto left_max = std::max_element(nums.begin() + left, nums.begin() + for_left);
			visited.at(left_max - nums.begin()) = 1;
			root->left = new TreeNode(-1);
			constructTree(root->left, nums, visited, left_max - nums.begin());
		}
		/*if (start < max_iter - nums.begin()) {
			root->left = new TreeNode(-1);
			constructTree(root->left, nums, start, max_iter - nums.begin());
		}
		if (max_iter - nums.begin() > end) {
			root->right = new TreeNode(-1);
			constructTree(root->right, nums, max_iter - nums.begin(), end);
		}*/
	}
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		vector<int> visited(nums.size(), 0);
		auto max_iter = std::max_element(nums.begin(), nums.end());
		visited.at(max_iter - nums.begin()) = 1;
		auto root = new TreeNode(-1);
		constructTree(root, nums, visited, max_iter-nums.begin());
		return root;
	}
};
int main() {
	Solution s;
	vector<int> nums = { 3,2,1,6,0,5 };
	auto x = s.constructMaximumBinaryTree(nums);
	return 0;
}