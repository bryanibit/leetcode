/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

//class Solution {
//public:
//	int sumAll;
//	Solution(int a = 0):sumAll(a){}
//	int cal(vector<int> res)
//	{
//		int sum = 0;
//		for (int i = 0; i < res.size(); ++i)
//		{
//			sum = sum * 10 + res.at(i);
//		}
//		return sum;
//	}
//	void pointToVector(TreeNode * p, vector<int>& res)
//	{
//		res.push_back(p->val);
//		if ((p->left == nullptr)&&(p->right == nullptr)) {
//			sumAll += cal(res);
//			return;
//		}
//		if (p->left != nullptr) {
//			pointToVector(p->left, res);
//			res.pop_back();
//		}
//		if (p->right != nullptr) {
//			pointToVector(p->right, res);
//			res.pop_back();
//		}
//	}
//	int sumNumbers(TreeNode* root) {
//		if (root == nullptr) return 0;
//		std::vector<int> res;
//		pointToVector(root, res);
//		return sumAll;
//	}
//};
class Solution {
public:
	int sum = 0;
	int sumNumbers(TreeNode* root) {
		if (root)
			dfs(root, 0);
		return sum;
	}
	void dfs(TreeNode* root, int cur) {
		cur = cur * 10 + root->val;
		if (!root->left && !root->right) {
			sum += cur;
			return;
		}
		if (root->left)
			dfs(root->left, cur);
		if (root->right)
			dfs(root->right, cur);
	}
};
int main() {
	auto left4 = new TreeNode(4);
	auto left9 = new TreeNode(9);
	auto left0 = new TreeNode(0);
	auto left5 = new TreeNode(5);
	auto left1 = new TreeNode(1);
	left4->left = left9;
	left4->right = left0;
	left9->left = left5;
	left9->right = left1;
	Solution s;
	auto sum = s.sumNumbers(left4);
	return 0;
}