#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
using namespace std;
class Solution {
public:
	vector<int> onePath;
	void dfs(vector<vector<int>>& graph, int source, int target, vector<vector<int>>& path)
	{
		onePath.push_back(source);
		if (source == target)
		{
			path.push_back(onePath);
		}
		for (auto i : graph[source])
		{
				dfs(graph, i, target, path);
				onePath.pop_back();
		}
	}
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		int source = 0;
		//vector<int> visited(graph.size(), 0);
		vector<vector<int>> path;
		int target = graph.size() - 1;
		dfs(graph, 0, target, path);
		//for (auto &i : path)
		//{
		//	i.insert(i.begin(), 0);
		//}
		return path;
	}
};
int main()
{
	Solution s;
	vector<vector<int>> graph;
	graph.emplace_back(std::initializer_list<int>{1, 2});
	graph.emplace_back(std::initializer_list<int>{3});
	graph.emplace_back(std::initializer_list<int>{3});
	graph.emplace_back(std::initializer_list<int>{});
	auto dfspath = s.allPathsSourceTarget(graph);
	return 0;
}