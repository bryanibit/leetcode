#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> res(m+1, vector<int>(n+1, 1));
		for (int i = 2; i <= m; ++i) {
			for (int j = 2; j <= n; ++j)
			{
				res[i][j] = res[i - 1][j] + res[i][j - 1];
			}
		}
		return res[m][n];
	}
};
int main() {
	Solution s;
	int m = 7;
	int n = 3;
	auto x = s.uniquePaths(m, n);
	return 0;
}