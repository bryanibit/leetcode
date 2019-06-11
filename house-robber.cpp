#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
class Solution {
public:
	int rob(vector<int>& nums) {
		//rob(i) = max(rob(i-1),rob(i-2)+nums(i))
		auto a = 0;
		auto b = 0;
		for (int i = 0; i < nums.size(); ++i) {
		/*auto a = nums.at(1);
		auto b = nums.at(0);
		for(int i = 2; i < nums.size(); ++i){*/
			int temp = b;
			b = a;
			a = std::max(a, temp + nums.at(i));
		}
		return a;
	}
};
int main() {
	Solution s;
	vector<int> num = {2,1,1,2};
	auto x = s.rob(num);
	return 0;
}