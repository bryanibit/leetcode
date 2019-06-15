#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	void dfs(vector<vector<int>> rooms, int id, vector<int>& visited) {
		int count = 0;
		for (auto i : rooms.at(id)) {
			if (visited[i] == 0) {
				visited.at(i) = 1;
				dfs(rooms, i, visited);
			}
		}
	}
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		vector<int> visited(rooms.size(), 0);
		visited.at(0) = 1;
		dfs(rooms, 0, visited);
		int sum = 0;
		for_each(visited.begin(), visited.end(), [&sum](int n) {sum += n; });
		if (sum < visited.size())
			return false;
		else
			return true;
	}
};
int main() {
	Solution s;
	vector<vector<int>> rooms = { {1,3},{3,0,1},{2},{0 } };
	auto x = s.canVisitAllRooms(rooms);
	return 0;
}