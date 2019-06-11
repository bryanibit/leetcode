#include <initializer_list>
#include <type_traits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.size() <2)
		{
			std::vector<vector<int>> special;
			special.push_back(nums);
			return special;
		}
		if (nums.size() == 2)
		{
			std::vector<vector<int>> special;
			special.emplace_back(std::initializer_list<int> {nums.at(0), nums.at(1)});
			// te = {nums.at(1), nums.at(0)};
			special.emplace_back(std::initializer_list<int> {nums.at(1), nums.at(0)});
			return special;
		}
		sort(nums.begin(), nums.end());
		std::vector<vector<int>> result;
		// auto te = {nums.at(0), nums.at(1)};
		result.emplace_back(std::initializer_list<int> {nums.at(0), nums.at(1)});
		// te = {nums.at(1), nums.at(0)};
		result.emplace_back(std::initializer_list<int> {nums.at(1), nums.at(0)});
		std::vector<vector<int>> temp;
		for (int i = 2; i < nums.size(); ++i)
		{
			result  = addNewElement(nums.at(i), result);
		}
		return result;
	}

	vector<vector<int>> addNewElement(int n, std::vector<vector<int>>& result)
	{
		std::vector<vector<int>> result_copy(result);
		std::vector<vector<int>> temp;
		for (int i = 0; i < result_copy.size(); ++i)
		{
			for (int j = 0; j <= result_copy.at(i).size(); ++j)
			{
				result_copy[i].insert(result_copy[i].begin() + j, n);
				temp.push_back(result_copy[i]);
				result_copy = result;
			}
		}
		return temp;
	}
};
int main() {
	Solution s;
	std::vector<int> nums = { 1,2,3,4};
	s.permute(nums);
}