#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <limits>
#include <map>
using namespace std;
class Solution {
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& graph) {
		int N = graph.size();
		if (graph[0][0] != 0 || graph[N - 1][N - 1] != 0)
			return -1;
		vector<vector<int>> dist(N, vector<int>(N, std::numeric_limits<int>::max()));
		vector<vector<int>> visited(N, vector<int>(N, 0));
		map<tuple<int, int>, tuple<int, int>> path;
		queue<tuple<int, int>> Q;
		Q.push(make_tuple(0, 0));
		visited[0][0] = 1;
		dist[0][0] = 0;
		while (!Q.empty()) {
			auto u = Q.front();
			auto first = std::get<0>(u);
			auto last = std::get<1>(u);
			Q.pop();
			visited[first][last] = 0;
			if (first+1 < N && graph[first + 1][last] == 0) {
				if (dist[first][last] + 1 < dist[first + 1][last]) {
					dist[first + 1][last] = dist[first][last] + 1;
					path[make_tuple(first + 1, last)] = u;

					if (!visited[first + 1][last]) {
						Q.push(make_tuple(first + 1, last));
						visited[first + 1][last] = 1;
					}
				}
			}
			if (first - 1 >= 0 && graph[first - 1][last] == 0) {
				if (dist[first][last] + 1 < dist[first - 1][last]) {
					dist[first - 1][last] = dist[first][last] + 1;
					path[make_tuple(first - 1, last)] = u;

					if (!visited[first - 1][last]) {
						Q.push(make_tuple(first - 1, last));
						visited[first - 1][last] = 1;
					}
				}
			}
			if (last + 1 < N && graph[first][last + 1] == 0) {
				if (dist[first][last] + 1 < dist[first][last + 1]) {
					dist[first][last + 1] = dist[first][last] + 1;
					path[make_tuple(first, last + 1)] = u;

					if (!visited[first][last + 1]) {
						Q.push(make_tuple(first, last + 1));
						visited[first][last + 1] = 1;
					}
				}
			}
			if (last - 1 >= 0 && graph[first][last - 1] == 0) {
				if (dist[first][last] + 1 < dist[first][last - 1]) {
					dist[first][last - 1] = dist[first][last] + 1;
					path[make_tuple(first, last - 1)] = u;

					if (!visited[first][last - 1]) {
						Q.push(make_tuple(first, last - 1));
						visited[first][last - 1] = 1;
					}
				}
			}
			if (last + 1 < N && first + 1 < N && graph[first + 1][last + 1] == 0) {
				if (dist[first][last] + 1 < dist[first + 1][last + 1]) {
					dist[first + 1][last + 1] = dist[first][last] + 1;
					path[make_tuple(first + 1, last + 1)] = u;

					if (!visited[first + 1][last + 1]) {
						Q.push(make_tuple(first + 1, last + 1));
						visited[first + 1][last + 1] = 1;
					}
				}
			}
			if (last - 1 >= 0 && first + 1 < N && graph[first + 1][last - 1] == 0) {
				if (dist[first][last] + 1 < dist[first + 1][last - 1]) {
					dist[first + 1][last - 1] = dist[first][last] + 1;
					path[make_tuple(first + 1, last - 1)] = u;

					if (!visited[first + 1][last - 1]) {
						Q.push(make_tuple(first + 1, last - 1));
						visited[first + 1][last - 1] = 1;
					}
				}
			}
			if (last + 1 < N && first - 1 >= 0 && graph[first - 1][last + 1] == 0) {
				if (dist[first][last] + 1 < dist[first - 1][last + 1]) {
					dist[first - 1][last + 1] = dist[first][last] + 1;
					path[make_tuple(first - 1, last + 1)] = u;

					if (!visited[first - 1][last + 1]) {
						Q.push(make_tuple(first - 1, last + 1));
						visited[first - 1][last + 1] = 1;
					}
				}
			}
			if (last - 1 >= 0 && first - 1 >= 0 && graph[first - 1][last - 1] == 0) {
				if (dist[first][last] + 1 < dist[first - 1][last - 1]) {
					dist[first - 1][last - 1] = dist[first][last] + 1;
					path[make_tuple(first - 1, last - 1)] = u;

					if (!visited[first - 1][last - 1]) {
						Q.push(make_tuple(first - 1, last - 1));
						visited[first - 1][last - 1] = 1;
					}
				}
			}
		}
		return dist[N - 1][N - 1] == std::numeric_limits<int>::max() ? -1 : dist[N - 1][N - 1] + 1;
	}
};
int main() {
	Solution s;
	vector<vector<int>> graph = { {0,0,1,0,0,0,0 }, { 0,1,0,0,0,0,1 }, { 0,0,1,0,1,0,0 }, 
	{ 0,0,0,1,1,1,0 }, { 1,0,0,1,1,0,0 }, { 1,1,1,1,1,0,1 }, { 0,0,1,0,0,0,0 }};
	auto x = s.shortestPathBinaryMatrix(graph);
	return 0;
}