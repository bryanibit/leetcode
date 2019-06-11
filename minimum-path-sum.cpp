#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <limits>
using namespace std;
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int row = grid.size();
		int col = grid[0].size();
		vector<int> line_dist(grid[0].size(), std::numeric_limits<int>::max());
		vector<int> line(grid[0].size(), 0);
		std::vector<vector<int>> dist(grid.size(), line_dist);
		vector<vector<int>> visited(grid.size(), line);
		std::map<std::pair<int, int>, std::pair<int, int>> path;
		std::queue<std::pair<int, int>> Q;
		Q.push(std::make_pair(0,0));
		dist[0][0] = grid[0][0];
		visited[0][0] = 1;
		
		while (!Q.empty())
		{
			auto node = Q.front();
			Q.pop();
			visited[node.first][node.second] = 0;
			if ((node.first + 1 < row)&&(dist[node.first][node.second] + grid[node.first+1][node.second] 
				< dist[node.first + 1][node.second])) {
				path[make_pair(node.first + 1, node.second)] = make_pair(node.first, node.second);
				dist[node.first + 1][node.second] = dist[node.first][node.second] + grid[node.first + 1][node.second];
				if (!visited[node.first + 1][node.second]) {
					Q.push(make_pair(node.first + 1, node.second));
					visited[node.first + 1][node.second] = 1;
				}
			}
			if ((node.second + 1 < col) && (dist[node.first][node.second] + grid[node.first][node.second + 1]
				< dist[node.first][node.second + 1])) {
				path[make_pair(node.first, node.second + 1)] = make_pair(node.first, node.second);
				dist[node.first][node.second + 1] = dist[node.first][node.second] + grid[node.first][node.second + 1];
				if (!visited[node.first][node.second + 1]) {
					Q.push(make_pair(node.first, node.second + 1));
					visited[node.first][node.second + 1] = 1;
				}
			}

		}
		std::stack<std::pair<int, int>> s;
		auto des = make_pair(row - 1, col - 1);
		while(des != make_pair(0,0)){
			s.push(des);
			des = path[des];
		}
		int sum_all = grid[0][0];
		while (!s.empty()) {
			sum_all += grid[s.top().first][s.top().second];
			s.pop();
		}
		return sum_all;
		
	}
};
int main() {
	Solution s;
	vector<vector<int>> grid = { {1,3,1},{1,5,1},{4,2,1} };
	std::cout << s.minPathSum(grid) << std::endl;
	return 0;
}