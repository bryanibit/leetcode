#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
	string multiply(string num1, string num2) {
		int sum = 0;
		string res = "";
		for (int i = num1.size() - 1; i >= 0; --i) {
			//auto n1 = stoi(string(1,num1.at(i))) * pow(10, num1.size() -1 - i);
			auto n1 = stoi(string(1, num1.at(i)));
			for (int j = num2.size() - 1; j >= 0; --j) {
				auto n2 = stoi(string(1, num2.at(j))) * pow(10,num2.size() - 1 - j);
				sum += n1*n2;
			}
			res += to_string(sum % 10);
			sum = sum / 10;
		}
		while (sum != 0) {
			res += std::to_string(sum % 10);
			sum = sum / 10;
		}
		std::reverse(res.begin(), res.end());
		if (res.front() == '0')
			return "0";
		else
			return res;
	}
};
int main() {
	Solution s;
	string num1 = "123";
	string num2 = "456";
	auto x = s.multiply(num1, num2);
	return 0;
}