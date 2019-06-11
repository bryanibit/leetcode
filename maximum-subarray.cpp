#include<vector>
#include <limits>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = std::numeric_limits<int>::min();
		int max = sum;
		for (auto i : nums) {
			
			if (sum < i && sum <0) {
				sum = i;
			}
			else {
				sum += i;
			}
			max = std::max({ max, sum });
		}
		return max;

	}
};
int main() {
	Solution s;
	vector<int> nums = { -2,1,-3,4,-1,2,1,-4,10,2,-5,4 };
	auto x = s.maxSubArray(nums);
	return 0;
}