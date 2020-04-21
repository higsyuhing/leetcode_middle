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
    void traverse(TreeNode *curr, int i, vector<int>& res){
        if(curr == NULL) return; 
        if(i < res.size()) res[i] = curr->val; 
        else res.push_back(curr->val); 
        
        traverse(curr->left, i+1, res); 
        traverse(curr->right, i+1, res); 
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        // so.. any potential problem here? 
        // I see, left side is longer than right side: 
        //              1
        //          2.     3
        //.       4.  5. 6   null
        //      7.  8
        
        // this is a left to right traverse. (in fact same)
        // if have value, update, otherwise push_back value
        
        vector<int> res; 
        TreeNode *curr = root; 
        int i = 0; 
        
        // the only way is recursive traverse, iterative doesn't work
        // since iterative pop parent first, thus stack depth != tree hight
        traverse(curr, i, res); 
        
        return res; 
    }
};
