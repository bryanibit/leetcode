#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
	bool canCross(vector<int>& stones) {
		vector<vector<int>> res(stones.back()+1, vector<int>(stones.back()+3, 0));
		res[0][1] = 1;
		res[1][0] = 1;
		res[1][1] = 1;
		res[1][2] = 1;//first i is location not stone index
		int k = 1;
		for (int i = 1; i < stones.size(); ++i) {
			res[stones.at(i)][k] = res[stones.at(i) - k][k - 1] || res[stones.at(i) - k][k]
				|| res[stones.at(i) - k][k + 1];
		}
		return true;
	}
};
int main() {
	Solution s;
	vector<int> stones = { 0,1,3,5,6,8,12,17 };
	auto x = s.canCross(stones);
	return 0;
}