#include <vector>
#include <string>
#include<algorithm>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		auto n = s.size();
		vector<vector<bool>> res(n, vector<bool>(n, false));
		string palindrome;
		int long_size = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i; j >= 0; --j) {
				if (i == j) {
					res[i][j] = true;
					if (j - i + 1 > long_size) {
						long_size = 1;
						palindrome = s.substr(j, 1);
					}
					continue;
				}
				if (s[i] == s[j] && i - j == 1)
					res[i][j] = true;
				else if (s[i] == s[j] && i - j > 1)
					res[i][j] = res[i - 1][j + 1];
				else if (s[i] != s[j])
					res[i][j] = false;

				if (res[i][j] && i - j + 1 > long_size) {
					palindrome = s.substr(j, i - j + 1);
					long_size = i - j + 1;
				}
				
			}
		}
		return palindrome;
	}
};
int main() {
	Solution s;
	string ss = "ac";
	s.longestPalindrome(ss);
	return 0;
}