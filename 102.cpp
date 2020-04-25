/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        // almost same as lc103.. 
        
        // use a global queue and a flag.. 
        queue<TreeNode *> travqueue; 
        
        vector<vector<int>> res; 
        vector<int> tempstack; 
        
        if(root == NULL) return res; 
        else travqueue.push(root); 
        travqueue.push(NULL); 
        
        TreeNode *currnode; 
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
                if(currnode->left) travqueue.push(currnode->left); 
                if(currnode->right) travqueue.push(currnode->right); 
            }
        }
        
        return res; 
    }
};
