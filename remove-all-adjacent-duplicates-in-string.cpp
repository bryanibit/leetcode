#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool removeTwo(string &s) {
		for (int i = 0; i < s.size() - 1; ++i) {
			if (s.at(i) == s.at(i + 1)) {
				s.erase(i, 2);
				return true;
			}
		}
		return false;
	}
	string removeDuplicates(string S) {
		bool count = true;
		while (count == true && S.size() >0) {
			count = removeTwo(S);
		}
		return S;
	}
};
int main() {
	Solution s;
	string str = "aaaaaaaa";
	auto x = s.removeDuplicates(str);
	return 0;
}