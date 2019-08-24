import operator
class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        tasks.sort()
        stat = dict.fromkeys(tasks, 0)
        for t in tasks:
            stat[t] = stat[t] + 1
        max_pair = max(stat.items(), key=operator.itemgetter(1))
        # timeof = (max_pair[1]-1) * (len(stat) if n < len(stat)-1 else n + 1)
        stat.pop(max_pair[0])
        letter_fre = 0;
        letter_key = []
        for key, val in stat.items():
            if val == max_pair[1]:
                letter_fre += 1
                n -= 1
                letter_key.append(key)
        for k in letter_key:
            stat.pop(k)
        timeof = (max_pair[1]-1) * n #todo
        count = 0
        for key, val in stat.items():
            count += val
        if count <= timeof:
            res = timeof + max_pair[1] * (letter_fre+1)
        else:
            res = timeof + max_pair[1] * (letter_fre+1) + count - timeof
        return res
if __name__ == "__main__":
    s = Solution()
    tasks = ["A","A","A","B","B","C","D","E","F","H"]
    n = 2
    res = s.leastInterval(tasks, n)
    pass    