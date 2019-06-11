#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maxChunksToSorted(vector<int>& arr) {
		int premax = 0;
		int count = 0;
		for (int i = 0; i < arr.size(); ++i) {
			// calculate current max val
			premax = std::max(premax, arr[i]);
			if (i == premax) {
				count++;
				//premax++;
			}
		}
		return count;
	}
};
int main() {
	Solution s;
	vector<int> arr = { 1,4,0,2,3,5 };//2
	auto x = s.maxChunksToSorted(arr);
	return 0;
}