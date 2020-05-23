/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // first copy, and create hash
        // second copy, use hash to find corresponding random.. 
        
        if(head == NULL) return NULL; 
        
        Node *res, *temp, *tempo, *last; 
        map<Node *, Node *> nodehash; 
        
        res = new Node(head->val); 
        nodehash[head] = res; 
        
        tempo = head->next; 
        last = res; 
        while(tempo != NULL){
            temp = new Node(tempo->val); 
            last->next = temp; 
            
            nodehash[tempo] = temp; 
            last = temp; 
            tempo = tempo->next; 
        }
        last->next = NULL; 
        
        nodehash[NULL] = NULL; 
        
        tempo = head; 
        temp = res; 
        while(tempo != NULL){
            temp->random = nodehash[tempo->random]; 
            
            tempo = tempo->next; 
            temp = temp->next; 
        }
        
        return res; 
    }
};
