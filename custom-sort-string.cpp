#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
	string customSortString(string S, string T) {
		map<int, string> dict;
		string extra = "";
		for (int i = 0; i < T.size(); ++i) {
			auto iter = find(S.begin(), S.end(), T.at(i));
			if (iter != S.end()) {
				if (dict.find(iter - S.begin()) != dict.end()) {
					dict[iter - S.begin()] += string(1, T.at(i));
				}
				else
					dict.emplace(iter - S.begin(), string(1, T.at(i)));
			}
			else
				extra += string(1, T.at(i));
		}
		string res = "";
		for (auto i : dict) {
			res += i.second;
		}
		res += extra;
		return res;
	}
};
int main() {
	Solution s;
	string S = "kqep";
	string T = "pekeq";
	auto x = s.customSortString(S, T);
	return 0;
}