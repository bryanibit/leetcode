#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;
class Solution {
public:
	int rob(vector<int>& nums) {
		auto a = 0;
		auto b = 0;
		auto resF = 0;
		auto resL = 0;
		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums.at(0);
		std::vector<int> delFirst(nums);
		delFirst[0] = 0;
		vector<int> delLast(nums);
		delLast.at(delLast.size() - 1) = 0;

		for (int i = 0; i < delFirst.size(); ++i) {
			int temp = b;
			b = a;
			a = std::max(a, temp + delFirst.at(i));
			}
		resF = a;
		a = 0;
		b = 0;
		for (int i = 0; i < delLast.size(); ++i) {
			int temp = b;
			b = a;
			a = std::max(a, temp + delLast.at(i));
		}
		resL = a;
		return resF > resL ? resF : resL;
		}
};
int main() {
	Solution s;
	vector<int> nums = { 1 };
	auto x = s.rob(nums);
	return 0;
}