/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(node == NULL) return NULL; 
        
        unordered_map<Node*, Node*> mapo2n; 
        queue<Node *> tempqueue; 
        
        tempqueue.push(node); 
        Node *tempnode, *newnode, *neighbornode; 
        while(tempqueue.size() != 0){
            tempnode = tempqueue.front(); 
            tempqueue.pop(); 
            
            newnode = new Node(tempnode->val); 
            mapo2n[tempnode] = newnode; 
            for(int i = 0; i < tempnode->neighbors.size(); i++){
                neighbornode = tempnode->neighbors[i]; 
                if(mapo2n.find(neighbornode) == mapo2n.end())
                    tempqueue.push(neighbornode); 
            }
        }
        
        for(auto it = mapo2n.begin(); it != mapo2n.end(); it++){
            tempnode = it->first; 
            newnode = it->second; 
            
            for(int i = 0; i < tempnode->neighbors.size(); i++){
                neighbornode = tempnode->neighbors[i]; 
                newnode->neighbors.push_back(mapo2n[neighbornode]); 
            }
        }
        
        return mapo2n[node]; 
    }
};
