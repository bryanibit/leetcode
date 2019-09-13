# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def __init__(self):
        self.res = None
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        lowest = root.val
        def dfs(root, p, q):
            if p.val <= root.val and q.val >= root.val:
                self.res = root
                return
            elif p.val < root.val and q.val < root.val and root.left:
                dfs(root.left, p, q)
            elif p.val > root.val and q.val > root.val and root.right:
                dfs(root.right, p, q)
        if p.val > q.val:
            p, q = q, p
        if root:
            dfs(root, p, q)
        return self.res
        
if __name__ == "__main__":
    s = Solution()
    root = TreeNode(6)
    p = TreeNode(2)
    q = TreeNode(4)
    root.left = TreeNode(2)
    root.right = TreeNode(8)
    root.left.left = TreeNode(0)
    root.left.right = TreeNode(4)
    root.left.right.left = TreeNode(3)
    root.left.right.right = TreeNode(5)
    root.right.left = TreeNode(7)
    root.right.right = TreeNode(9)
    s.lowestCommonAncestor(root, p, q)        