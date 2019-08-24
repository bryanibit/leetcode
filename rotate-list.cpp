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
	ListNode* rotateOnce(ListNode* head) {
		auto sentinel = new ListNode(-1);
		sentinel->next = head;
		while (head != nullptr && head->next != nullptr && head->next->next != nullptr) {
			head = head->next;
		}
		auto last = head->next;
		head->next = nullptr;
		last->next = sentinel->next;
		return last;
	}
	ListNode* rotateRight(ListNode* head, int k) {
		int count = 0; 
		auto p = head;
		while (p != nullptr) {
			p = p->next;
			count++;
		}

		if (head == nullptr)
			return nullptr;
		else if (head != nullptr && head->next == nullptr)
			return head;
		else if (head != nullptr && head->next != nullptr && head->next == nullptr) {
			if (k % 2 == 0)
				return head;
			else {
				auto next = head->next;
				head->next = nullptr;
				next->next = head;
				return next;
			}
		}

		for (int i = 0; i < (k % count); ++i) {
			head = rotateOnce(head);
		}
		return head;
	}
};
int main() {
	Solution s;
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	int k = 3;
	auto x = s.rotateRight(head, k);
	return 0;
}