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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		auto m_c = m;
		auto num = n - m + 1;
		if (num == 0 || num == 1)
			return head;
		auto p = head;
		while (p != nullptr && m > 2) {
			p = p->next;
			m--;
		}
		auto remain = p;
		auto start = p->next;
		ListNode* first = nullptr;
		auto sec = p->next;
		auto third = sec->next;
		if (m_c == 1) {
			remain = new ListNode(-1);
			remain->next = head;
			start = head;
			first = nullptr;
			sec = head;
			third = sec->next;
		}

		if (num < 3) {
			if (num == 0 || num == 1)
				return head;
			else if (num == 2) {
				auto temp = third->next;
				remain->next = third;
				third->next = sec;
				sec->next = temp;
				if (m_c != 1)
					return head;
				else
					return remain->next;
			}
		}
		else {
			while (third != nullptr && num > 1) {
				auto temp = third->next;
				sec->next = first;
				third->next = sec;
				first = sec;
				sec = third;
				third = temp;
				--num;
			}
			remain->next = sec;
			start->next = third;
			if (m_c != 1)
				return head;
			else
				return remain->next;
		}
		return head;
	}
};
int main() {
	Solution s;
	auto head = new ListNode(1);
	/*head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);
	head->next->next->next->next->next->next = new ListNode(7);*/
	auto x = s.reverseBetween(head, 1, 1);
	return 0;
}