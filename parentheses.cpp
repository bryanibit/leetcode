#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	void removeDuplicate(std::vector<string>& s)
	{
		sort(s.begin(), s.end());
		for (int i = 1; i < s.size(); ++i)
		{
			if (s[i - 1] == s[i])
			{
				s.erase(s.begin()+i-1);
				--i;
			}
		}
	}
	vector<string> addParent(string s)
	{
		std::vector<string> result;
		std::string s_c(s);
		for (int j = 0; j <= s.size(); ++j)
		{
			s.insert(j, "()");
			result.push_back(s);
			s = s_c;
		}
		removeDuplicate(result);
		return result;
	}
	vector<string> generateParenthesis(int n) {
		vector<string> temp;
		temp.push_back("()");
		if (n == 1)
			return temp;
		for (int i = 0; i< n-1; ++i)
		{
			vector<string> result;
			for (int k = 0; k < temp.size(); ++k)
			{
				auto result_for_eachString = addParent(temp.at(k));
				for (auto str : result_for_eachString)
				{
					result.push_back(str);
				}
			}
			removeDuplicate(result);
			temp = result;
		}
		removeDuplicate(temp);
		return temp;
	}
};
int main() {
	Solution s;
	auto x = s.generateParenthesis(6);
	for (auto i : x)
	{
		std::cout << i << "\n";
	}
	return 0;
}