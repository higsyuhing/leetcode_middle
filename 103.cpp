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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        // use a global queue and a flag.. 
        int left2right = 1; // 0 is from right to left
        queue<TreeNode *> travqueue; 
        
        vector<vector<int>> res; 
        vector<int> tempstack; 
        vector<int> tempvec; 
        
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
                if(left2right){
                    res.push_back(tempstack); 
                    tempstack.clear(); 
                }
                else{
                    res.push_back(tempvec); 
                    int last = res.size()-1; 
                    for(int i = tempstack.size()-1; i >= 0; i--){
                        res[last].push_back(tempstack[i]); 
                    }
                    tempstack.clear(); 
                }
                
                travqueue.push(NULL); 
                left2right = 1 - left2right; 
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
