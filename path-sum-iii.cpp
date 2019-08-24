#include <vector>
#include <iostream>
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
	void dfs(TreeNode* root, vector<int> sum_res, const int sum, int& flag) {
		for_each(sum_res.begin(), sum_res.end(), [&root](auto &n) {
			n += root->val;
		});
		sum_res.push_back(root->val);
		for_each(sum_res.begin(), sum_res.end(), [&flag, sum](auto n) {
			if (n == sum)
				flag++;
		});
		if (root->left != nullptr) {
			dfs(root->left, sum_res, sum, flag);
		}
		if (root->right != nullptr) {
			dfs(root->right, sum_res, sum, flag);
		}
	}
	int pathSum(TreeNode* root, int sum) {
		int flag = 0;
		auto sum_res = vector<int>{};
		if (root != nullptr) {
			dfs(root, sum_res, sum, flag);
		}
		return flag;
	}
};
int main() {
	auto s = Solution();
	auto root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(-3);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(2);
	root->left->left->left = new TreeNode(3);
	root->left->left->right = new TreeNode(-2);
	root->left->right = new TreeNode(2);
	root->left->right->right = new TreeNode(1);
	root->right = new TreeNode(-3);
	root->right->right = new TreeNode(11);
	auto sum = 8;
	auto x = s.pathSum(root, sum);
	return 0;
}