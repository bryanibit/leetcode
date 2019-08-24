class Solution:
    def generate(self, numRows):
        res = [[] for x in range(numRows)]
        for i in range(numRows):
            if i == 0:
                res[i].append(1)
            elif i == 1:
                res[i].append(1)
                res[i].append(1)
            else:
                res[i].append(1)
                for j in range(1, len(res[i - 1])):
                    res[i].append(res[i-1][j-1] + res[i-1][j])
                res[i].append(1)
        return res
if __name__ == "__main__":
    s=Solution()
    numRows = 5
    x = s.generate(numRows)    