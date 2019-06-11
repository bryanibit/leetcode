#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
//class Solution {
//public:
//	int maxProfit(vector<int> &prices) {
//		auto profit1 = 0;
//		auto profit2 = 0;
//		auto cost1 = std::numeric_limits<int>::max();
//		auto cost2 = std::numeric_limits<int>::max();
//		for (auto i : prices) {
//			cost1 = std::min(cost1, i);
//			profit1 = std::max(profit1, i - cost1);
//			cost2 = std::min(cost2, i - profit1);
//			profit2 = std::max(profit2, i - cost2);
//		}
//		return profit2;
//	}
//};
class Solution {
public:
	int maxProfit(vector<int> &prices) {
			auto profit1 = 0;
			auto profit2 = 0;
			auto hold1 = std::numeric_limits<int>::min();
			auto hold2 = std::numeric_limits<int>::min();
			for (auto i : prices) {
				hold1 = std::max(hold1, -i);
				profit1 = std::max(profit1, hold1 + i);
				hold2 = std::max(hold2, profit1 - i);
				profit2 = std::max(profit2, hold2 + i);
			}
			return profit2;

	}
};
int main() {
	Solution s;
	vector<int> prices = { 3,3,5,0,0,3,1,4 };
	auto x = s.maxProfit(prices);
	return 0;
}