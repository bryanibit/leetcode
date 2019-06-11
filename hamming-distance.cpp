#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	int hammingDistance(int x, int y) {
		int count = 0;
		
		while (x || y) {
			if (x % 2 != y % 2)
				count++;
			x = x / 2;
			y = y / 2;
		}
		return count;
	}
};
int main() {
	Solution s;
	auto x = s.hammingDistance(1, 4);
	return 0;
}