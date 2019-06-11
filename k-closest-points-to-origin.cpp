#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;
class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		vector<int> distances(points.size(), 0);
		for (int i = 0; i < points.size(); ++i) {
			auto dis = points.at(i).at(0) * points.at(i).at(0) + points.at(i).at(1) * points.at(i).at(1);
			distances.at(i) = dis;
		}
		//find the closest distance
		vector<vector<int>> res;
		for (int j = 0; j < K; ++j) {
			auto iter = std::min_element(distances.begin(), distances.end());
			auto loc = iter - distances.begin();
			*iter = std::numeric_limits<int>::max();
			res.push_back(points.at(loc));
		}
		return res;
	}
};
int main() {
	Solution s;
	vector<vector<int>> points = { {3,3}, {5, -1}, {-2, 4} };
	int k = 2;
	auto x = s.kClosest(points, k);
	return 0;
}