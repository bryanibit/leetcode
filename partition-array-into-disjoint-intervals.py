import numpy as np 
class Solution(object):
    def partitionDisjoint(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        a = np.array(A)
        index = np.argsort(a, axis = -1, kind='stable', order=None)
        ind = set()
        val = set()
        for i, v in enumerate(index):
            ind.add(i)
            val.add(v)
            if ind == val:
                return i+1
        return -1

if __name__ == "__main__":
    s = Solution()
    A = [12,75,26,38,56,59,83,55,49,52,27,48,77,21,27,79,54,15,59,22,34,35,81,67,
    2,41,40,0,73,61,75,8,86,42,49,83,43,16,2,54,26,35,15,63,31,24,51,86,6,35,
    42,37,83,51,34,21,71,57,61,76,
    50,1,43,32,19,13,67,87,3,33,
    38,34,34,84,38,76,52,7,27,49,
    2,78,56,28,70,6,64,87,100,97,
    99,97,97,100,100,100,97,89,98,100]
    s.partitionDisjoint(A)