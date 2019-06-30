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
	int minDepth(TreeNode* root) {
		if (!root)
			return 0;
		queue<TreeNode*> Q;
		Q.push(root);
		auto count = 1;
		while (!Q.empty()) {
			auto size_q = Q.size();
			
			for (int i = 0; i < size_q; i++) {
				auto u = Q.front();
				Q.pop();
				if (u->left)
					Q.push(u->left);
				if (u->right)
					Q.push(u->right);
				if (!u->right && !u->left)
					return count;
			}
			count++;
		}
		return count;
	}
};
int main() {
	Solution s;
	auto root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	auto x = s.minDepth(root);
	return 0;
}