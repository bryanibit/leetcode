#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	bool wordBreakbsf(int start, const string s, const vector<string> wordDict, vector<int> & memo) {
		if (start == s.size()){
			/*memo.at(start) = true;*/
			return true;
		}
		if (memo.at(start) != -1)
			return memo[start];
		for (int i = start + 1; i <= s.size(); ++i) {
			auto iter = std::find(wordDict.begin(), wordDict.end(), s.substr(start, i - start));
			if (iter != wordDict.end() && wordBreakbsf(i, s, wordDict, memo)) {
				memo.at(start) = true;
				return true;
			}
		}
		memo[start] = false;
		return false;
	}
	bool wordBreak(string s, vector<string>& wordDict) {
		auto start = 0;
		vector<int> memo(s.size()+ 1, -1);
		return wordBreakbsf(start, s, wordDict, memo);
	}
};
int main() {
	Solution s;
	string aa = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	vector<string> wordDict1 = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
	string app = "applepenapple";
	string scat = "catsandog";
	string ss = "aaaaaaa";
	//std::cout << ss.substr(6, 1) << std::endl;
	string ss_ = "leetcode";
	vector<string> wordDict = { "leet", "code", "aaaa", "aaa", "cat", "cats", "sand", "dog", "and" };
	auto x = s.wordBreak(aa, wordDict1);
	return 0;
}