class Solution(object):
    def permute(self, nums):
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
        for i in range(len(nums)): 
            curr = nums[i]
            res = self.permute(nums[0:i] + nums[(i+1):])
            for ele in res: 
                ret.append([curr] + ele)
                pass
            pass
        return ret
