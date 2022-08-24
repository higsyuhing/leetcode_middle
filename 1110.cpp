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
    
    void helper_treetraverse(TreeNode* node, map<int, pair<TreeNode*, TreeNode*> >& treemap, TreeNode* parent){
        if (node == NULL) return; 
        treemap[node->val] = make_pair(node, parent); 
        helper_treetraverse(node->left, treemap, node); 
        helper_treetraverse(node->right, treemap, node); 
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        // 1. we need a hash table for <value, node*>, 
        // since the tree is not binary search tree, don't want to search every time
        // 2. delete the node, put the child into a <value, node*> hash table 
        // (including the root). 
        // 3. use to_delete on the hash table for the case: node and its child both get deleted
        vector<TreeNode*> ret; 
        if (root == NULL){
            return ret; 
        }
        
        // hash table check for the tree node
        map<int, pair<TreeNode*, TreeNode*> > treemap; // node and parent
        helper_treetraverse(root, treemap, NULL); 
        
        // just use value is enough since we have treemap. 
        set<int> forestval; 
        forestval.insert(root->val); 
        // delete process
        for (int delval : to_delete){
            auto& p = treemap[delval]; 
            TreeNode* node = p.first; 
            if (node->left != NULL) forestval.insert(node->left->val); 
            if (node->right != NULL) forestval.insert(node->right->val); 
            if (forestval.count(node->val) == 0){
                // current node is not a forest root, parent needs to delete pointer
                TreeNode* par = p.second; 
                if (par->left == node) par->left = NULL; 
                if (par->right == node) par->right = NULL; 
            }
            delete node; 
        }
        
        // check the redundancy and insert into a vector. 
        set<int> setdelete; 
        for (int val : to_delete){
            setdelete.insert(val); 
        }
        
        for (int val : forestval){
            if (setdelete.count(val) == 0){
                ret.push_back(treemap[val].first); 
            }
        }
        
        return ret; 
    }
};

/*
https://leetcode.com/problems/delete-nodes-and-return-forest/discuss/328853/JavaC%2B%2BPython-Recursion-Solution

ohh.. so stupid I am.. 
*/
