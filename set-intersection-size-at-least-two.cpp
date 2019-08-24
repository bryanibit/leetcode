#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <functional>
using namespace std;

template<typename A, typename B>
std::pair<B, A> flip_pair(const std::pair<A, B> &p)
{
	return std::pair<B, A>(p.second, p.first);
}

template<typename A, typename B>
std::multimap<B, A> flip_map(const std::map<A, B> &src)
{
	std::multimap<B, A> dst;
	std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()),
		flip_pair<A, B>);
	return dst;
}

class Solution {
public:
	int intersectionSizeTwo(vector<vector<int>>& intervals) {
		map<int, int> res;
		auto inter_size = intervals.size();
		for (auto interval : intervals) {
			for (int i = interval.at(0); i <= interval.at(1); ++i) {
				res[i]++;
			}
		}
		/*auto multi_res = flip_map(res);
		vector<int> keys;
		for (auto it = multi_res.rbegin() + 1; it != multi_res.rend() - 1; ++it) {
			keys.push_back(it->first);
		}*/
		vector<int> keys;
		for (auto it = res.begin(); it != res.end(); ++it) {
			keys.push_back(it->second);
		}
		sort(keys.begin(), keys.end(), std::greater<int>());
		bool travel = false;
		auto val = -1;
		int i = 0;
		for (; i < keys.size(); ++i) {
			if (!travel && keys[i] < keys.at(0)) {
				val = keys[i];
				travel = true;
			}
			else {
				if (val == keys[i])
					continue;
				else if (keys[i] < val)
					break;
			}
		}
		return i;
	}
};
int main() {
	Solution s;
	vector<vector<int>> intervals = { {1, 2 }, { 2, 3 }, { 2, 4 }, { 4, 5 }
};
	auto x = s.intersectionSizeTwo(intervals);
	return 0;
}