class Solution(object):
    def normalsearch(self, nums, target): 
        ii = 0
        jj = len(nums)
        while ii < jj: 
            # print ii, jj
            mid = (ii + jj)/2
            temp = nums[mid]
            if temp == target: 
                return mid
            elif temp > target: 
                jj = mid
                pass
            else: 
                ii = mid + 1
                pass
            pass
        return -1
    
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # the sol in CSDN is better than me. 
        # https://blog.csdn.net/linhuanmars/article/details/20525681
        ii = 0
        jj = len(nums)
        if jj == 0: 
            return -1
        mid = (ii + jj)/2
        # print nums, jj
        if nums[0] < nums[mid]: 
            if nums[0] <= target and target <= nums[mid]: 
                return self.normalsearch(nums[0:(mid+1)], target)
            else: 
                ret = self.search(nums[(mid+1):], target)
                if ret == -1: 
                    return -1
                else: 
                    return mid + 1 + ret
            pass
        else: 
            # nums[0] >= nums[mid], i.e. nums[mid] < nums[len-1]
            if nums[mid] <= target and target <= nums[-1]: 
                ret = self.normalsearch(nums[mid:], target)
                if ret == -1: 
                    return -1
                else: 
                    return mid + ret
            else: 
                return self.search(nums[0:mid], target)
            pass
        pass
        
