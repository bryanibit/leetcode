#include <iostream>
#include <queue>
#include <limits>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		//int flag = 0;
		//if (x < 0) {
		//	flag = 1;
		//	//x = 0 - x;
		//}
		/*std::cout << 5 % 10 << std::endl;
		std::cout << 5 / 10 << std::endl;*/
		queue<int> st;
		while (x != 0) {
			st.push(x % 10);
			x = x / 10;
		}
		int sum = 0;
		while (!st.empty()) {
			if ((sum > std::numeric_limits<int>::max() / 10 && sum > 0) || (sum < std::numeric_limits<int>::min() / 10 && sum < 0))
				return 0;
			sum = sum * 10 + st.front();
			st.pop();
		}
		/*if (flag == 1)
			return sum*(-1);
		else*/
		return sum;
	}
};
int main() {
	Solution s;
	std::cout << std::numeric_limits<int>::max() << std::endl;
	auto x = s.reverse(-2147483648);
	return 0;
}