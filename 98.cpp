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
    
    bool checkbst(TreeNode *node, int *retmin, int *retmax){
        // node is always valid, retmin and retmax are pointer to parent func var
        
        int min, max; 
        if(node->left){
            if(checkbst(node->left, &min, &max) == false) return false; 
            // valid and returned. 
            // if the max of left child tree is larger than curr node
            if(node->val <= max) return false; 
            // normal
            *retmin = min; 
        }
        else{
            // no left child
            *retmin = node->val; 
        }
        
        if(node->right){
            if(checkbst(node->right, &min, &max) == false) return false; 
            // if the min of right child tree is smaller than curr node
            if(node->val >= min) return false; 
            // normal
            *retmax = max; 
        }
        else{
            // no right child
            *retmax = node->val; 
        }
        return true; 
    }
    
    bool isValidBST(TreeNode* root) {
        // return the min and max value of the sub-tree
        // then compare and return
        // if false, directly return.. 
        if(root == NULL) return true; 
        
        int min, max; 
        return checkbst(root, &min, &max); 
    }
};
