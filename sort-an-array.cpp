#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
	void quickSort(vector<int> &nums, int left, int right) {
		int i = left;
		int j = right;
		auto base_num = nums.at(left);
		while (i < j) {
			while (i < j && nums.at(j) >= base_num)
				--j;
			while (i < j && nums.at(i) <= base_num)
				++i;
			int temp = nums.at(i);
			nums.at(i) = nums.at(j);
			nums.at(j) = temp;
		}
		nums.at(left) = nums.at(i);
		nums.at(i) = base_num;
		if (i > left)
			quickSort(nums, left, i - 1);
		if(i+1<= right)
			quickSort(nums, i + 1, right);
	}
	vector<int> sortArray(vector<int>& nums) {
		quickSort(nums, 0, nums.size() - 1);
		return nums;
	}
};
int main() {
	Solution s;
	vector<int> nums = {3,2,4,9,7,5};
	auto x = s.sortArray(nums);
	return 0;
}