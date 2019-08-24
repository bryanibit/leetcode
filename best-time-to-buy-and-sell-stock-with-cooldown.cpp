#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2)
			return 0;
		if (prices.size() == 2)
			return prices[1] - prices[0] > 0 ? (prices[1] - prices[0]) : 0;
		if (prices.size() == 3) {
			return std::max({ prices[2] - prices[1], prices[2] - prices[0], prices[1] - prices[0], 0 });
		}
		vector<int> diff;
		for (int i = 1; i < prices.size(); ++i)
			diff.push_back(prices.at(i) - prices.at(i - 1));
		int sum = 0;
		int j = 0;
		while(j < diff.size() - 2) {
			if (diff[j] > 0 && diff[j + 1] < 0 && diff[j + 2] > 0) {
				if (diff[j] > diff[j + 2])
					sum += diff[j];
				else
					sum += diff[j + 2];
				++j;
			}
			else if (diff[j] > 0 && diff[j + 1] < 0 && diff[j + 2] < 0) {
				sum += diff[j];
				int k = j + 1;
				while (k < diff.size()) {
					if (diff[k] > 0) {
						sum += diff[k];
						j = k + 1;
						break;
					}
					++k;
				}
				if (k = diff.size())
					return sum;
			}
			else if (diff[j] > 0) {
				sum += diff[j];
				++j;
			}
			else if (diff[j] < 0)
				++j;
		}
		return sum;
	}
};
int main() {
	Solution s;
	vector<int> prices = {6,1,3,2,4,7}; ///6
	auto x = s.maxProfit(prices);
	return 0;
}