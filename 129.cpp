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
    int helper(TreeNode *node, vector<int>& path){
        // node is not nullptr
        if (node->left == nullptr && node->right == nullptr){
            // compute.. 
            int ret = 0; 
            for (int i = 0; i < path.size(); i++){ // all previous nodes
                ret = ret*10 + path[i]; 
            }
            ret = ret*10 + node->val; 
            return ret; 
        }
        path.push_back(node->val); 
        int ret = 0; 
        if (node->left != nullptr){
            ret += helper(node->left, path); 
        }
        if (node->right != nullptr){
            ret += helper(node->right, path); 
        }
        path.pop_back(); 
        return ret; 
    }


    int sumNumbers(TreeNode* root) {
        if (root == nullptr)
            return 0; 
        vector<int> path; 
        return helper(root, path); 
    }
};

/*
class Solution {
public:
    void dfs(TreeNode* root, int &num, int &sum){
        if(!root)return;

        num=(num*10)+(root->val);
        if(!root->left && !root->right){
            sum+=num;
        }
        dfs(root->left,num,sum);
        dfs(root->right,num,sum);
        num/=10;
    }
    int sumNumbers(TreeNode* root) {
        int num=0;
        int sum=0;
        dfs(root,num,sum);
        return sum;        
    }
};
*/
