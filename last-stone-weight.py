class Solution:
    def lastStoneWeight(self, stones):
        stones.sort()
        while len(stones) > 1:
            if stones[-1] != stones[-2]:
                val = stones[-1] - stones[-2]
                stones.pop()
                stones.pop()
                if len(stones) == 0:
                    return val
                # insert in right place
                i = 0
                while i < len(stones):
                    if stones[i] < val:
                        i += 1
                    # elif stones[i] == val:
                    #     stones.insert(i, val)
                    #     break
                    else:
                        stones.insert(i, val)
                        break
                if i == len(stones):
                    stones.append(val)
            else:
                stones.pop()
                stones.pop()
        if len(stones) == 0:
            return 0
        else:                
            return stones[0]
        
if __name__ == "__main__":
    s = Solution()
    stones = [2,7,4,1,8,1]
    x = s.lastStoneWeight(stones)
    print(x)

