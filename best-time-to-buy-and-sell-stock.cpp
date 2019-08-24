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
	int maxProfit_1(vector<int>& prices) {
		int cur_max = 0;
		int global_max = 0;
		vector<int> diff;
		for (int i = 1; i < prices.size(); ++i) {
			diff.push_back(prices.at(i) - prices.at(i - 1));
		}
		for (int j = 0; j < diff.size(); ++j) {
			cur_max = diff.at(j) > cur_max + diff.at(j) ? diff.at(j) : cur_max + diff.at(j);
			global_max = max(global_max, cur_max);
		}
		return global_max;
	}
};
int main() {
	Solution s;
	vector<int> v{ 1, 3, 2, 8, 4, 9 };
	auto x = s.maxProfit_1(v);
	return 0;
}