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
    void helper(TreeNode *node, int &sum){
        if (node == nullptr)
            return; 
        
        // reverse traversal
        helper(node->right, sum); 
        sum += node->val; 
        node->val = sum; 
        helper(node->left, sum); 
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0; 
        helper(root, sum); 
        return root; 
    }
};
