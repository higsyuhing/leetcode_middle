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
    ListNode* deleteDuplicates(ListNode* head) {
        int flag, init, temp; 
        ListNode *curr, *last, *preserved, *lasttemp; 
        
        preserved = new ListNode(0); 
        preserved->next = head; 
        last = preserved; 
        curr = head; 
        flag = 0; // label if repeat
        init = 1; 
        
        while(curr != NULL){
            if(init == 1){
                temp = curr->val; 
                curr = curr->next; 
                init = 0; 
                continue; 
            }
            
            if(flag == 0){
                // if diff val, keep going
                if(curr->val != temp){
                    last = last->next; 
                    temp = curr->val; 
                    curr = curr->next; 
                }
                // if same, from diff to same, go next, set flag
                else{
                    curr = curr->next; 
                    flag = 1; 
                }
            }
            else{
                // if diff, clean up in between node
                if(curr->val != temp){
                    // keep deleting last->next until curr
                    while(last->next != curr){
                        lasttemp = last->next; 
                        last->next = lasttemp->next; 
                        delete lasttemp; 
                    }
                    temp = curr->val; 
                    flag = 0; 
                    curr = curr->next; 
                }
                // if same, keep next
                else{
                    curr = curr->next; 
                }
            }
        }
        // check flag and clean up if needed
        if(flag == 1){
            while(last->next != curr){
                lasttemp = last->next; 
                last->next = lasttemp->next; 
                delete lasttemp; 
            }
        }
        
        head = preserved->next; 
        delete preserved; 
        return head; 
    }
};
