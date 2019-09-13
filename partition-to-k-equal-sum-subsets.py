import numpy as np
class Solution(object):
    def canPartitionKSubsets(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        nums_np = np.array(nums)
        sm = np.sum(nums_np)
        if sm % k != 0:
            return False
        
if __name__ == "__main__":
    s = Solution()
    nums = [4, 3, 2, 3, 5, 2, 1]
    k = 4
    s.canPartitionKSubsets(nums, k)