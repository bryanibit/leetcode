import math
class Solution:
    def pathInZigZagTree(self, label: int):
        """
        :type label: int
        :rtype: List[int]
        """
        l = []
        if math.log2(label) == math.ceil(math.log2(label)):
            temp = math.ceil(math.log2(label)) + 1
        else:
            temp = math.ceil(math.log2(label))
        if  temp % 2 == 0:
            label = 2**temp - 1 + 2**(temp - 1) - label
        while label > 0:
            l.append(label)
            label = label // 2
        l.reverse()
        for i, v in enumerate(l):
            line = i + 1
            if line % 2 == 0:
                l[i] = 2**line-1 + 2**(line-1) - l[i]
        return l
        
if __name__ == "__main__":
    s = Solution()
    label = 32
    x = s.pathInZigZagTree(label)