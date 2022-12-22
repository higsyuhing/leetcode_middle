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
    // return: 
    // length of left zigzag, length of right zigzag
    pair<int, int> check(TreeNode *curr, int& ret){
        // curr never be nullptr
        if (curr->left == nullptr && curr->right == nullptr){
            return make_pair(1, 1); // both direction with 1 visited node
        }

        pair<int, int> pl(0, 0); 
        pair<int, int> pr(0, 0); 
        if (curr->left){
            pl = check(curr->left, ret); 
        }
        if (curr->right){
            pr = check(curr->right, ret); 
        }

        pair<int, int> p(0, 0); 
        p.first = pl.second + 1; 
        p.second = pr.first + 1; 
        ret = (pl.second > ret) ? pl.second : ret; 
        ret = (pr.first > ret) ? pr.first : ret; 

        // cout << curr->val << ": " << p.first << ", " << p.second << endl; 
        return p; 
    }

    int longestZigZag(TreeNode* root) {
        // recursion: child returns: 
        //  left/right direction and length
        // if the zigzag stops, check and update the maximum.. 
        int ret = 0; 
        pair<int, int> p = check(root, ret); 
        ret = ((p.second-1) > ret) ? (p.second-1) : ret; 
        ret = ((p.first-1) > ret) ? (p.first-1) : ret; 
        return ret; 
    }
};

