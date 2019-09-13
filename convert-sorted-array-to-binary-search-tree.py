# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    def generateFromMid(self, root, nums, left, right):
            mid = (left+right) // 2
            root.val = nums[mid]
            # the point is left and mid
            if left < mid:
                root.left = TreeNode(-1)
                self.generateFromMid(root.left, nums, left, mid)
            # the point is mid+1 and right
            if mid + 1 < right:
                root.right = TreeNode(-1)
                self.generateFromMid(root.right, nums, mid+1, right)
    def sortedArrayToBST(self, nums):
        L = len(nums)
        if L == 0:
            return None
        root = TreeNode(-1)
        self.generateFromMid(root, nums, 0, len(nums))
        return root
if __name__ == "__main__":
    s = Solution()
    nums = [-10,-3,0,5,9]
    s.sortedArrayToBST(nums)
