#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
	vector<vector<char>> board_g;
	bool dfs(vector<vector<char>> &board, string word, int word_loc, int i, int j) {
		//auto board = board_h;
		if (word_loc == word.size())
			return true;
		board.at(i).at(j) = '1';
		bool left = false, right = false, top = false, down = false;
		if (i + 1 < board.size() && board.at(i + 1).at(j) == word[word_loc])
			down = dfs(board, word, word_loc + 1, i + 1, j);
		if (i - 1 >= 0 && board.at(i - 1).at(j) == word[word_loc])
			top = dfs(board, word, word_loc + 1, i - 1, j);
		if (j + 1 < board.at(0).size() && board.at(i).at(j + 1) == word[word_loc])
			right = dfs(board, word, word_loc + 1, i, j + 1);
		if (j - 1 >= 0 && board.at(i).at(j - 1) == word[word_loc])
			left = dfs(board, word, word_loc + 1, i, j - 1);
		if ((left || right || top || down) == false)
		{	
			board.at(i).at(j) = board_g.at(i).at(j);
			return false;
		}
		else
			return true;
	}
	bool exist(vector<vector<char>>& board, string word) {
		board_g = board;
		std::vector<vector<int>> initLoc;
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board.at(0).size(); ++j) {
				if (board.at(i).at(j) == word[0])
					initLoc.push_back(vector<int>{i, j});
			}
			/*auto row = board.at(i);
			auto iter = std::find(row.begin(), row.end(), word[0]);
			if (iter != row.end())
				initLoc.push_back(vector<int>{ i, static_cast<int>(iter - row.begin()) });*/
		}
		for (int i = 0; i < initLoc.size(); ++i) {
			auto save_board = board;
			auto ax = dfs(save_board, word, 1, initLoc.at(i).at(0), initLoc.at(i).at(1));
			if (ax == true)
				return true;
		}
		return false;
	}
};
int main() {
	Solution s;
	/*vector<vector<char>> board = {
	{'A','B','C','E'},
	{'S','F','C','S'},
	{'A','D','E','E' }
	};*/
	vector<vector<char>> board = {
		{'A', 'B', 'C', 'E'}, 
		{ 'S', 'F', 'E', 'S'}, 
		{ 'A', 'D', 'E', 'E'}
	};
	auto x = s.exist(board, "ABCESEEEFS");
	return 0;
}