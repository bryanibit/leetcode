#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
	int scoreOfParentheses(string S) {
		stack<int> stack;
		stack.push(0);
		for (int i = 0; i < S.size(); ++i) {
			if (S[i] == '(')
				stack.push(0);
			else {
				auto tem = stack.top();
				stack.pop();
				if (tem == 0) {
					stack.top() += 1;
				}
				else {
					stack.top() += tem * 2;
				}
			}
		}
		return stack.top();
	}
};
int main() {
	Solution s;
	string S = "(())";
	auto x = s.scoreOfParentheses(S);
	return 0;
}