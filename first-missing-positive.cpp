#include<iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if (nums.empty()) return 1;
		//auto max = std::max_element(std::begin(nums), std::end(nums));
		//std::vector<int> large(static_cast<long long int>(*max)+1, 0);
		std::vector<int> large(nums.size()+1, 0);
		for (int i = 0; i< nums.size(); ++i)
		{
			if((nums.at(i) > 0)&&(nums.at(i) < large.size()))
				large.at(nums.at(i)) = 1;
		}
		int result = 0;
		int count = 0;
		for (int j = 1; j< large.size(); ++j)
		{
			
			if (large.at(j) == 0)
			{
				count = 1;
				result = j;
				break;
			}

		}
		if ((count == 0) && (result == 0))
			return nums.size()+1;
		else
			return result;

	}
};
int main()
{
	/*std::vector<int> a;
	std::cout <<std::numeric_limits<unsigned int>::max() << std::endl;
	std::cout << a.max_size() << std::endl;*/
	Solution s;
	std::vector<int> nums = {1};
	auto x = s.firstMissingPositive(nums);
	std::cout << x << std::endl;
	return 0;
}