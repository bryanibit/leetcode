class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        """
        :type A: int
        :type B: int
        :type C: int
        :type D: int
        :type E: int
        :type F: int
        :type G: int
        :type H: int
        :rtype: int
        """
        rect1v = set()
        for i in range(A, C+1):
            rect1v.add(i)
        rect2v = set()
        for i in range(E, G+1):
            rect2v.add(i)
        rectv = rect1v.intersection(rect2v)
        rect1h = set()
        for i in range(B, D+1):
            rect1h.add(i)
        rect2h = set()
        for i in range(F, H+1):
            rect2h.add(i)
        recth = rect1h.intersection(rect2h)
        interction_area = (lambda x: x if x >= 0 else 0)(len(recth) - 1) * (
        (lambda x: x if x >= 0 else 0)(len(rectv) - 1))
        sum_area = (C-A)*(D-B) + (G-E)*(H-F)
        return (sum_area - interction_area)

        
if __name__ == "__main__":
    s = Solution()
    x = s.computeArea(A=-2, B=-2, C=2, D=2, E=3, F=3, G=4, H=4)
    pass