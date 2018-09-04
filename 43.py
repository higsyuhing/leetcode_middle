class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        if len(num1) == 0 or len(num2) == 0: 
            return ""
        dic = {"0":0, "1":1, "2":2, "3":3, "4":4, "5":5, "6":6, "7":7, "8":8, "9":9}
        n1 = []
        n2 = []
        
        for char in num1: 
            if not dic.has_key(char): 
                print "unknown char: ", char
                return ""
            n1.append(dic[char])
            pass
        n1.reverse()
        for char in num2: 
            if not dic.has_key(char): 
                print "unknown char: ", char
                return ""
            n2.append(dic[char])
            pass
        n2.reverse()
        
        res = []
        for i in range(len(n1) + len(n2) - 1): 
            res.append(0)
            pass
        for r in range(len(n1)): 
            for c in range(len(n2)): 
                res[r+c] += n1[r]*n2[c]
                pass
            pass
        
        index = 0
        while 1: 
            # condition
            if index >= len(res): 
                break
                pass
            # process
            temp = res[index]
            res[index] = 0
            carrydigit = 0
            while temp > 0: 
                if (index + carrydigit) < len(res): 
                    res[index + carrydigit] += temp%10
                    pass
                else: 
                    res.append(temp%10)
                    pass
                temp = temp/10
                carrydigit += 1
                pass
            index += 1
            pass
        
        ret = []
        dic_rev = {0:"0", 1:"1", 2:"2", 3:"3", 4:"4", 5:"5", 6:"6", 7:"7", 8:"8", 9:"9"}
        for ele in res: 
            if not dic_rev.has_key(ele): 
                print "unknown number: ", ele
                return ""
            ret.append(dic_rev[ele])
            pass
        while len(ret) > 1 and ret[-1] == "0": 
            ret.pop()
            pass
        ret.reverse()
        return "".join(ret)
        
        
        
        
        
