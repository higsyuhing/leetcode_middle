/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // 2 pointer: 
        //  - fast pointer: jump 2, then slow pointer, also maintain a parent pointer
        // if fast pointer can not jump 1 (current is len-1), no modify
        // if fast pointer can jump 1 but not 2, then slow pointer move 1 ahead
        if (head == nullptr) return nullptr; 
        ListNode *fastptr, *slowptr, *sparentptr; 
        fastptr = head; 
        slowptr = head; 
        sparentptr = nullptr; 
        // bool flag_jump1 = false; 

        while(1){
            if (fastptr->next == nullptr) break; 

            // some original code here.. 

            sparentptr = slowptr; 
            slowptr = slowptr->next; 

            fastptr = fastptr->next; 
            if (fastptr->next == nullptr) break; 
            fastptr = fastptr->next; 
        }

        // if (flag_jump1){
        //     sparentptr = slowptr; 
        //     slowptr = slowptr->next; 
        // }

        if (sparentptr == nullptr){ // only 1 element
            delete head; 
            return nullptr; 
        }
        sparentptr->next = slowptr->next; 
        delete slowptr; 
        return head; 
    }
};
