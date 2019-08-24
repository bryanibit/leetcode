//#include <vector>
//#include <iostream>
//#include <algorithm>
//struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//	ListNode* reverseList(ListNode* head) {
//		if (head == nullptr || head->next == nullptr)
//			return head;
//		if (head != nullptr && head->next != nullptr && head->next->next == nullptr) {
//			auto temp = head->next;
//			head->next = nullptr;
//			temp->next = head;
//			return temp;
//		}
//		ListNode* first = nullptr;
//		auto sec = head;
//		auto third = head->next;
//		while (third != nullptr) {
//			auto temp = third->next;
//			sec->next = first;
//			third->next = sec;
//			first = sec;
//			sec = third;
//			third = temp;
//		}
//		return sec;
//	}
//};
//int main() {
//	Solution s;
//	auto head = new ListNode(1);
//	head->next = new ListNode(2);
//	head->next->next = new ListNode(3);
//	head->next->next->next = new ListNode(4);
//	head->next->next->next->next = new ListNode(5);
//	auto x = s.reverseList(head);
//	return 0;
//}