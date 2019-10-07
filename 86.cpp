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
    ListNode* partition(ListNode* head, int x) {
        ListNode *less, *curr, *preserved, *temp; 
        // the "less" points to the last one less than x
        // the "curr" points to the last one greater/equal to x
        
        // create a fake head
        preserved = new ListNode(0); 
        preserved->next = head; 
        
        less = preserved; 
        curr = preserved; 
        // 1st move forward, locate the first divergence point
        while(less->next != NULL){
            temp = less->next; 
            if(temp->val < x) less = temp; 
            else break; 
        }
        curr = less; 
        
        while(curr->next != NULL){
            temp = curr->next; 
            if(temp->val < x){
                curr->next = temp->next; 
                temp->next = less->next; 
                less->next = temp; 
                less = temp; 
            }
            else{
                curr = temp; 
            }
        }
        
        temp = preserved->next; 
        delete preserved; 
        return temp; 
    }
};
