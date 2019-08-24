class Solution:
    def reverseVowels(self, st: str) -> str:
        s = [i for i in st]
        i = 0
        j = len(s) - 1
        vowel = set(['a','e','i','o','u'])
        while i < j:
            if s[i] not in vowel:
                i += 1
                
            if s[j] not in vowel:
                j -= 1
                  
            if s[i] in vowel and s[j] in vowel:
                temp = s[i]
                s[i] = s[j]
                s[j] = temp
                i += 1
                j -= 1
        return ''.join(s)
if __name__ == "__main__":
    s = Solution()
    st = "hellomyfriand"
    s.reverseVowels(st)            