#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
		s.insert(s.begin(), ' ');
		p.insert(p.begin(), ' ');
		vector<vector<int>> res(s.size() + 1, vector<int>(p.size() + 1, 0));
		res[0][0] = 1;
		for (int i = 1; i < p.size(); ++i) {
			if (p.at(i) == '*')
				res[0][i] = 1;
			else
				break;
		}
		for (int i = 1; i < s.size(); ++i) {
			if (std::find(res.at(i - 1).begin(), res.at(i - 1).end(), 1) == res.at(i - 1).end())
				return false;
			for (int j = 1; j < p.size(); ++j) {
				if (s.at(i) == p.at(j) || p.at(j) == '.')
					res[i][j] = res[i - 1][j - 1];

				else if (p.at(j) == '*') {
					int num_qm = 0;
					int k = j - 1;
					while (k > 0) {
						if (p.at(k) >= 'a' && p.at(k) <= 'z')
							break;
						else if (p.at(k) == '.')
							num_qm++;
						--k;
					}
					int h = 0;
					vector<int> temp;
					while (h <= i - num_qm) {
						if (s.at(h) == p.at(k))
							temp.push_back(h);
						++h;
					}
					for_each(temp.begin(), temp.end(), [&res, j, i, k](int n) {
						res[i][j] += res[n][k];
					});
					if (res[i][j] > 0)
						res[i][j] = 1;
				}
				else
					res[i][j] = 0;
			}
		}
		return res[s.size() - 1][p.size() - 1];
	}
};
int main() {
	Solution s;
	string ss = "mississippi";
	string p = "mis*is*p*.";
	auto x = s.isMatch(ss, p);
	return 0;
}