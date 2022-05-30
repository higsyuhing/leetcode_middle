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
    int leftkey = 0; 
    int rightkey = 0; 
    
    /*
    void traverse(TreeNode* node, int key, map<int, vector<int>>& table){
        // node is guaranteed valid. 
        
        // add node to the table
        if (table.find(key) == table.end()){
            vector<int> tmp; 
            tmp.push_back(node->val); 
            table[key] = tmp; 
            // update most-key. 
            leftkey = (key < leftkey) ? key : leftkey; 
            rightkey = (key > rightkey) ? key : rightkey; 
        }
        else{
            vector<int>& tmp = table[key]; 
            tmp.push_back(node->val); 
        }
        
        // check children. 
        if (node->left){
            traverse(node->left, key - 1, table); 
        }
        if (node->right){
            traverse(node->right, key + 1, table); 
        }
        
    }
    */
    
    
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> table; 
        vector<vector<int>> ret; 
        
        if (root == NULL) return ret; 
        
        queue<pair<TreeNode*, int>> nodequeue; 
        nodequeue.push(make_pair(root, 0)); 
        
        while(!nodequeue.empty()){
            pair<TreeNode*, int>& tmp = nodequeue.front(); 
            TreeNode* node = tmp.first; 
            int key = tmp.second; 
            nodequeue.pop(); 
            
            if (table.find(key) == table.end()){
                vector<int> tmp; 
                tmp.push_back(node->val); 
                table[key] = tmp; 
                // update most-key. 
                leftkey = (key < leftkey) ? key : leftkey; 
                rightkey = (key > rightkey) ? key : rightkey; 
            }
            else{
                vector<int>& tmp = table[key]; 
                tmp.push_back(node->val); 
            }

            // check children. 
            if (node->left){
                nodequeue.push(make_pair(node->left, key-1)); 
            }
            if (node->right){
                nodequeue.push(make_pair(node->right, key+1)); 
            }
            
        }
        
        for (int i = leftkey; i <= rightkey; i++){
            ret.push_back(table[i]); 
        }
        
        return ret; 
    }
};
