#include <vector>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
	enum class Mode{normal, positive, negetive, letter, signpositive};
	Mode mode = Mode::normal;
	int myAtoi(string str) {
		//auto res = std::stoi(str);
		//return res;
		// remove first certain whitespaces
		int start = 0;
		for (int i = 0; i < str.size(); ++i) {
			if (str.at(i) == ' ') {
				continue;
			}
			else
			{
				start = i;
				if (str.at(start) == '-')
					mode = Mode::negetive;
				else if (str.at(start) < 58 && str.at(i) > 47)
					mode = Mode::positive;
				else if (str.at(start) == '+')
					mode = Mode::signpositive;
				else {
					mode = Mode::letter;
				}
				break;
			}
		}
		// calculate number
		int minus = 1;
		int num = 0;
		for (int i = start; i < str.size(); ++i) {
			switch (mode) {
			case Mode::positive:
				//int num = 0;
				if (str.at(i) > 47 && str.at(i) < 58) {
					if (num > std::numeric_limits<int>::max() / 10 || 
						(num == std::numeric_limits<int>::max() / 10 && stoi(string(1, str.at(i))) >
							std::numeric_limits<int>::max() % 10))
						return std::numeric_limits<int>::max();
					if (num < std::numeric_limits<int>::min() / 10 ||
						(num == std::numeric_limits<int>::min() / 10 && stoi(string(1, str.at(i)))*minus <
							std::numeric_limits<int>::min() % 10))
						return std::numeric_limits<int>::min();
					num = num * 10 + minus * stoi(string(1, str.at(i)));
				}
				else
					return num;
				break;
			case Mode::negetive:
				minus = -1;
				if (str.at(start) == '-') {
					mode = Mode::positive;
					continue;
				}
			case Mode::signpositive:
				minus = 1;
				if (str.at(start) == '+') {
					mode = Mode::positive;
					continue;
				}
			case Mode::letter:
				return 0;	
			}
		}
		return num;
	}
};
int main() {
	Solution s;
	std::cout << "max int: " << std::numeric_limits<int>::max() << std::endl;
	std::cout << "max %10: " << std::numeric_limits<int>::max() % 10 << std::endl;
	std::cout << "max / 10: " << std::numeric_limits<int>::max() / 10 << std::endl;
	string str = "2147483646";
	try {
		std::stoi(str);
	}
	catch(std::exception& e){
		std::cout << "not a number" << std::endl;
	}
	auto x = s.myAtoi(str);
	return 0;
}