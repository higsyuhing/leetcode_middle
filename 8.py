class Solution(object):
    def myAtoi(self, string):
        """
        :type str: str
        :rtype: int
        """
        sign = True # positive
        num = []
        index = 0
        for char in string: 
            if char != " ": 
                break
                pass
            index += 1
            pass
        if index == len(string): 
            return 0
        char = string[index]
        if char == "+" or char == "-" or (ord(char) >= 48 and ord(char) < 58): 
            if char == "+": 
                index += 1
                pass
            elif char == "-": 
                index += 1
                sign = False
                pass
            while index < len(string): 
                char = string[index]
                if ord(char) >= 48 and ord(char) < 58: 
                    num.append(ord(char) - 48)
                    pass
                else: 
                    break
                    pass
                index += 1
                pass
            if len(num) == 0: 
                return 0
            else: 
                retnum = 0
                for ele in num: 
                    retnum = retnum*10 + ele
                    pass
                if not sign: 
                    retnum = -retnum
                    pass
                if retnum > 2147483647: 
                    return 2147483647
                elif retnum < -2147483648: 
                    return -2147483648
                else: 
                    return retnum
                pass
            pass
        else: 
            return 0
        pass
