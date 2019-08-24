class Solution:
    def parseBoolExpr(self, expression):
        tf = {'t':True, 'f':False}
        tf_res={True:'t', False:'f'}
        def parseSymbol(symbol, unit):
            if symbol == '&':
                words = unit.split(',')
                res = True
                for word in words:
                    res &= tf[word]
                return tf_res[res]
            elif symbol == '!':
                return tf_res[not tf[unit]]
            elif symbol == '|':
                words = unit.split(',')
                res = False
                for word in words:
                    res |= tf[word]
                return tf_res[res]
            else:
                return -1
        exp = []
        for s in expression:
            if s != ')':
                exp.append(s)
            else:
                end = ''
                unit = ''
                while end != '(' and len(exp) != 0:
                    unit += end
                    end = exp.pop()
                vv = parseSymbol(exp.pop(), unit)
                exp.append(vv)
        return tf[exp[0]]

if __name__ == "__main__":
    s = Solution()
    expression = "&(f,t)"
    expression1 = "|(&(t,f,t),!(t))"
    s.parseBoolExpr(expression)