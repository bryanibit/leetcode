class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        def cmp_to_key(mycmp):
            class K(object):
                def __init__(self, obj, *args):
                    self.obj = obj
                def __lt__(self, other):
                    return mycmp(self.obj, other.obj) < 0
                def __gt__(self, other):
                    return mycmp(self.obj, other.obj) > 0
                def __eq__(self, other):
                    return mycmp(self.obj, other.obj) == 0
                def __le__(self, other):
                    return mycmp(self.obj, other.obj) <= 0
                def __ge__(self, other):
                    return mycmp(self.obj, other.obj) >= 0
                def __ne__(self, other):
                    return mycmp(self.obj, other.obj) != 0
            return K
        def comparePeople(people1, people2):
            if people1[0] != people2[0]:
                return people2[0] - people1[0]
            else:
                # because equal vals contribute to people[2]
                return people1[1] - people2[1]

        sortedPeople = sorted(people, key=cmp_to_key(comparePeople))
        res = []
        for p in sortedPeople:
            res.insert(p[1],p)
        return res

if __name__ == "__main__":
    s = Solution()
    people = [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
    s.reconstructQueue(people)
    pass
