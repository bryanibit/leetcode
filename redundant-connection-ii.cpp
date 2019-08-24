#include <vector>
#include <unordered_set>
#include <iterator>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
using namespace std;
class Solution {
public:
	map<int, int> graph;
	set<int> vertices;

	vector<set<int>> makeParent(vector <vector<int>> &edges, int verti_size) {
		vector<set<int>> parents(verti_size + 1, set<int>{});
		for (int i = 0; i < edges.size(); ++i) {
			if (parents.at(edges[i][0]).empty() && parents.at(edges[i][1]).empty()) {
				parents.at(edges[i][0]).insert(edges[i][0]);
				parents.at(edges[i][1]).insert(edges[i][0]);
			}
			else if (parents.at(edges[i][0]).empty()) {
				parents.at(edges[i][0]).insert(edges[i][0]);
				auto iter = set_union(parents.at(edges[i][1]).begin(), parents.at(edges[i][1]).end(),
					parents.at(edges[i][0]).begin(), parents.at(edges[i][0]).end(), 
					std::inserter(parents.at(edges[i][1]), parents.at(edges[i][1]).begin()));
			}
			else {
				auto iter = set_union(parents.at(edges[i][1]).begin(), parents.at(edges[i][1]).end(),
					parents.at(edges[i][0]).begin(), parents.at(edges[i][0]).end(),
					std::inserter(parents.at(edges[i][1]), parents.at(edges[i][1]).begin()));
			}
		}
		return parents;
	}

	void makeGraph(vector <vector<int>> &edges) {
		for (int i = 0; i < edges.size(); ++i) {
			this->graph[edges[i][0]] = edges[i][1];
			this->vertices.insert(edges[i][0]);
			this->vertices.insert(edges[i][1]);
		}
	}

	void dfsGraph(int root) {
		
	}

	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		this->makeGraph(edges);
		auto parents = this->makeParent(edges, this->vertices.size());
		set<int> temp = parents.at(1);
		set<int> __intersection;
		for (int i = 2; i < parents.size(); ++i) {
			set_intersection(temp.begin(), temp.end(), parents.at(i).begin(), parents.at(i).end(),
				std::inserter(__intersection, __intersection.begin()));
			std::swap(temp, __intersection);
			__intersection.clear();
		}
		if (temp.size() > 1)
			std::cerr << "Root size larger than 1\n";
		auto root = *(temp.begin());
		
		return vector<int>{};
	}
};
int main() {
	Solution s;
	vector<vector<int>> edges = { {2,1},{3,1},{1,4},{4,2} };
	auto x = s.findRedundantDirectedConnection(edges);
	return 0;
}