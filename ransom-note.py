class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        letterNote = [char for char in ransomNote]
        letterMaga = [char for char in magazine]
        for l in letterNote:
            if letterMaga.count(l) > 0:
                letterMaga.remove(l)
            else:
                return False
        return True
if __name__ == "__main__":
    s = Solution()
    str1 = 'aa'
    str2 = 'aab'
    x = s.canConstruct(str1, str2)
    pass