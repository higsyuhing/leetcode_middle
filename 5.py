class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        # all searching space is [start, end), start <= end
        # then, it will be a pic like below: 
        #  + + + + + + + + +
        #  + * * * * * * * * 
        #  + + * * * * * * *, go up-right direction
        #  + + + * * * * * *, then it will be 2n-1 search time
        #  ...              , then and reduce the searching cost
        #  + + + + + + + + *
        res = [0, 0]
        lenmax = 0
        length = len(s)
        for x in range(2*length - 1): 
            # ymax = x/2 + 1
            ci = x/2 # central (i)
            yrange = min((x/2+1), ((2*length - 2 - x)/2+1))
            #print ci
            if x%2 == 1: # offset 1
                cj = ci + 1
                for y in range(yrange): 
                    tempi = ci - y
                    tempj = cj + y
                    if s[tempi] == s[tempj]: 
                        if (y*2+1) > lenmax: 
                            res = [tempi, tempj]
                            lenmax = (y*2+1)
                            pass
                        pass
                    else: 
                        break
                        pass
                    pass
                pass
            else: # offset 0
                cj = ci
                for y in range(yrange): 
                    tempi = ci - y
                    tempj = cj + y
                    if s[tempi] == s[tempj]: 
                        if (2*y) > lenmax: 
                            res = [tempi, tempj]
                            lenmax = 2*y
                            pass
                        pass
                    else: 
                        break
                        pass
                    pass
                pass
            pass
        #print res
        return s[res[0]:(res[1]+1)]
        
        
