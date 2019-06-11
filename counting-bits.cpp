#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> res;
		for (int i = 0; i <= num; ++i) {
			int fac = 1; //商
			int extra = 0; // 余数
			int count = 0;
			int divident = i; //被除数，除数是2

			while (fac > 0) {
				fac = divident / 2;
				extra = divident % 2;
				if (extra == 1)
					count++;
				divident = fac;
			}
			res.push_back(count);
		}
		return res;
	}
};
int main() {
	/*int a = 8;
	auto b = a >> 1;
	auto c = b >> 1;
	cout << b << "  " << c << endl;*/
	Solution s;
	auto x = s.countBits(9);
	return 0;
}