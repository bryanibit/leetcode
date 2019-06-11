#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
using namespace std;
class Solution {
public:
	/*void quickSort(vector<int> &nums, int left, int right) {
		int i = left;
		int j = right;
		auto base_num = nums.at(left);
		while (i < j) {
			while (i < j && nums.at(j) >= base_num)
				--j;
			while (i < j && nums.at(i) <= base_num)
				++i;
			int temp = nums.at(i);
			nums.at(i) = nums.at(j);
			nums.at(j) = temp;
		}
		nums.at(left) = nums.at(i);
		nums.at(i) = base_num;
		if (i > left)
			quickSort(nums, left, i - 1);
		if (i + 1 <= right)
			quickSort(nums, i + 1, right);
	}*/
	vector<int> deckRevealedIncreasing(vector<int>& deck) {
		auto cp_deck = deck;
		vector<int> res(deck.size(), std::numeric_limits<int>::min());
		sort(deck.begin(), deck.end());
		std::queue<int*> Q;
		for (int i = 0; i < res.size(); ++i) {
			Q.push(&(res.at(i)));
		}
		int i = 0;
		while (!Q.empty()) {
			auto p_val = Q.front();
			*p_val = deck.at(i);
			++i;
			Q.pop();
			if (Q.empty())
				break;
			Q.push(Q.front());
			Q.pop();
		}
		return res;
	}
};
int main() {
	Solution s;
	vector<int> deck = { 17,13,11,2,3,5,7 };
	//2,13,3,11,5,17,7
	auto x = s.deckRevealedIncreasing(deck);
	return 0;
}

