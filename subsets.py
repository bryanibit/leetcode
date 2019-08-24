class Solution:
    def subsets(self, nums):
        res = [[]]
        for i in nums:
            temp = []
            for re in res:
                temp.append([r for r in re]+[i])
            res.extend(temp)
        return res
if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3]
    x = s.subsets(nums)            