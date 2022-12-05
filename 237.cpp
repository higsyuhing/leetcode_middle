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
    void deleteNode(ListNode* node) {
        // not the last node, thus just move the value to the previous one... 
        ListNode *curr = node; 
        ListNode *currnext = curr->next; 

        while (currnext->next != NULL){
            curr->val = currnext->val; 
            curr = currnext; 
            currnext = currnext->next; 
        }

        curr->val = currnext->val; 
        curr->next = NULL; 
        // free(currnext); 
    }
};
