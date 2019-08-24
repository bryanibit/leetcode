class Solution:
    def nthSuperUglyNumber(self, n, primes):
        index = [0] * len(primes)
        res = [1]
        x = 10000
        rem = 0
        while len(set(res)) < n:
            for k in range(len(index)):
                if x > res[index[k]]*primes[k]:
                    x = res[index[k]]*primes[k]
                    rem = k
            index[rem] += 1
            res.append(x)
            # n -= 1
            x = 10000
        return res[-1]
if __name__ == "__main__":
    s = Solution()
    n = 650
    primes = [3,11,13,19,29,31,41,43,47,59,61,71,79,83,89,97,103,107,137,139,149,163,173,179,191,197,211,223,229,239]
    x = s.nthSuperUglyNumber(n, primes)            
    print(x)