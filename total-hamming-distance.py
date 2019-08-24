import math
class Solution:
    def totalHammingDistance(self, nums):
        mask = 1
        sum = 0
        order = int(math.log(max(nums), 2)) + 1
        for i in range(order):
            time = 0
            for j in range(len(nums)):
                if mask & nums[j]:
                    time += 1
            mask = mask << 1
            sum += time*(len(nums) - time)
        return sum
if __name__ == "__main__":
    s = Solution()
    nums = [4,14,2]
    s.totalHammingDistance(nums)        