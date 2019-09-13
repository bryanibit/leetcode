# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root, p, q):
        stack = []
        def count(root, p, q):
            if not root:
                return 0
            
            cur = count(root.left, p, q) + count(root.right, p, q)
            if root.val == p.val or root.val == q.val:
                cur += 1
            
            if cur == 2:
                stack.append(root)
            print("{0}:{1}".format(root.val, cur))
            return cur
        count(root, p, q)
        return stack[0]
                            
if __name__ == "__main__":
    s = Solution()
    p = TreeNode(4)
    q = TreeNode(5)

    root = TreeNode(6)
    root.left = TreeNode(2)
    root.right = TreeNode(8)
    root.left.left = TreeNode(0)
    root.left.right = TreeNode(4)
    root.left.right.left = TreeNode(3)
    root.left.right.right = TreeNode(5)
    root.right.left = TreeNode(7)
    root.right.right = TreeNode(9)
    x = s.lowestCommonAncestor(root, p, q)   
    pass   