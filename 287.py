class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        '''
        I found the Approach #3 is not correct with the input: [2,3,0,3,3]
        Since there is a loop 0->2->0->2..., the duplicate number 3 will never be reached.
        The reason for this, is that a perfect length n array may not generate one link list loop, for example:
        [2,3,4,5,0,1] (2 linked list loops: 0->2->4->0... and 1->3->5->1...)
        '''
        # Find the intersection point of the two runners.
        tortoise = nums[0]
        hare = nums[0]
        while True:
            tortoise = nums[tortoise]
            hare = nums[nums[hare]]
            if tortoise == hare:
                break
                pass
            pass
        
        # Find the "entrance" to the cycle.
        ptr1 = nums[0]
        ptr2 = tortoise
        while ptr1 != ptr2:
            ### what about they go to the same "3" in intuition, not 6, is that possible? 
            ptr1 = nums[ptr1]
            ptr2 = nums[ptr2]
            pass
        
        return ptr1
