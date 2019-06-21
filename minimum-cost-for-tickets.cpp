#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
class Solution {
public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		//days.insert(days.begin(), 0);
		if (costs[0] < costs[1] / 7 || costs[1] / 7 < costs[2] / 30) {
			cout << "error\n";
			return -1;
		}
		vector<int> res(days.size() + 1, 0);
		for (int i = days.size()-1; i>= 0; --i) {
			int k = 0;
			int j = i;
			while (j < days.size()) {
				if (days[j] >= days[i] + 7) {
					k = j;
					break;
				}
				++j;
			}
			/*if (j == days.size()) {
				k = j - 1;
			}*/
			auto res7 = res[k] + costs[1];

			k = 0;
			j = i;
			while (j < days.size()) {
				if (days[j] >= days[i] + 30) {
					k = j;
					break;
				}
				++j;
			}
			/*if (j == days.size()) {
				k = j - 1;
			}*/

			auto res30 = res[k] + costs[2];
			res[i] = min({ res[i + 1] + costs[0], res7, res30 });

		}
		return res[0];
	}
};
int main() {
	Solution s;
	vector<int> days = { 1,2,3,4,6,8,9,10,13,14,16,17,19,21,24,26,27,28,29};
	//{ 1,4,6,7,8,20 }; 
	vector<int> costs = { 3,14,50 };
	auto x = s.mincostTickets(days, costs);
	return 0;
}