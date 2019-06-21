#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		vector<int> res(T.size(), 0);
		stack<int> stack;

		stack.push(T.size() - 1);
		res.back() = 0;

		for (int i = T.size() - 2; i >= 0; --i) {
			while (!stack.empty() && T[stack.top()] <= T[i]) {
				stack.pop();
			}
			if (stack.empty()) {
				res.at(i) = 0;
			}
			else {
				res.at(i) = stack.top() - i;
			}
			stack.push(i);
		}
		return res;
	}
};
int main() {
	Solution s;
	vector<int> T = { 73,74,74,74,75,71,69,72,76,73 };
	auto x = s.dailyTemperatures(T);
	return 0;
}