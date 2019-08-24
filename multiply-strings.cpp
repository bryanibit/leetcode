#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
	string multiply(string num1, string num2) {
		vector<int> res(num1.size() + num2.size() + 1, 0);
		string rs = "";
		std::reverse(num1.begin(), num1.end());
		std::reverse(num2.begin(), num2.end());
		for (int i = 0; i < num1.size(); ++i) {
			auto n1 = stoi(string(1, num1.at(i)));
			for (int j = 0; j < num2.size(); ++j) {
				auto n2 = stoi(string(1, num2.at(j)));
				res[i+j] += n1*n2;
			}
		}
		bool flag = false;
		for_each(res.begin(), res.end(), [&flag](int n) {
			if (n != 0)
				flag = true;
		});
		if (!flag)
			return "0";
		for (int i = 0; i < res.size() - 1; ++i) {
			rs += to_string(res.at(i) % 10);
			res.at(i + 1) += res.at(i) / 10;
		}
		std::reverse(rs.begin(), rs.end());
		if (rs.size() > 0 && rs.at(0) == '0')
			rs = rs.substr(1);
		return rs;
	}
};
int main() {
	Solution s;
	string num1 = "52";
	string num2 = "60";
	auto x = s.multiply(num1, num2);
	return 0;
}