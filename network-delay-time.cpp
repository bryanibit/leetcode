#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
using namespace std;
class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		vector<int> visited(N+1, 0);
		vector<int> dist(N+1, std::numeric_limits<int>::max());
		queue<int> Q;
		Q.push(K);
		visited[K] = 1;
		dist[K] = 0;
		while (!Q.empty()) {
			auto u = Q.front();
			Q.pop();
			visited[u] = 0;
			for (int i = 0; i < times.size(); ++i) {
				if (times.at(i).at(0) == u) {
					if (dist[times.at(i).at(1)] > dist[u] + times.at(i).at(2)) {
						dist[times.at(i).at(1)] = dist[u] + times.at(i).at(2);
						if (!visited[times.at(i).at(1)]) {
							Q.push(times.at(i).at(1));
							visited[times.at(i).at(1)] = 1;
						}
					}
				}
			}
		}
		int delay_time = 0;
		for (int i = 1; i < dist.size(); ++i) {
			if (dist.at(i) > delay_time)
				delay_time = dist.at(i);
		}
		return delay_time;
	}
};
int main() {
	Solution s;
	vector<vector<int>> times = { {1,2,1}};
	auto N = 2;
	auto K = 2;
	auto x = s.networkDelayTime(times, N, K);
	return 0;
}