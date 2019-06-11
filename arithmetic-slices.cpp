#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		if (A.empty())
			return 0;
		int count = 0;
		for (int i = 1; i < A.size() - 1; ++i) {
			auto diff = A.at(i) - A.at(i - 1);
			int j = i + 1;
			while(j < A.size()){
				if (A[j] - A[j - 1] == diff) {
					count++;
					j++;
				}
				else {
					break;
				}
			}
		}
		return count;
	}
};
int main() {
	Solution s;
	vector<int> A = { 1,2,3,4, 5, 8};
	auto x = s.numberOfArithmeticSlices(A);
	return 0;
}