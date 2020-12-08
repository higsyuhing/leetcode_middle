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
    int helper_treedepth(TreeNode* node){
        if(node == NULL) return 0; 
        int leftret = helper_treedepth(node->left); 
        int rightret = helper_treedepth(node->right); 
        int res = (leftret > rightret) ? leftret : rightret; 
        return res + 1; 
    }
    
    void helper_assign(vector<vector<string>>& res, TreeNode* node, int row, int col, int level){
        if(node == NULL) return; 
        // assign current node
        int pos_off = (1<<(level - 1)) - 1; 
        res[row][col+pos_off] = to_string(node->val); 
        
        // left child: 
        helper_assign(res, node->left, row+1, col, level-1); 
        // right child: 
        helper_assign(res, node->right, row+1, col+pos_off+1, level-1); 
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        // root != NULL
        
        int depth = helper_treedepth(root); 
        // width: f(h) = 2*f(h-1)+1 => f(h) = 2^h-1
        int width = (1<<depth) - 1; 
        //cout << depth <<" " << width << endl; 
        
        // init tree
        vector<vector<string>> res; 
        vector<string> tempvec; 
        for (int i = 0; i < width; i++) tempvec.push_back(""); 
        for (int i = 0; i < depth; i++) res.push_back(tempvec); 
        
        // assign recursively.. 
        helper_assign(res, root, 0, 0, depth); 
        
        return res; 
    }
};
