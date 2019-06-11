#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int acquire(vector<int> heights, int i) {
		int j = i;
		int k = i;
		auto left = -1;
		auto right = -1;
		while (j >= 0) {
			if (heights.at(j) < heights.at(i)) {
				break;
			}
			else{
				--j;
			}
		}
		left = j + 1;
		while (k < heights.size()) {
			if (heights.at(k) < heights.at(i)) {
				break;
			}
			else {
				++k;
			}
		}
		right = k - 1;
		return heights[i] * (right - left + 1);
	}
	int largestRectangleArea(vector<int>& heights) {
		int len = heights.size();
		if (len == 0) return 0;
		if (*std::max_element(heights.begin(), heights.end()) == *std::min_element(heights.begin(), heights.end()))
		{
			return *std::max_element(heights.begin(), heights.end())*len;
		}
		auto max_val = -1;
		for (int i = 0; i < len; ++i) {
			/*auto a = acquire(heights, i);
			if (max_val < a)
				max_val = a;*/
			max_val = std::max(acquire(heights, i), max_val);
		}
		return max_val;
	}
};
int main() {
	Solution s;
	vector<int> heights = { };
	auto x = s.largestRectangleArea(heights);
	return 0;
}