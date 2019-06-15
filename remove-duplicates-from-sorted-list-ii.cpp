#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		auto dummy = new ListNode(-1);
		dummy->next = head;
		/*auto q = dummy;
		while (q) {
			if (!q->next) {
				q->next = new ListNode(q->val);
			}
		}*/
		auto p = dummy;
		bool gotIt = false;
		while (p&&p->next&&p->next->next) {
			if (!gotIt) {
				if (p->next->val == p->next->next->val) {
					gotIt = true;
					p->next->next = p->next->next->next;
				}
				else {
					p = p->next;
				}
			}
			else {
				if (p->next->val == p->next->next->val) {
					p->next->next = p->next->next->next;
				}
				else {
					p->next = p->next->next;
					gotIt = false;
				}
			}
		}
		if (gotIt) {
			auto q = dummy;
			while (q && q->next)
			{
				if (!q->next->next) {
					q->next = q->next->next;
				}
				else
					q = q->next;
			}
		}
		return dummy->next;
	}
};
int main() {
	Solution s;
	auto head = new ListNode(1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(1);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(3);
	head->next->next->next->next->next = new ListNode(3);
	head->next->next->next->next->next->next = new ListNode(3);
	auto x = s.deleteDuplicates(head);
	return 0;
}