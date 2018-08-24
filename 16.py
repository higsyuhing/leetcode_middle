class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        length = len(nums)
        res = 1000000
        ret = 0
        for index in range(length): 
            i = index - 1
            j = index + 1
            while 1: 
                if i < 0 or j >= length: 
                    break
                    pass
                temp = nums[i] + nums[j] + nums[index]
                if abs(temp - target) < res: 
                    #print nums[i], nums[index], nums[j]
                    res = abs(temp - target)
                    ret = temp
                    pass
                if temp < target: 
                    j += 1
                    pass
                else: 
                    i -= 1
                    pass
                pass
            pass
        return ret
