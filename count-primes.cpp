#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	int countPrimes(int n) {
		int count = 0;
		if (n > 2)
			count = 1;
		else
			count = 0;
		for (int k = 3; k < n; k = k + 2) {
			bool flag = true;
			for (int j = 2; j <= sqrt(k); j++) {
				if (k % j == 0) {
					flag = false;
					break;
				}
			}
			if (flag)
				count++;
		}
		return count;
	}
};
int main() {
	Solution s;
	auto x = s.countPrimes(2);
	return 0;
}