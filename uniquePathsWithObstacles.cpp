#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>> obstacleGrid_) {
		vector<vector<long>> obstacleGrid(obstacleGrid_.size(), vector<long>(obstacleGrid_.at(0).size(), 0));
		for (int i = 0; i < obstacleGrid.size(); ++i) {
			for (int j = 0; j < obstacleGrid.at(0).size(); ++j) {
				obstacleGrid[i][j] = obstacleGrid_[i][j];
			}
		}

		if (obstacleGrid.empty()) return 0;
		if (obstacleGrid[0][0] == 1)
			return 0;
		else
			obstacleGrid[0][0] = 1;
		for (int k = 1; k < obstacleGrid.size(); ++k) {
			if (obstacleGrid[k][0] == 0) 
				obstacleGrid[k][0] = 1;
			else
			{
				for (int x = k; x < obstacleGrid.size(); ++x)
				{
					obstacleGrid[x][0] = 0;
				}
				break;
			}
		}
		for (int k = 1; k < obstacleGrid.at(0).size(); ++k) {
			if (obstacleGrid[0][k] == 0) obstacleGrid[0][k] = 1;
			else {
				for(int x = k; x < obstacleGrid.at(0).size(); ++x)
					obstacleGrid[0][x] = 0;
				break;
			}
		}
		for (int i = 1; i < obstacleGrid.size(); ++i) {
			for (int j = 1; j < obstacleGrid.at(0).size(); ++j)
			{
				if (obstacleGrid[i][j] == 1) {
					obstacleGrid[i][j] = 0;
				}
				else {
					obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
				}
			}
		}
		return obstacleGrid.back().back();
	}
};
int main() {
	Solution s;
	vector<vector<int>> grid = { { { 0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },{ 0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0 },{ 1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1 },{ 0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0 },{ 0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0 },{ 1,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0 },{ 0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0 },{ 0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0 },{ 0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0 },{ 1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1 },{ 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0 },{ 0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0 },{ 0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,1 },{ 1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0 },{ 0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1,1,0,1,0,0,0,0,1,1 },{ 0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1 },{ 1,1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1 },{ 0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0 } } };
	auto x = s.uniquePathsWithObstacles(grid);
	return 0;
}