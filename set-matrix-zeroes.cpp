#include <vector>
#include <set>
#include <map>
using namespace std;
class Solution {
public:
	set<std::pair<int,int>> zeros;
	void toZero(vector<vector<int>>& matrix, int i, int j) {
		for (int k = 0; k < matrix.size(); ++k) 
			matrix[k][j] = 0;
		for (int k = 0; k < matrix[0].size(); ++k)
			matrix[i][k] = 0;
	}
	void setZeroes(vector<vector<int>>& matrix) {
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				if (matrix[i][j] == 0)
					zeros.insert(std::make_pair(i, j));
			}
		}
		for (auto k : zeros) {
			toZero(matrix, k.first, k.second);
		}
	}
};
int main() {
	Solution s;
	vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
	s.setZeroes(matrix);
	return 0;
}