#include <algorithm>
#include <queue>
using namespace std;
class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		vector<int> parent(edges.size() + 1, -1);
		vector<int> res;
		for (int i = 0; i < edges.size(); ++i) {
			if (parent.at(edges[i][0]) == -1 && parent.at(edges[i][1]) == -1) {
				parent.at(edges[i][0]) = edges[i][0];
				parent.at(edges[i][1]) = edges[i][0];
			}
			else if (parent.at(edges[i][1]) == -1) {
				parent.at(edges[i][1]) = parent.at(edges[i][0]);
			}
			else if (parent.at(edges[i][0]) == -1) {
				parent.at(edges[i][0]) = parent.at(edges[i][1]);
			}
			else if (parent.at(edges[i][0]) != parent.at(edges[i][1])) {
				/*for_each(parent.begin(), parent.end(), [&i, &edges, &parent](auto& n) {
					if (n == parent.at(edges[i][1]))
						n = parent.at(edges[i][0]);
				});*/
				auto temp = parent.at(edges[i][1]);
				auto val = parent.at(edges[i][0]);
				for (int k = 0; k < parent.size(); k++) {
					if (parent[k] == temp)
						parent[k] = val;
				}
			}
			else if (parent.at(edges[i][0]) == parent.at(edges[i][1]))
				res = edges[i];
		}
		return res;
	}
};
int main() {
	Solution s;
	vector<vector<int>> edges = { {1,2},{2,3},{3,4},{1,4},{1,5} };
	auto x = s.findRedundantConnection(edges);
	return 0;
}