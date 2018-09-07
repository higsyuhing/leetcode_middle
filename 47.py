class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ret = []
        if len(nums) == 0: 
            return [[]]
        if len(nums) == 1: 
            return [nums]
        nums.sort()
        last = -11111111
        for i in range(len(nums)): 
            curr = nums[i]
            if last == curr: 
                continue
                pass
            res = self.permuteUnique(nums[0:i] + nums[(i+1):])
            for ele in res: 
                ret.append([curr] + ele)
                pass
            last = curr
            pass
        return ret
