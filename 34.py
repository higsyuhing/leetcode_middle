class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # two search
        if len(nums) == 0: 
            return [-1, -1]
        # first
        first = -1
        start = 0
        end = len(nums)
        while start < end: 
            mid = (start + end)/2
            temp = nums[mid]
            if temp >= target: 
                end = mid
                pass
            else: 
                start = mid + 1
                pass
            pass
        if start < len(nums) and nums[start] == target: 
            first = start
            pass
        # second
        second = -1
        start = 0
        end = len(nums)
        while start < (end - 1): 
            mid = (start + end)/2
            temp = nums[mid]
            if temp > target: 
                end = mid
                pass
            else: 
                start = mid
                pass
            pass
        if start < len(nums) and nums[start] == target: 
            second = start
            pass
        return [first, second]
            
        
        
        
