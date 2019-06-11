#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		vector<string> res_str;
		vector<bool> splitTable(s.size() + 1, false);
		//vector<std::pair<int,int>> res;
		splitTable[s.size()] = true;
		vector<vector<string>> normal(s.size() + 1, vector<string>{});
		normal[s.size()] = { "" };
		vector<string> ans;
		for (int i = s.size()-1; i >= 0; --i) {
			splitTable.at(i) = false;
			for (int j = i+1; j <= s.size(); ++j) {
				auto iter = std::find(wordDict.begin(), wordDict.end(), s.substr(i, j - i));
				if (iter != wordDict.end() && splitTable[j]) {
					splitTable[i] = true;
					//res.emplace_back(i, j);
					for (auto &h : normal[j]) {
						if (h == "")
							normal[i].push_back(s.substr(i, j - i));
						else
							normal[i].push_back(s.substr(i, j - i) + " " + h);
					}
				}
			}
		}
		return normal[0];
	}
};
int main() {
	Solution s;
	/*string aa = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	vector<string> wordDict1 = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", 
	"aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };*/
	/*string app = "applepenapple";*/
	string pine = "pineapplepenapple";
	string scat = "catsanddog";
	string ss = "aaaaaaa";
	string leet = "leetcode";
	//"apple", "pen", "leet", "code", "aaaa", "aaa",
	vector<string> wordDict = {  "cat", "cats", "sand", "dog", "and", "aaa", "aaaa" };
	vector<string> wordDict2 = { "apple", "pen", "applepen", "pine", "pineapple" };
	string s_s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	vector<string> wordDict3 = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
	auto x = s.wordBreak(s_s, wordDict3);
	//auto x = s.wordBreak(scat, wordDict);
	return 0;
}