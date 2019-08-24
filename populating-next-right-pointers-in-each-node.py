"""
# Definition for a Node.
"""
class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

from collections import deque
class Solution:
    def connect(self, root):
        Q = deque()
        if root:
            Q.append(root)
        else:
            return root
        while Q:
            count = 0
            old_u = None
            L = len(Q)
            for i in range(L):
                new_u = Q.popleft()
                if count != 0:
                    new_u.next = old_u
                old_u = new_u
                count += 1
                if new_u.right:
                    Q.append(new_u.right)
                if new_u.left:
                    Q.append(new_u.left)
        return root

if __name__ == "__main__":
    s = Solution()
    root7 = Node(7, None, None, None)
    root6 = Node(6, None, None, None)
    root5 = Node(5, None, None, None)
    root4 = Node(4, None, None, None)
    root3 = Node(3, root6, root7, None)
    root2 = Node(2, root4, root5, None)
    root1 = Node(1, root2, root3, None)
    s.connect(root1)                