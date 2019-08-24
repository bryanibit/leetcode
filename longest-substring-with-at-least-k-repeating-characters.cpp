#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
	int longestSubstring(string s, int k) {
		std::unordered_map<char, int> umap;
		for (int i = 0; i < s.size(); ++i) {
			umap[s.at(i)]++;
		}
		int sum = 0;
		for (auto it = umap.begin(); it != umap.end(); ++it) {
			if (it->second >= k)
				sum += it->second;
		}
		return sum;
	}
};
int main() {
	Solution s;
	string ss = "aaabbfadfaderadfjiruoymnpxmwe";
	int k = 3;
	auto x = s.longestSubstring(ss, k);
	return 0;
}