#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
	int longestValidParentheses(string s) {
		vector<int> temp(s.size(), 0);
		int max_val = -1;
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] == ')') {
				if (s[i - 1] == '(') {
					temp[i] = ((i - 2 >= 0) ? temp[i - 2] : 0) + 2;
					max_val = std::max(temp[i], max_val);
				}
				else if (i - temp[i - 1] - 1 >= 0 && s[i - temp[i - 1] - 1] == '(') {
					temp[i] = temp[i - 1] + 2 + ((i - temp[i - 1] - 2 > 0) ? temp[i - temp[i - 1] - 2] : 0);
					max_val = std::max(temp[i], max_val);
				}
			}
		}
		return max_val;
	}
};
int main() {
	Solution s;
	string ss = "())())";
	/*string st = "020002"*/
	auto x = s.longestValidParentheses(ss);
	return 0;
}