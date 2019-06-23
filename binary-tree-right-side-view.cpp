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
	vector<int> rightSideView(TreeNode* root) {
		if (!root)
			return vector<int> {};
		queue<TreeNode*> Q;
		Q.push(root);
		vector<int> line;
		while (!Q.empty()) {
			auto size_q = Q.size();
			for (int i = 0; i < size_q; ++i) {
				auto u = Q.front();
				Q.pop();
				if(i == size_q - 1)
					line.emplace_back(u->val);
				if (u->left) {
					Q.push(u->left);
				}
				if (u->right) {
					Q.push(u->right);
				}
			}
			
		}
		return line;
	}
};
int main() {
	Solution s;
	auto root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	auto x = s.rightSideView(root);
	return 0;
}