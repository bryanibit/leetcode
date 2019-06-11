#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int max_val = std::numeric_limits<int>::min();
		int min_val = std::numeric_limits<int>::max();
		if (prices.size() == 0) return 0;
		for (int i = 0; i < prices.size(); ++i) {
			if (prices.at(i) < min_val)
				min_val = prices.at(i);
			max_val = std::max(max_val, prices.at(i) - min_val);
		}
		return max_val;
	}
};
int main() {
	Solution s;
	//vector<int> v = { 7,1,5,3,6,4 };
	vector<int> v{};
	auto x = s.maxProfit(v);
	return 0;
}