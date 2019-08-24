//#include <algorithm>
//using namespace std;
//struct ListNode {
//    int val;
//    ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//	ListNode* reverseKGroup(ListNode* head, int k) {
//		auto p = head;
//		int count = 0;
//		while (!p) {
//			p = p->next;
//			count++;
//		}
//		auto num = count / k;
//		for (int i = 0; i < num; ++i) {
//			//k nodes swap
//		}
//	}
//};
//int main() {
//	Solution s;
//	auto head = new ListNode(1);
//	head->next = new ListNode(2);
//	head->next->next = new ListNode(3);
//	head->next->next->next = new ListNode(4);
//	head->next->next->next->next = new ListNode(5);
//	head->next->next->next->next->next = new ListNode(6);
//	head->next->next->next->next->next->next = new ListNode(7);
//	head->next->next->next->next->next->next->next = new ListNode(8);
//	int k = 2;
//	auto x = s.reverseKGroup(head, k);
//	return 0;
//}