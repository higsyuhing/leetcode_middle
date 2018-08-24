class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        length = len(nums)
        if length < 4: 
            return []
        nums.sort()
        #print nums
        res = []
        for i in range(length-3): 
            # i range [0, length-3)
            num1 = nums[i]
            if i > 0 and num1 == nums[i-1]: 
                continue
                pass
            for j in range(length-3-i): 
                # j range [i+1, len-2)
                num2 = nums[i+1+j]
                if j > 0 and num2 == nums[i+j]: 
                    continue
                    pass
                subtarget = target - num1 - num2
                p = j + i + 2
                lastp = nums[0] - 1
                q = length - 1
                lastq = nums[0] - 1 # never duplicate
                while p < q: 
                    #print i, (i+j+1), p, q
                    num3 = nums[p]
                    num4 = nums[q]
                    subsum = num3 + num4
                    if subsum == subtarget: 
                        #print "res!"
                        res.append([num1, num2, num3, num4])
                        p += 1
                        q -= 1
                        pass
                    elif subsum < subtarget: 
                        p += 1
                        pass
                    else: 
                        q -= 1
                        pass
                    pass
                pass
            pass
        #print res
        index = 0
        while 1: 
            if index >= len(res): 
                break
                pass
            #print len(res), index
            if index > 0 and res[index] == res[index - 1]: 
                del res[index]
                pass
            else: 
                index += 1
                pass
            pass
        return res
                    
                    
