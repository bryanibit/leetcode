#include <queue>
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> Q;
		if (!root)
			return vector<vector<int>> {};
		Q.push(root);
		vector<vector<int>> lines;
		while (!Q.empty()) {
			vector<int> line;
			auto size_q = Q.size();
			for (int i = 0; i < size_q; ++i) {
				auto u = Q.front();
				Q.pop();
				line.push_back(u->val);
				if (u->left) {
					Q.push(u->left);
				}
				if (u->right) {
					Q.push(u->right);
				}
			}
			lines.push_back(line);
		}
		return lines;
	}
};
int main() {
	Solution s;
	auto root = nullptr;
	/*auto root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);*/
	auto x = s.levelOrder(root);
	return 0;
}