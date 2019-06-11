#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		if (nums.size() < 2) return false;
		vector<int> sumvector;
		for (int x = 1; x < nums.size(); ++x) {
			int sumeach = 0;
			for_each(nums.begin(), nums.begin() + x, [&](int n) {sumeach += n; });
			sumvector.push_back(sumeach);
		}
		sumvector.push_back(sumvector.back() + nums.back());
		for (int j = 2; j <= nums.size(); ++j) {
			for (int i = j-1; i < nums.size(); ++i) {
				//int sumeach = 0;
				//for_each(nums.begin() + i - (j - 1), nums.begin() + i + 1, [&](int n) {sumeach += n; });
				int sumeach = sumvector.at(i) - sumvector.at(i - (j - 1)) + nums.at(i - (j - 1));
				if (sumeach == 0) return true;
				if (k == 0) {
					if (sumeach == 0)
						return true;
				}
				else {
					if (sumeach % abs(k) == 0)
						return true;
				}
			}
		}
		return false;
	}
};
int main() {
	Solution s;
	std::cout << 5 % 6 << std::endl;
	vector<int> nums{ 0 };
	int k = 0;
	auto x = s.checkSubarraySum(nums, k);
	return 0;
}