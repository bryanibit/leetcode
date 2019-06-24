#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		stack<char> stack;
		vector<int> count_right;
		for (int i = 0; i < s.size(); ++i) {
			if (s.at(i) != '(' && s.at(i) != ')')
				continue;
			if (s.at(i) == '(')
				stack.push('(');
			else {
				if (!stack.empty() && stack.top() == '(')
					stack.pop();
				else {
					count_right.push_back(i);
				}
			}
		}
		auto count_left = stack.size();
		for (int i = 0; i <= count_right.back(); ++i) {
			if(s.at(i) == ')')
		}
	}
};
int main() {
	Solution s;
	string ss = "()())()";
	auto x = s.removeInvalidParentheses(ss);
	return 0;
}