import math
class Solution(object):
    def rangeBitwiseAnd(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        res = 0
        for i in range(math.ceil(math.log(n, 2)), -1, -1):
            eg = 2**i
            if m >= eg and n >= eg:
                res += 2**i
                m = m - eg
                n = n - eg
            elif (m - eg)*(n - eg) < 0 or (m< eg and n == eg):
                return res
            else:
                continue
        
if __name__ == "__main__":
    s = Solution()
    s.rangeBitwiseAnd(20000,2147483647)