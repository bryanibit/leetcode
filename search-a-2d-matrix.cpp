#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty())
			return false;
		else if (matrix[0].empty())
			return false;
		int row = matrix.size();
		int col = matrix[0].size();
		int i = 0;
		while (i < row) {
			if (matrix[i][0] == target)
				return true;
			else if (matrix[i][0] < target) {
				++i;
				continue;
			}
			else {
				if (i == 0)
					return false;
				auto iter = std::find(matrix[i - 1].begin(), matrix[i - 1].end(), target);
				if (iter != matrix[i-1].end())
					return true;
				else
					return false;
			}
			++i;
		}
		auto ite = std::find(matrix[i - 1].begin(), matrix[i - 1].end(), target);
		if (ite != matrix[i - 1].end())
			return true;
		else
			return false;
	}
};
int main() {
	Solution s;
	vector<vector<int>> matrix = { {1} };
	/*vector<vector<int>> matrix = {
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 50}
	};*/
	auto x = s.searchMatrix(matrix, 1);
	return 0;
}