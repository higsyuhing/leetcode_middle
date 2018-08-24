# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        temp = head
        for i in range(n): 
            if temp == None: 
                return head
            temp = temp.next
            pass
        if temp == None: 
            res = head.next
            del head
            return res
        parent = head
        while temp.next != None: 
            temp = temp.next
            parent = parent.next
            pass
        target = parent.next
        parent.next = target.next
        del target
        return head
        
        
        
        
        
