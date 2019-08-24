#include <vector>
using namespace std;
class Solution {
public:
	void rotateOnce(vector<int>& nums) {
		auto len = nums.size();
		nums.insert(nums.begin(), nums.back());
		nums.resize(len);
	}
	void rotate(vector<int>& nums, int k) {
		if (nums.empty() || nums.size() == 1)
			return;
		auto len = nums.size();
		for (int i = 0; i < (k % len); ++i) {
			rotateOnce(nums);
		}
	}
};
int main() {
	Solution s;
	vector<int> nums = { 1,2,3,4,5,6,7 };
	int k = 2;
	s.rotate(nums, k);
	return 0;
}