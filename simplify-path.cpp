#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	enum class Mode {
		path_letter, slash, point
	};
	string simplifyPath(string path) {
		vector<string> v_p;
		Mode mode;
		// set state machine
		for (int i = 0; i < path.size(); ++i) {
			if (path.at(i) == '/')
				mode = Mode::slash;
			else if (path.at(i) == '.')
				mode = Mode::point;
			else
				mode = Mode::path_letter;
		}
	}
};
int main() {
	Solution s;
	string path = "/home/./b/../../c/";
	auto x = s.simplifyPath(path);
	return 0;
}