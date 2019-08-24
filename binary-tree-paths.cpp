#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void dfs(vector<string> &res, std::string s, TreeNode* root) {
		s += to_string(root->val);
		cout << "in root->val: " << root->val << std::endl;
		if ((!root->left) && (!root->right)) {
			res.push_back(s);
			return;
		}
		//+ to_string(root->left->val)
		if (root->left) {
			if (s.back() != '>')
				s += "->";
			dfs(res, s, root->left);
		}
		// + to_string(root->right->val)
		if (root->right) {
			if(s.back() != '>')
				s += "->";
			dfs(res, s, root->right);
		}
		cout << "out root->val: " << root->val << std::endl;
	}
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		string s = "";
		if (!root)
			return vector<string>{};
		else
			dfs(res, s, root);
		return res;
	}
};
int main() {
	Solution s;
	auto root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(5);
	//root->left->left = new TreeNode(4);
	auto x = s.binaryTreePaths(root);
	return 0;
}