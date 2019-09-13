# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def __init__(self):
            self.res = -1
    def maxAncestorDiff(self, root: TreeNode) -> int:
        def preorder(root, small, big):
            small = min(small, root.val)
            big = max(big, root.val)
            self.res = max(big - small, self.res)
            if root.left:
                preorder(root.left, small, big)
            if root.right:
                preorder(root.right, small, big)
        if not root:
            return 0
        preorder(root, root.val, root.val)
        return self.res

if __name__ == "__main__":
    s = Solution()
    root = TreeNode(8)
    root.left = TreeNode(3)
    root.right = TreeNode(10)
    root.left.left = TreeNode(1)
    root.left.right = TreeNode(6)
    root.left.right.left = TreeNode(4)
    root.left.right.right = TreeNode(7)
    root.right.right = TreeNode(14)
    root.right.right.left = TreeNode(13)
    x = s.maxAncestorDiff(root)    
    print(x)