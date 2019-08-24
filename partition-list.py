# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        left = ListNode(-1)
        left_head = left
        right = ListNode(-1)
        right_head = right
        p = head
        while p != None:
            if p.val < x:
                left.next = ListNode(-1)
                left.next.val = p.val
                left = left.next
            else:
                right.next = ListNode(-1)
                right.next.val = p.val
                right = right.next
            p = p.next
        left.next = right_head.next
        return left_head.next
if __name__ == "__main__":
    s = Solution()
    head = ListNode(1)
    head.next = ListNode(4)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(2)
    head.next.next.next.next = ListNode(5)
    head.next.next.next.next.next = ListNode(2)
    x = 3
    s.partition(head, x)    