class Solution(object):
    def func(self, candidates, index, target): 
        #print index, candidates[index], target
        if target == 0: 
            return [[]]
        length = len(candidates) - 1 - index
        ret = []
        last = -1
        for i in range(length): 
            curr = candidates[index + 1 + i]
            #print "\t", curr
            if curr == last: 
                continue
                pass
            curr_target = target - curr
            if curr_target < 0: 
                break
                pass
            '''
            if curr_target < curr: 
                if curr_target == 0: 
                    ret.append([curr])
                    pass
                break
                pass
            '''
            res = self.func(candidates, index + 1 + i, curr_target)
            if len(res) > 0: 
                for each in res: 
                    ret.append([curr] + each)
                    pass
                pass
            last = curr
            pass
        return ret
    
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        #print candidates
        length = len(candidates)
        ret = []
        index = 0
        last = -1
        while index < length: 
            curr = candidates[index]
            if curr == last: 
                index += 1
                continue
                pass
            curr_target = target - curr
            if curr_target < 0: 
                break
                pass
            '''
            if curr_target < curr: 
                if curr_target == 0: 
                    ret.append([curr])
                    pass
                break
                pass
            '''
            res = self.func(candidates, index, curr_target)
            #print curr, res
            if len(res) > 0: 
                for each in res: 
                    ret.append([curr] + each)
                    pass
                pass
            last = curr
            index += 1
            pass
        return ret
        
        # what? this answer can beat 95% python submit? 
        # I think this answer not very good... 
        # since it cannot record duplicate computation
        # e.g. 1,2,3,4,...: [2,3] and [1,4] share the same remaining computation... 
        # the solution in csdn etc. is pretty good
        # but how to avoid the case above? post it on leetcode, lets see
        
        
        
        
        
        
        
        
        
        
