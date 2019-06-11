#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>
#include <map>
using namespace std;
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int row = triangle.size();
		int col = triangle.back().size();
		std::queue<std::pair<int, int>> Q;
		std::vector<vector<int>> dis(row, vector<int>(col, std::numeric_limits<int>::max()));
		vector<vector<int>> visited(row, vector<int>(col, 0));
		std::map<std::pair<int, int>, std::pair<int, int>> path;
		Q.push(std::make_pair(0, 0));
		visited[0][0] = 1;
		dis[0][0] = triangle[0][0];
		while (!Q.empty()) {
			auto u = Q.front();
			Q.pop();
			visited[u.first][u.second] = 0;
			if (u.first + 1 < row && dis[u.first][u.second] + triangle[u.first + 1][u.second] < dis[u.first + 1][u.second]) {
				path[make_pair(u.first + 1, u.second)] = u;
				dis[u.first + 1][u.second] = dis[u.first][u.second] + triangle[u.first + 1][u.second];
				if (!visited[u.first + 1][u.second]) {
					Q.push(make_pair(u.first + 1, u.second));
					visited[u.first + 1][u.second] = 1;
				}
			}
			if (u.first + 1 < row && dis[u.first][u.second] + triangle[u.first + 1][u.second + 1] < dis[u.first + 1][u.second + 1]) {
				path[make_pair(u.first + 1, u.second + 1)] = u;
				dis[u.first + 1][u.second + 1] = dis[u.first][u.second] + triangle[u.first + 1][u.second + 1];
				if (!visited[u.first + 1][u.second + 1]) {
					Q.push(make_pair(u.first + 1, u.second + 1));
					visited[u.first + 1][u.second + 1] = 1;
				}
			}
		}
		int re = *std::min_element(dis.back().begin(), dis.back().end());
		return re;
	}
};
int main() {
	Solution s;
	vector<vector<int>> triangle = { {2}, {3,4}, {6,5,7},{4,1,8,3} };
	auto x = s.minimumTotal(triangle);
	return 0;
}