#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxCoins(vector<int>& nums) {
		int n = nums.size();
		nums.insert(nums.begin(), 1);
		nums.insert(nums.end(), 1);
		vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
		for (int len = 1; len <= n; ++len) {
			for (int start = 1; start <= n + 1 - len; ++start) {
				for (int k = start; k < start + len; ++k) {
					dp[start][start + len - 1] = max(dp[start][start + len - 1],
						nums[start - 1] * nums[k] * nums[start + len] + dp[start][k - 1] + dp[k + 1][start + len - 1]);
				}
			}
		}
		return dp[1][n];
	}
};
int main() {
	Solution s;
	vector<int> nums = { 3,1,5,8 };
	auto x = s.maxCoins(nums);
	return 0;
}