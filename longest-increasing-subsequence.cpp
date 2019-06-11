#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		nums.insert(nums.begin(), std::numeric_limits<int>::min());
		int n = nums.size();
		vector<vector<int>> res(n+1, vector<int>(n+1, 0));
		
		for (int j = n - 1; j > 0; --j) {
			for (int i = 0; i < j; ++i) {
				int skip = res[i][j + 1];
				int keep = res[j][j + 1] + 1;
				if (nums.at(i) >= nums.at(j))
					res[i][j] = skip;
				else
					res[i][j] = std::max({ skip, keep });
			}
		}
		return res[0][1];
	}
};
int main(){
	Solution s;
	vector<int> nums = { 2,2 };
	auto x = s.lengthOfLIS(nums);
	return 0;
}