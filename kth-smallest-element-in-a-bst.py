# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def __init__(self):
        self.hello = -1
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        def dfs(root, res, k):
            if root.left:
                dfs(root.left, res, k)
            res.append(root.val)
            if len(res) == k:
                self.hello = root.val
            if root.right:
                dfs(root.right, res, k)
        res = []
        dfs(root, res, k)
        return self.hello
if __name__ == "__main__":
    s = Solution()
    root = TreeNode(3)
    root.left = TreeNode(1)
    root.right = TreeNode(4)
    root.left.right = TreeNode(2)
    s.kthSmallest(root, 1)        