#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
	int nthUglyNumber(int n) {
		int i = 0;
		int j = 0;
		int k = 0;
		vector<int> res{ 1 };
		//std::cout << res.size() << std::endl;
		while (res.size() < n) {
			auto x = std::min({ res.at(i)*2, res.at(j)*3 , res.at(k)*5 });

			if (x == res[i]*2) i = i + 1;
			if (x == res[j]*3) j = j + 1;
			if (x == res[k]*5) k = k + 1;
			//std::cout << x << std::endl;
			res.push_back(x);
		}
		return res.back();
	}
};
int main() {
	Solution s;
	auto x = s.nthUglyNumber(10);
	return 0;
}