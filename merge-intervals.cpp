#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end());
		for (int i = 0; i < intervals.size(); ++i) {
			for (int j = i + 1; j < intervals.size(); ++j) {
				if (intervals.at(i).at(1) >= intervals.at(j).at(0)) {
					if (intervals.at(i).at(1) < intervals.at(j).at(1)) {
						intervals.at(i).at(1) = intervals.at(j).at(1);
						intervals.erase(intervals.begin() + j);
					}
					else {
						intervals.erase(intervals.begin() + j);
					}
					j--;
				}
			}
		}
		return intervals;
	}
};
int main() {
	Solution s;
	//vector<vector<int>> intervals = { {1,3},{2,6},{8,10},{15,18} };
	vector<vector<int>> intervals = { { 1,4 },{ 0,2 }, {3,5} };
	auto x = s.merge(intervals);
	return 0;
}