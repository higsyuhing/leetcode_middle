class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) < 3: 
            return []
        nums.sort()
        dic = {}
        index = 0
        for ele in nums: 
            if dic.has_key(ele): 
                dic[ele].append(index)
                pass
            else: 
                dic[ele] = [index]
                pass
            index += 1
            pass
        res = []
        length = len(nums)
        #print nums
        for ii in range(length - 2): 
            num1 = nums[ii]
            if ii > 0 and nums[ii-1] == num1: 
                continue
                pass
            #print num1
            for jj in range(length - 1 - ii - 1): 
                # jj range: [ii+1, len-2] => [ii+1, len-1)
                realjj = ii + 1 + jj
                num2 = nums[realjj]
                if jj > 0 and nums[realjj-1] == num2: 
                    continue
                    pass
                #print "\t", num2
                # core
                testnum3 = 0 - num1 - num2
                if testnum3 < num2 or not dic.has_key(testnum3): 
                    # in this case, we should find testnum3 before num2
                    # target number cannot be found
                    pass
                else: 
                    if testnum3 == num2: 
                        if num2 == num1 and len(dic[num2]) < 3: 
                            pass
                        elif len(dic[num2]) < 2: 
                            pass
                        else: 
                            res.append([num1, num2, testnum3])
                            pass
                        pass
                    else: 
                        res.append([num1, num2, testnum3])
                        pass
                    pass
                pass
            pass
        return res
    
        '''
        # looks like we need to de-duplicate
        if len(res) < 2: 
            return res
        else: 
            index = 0
            while 1: 
                pair = index + 1
                if pair == len(res): 
                    return res
                if res[index] == res[pair]: 
                    del res[pair]
                    pass
                else: 
                    index += 1
                    pass
                pass
            pass
        pass
        '''
                    
                
                
