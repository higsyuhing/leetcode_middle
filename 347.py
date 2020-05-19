class Solution:
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """ 
        # this code.. feel cheating.. 
        count = collections.Counter(nums)   
        return heapq.nlargest(k, count.keys(), key=count.get) 

'''
        # looks like all sorting is better.. 
        # due to the heap management overhead? 
        numdict = {} #Counter of elements
        for num in nums:
            numdict[num] = numdict.get(num, 0) + 1
            #print("num:",num,".",numdict.get(num, 0))
        output = [] #stores all elements sorted by frequency
        for num in sorted(numdict, key = numdict.get, reverse = True):
            output.append(num)
        return output[:k]
'''
