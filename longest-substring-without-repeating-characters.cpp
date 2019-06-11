#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		std::map<char, int> map_nums;
		string str_nums = "";
		string str_max = "";
		for (int i = 0; i < s.size(); ++i) {
			if (map_nums.count(s.at(i))) {
				int index = map_nums.find(s.at(i))->second;
				//delete iter before
				map_nums.clear();
				for (int j = index + 1; j < i; ++j) {
					map_nums.emplace(s.at(j), j);
				}
				str_nums = "";
				str_nums.assign(s.begin() + index + 1, s.begin() + i);
				
				/*str_nums = "";*/
			}
			str_nums += s.at(i);
			map_nums.emplace(s.at(i), i);
			if (str_max.length() < str_nums.length()) {
				str_max = str_nums;
			}
		}
		return str_max.length();
	}
};
int main() {
	Solution s;
	string str1 = "pwwkew";//kew
	string str2 = "pwawkew";//
	auto x = s.lengthOfLongestSubstring(str1);
	return x;
}