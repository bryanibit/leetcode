class Solution(object):
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 1:
            return False
        sum = 0
        i = 1
        while i**2 <= num:
            if num %i == 0:
                sum += i
                if i != 1 and num/i != i:
                    sum += num / i
            i += 1
        if sum == num:
            return True
        else:
            return False
if __name__ == "__main__":
    s = Solution()
    num = 25
    s.checkPerfectNumber(num)            