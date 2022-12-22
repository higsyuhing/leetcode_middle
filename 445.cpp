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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> val1, val2; 
        ListNode *curr = l1; 
        while (curr){
            val1.push(curr->val); 
            curr = curr->next; 
        }
        curr = l2; 
        while (curr){
            val2.push(curr->val); 
            curr = curr->next; 
        }
        curr = nullptr; 
        int carry = 0; 
        while (1){
            int v1, v2; 
            v1 = 0; v2 = 0; 
            bool flag1, flag2; 
            flag1 = true; flag2 = true; 
            if (!val1.empty()){
                v1 = val1.top(); 
                val1.pop(); 
            }
            else{
                flag1 = false; 
            }
            if (!val2.empty()){
                v2 = val2.top(); 
                val2.pop(); 
            }
            else{
                flag2 = false; 
            }
            if (flag1 == false && flag2 == false && carry == 0)
                break; 
            carry += (v1+v2); 

            ListNode *tmp = new ListNode(carry % 10, curr); 
            carry = carry / 10; 
            curr = tmp; 
        }
        if (curr == nullptr){
            curr = new ListNode(); 
        }
        return curr; 
    }
};
