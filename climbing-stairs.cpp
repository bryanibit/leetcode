#include <vector>
using namespace std;
class Solution {
public:
	int climbStairs(int n) {
		vector<int> res(n+1, 0);
		res[0] = 1;
		res[1] = 1;
		for (int i = 2; i <= n; ++i) {
			res[i] = res[i - 1] + res[i - 2];
		}
		return res.at(n);
	}
};
int main() {
	Solution s;
	auto x = s.climbStairs(4);
	return 0;
}