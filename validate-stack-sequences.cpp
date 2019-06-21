#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
	stack<int> stack;
	int j = 0;
	int i = 0;
		while(i < pushed.size() && j < popped.size()) {
			stack.push(pushed.at(i));
			while(j < popped.size() && !stack.empty() && popped[j] == stack.top()) {
				stack.pop();
				++j;
			}
			++i;
		}
		if (stack.empty())
			return true;
		else
			return false;
}
};
int main() {
Solution s;
vector<int> pushed = { 1,0 };
vector<int> poped = { 1,0 };
auto x = s.validateStackSequences(pushed, poped);
return 0;
}