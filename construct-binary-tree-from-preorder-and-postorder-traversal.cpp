#include <vector>
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
	void dfs(vector<int> pre, vector<int> post, TreeNode* root) {
		if (pre.size() == 1 && post.size() == 1) {
			root->val = pre[0];
			return;
		}
		root->val = pre[0];
		auto iter = std::find(post.begin(), post.end(), pre[1]);
		vector<int> left_post;
		vector<int> right_post;
		left_post.assign(post.begin(), iter + 1);
		right_post.assign(iter + 1, post.end() - 1);
		vector<int> left_pre;
		vector<int> right_pre;
		left_pre.assign(pre.begin() + 1, pre.begin() + 1 + left_post.size());
		right_pre.assign(pre.begin() + 1 + left_post.size(), pre.end());
		if (left_post.size() != 0 && left_pre.size() != 0) {
			root->left = new TreeNode(-1);
			dfs(left_pre, left_post, root->left);
		}
		if (right_post.size() != 0 && right_pre.size() != 0) {
			root->right = new TreeNode(-1);
			dfs(right_pre, right_post, root->right);
		}
	}
	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
		auto root = new TreeNode(-1);
		dfs(pre, post, root);
		return root;
	}
};
int main() {
	Solution s;
	vector<int> pre = { 2,1 };
	vector<int> post = { 1, 2 };
	auto x = s.constructFromPrePost(pre, post);
	return 0;
}