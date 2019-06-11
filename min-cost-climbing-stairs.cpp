#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		cost.insert(cost.begin(), 0);
		cost.insert(cost.end(), 0);
		vector<int> allCost(cost.size(), 0);
		allCost.at(0) = 0;
		allCost.at(1) = cost.at(1);
		for (int i = 2; i < cost.size(); ++i) {
			allCost[i] = min(allCost[i - 1] + cost.at(i), allCost[i - 2] + cost.at(i));
		}
		return allCost[cost.size()-1];
	}
};
int main(){
	Solution s;
	vector<int> cost = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
	auto x = s.minCostClimbingStairs(cost);
	return 0;
}