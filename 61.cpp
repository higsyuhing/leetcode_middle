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
    ListNode* rotateRight(ListNode* head, int k) {
        
        // 1. determine the length of list (including cycle LL?)
        int length = 0; 
        ListNode *temp, *curr; 
        temp = head; 
        
        while(temp != NULL){
            length++; 
            curr = temp; 
            temp = temp->next; 
            if(temp == head){
                cout << "head and cycle LL!" << endl; 
                break; 
            }
        }
        
        // doesn't make sense if no LL or unit LL (no shift in fact)
        if(length == 0 || length == 1) return head; 
        
        // 2. create a space for temp k%N data, fill in to it
        k = k % length; 
        if(k == 0) return head; 
        // no, in fact, you just change the link "next"
        
        // 3. move data in-place
        // move data's relationship.. 
        
        k = length - k; 
        curr->next = head; // cycle first
        temp = head; 
        while(k > 0){
            curr = temp; 
            temp = temp->next; 
            k--; 
        }
        curr->next = NULL; 
        return temp; 
        
    }
};
