# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        p1 = l1
        p2 = l2
        p3 = ListNode(0) # result
        head = p3
        carry = 0
        while 1: 
            if p1 != None and p2 != None: 
                num = p1.val + p2.val + carry
                carry = num/10
                num = num%10
                temp = ListNode(num)
                p3.next = temp
                
                p1 = p1.next
                p2 = p2.next
                p3 = temp
                pass
            elif p1 == None and p2 != None: 
                num = p2.val + carry
                carry = num/10
                num = num%10
                temp = ListNode(num)
                p3.next = temp
                
                p2 = p2.next
                p3 = temp
                pass
            elif p1 != None and p2 == None: 
                num = p1.val + carry
                carry = num/10
                num = num%10
                temp = ListNode(num)
                p3.next = temp
                
                p1 = p1.next
                p3 = temp
                pass
            else: 
                # both None
                num = carry
                if num == 0: 
                    break
                    pass
                carry = num/10
                num = num%10
                temp = ListNode(num)
                p3.next = temp
                p3 = temp
                pass
            pass
        temp = head
        head = head.next
        del temp
        return head
                
        
