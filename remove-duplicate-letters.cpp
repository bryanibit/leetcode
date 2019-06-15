#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	string removeDuplicateLetters(string s) {
		vector<int> count(26, 0);
		for (int i = 0; i < s.size(); ++i) {
			count.at(s.at(i) - 'a')++;
		}
		/*count������¼����**ʣ��**��s�У���i��s.size()-1�Ĳ����и���ĸʣ��ĸ���
		visited������¼���res�ж���ʲô��ĸ*/

		vector<bool> visited(26, false);
		string res = " ";
		for (int i = 0; i < s.size(); ++i) {
			auto chr = s.at(i);
			if (visited.at(chr - 'a'))
			{
				count[chr - 'a']--;
				continue;
			}
			if (res.back() > chr && count[res.back() - 'a'] > 0) {
				//count[res.back() - 'a']++;
				visited[res.back() - 'a'] = false;
				res.pop_back();
				--i;
				/*res +=chr;
				count[chr - 'a']--;*/
			}
			else {
				res += chr;
				visited[chr - 'a'] = true;
				count[chr - 'a']--;
			}
		}
		return res.substr(1);
	}
};
int main() {
	Solution s;
	string str = "bbcaac";
	auto x = s.removeDuplicateLetters(str);
	return 0;
}