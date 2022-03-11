/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int nodelabel(TreeNode* node, vector<vector<int>>& result){
        int left, right; 
        
        if(node->left == NULL) left = 0; 
        else left = nodelabel(node->left, result); 
        
        if(node->right == NULL) right = 0; 
        else right = nodelabel(node->right, result); 
        
        // now left/right means the height for left/right sub-tree
        int curr = (left > right) ? left : right; 
        
        // add into the result
        // guaranteed we have "curr-1" element. 
        // but "curr" is not sure.. 
        if(result.size() == curr){
            vector<int> tmp; 
            tmp.push_back(node->val); 
            result.push_back(tmp); 
        }
        else{
            result[curr].push_back(node->val); 
        }
        
        // return height+1
        return (curr+1); 
    }
    
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        // use a helper function for getting the label of a node. 
        // the label means the max-depth from this curr node
        vector<vector<int>> result; 
        
        nodelabel(root, result); 
        
        return result; 
    }
};


