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
    int helper(TreeNode* curr, int& ret){
        if (curr == nullptr)
            return 0; // no change
        
        int left = helper(curr->left, ret); 
        int right = helper(curr->right, ret); 
        int res = left + right + curr->val - 1; // curr need '1'
        ret += ((res > 0) ? res : (-res)); 
        return res; 
    }

    int distributeCoins(TreeNode* root) {
        int ret = 0; 
        helper(root, ret); 
        return ret; 
    }
};
