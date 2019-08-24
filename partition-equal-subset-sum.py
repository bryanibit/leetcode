import numpy as np
from collections import defaultdict
class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        num = np.array(nums)
        sn = np.sum(num)
        if sn % 2 == 1:
            return False
        else:
            sn = sn // 2
        dp = [False] * (sn+1)
        # find all sums which elements of nums can be added
        dp[0] = True
        for i in nums:
            for j in range(sn, -1, -1):
                if j - i >= 0:
                    dp[j] = dp[j] or dp[j - i]
        return dp[sn]

if __name__ == "__main__":
    s = Solution()
    nums = [1,5,11,5]
    s.canPartition(nums)    