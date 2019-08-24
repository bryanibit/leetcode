#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int min_price = std::numeric_limits<int>::max();
		int profit = 0;
		for (int i = 0; i < prices.size(); ++i) {
			if (prices.at(i) < min_price) {
				min_price = prices.at(i);
			}
			else if (prices.at(i) > min_price + fee) {
				profit += prices.at(i) - min_price - fee;
				min_price = prices.at(i) - fee;
			}
		}
		return profit;
	}
};
int main() {
	Solution s;
	vector<int> prices = { 1, 3, 4, 8, 4, 9 };
	int fee = 1;
	auto x = s.maxProfit(prices, fee);
	return 0;
}