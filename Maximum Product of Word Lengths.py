class Solution:
    def maxProduct(self, words):
        new_words = []
        for word in words:
            new_words.append(set([i for i in word]))
        max_val = 0
        for i in range(len(new_words)):
            for j in range(i+1, len(new_words)):
                if new_words[i] & new_words[j]:
                    continue
                else:
                    max_val = max(max_val, len(words[i]) * len(words[j]))
        return max_val
if __name__ == "__main__":
    s = Solution()
    words = ["abcw","baz","foo","bar","xtfn","abcdef"]
    s.maxProduct(words)            