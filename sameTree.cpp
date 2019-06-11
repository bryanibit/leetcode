/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
#include <vector>
#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void pointToVector(TreeNode * p, vector<int>& res)
	{
		if (p == nullptr) {
			res.push_back(-1);
			return;
		}
		else
			res.push_back(p->val);
		pointToVector(p->left, res);
		pointToVector(p->right, res);

	}
	bool isSameTree(TreeNode* p, TreeNode* q) {
		std::vector<int> res_p;
		std::vector<int> res_q;
		pointToVector(p, res_p);
		pointToVector(q, res_q);
		return res_p == res_q;
	}
};
int main() {
	Solution s;
	auto p = new TreeNode(1);
	auto q = new TreeNode(1);
	auto node2 = new TreeNode(2);
	p->left = node2;
	q->right = node2;
	auto ver = s.isSameTree(p, q);
	std::cout << ver << std::endl;
	return 0;
}