#include <vector>
#include <algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		auto dummy = new ListNode(-1);
		dummy->next = head;
		auto p = dummy;
		while (p->next != nullptr && p->next->next != nullptr) {
			auto node1 = p->next;
			auto node2 = node1->next;
			auto next = node2->next;

			node2->next = node1;
			node1->next = next;
			p->next = node2;

			p = node1;
		}

		return dummy->next;
	}
};
int main() {
	Solution s;
	auto head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	auto x = s.swapPairs(head);
	return 0;
}