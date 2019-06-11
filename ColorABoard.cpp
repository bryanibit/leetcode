#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int infect;
	int max_col;
	int max_row;
	void parseColorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
		if ((r0 + 1 < max_row) && (grid[r0 + 1][c0] != infect) && (c0 + 1 < max_col) && (grid[r0][c0 + 1] != infect)
			&& (r0 - 1 >= 0) && (grid[r0 - 1][c0] != infect) && (c0 - 1 >= 0) && (grid[r0][c0 - 1] != infect))
			return;

		if ((r0 + 1 < max_row) && (grid[r0+1][c0] == infect)){
			grid[r0 + 1][c0] = color;
			parseColorBorder(grid, r0 + 1, c0, color);
		}
		if ((c0 + 1 < max_col) && (grid[r0][c0+1] == infect)) {
			grid[r0][c0+1] = color;
			parseColorBorder(grid, r0, c0 + 1, color);
		}
		if ((r0 - 1 >= 0) && (grid[r0 - 1][c0] == infect)) {
			grid[r0 - 1][c0] = color;
			parseColorBorder(grid, r0 - 1, c0, color);
		}
		if ((c0 - 1 >= 0) && (grid[r0][c0 - 1] == infect)) {
			grid[r0][c0 - 1] = color;
			parseColorBorder(grid, r0, c0 - 1, color);
		}
	}
	vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
		parseColorBorder(grid, r0, c0, color);
		return grid;
	}
};
int main() {
	vector<vector<int>> grid = { { 1,1 }, { 1,2 } };
	Solution s;
	s.max_col = grid[0].size();
	s.max_row = grid.size();
	auto source_x = 0;
	auto source_y = 0;
	s.infect = grid[source_x][source_y];
	auto res = s.colorBorder(grid, source_x, source_y, 3);
	return 0;
}