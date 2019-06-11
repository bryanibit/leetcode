#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;
class Solution {
public:
	int divide(int dividend, int divisor) {
		int dividend_flag = 1;
		int divisor_flag = 1;
		int count = 0;
		//dividend is negetive
		if (dividend > 0) {
			dividend = 0 - dividend;
			dividend_flag = 0;
		}
		//divisor is negative
		if (divisor > 0) {
			divisor = 0 - divisor;
			divisor_flag = 0;
		}
		int res;
		if (dividend == std::numeric_limits<int>::min() && divisor == -1) {
			if(divisor_flag == 0)
				return std::numeric_limits<int>::min();
			if (divisor_flag == 1)
				return std::numeric_limits<int>::max();
		}
 		res = dividend / divisor;
		if ((dividend_flag == 1 && divisor_flag == 1) || (dividend_flag == 0 && divisor_flag == 0)) {
			if (res > 0)
				res = res;
			else
				res = 0 - res;
		}
		if ((dividend_flag == 0 && divisor_flag == 1) || (dividend_flag == 1 && divisor_flag == 0)) {
			if (res > 0)
				res = 0 - res;
			else
				res = res;
		}
		return res;
	}
};
int main() {
	Solution s;
	auto dividend = -214748368;
	auto divisor = -2147483648;
	/*try { int h = dividend / divisor; }
	catch (std::exception& e) {
		std::cout << "error\n";
	}
	std::cout << "7/(-3): " << 7 / (-3) << std::endl;
	std::cout << "-7/(-3): " << -7 / (-3) << std::endl;
	std::cout << "108/3: " << 108/3 << std::endl;*/
	auto x = s.divide(dividend, divisor);
	return 0;
}