#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
	int minAddToMakeValid(string S) {
		stack<int> st;
		for (int i = 0; i < S.size(); ++i) {
			if (S.at(i) == '(')
				st.push(S.at(i));
			else {
				if (!st.empty() && st.top() == '(')
					st.pop();
				else
					st.push(S.at(i));
			}
		}
		return st.size();
	}
};
int main() {
	Solution s;
	string S = "()";
	auto x = s.minAddToMakeValid(S);
	return 0;
}