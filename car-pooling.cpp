#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
class Solution {
public:
	bool carPooling(vector<vector<int>>& trips, int capacity) {
		auto start_loc = std::numeric_limits<int>::max();
		auto end_loc = std::numeric_limits<int>::min();
		for (const auto &trip : trips) {
			if (trip.at(1) < start_loc)
				start_loc = trip.at(1);
			if (trip.at(2) > end_loc)
				end_loc = trip.at(2);
		}
		for (int i = start_loc; i <= end_loc; ++i) {
			int sum = 0;
			for (const auto &trip : trips) {
				if (i >= trip.at(1) && i < trip.at(2))
					sum += trip.at(0);
			}
			if (sum > capacity)
				return false;
		}
		return true;
	}
};
int main() {
	Solution s;
	vector<vector<int>> trips = { {7,5,6 }, {6, 7, 8},{10,1,6} };
	int capacity = 16;
	auto x = s.carPooling(trips, capacity);
	return 0;
}