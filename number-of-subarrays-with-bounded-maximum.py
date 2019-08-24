import numpy as np
import math
class Solution(object):
    def numSubarrayBoundedMax(self, A, L, R):
        """
        :type A: List[int]
        :type L: int
        :type R: int
        :rtype: int
        """
        # divide and conque
        

if __name__ == "__main__":
    s = Solution()
    A = [2,1,4,3]
    L = 2
    R = 3
    x = s.numSubarrayBoundedMax(A, L, R)        
    print(x)