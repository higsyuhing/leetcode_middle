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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, TreeNode*> dictnode; 
        map<int, int> dictparent; 
        TreeNode* root = NULL; 
        
        for (int i = 0; i < descriptions.size(); i++){
            vector<int>& des = descriptions[i]; 
            int parent, child, isleft; 
            parent = des[0]; 
            child = des[1]; 
            isleft = des[2]; 
            
            // check availability in dictnode. 
            TreeNode* parentnode, *childnode; 
            if (dictnode.find(parent) == dictnode.end()){
                parentnode = new TreeNode(parent); 
                dictnode[parent] = parentnode; 
            }
            else{
                parentnode = dictnode[parent]; 
            }
            if (dictnode.find(child) == dictnode.end()){
                childnode = new TreeNode(child); 
                dictnode[child] = childnode; 
            }
            else{
                childnode = dictnode[child]; 
            }
            
            // assign relationship
            if (isleft){
                parentnode->left = childnode; 
            }
            else{
                parentnode->right = childnode; 
            }
            dictparent[child] = parent; 
            
            // update dictparent, and root node
            if (root == NULL){
                root = parentnode; 
            }
            else if (root->val == child){
                int curr = parent; 
                while (dictparent.find(curr) != dictparent.end()){
                    curr = dictparent[curr]; 
                }
                root = dictnode[curr]; 
            }
        }
        
        return root; 
    }
};
