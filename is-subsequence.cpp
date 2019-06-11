#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <string>
using namespace std;
class Solution {
public:
	bool isSubsequence(string s, string t) {
		int i = 0;
		int j = 0;
		while (i < s.size() && j < t.size()) {
			if (s[i] == t[j]) {
				i++;
				j++;
			}
			else
				++j;
		}
		return i == s.size();
	}
};
int main() {
	Solution solution;
	string s = "axc";//short
	string t = "ahbgdc";
	auto x = solution.isSubsequence(s, t);
	return 0;
}