#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.size() == 1 || nums.size() == 0)
			return true;
		vector<int> zeros;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums.at(i) == 0)
				zeros.push_back(i);
		}
		int count = 0;
		for (int i = 0; i < zeros.size(); ++i) {
			int start =zeros.at(i);
			int j = 1;

			if (start == nums.size() - 1) {
				while (start - j >= 0) {
					if (nums.at(start - j) >= j) {
						count++;
						break;
					}
					j++;
				}
			}
			else {
				while (start - j >= 0) {
					if (nums.at(start - j) > j) {
						count++;
						break;
					}
					j++;
				}
			}
		}
		if (count == zeros.size())
			return true;
		else
			return false;
	}
};
int main() {
	Solution s;
	vector<int> nums = {2,0,0};
	auto x = s.canJump(nums);
	return 0;
}