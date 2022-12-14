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

    void helper(TreeNode* curr, int& ret, TreeNode *grandpar, TreeNode *par){
        if (curr == nullptr)
            return; 
        
        if (grandpar != nullptr && (grandpar->val%2 == 0)){
            ret += curr->val; 
        }
        helper(curr->left, ret, par, curr); 
        helper(curr->right, ret, par, curr); 
    }

    int sumEvenGrandparent(TreeNode* root) {
        int ret = 0; 
        helper(root, ret, nullptr, nullptr); 
        return ret; 
    }
};
