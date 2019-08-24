class Solution(object):
    def partitionLabels(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        map = dict()
        for index, i in enumerate(S):
            map[i] = index
        cur_max = -1
        loc = -1
        res = []
        for index, i in enumerate(S):
            if map[i] > cur_max:
                cur_max = map[i]
            if cur_max <= index:
                res.append(index - loc)
                loc = index
        return res
if __name__ == "__main__":
    s = Solution()
    S = "ababcbacadefegdehijhklij"
    s.partitionLabels(S)