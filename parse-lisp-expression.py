class Solution:
    def evaluate(self, expression):
        stack=[]
        varible = {}
        words = expression.split()
        for i in words:
            if i == '(let':
                pass
            elif i == '(mul':
                pass
                # find two vals
            elif i == '(add':
                # find two vals
                pass
            else:
                pass
        pass
if __name__ == "__main__":
    s = Solution()
    expression='(let x 2 (add (let x 3 (let x 4 x)) x))'
    s.evaluate(expression)        