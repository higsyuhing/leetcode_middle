class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        maxarea = 0
        l = 0
        r = len(height) - 1
        while (l < r):
            maxarea = max(maxarea, min(height[l], height[r]) * (r - l))
            if height[l] < height[r]: 
                l += 1
                pass
            else: 
                r -= 1
                pass
            pass
        return maxarea
        
        '''
        # alright... has O(N) algo... 
        length = len(height)
        arr = [] # 1 ... length - 1
        for i in range(length - 1): 
            diff = i + 1
            maxofmin = -1
            for j in range(length - 1 - i): 
                indexi = j
                indexj = j + diff
                tempmin = min(height[indexi], height[indexj])
                maxofmin = max(maxofmin, tempmin)
                pass
            arr.append(diff*maxofmin)
            pass
        return max(arr)
        '''
            
                    
        
        
        
        
        
        
        
        
