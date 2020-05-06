/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // use fast/slow pointer: 2 times faster
        // assume start -> begin is step p. 
        //          begin -> meet is step u
        //          meet -> end is step v
        // thus: slow = p+u, fast = p+u+v+u = 2*slow => 
        //      v = p => starting from meeting point and head, 
        //      step 1 will make them meet at the begining. :)
        
        ListNode *fast, *slow; 
        fast = head; slow = head; 
        int init = 1; 
        
        if(head == NULL || head->next == NULL) return NULL; 
        
        while(1){
            if(init == 0){
                if(fast == slow) break; 
            }
            else init = 0; 
            
            if(fast == NULL || fast->next == NULL) return NULL; 
            fast = fast->next->next; 
            slow = slow->next; 
        }
        
        // find the meeting point
        slow = head; 
        while(1){
            if(fast == slow) return fast; 
            
            fast = fast->next; 
            slow = slow->next; 
        }
        // never reach here.. 
    }
};
