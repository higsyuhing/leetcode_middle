class Solution(object):
    def func(self, digitarr, dic): 
        if len(digitarr) == 0: 
            return []
        char = digitarr[0]
        if not dic.has_key(char): 
            print "invalid input char! ", char
            return []
        charres = dic[char]
        arrremains = self.func(digitarr[1:], dic)
        if len(arrremains) == 0: 
            return charres
        ret = []
        for chari in charres: 
            for charj in arrremains: 
                temp = chari + charj
                ret.append(temp)
                pass
            pass
        return ret
    
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        # it has a recursive functionality
        dic = {"1":["*"], "2":["a", "b", "c"], "3":["d", "e", "f"], "4":["g", "h", "i"], "5":["j", "k", "l"], "6":["m", "n", "o"], "7":["p", "q", "r", "s"], "8":["t", "u", "v"], "9":["w", "x", "y", "z"], "0":[" "]}
        return self.func(list(digits), dic)
