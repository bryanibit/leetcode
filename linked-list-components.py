# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def numComponents(self, head, G):
        """
        :type head: ListNode
        :type G: List[int]
        :rtype: int
        """
        p = head
        check = dict()
        while p != None and p.next != None:
            check[p.val] = p.next.val
            p = p.next
        check[check[check.keys()[-1]]] = len(check) + 1
        val = G[0]
        part = []
        while val in G:
            part.append(val)
            G.remove(val)
            val = check[val]
        mid = val
        if mid in check and check[mid] in G:
            return mid
        else:
            gv = G[0]
            hp = 0
            while gv not in part:
                hp = gv
                gv = check[gv]
            return hp
if __name__ == "__main__":
    s = Solution()
    head = ListNode(0)
    # head.next = ListNode(1)
    # head.next.next = ListNode(2)
    # head.next.next.next = ListNode(3)
    # head.next.next.next.next = ListNode(4)
    G = [0]
    s.numComponents(head, G)            