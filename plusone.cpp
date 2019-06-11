#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		if (digits.empty())
		{
			return digits;
		}
		int i = 0;
		for (i = digits.size() - 1; i >= 0; --i)
		{
			if (digits.at(i) + 1 > 9)
			{
				digits.at(i) = 0;
				continue;
			}
			else
			{
				digits.at(i) += 1;
				break;
			}
		}
		if (i == -1)
		{
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};
int main() {
	Solution s;
	vector<int> num = { 9 };
	s.plusOne(num);
	for (auto i : num)
	{
		std::cout << i << ", ";
	}
	std::cout << std::endl;
	return 0;
}