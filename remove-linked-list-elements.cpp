#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		auto dummy = new ListNode(-1);
		dummy->next = head;
		auto p = dummy;
		while (p && p->next) {
			if (p->next->val == val) {
				p->next = p->next->next;
			}
			else
				p = p->next;
		}
		return dummy->next;
	}
};
int main() {
	Solution s;
	auto head = new ListNode(1);
	head->next = new ListNode(1);
	//head->next->next = new ListNode(6);
	//head->next->next->next = new ListNode(3);
	//head->next->next->next->next = new ListNode(4);
	//head->next->next->next->next->next = new ListNode(6);
	auto x = s.removeElements(head, 1);
	return 0;
}