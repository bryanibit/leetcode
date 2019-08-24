# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def oddEvenList(self, head):
        tail = head
        p = head
        count = 1
        last_p = None
        p_next = None
        while p:
            if count > 1 and count % 2 == 1:
                temp = tail.next
                p_next = p.next
                tail.next = p
                p.next = temp
                last_p.next = p_next

                tail = tail.next
                p = p_next
            else:
                last_p = p
                p = p.next

            count += 1

        return head

if __name__ == "__main__":
    s = Solution()
    # head = ListNode(1)
    # head.next = ListNode(2)
    # head.next.next = ListNode(3)
    # head.next.next.next = ListNode(4)
    # head.next.next.next.next = ListNode(5)
    # head.next.next.next.next.next = ListNode(6)
    s.oddEvenList(head)        