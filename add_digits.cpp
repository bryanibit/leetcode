#include<iostream>
class Solution {
public:
	int addDigits(int num) {
		auto num_cp = num;
		int sum = 0;
		bool count = false;
		while (!count || sum / 10 > 0) {
			count = true;
			sum = 0;
			while (num_cp != 0) {
				sum += num_cp % 10;
				num_cp = num_cp / 10;
			}
			num_cp = sum;
		}
		return sum;
	}
};
int main() {
	Solution s;
	auto x = s.addDigits(38);
	return 0;
}