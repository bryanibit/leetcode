#include <algorithm>
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
	void clone(TreeNode* des, TreeNode* tree, int j) {
		des->val = tree->val + j;
		if (tree->left) {
			des->left = new TreeNode(-1);
			clone(des->left, tree->left, j);
		}
		if (tree->right) {
			des->right = new TreeNode(-1);
			clone(des->right, tree->right, j);
		}
	}
	int numTrees(int n) {
		vector <vector<TreeNode*>> tree;
		vector<int> res(n + 1, 0);
		//res i == 0 or 1
		res[0] = 1;
		res[1] = 1;
		tree.emplace_back(vector<TreeNode*>{ nullptr });
		tree.emplace_back(vector<TreeNode*>{ new TreeNode(1) });
		// i start from 2
		for (int i = 2; i <= n; ++i) {
			vector<TreeNode*> j_tree;
			for (int j = 1; j <= i; ++j) {
				res[i] += res[j - 1] * res[i - j];
				auto root = new TreeNode(j);
				vector<TreeNode*> root_j(tree[j - 1].size()*tree[i - j].size(), new TreeNode(j));
				int hh = 0;
				for (int k = 0; k < tree[j - 1].size(); ++k) {
					if (tree[j - 1][k] != nullptr) {
						root_j[hh]->left = new TreeNode(-1);
						clone(root_j[hh]->left, tree[j - 1][k], 0);
					}
				}
				for (int k = 0; k < tree[i - j].size(); ++k) {
					if (tree[i - j][k] != nullptr) {
						root_j[hh]->right = new TreeNode(-1);
						clone(root_j[hh]->right, tree[i - j][k], j);
					}
				}		
			}
			tree.push_back(j_tree);
		}
		return res[n];
	}
};
int main() {
	Solution s;
	auto x = s.numTrees(3);
	return 0;
}