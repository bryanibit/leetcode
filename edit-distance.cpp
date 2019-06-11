#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
	/*int editDistance(string word1, string word2, int i, int j, vector<vector<int>> &res) {
		if (i == 0)
			res[0][j] = j;
		else if (j == 0)
			res[i][0] = i;
		else{
			auto del = editDistance(word1, word2, i - 1, j, res) + 1;
			auto ins = editDistance(word1, word2, i, j - 1, res) + 1;
			int rep;
			if (word1.at(i) == word2.at(j)) {
				rep = editDistance(word1, word2, i - 1, j - 1, res);
			}
			else {
				rep = editDistance(word1, word2, i - 1, j - 1, res) + 1;
			}
			res[i][j] = std::min({ del, ins, rep });
		}
	}*/
	int minDistance(string word1, string word2) {
		int a = word1.size();
		int b = word2.size();
		if (a < b) {
			word1.swap(word2);
		}
		int m = word1.size();
		int n = word2.size();
		vector<vector<int>> res(m + 1, vector<int>(n + 1, -1));
		res.at(0).at(0) = 0;
		for (int i = 1; i <= m; ++i) {
			res[i][0] = i;
			for (int j = 1; j <= n; ++j) {
				res[0][j] = j;
				int del = res[i - 1][j] + 1;
				int ins = res[i][j - 1] + 1;
				int rep = word1.at(i-1) == word2[j-1] ? res[i - 1][j - 1] : res[i - 1][j - 1] + 1;
				res[i][j] = std::min({ del, ins, rep });
			}
		}
		return res[m][n];

	}
};
int main() {
	Solution s;
	string s1 = "";
	string s2 = "a";
	auto x = s.minDistance(s1, s2);
	return 0;
}