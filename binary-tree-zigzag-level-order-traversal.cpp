#include <queue>
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (!root)
			return vector<vector<int>> {};
		queue<TreeNode*> Q;
		Q.push(root);
		vector<vector<int>> lines;
		while (!Q.empty()) {
			vector<int> line;
			auto size_q = Q.size();
			for (int i = 0; i < size_q; ++i) {
				auto u = Q.front();
				Q.pop();
				line.emplace_back(u->val);
				if (u->left) {
					Q.push(u->left);
				}
				if (u->right) {
					Q.push(u->right);
				}
			}
			lines.emplace_back(line);
		}
		for (int i = 0; i < lines.size(); ++i) {
			if (i % 2 == 1)
				std::reverse(lines[i].begin(), lines[i].end());
		}
		return lines;
	}
};
int main() {
	Solution s;
	auto root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	auto x = s.zigzagLevelOrder(root);
	return 0;
}