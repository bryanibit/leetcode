#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	vector<string> splitString(string s, const char c) {
		vector<string> ss;
		while (!s.empty()) {
			auto iter = std::find(s.begin(), s.end(), c);
			if (iter != s.end()) {
				ss.push_back(s.substr(0, iter - s.begin()));
				s.erase(s.begin(), iter + 1);
			}
			else {
				ss.push_back(s.substr(0, iter - s.begin()));
				s.clear();
			}
		}
		return ss;
	}
	vector<string> uncommonFromSentences(string A, string B) {
		vector<string> res;
		string C = A + " " + B;
		vector<string> s1 = splitString(C, ' ');
		for (int i = 0; i < s1.size(); ++i) {
			if (std::find(s1.begin(), s1.begin() + i, s1.at(i)) == s1.begin() + i &&
				std::find(s1.begin() + i + 1, s1.end(), s1.at(i)) == s1.end()) {
				res.push_back(s1.at(i));
			}
		}
		/*vector<string> s2 = splitString(B, ' ');
		for (int i = 0; i < s1.size(); ++i) {
			if (std::find(s2.begin(), s2.end(), s1.at(i)) == s2.end())
				res.push_back(s1.at(i));
		}

		for (int i = 0; i < s2.size(); ++i) {
			if (std::find(s1.begin(), s1.end(), s2.at(i)) == s1.end())
				res.push_back(s2.at(i));
		}*/
		return res;
	}
};
int main() {
	string s1 = "this apple is sweet";
	string s2 = "this apple is sour";
	Solution s;
	auto x = s.uncommonFromSentences(s1, s2);
	return 0;
}