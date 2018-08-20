class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        # input guaranteed in [1, 3999]
        arr = []
        temp = num
        while temp > 0: 
            arr.append(temp%10)
            temp = temp/10
            pass
        strarr = []
        level =[["","I","II","III","IV","V","VI","VII","VIII","IX"], 
                ["","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"], 
                ["","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"], 
                ["","M","MM","MMM"]]
        index = 0
        for ele in arr: 
            temp = level[index][ele]
            strarr.append(temp)
            index += 1
            pass
        strarr.reverse()
        return "".join(strarr)
