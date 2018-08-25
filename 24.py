# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None or head.next == None: 
            return head
        temp1 = head
        temp2 = head.next
        fakehead = ListNode(0)
        fakehead.next = head
        last = fakehead
        while 1: 
            # process
            temp = temp2.next
            temp2.next = temp1
            last.next = temp2
            last = temp1
            # condition and increamental
            if temp == None or temp.next == None: 
                last.next = temp
                break
                pass
            temp1 = temp
            temp2 = temp.next
            pass
        res = fakehead.next
        del fakehead
        return res
