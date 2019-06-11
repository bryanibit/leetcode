#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	vector<vector<int>> res_all;
	void dfs(vector<int> res, TreeNode* root, int sum, const int val) {
		sum += root->val;
		res.push_back(root->val);
		if (sum == val && root->left == nullptr && root->right == nullptr) {
			//std::for_each(res.begin(), res.end(), [](const int& n) {std::cout << n << std::endl; });
			res_all.push_back(res);
			return;
		}
		if (root->left != nullptr) {
			dfs(res, root->left, sum, val);
		}
		if (root->right != nullptr) {
			dfs(res, root->right, sum, val);
		}
		// if not enter return, then pop the root->val out of vector
		res.pop_back();
	}
	vector<vector<int>> pathSum(TreeNode* root, int val) {
		vector<int> res;
		int sum = 0;
		if(root != nullptr)
			dfs(res, root, sum, val);
		return res_all;
	}
};
int main() {
	Solution s;
	auto root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right->right->right = new TreeNode(1);
	root->right->right->left = new TreeNode(5);
	auto x = s.pathSum(root, 22);
	return 0;
}