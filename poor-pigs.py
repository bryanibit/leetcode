import math
class Solution(object):
    def poorPigs(self, buckets, minutesToDie, minutesToTest):
        """
        :type buckets: int
        :type minutesToDie: int
        :type minutesToTest: int
        :rtype: int
        """
        times = minutesToTest/minutesToDie
        pig = 0
        res = -1
        comp = math.log(buckets, times+1)
        res = math.ceil(comp)
        return res
if __name__ == "__main__":
    s = Solution()
    s.poorPigs(1000, 15, 60)
    pass