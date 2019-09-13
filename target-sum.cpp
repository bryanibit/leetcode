#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int sum = 0;
		for_each(nums.begin(), nums.end(), [&sum](auto x) {
			sum += x;
		});
		int offset = sum;
		vector<vector<int>> res(nums.size() + 1, vector<int>(2 * sum + 3, 0));
		res[0][offset] = 1;
		for (int i = 0; i < nums.size(); ++i) {
			// avoid res overflow, then j starts from nums[i].
			// in fact, j should start from 0 but nonsense
			for (int j = nums[i]; j < sum*2+1; ++j) {
				if (res[i][j] != 0) {
					res[i + 1][j + nums[i]] += res[i][j];
					res[i + 1][j - nums[i]] += res[i][j];
				}
			}
		}
		return res[nums.size()][S + offset];
	}
};
int main() {
	Solution s;
	auto nums = vector<int>{ 42,24,30,14,38,27,12,29,43,42,5,18,0,1,12,44,45,50,21,47 };
	auto S = 45;
	auto x = s.findTargetSumWays(nums, S);
	return 0;
}