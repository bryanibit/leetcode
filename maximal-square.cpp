#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.size() == 0) return 0;
		vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size(), 0));
		auto res = 0;
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix.at(0).size(); ++j) {
				if (i == 0 || j == 0) {
					dp[i][j] = matrix.at(i).at(j) - 48;
				}
				else {
					if(matrix[i][j] == '1')
						dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
				}
				res = max(res, dp[i][j]);
			}
		}
		return res*res;
	}
};
int main() {
	Solution s;
	vector<vector<char>> matrix = { {'1', '1', '1', '0', '1' },{ '1', '1', '1', '0', '1' },{ '0', '0', '0', '1', '1' },{ '1', '1', '1', '1', '1' } };
	auto x = s.maximalSquare(matrix);
	return 0;
}