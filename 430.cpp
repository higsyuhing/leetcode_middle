/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node *transform(Node* head){
        // head is guaranteed valid. 
        
        Node *curr = head; // curr is valid node
        while(curr->next){ // exist next
            if(curr->child){
                Node *childtail = transform(curr->child); 
                Node *temp = curr->next; 
                curr->next = curr->child; 
                curr->child->prev = curr; 
                curr->child = NULL; 
                childtail->next = temp; 
                temp->prev = childtail; 
                
                curr = temp; 
            }
            else curr = curr->next; 
        }
        // curr->next == NULL
        if(curr->child){
            Node *childtail = transform(curr->child); 
            curr->next = curr->child; 
            curr->child->prev = curr; 
            curr->child = NULL; 
            return childtail; 
        }
        return curr; 
    }
    
    Node* flatten(Node* head) {
        // dfs.. 
        // use a helper function.. 
        // return the end node pointer. 
        
        if(head == NULL) return NULL; 
        
        Node *tail; 
        tail = transform(head); 
        return head; 
    }
};
