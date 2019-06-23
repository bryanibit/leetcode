#include <vector>
#include <queue>
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
	int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode*> Q;
		if (!root)
			return -1;
		Q.push(root);
		vector<vector<int>> lines;
		while (!Q.empty()) {
			auto size_q = Q.size();
			vector<int> line;
			for (int i = 0; i < size_q; i++) {
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
		return lines.back().at(0);
	}
};
int main() {
	Solution s;
	auto root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	auto x = s.findBottomLeftValue(root);
	return 0;
}