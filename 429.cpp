/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        // same as lc102. 
        // some other solution. learn from them, write clean/clear code! 
        // this version is even worse than mine....... anyway.. 
        
        if (!root) {
            return vector<vector<int>>();
        }
        vector<vector<int>> result;
        queue<Node*> helper;
        helper.push(root);
        while(!helper.empty()) {
            int count = helper.size();
            vector<int> res;
            for (int i = 0; i < count; ++i) {
                Node* node = helper.front();
                res.push_back(node->val);
                for (const auto child:node->children) {
                    helper.push(child);
                }
                helper.pop();
            }
            result.push_back(res);
        }
        return result;
        
        
        /*
        // use a global queue and a flag.. 
        queue<Node *> travqueue; 
        
        vector<vector<int>> res; 
        vector<int> tempstack; 
        
        if(root == NULL) return res; 
        else travqueue.push(root); 
        travqueue.push(NULL); 
        
        Node *currnode; 
        while(1){
            currnode = travqueue.front(); 
            travqueue.pop(); 
            
            if(currnode == NULL){
                //cout << "NULL" << endl; 
                
                if(tempstack.size() == 0) break; 
                res.push_back(tempstack); 
                tempstack.clear(); 
                
                travqueue.push(NULL); 
                continue; 
            }
            else{
                //cout << currnode->val << endl; 
                tempstack.push_back(currnode->val); 
                for(int i = 0; i < currnode->children.size(); i++)
                    if(currnode->children[i]) travqueue.push(currnode->children[i]); 
            }
        }
        
        return res; 
        */
    }
};
