#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:
	// Encodes a tree to a single string.
	void dfs(TreeNode* root, string& str) {
		if (root == nullptr)
			str += "x,";
		else {
			str += (to_string(root->val) + ",");
			dfs(root->left, str);
			dfs(root->right, str);
		}
	}
	string serialize(TreeNode* root) {
		string str = "";
		dfs(root, str);
		return str;
	}
	// Decodes your encoded data to tree.
	void buildTree(TreeNode* root, queue<string> &data, int i) {
		if (data.front() == "x") {
			root = nullptr;
			data.pop();
		}
		else {
			root->val = stoi(data.front());
			data.pop();
			if(data.front() != "x")
				root->left = new TreeNode(std::numeric_limits<int>::min());
			buildTree(root->left, data, i + 1);
			if (data.front() != "x")
				root->right = new TreeNode(std::numeric_limits<int>::min());
			buildTree(root->right, data, i + 2);
		}
	}
	std::queue<std::string> split(const std::string& s, char seperator)
	{
		std::queue<std::string> output;
		std::string::size_type prev_pos = 0, pos = 0;
		while ((pos = s.find(seperator, pos)) != std::string::npos)
		{
			std::string substring(s.substr(prev_pos, pos - prev_pos));
			output.push(substring);
			prev_pos = ++pos;
		}
		output.push(s.substr(prev_pos, pos - prev_pos)); // Last word
		return output;
	}
	TreeNode* deserialize(string data) {
		auto data_v = split(data, ',');
		auto root = new TreeNode(std::numeric_limits<int>::min());
		if (!data_v.empty()) {
			buildTree(root, data_v, 0);
		}
		if (root->val == std::numeric_limits<int>::min())
			return nullptr;
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
int main() {
	//auto root = new TreeNode(1);
	//root->left = new TreeNode(6);
	//root->right = new TreeNode(2);
	//root->left->left = new TreeNode(7);
	//root->left->right = new TreeNode(5);
	//root->left->left->left = new TreeNode(8);
	//root->left->right->left = new TreeNode(6);
	//root->left->right->right = new TreeNode(4);
	//root->left->left->left->left = new TreeNode(7);
	//root->left->left->left->right = new TreeNode(9);
	//root->left->right->right->left = new TreeNode(3);
	//root->left->right->right->right = new TreeNode(5);
	//root->left->left->left->right->left = new TreeNode(10);
	//root->left->left->left->right->right = new TreeNode(8);
	//root->left->right->right->left->left = new TreeNode(4);
	//root->left->right->right->left->right = new TreeNode(2);
	//root->left->left->left->right->left->left = new TreeNode(9);
	//root->left->left->left->right->left->right = new TreeNode(11);
	//root->left->right->right->left->left->left = new TreeNode(1);
	/*auto root = new TreeNode(1);
	root->left = new TreeNode(6);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(7);
	root->left->right = new TreeNode(5);
	root->left->left->left = new TreeNode(8);*/
	auto root = new TreeNode(-1);
	root->left = new TreeNode(0);
	root->right = new TreeNode(1);
	Codec codec;
	auto x = codec.serialize(root);
	cout << x << std::endl;
	/*string ss = "1 2 4 3 6 7 |4 2 1 6 3 7 ";*/
	auto xh = codec.deserialize(x);
	//codec.deserialize(codec.serialize(root));
	return 0;
}