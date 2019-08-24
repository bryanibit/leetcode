class Solution(object):
    def dfs(self, ok, dislikes):
        dislikes = sorted(dislikes, key = lambda x: x[0])
        log={}
        temp = []
        for index, val in enumerate(dislikes):
            if index == 0 and val[0] not in log and val[1] not in log:
                log[val[0]] = True
                log[val[1]] = False
            elif index != 0 and val[0] not in log and val[1] not in log:
                temp.append(val)
                continue
            elif val[0] in log and val[1] not in log:
                log[val[1]] = not log[val[0]]
            elif val[1] in log and val[0] not in log:
                log[val[0]] = not log[val[1]]
            else:
                if log[val[0]] == log[val[1]]:
                    ok = False
                else:
                    continue
        return temp, ok
    def possibleBipartition(self, N, dislikes):
        """
        :type N: int
        :type dislikes: List[List[int]]
        :rtype: bool
        """
        ok = True
        while dislikes:
            dislikes, ok = self.dfs(ok, dislikes)
            if not ok:
                return False
        return ok

if __name__ == "__main__":
    s = Solution()
    N = 5
    dislikes = [[1,2],[3,4],[4,5],[3,5]]
    s.possibleBipartition(N, dislikes)