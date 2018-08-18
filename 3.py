class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        linklist = []
        eledic = {}
        ret = 0
        for char in s: 
            if eledic.has_key(char): 
                # has same element
                while 1: 
                    temp = linklist[0]
                    if temp != char: 
                        del eledic[temp]
                        del linklist[0]
                        pass
                    else: 
                        del linklist[0]
                        linklist.append(char)
                        break
                        pass
                    pass
                # if has same ele, the length must be shrink <=
                pass
            else:
                # all are diff, then directly add it
                linklist.append(char)
                eledic[char] = 1
                ret = max(ret, len(linklist))
                pass
            pass
        return ret
