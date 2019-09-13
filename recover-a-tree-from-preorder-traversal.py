# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class PTreeNode:
    def __init__(self, x, p):
        self.val = x
        self.left = None
        self.right = None
        self.parent = p

class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        parent = TreeNode(-1)
        count_num = 0
        count_letter = 0
        num = 0
        for i in S:
            if i != '-':
                clc = -1
                if count_letter != 0:
                    clc = count_letter
                    count_letter = 0
                    count_num = -1
                    num = 0
                count_num += 1
                num = int(i) + num * count_num
                print('num:{}'.format(num))
            else:
                if count_num != 0:
                    count_num = 0
                    count_letter = 0
                count_letter += 1
                print('letter:{}'.format(count_letter))

if __name__ == "__main__":
    s = Solution()
    S = "1-401--349---90--88"
    s.recoverFromPreorder(S)
