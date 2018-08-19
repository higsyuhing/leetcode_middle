class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows <= 1: 
            return s
        nummid = numRows - 2
        head = []
        tail = []
        middle = []
        for i in range(nummid): 
            middle.append([])
            pass
        direction = True # top-down
        index = 0
        cycle = 2 + (numRows - 2)*2
        for char in s: 
            if index%cycle == 0: 
                head.append(char)
                direction = True
                pass
            elif (index - cycle/2)%cycle == 0: 
                tail.append(char)
                direction = False
                pass
            elif direction: 
                temp = index%(cycle/2) - 1
                middle[temp].append(char)
                pass
            else: # direction == False
                temp = index%(cycle/2) - 1
                middle[nummid - 1 - temp].append(char)
                pass
            index += 1
            pass
        res = "".join(head)
        for i in range(nummid): 
            res += "".join(middle[i])
            pass
        res += "".join(tail)
        return res
