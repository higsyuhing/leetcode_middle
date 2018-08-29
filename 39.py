class Solution(object):
    def func(self, candidates, res, target, current, last): 
        if target < 0: 
            return
        if target == 0: 
            res.append(current)
            return
        for num in candidates: 
            if num < last: 
                continue
                pass
            # at least >= last
            newcurr = list(current)
            newcurr.append(num)
            self.func(candidates, res, target - num, newcurr, num)
            pass
        pass
    
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        # get hint by CSDN: 
        # https://blog.csdn.net/zjkC050818/article/details/73527689
        if len(candidates) < 1: 
            return []
        candidates.sort()
        res = []
        self.func(candidates, res, target, [], 0)
        return res
        
