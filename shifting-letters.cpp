#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
	int sum_vector(const vector<int>& shifts, int i, int j) {
		int sum = 0;
		for (int k = i; k < j; ++k) {
			sum += shifts.at(k);
			//sum = sum % 26;
		}
		sum = sum % 26;
		return sum;
	}
	string shiftingLetters(string& S, vector<int>& shifts) {
		for_each(shifts.begin(), shifts.end(), [](auto & n) {
			n = n % 26;
		});
		for (int i = shifts.size() - 1; i > 0; --i) {
			shifts[i - 1] += shifts[i];
		}
		int i = 0;
		int j = 0;
		while (i < shifts.size()) {
			S[j] = (S[j] - 'a' + shifts[i]) % 26 + 'a';
			i++;
			j++;
		}
		return S;
	}
};
int main() {
	Solution s;
	string S = "abc";
	vector<int> shifts = { 3,5,9 };
	auto x = s.shiftingLetters(S, shifts);
	return 0;
}