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
    int countNodes(TreeNode* root) {
        // 1. we go left most leaf, to count tree height, and base node num 1 - (height-1)
        // 2. binary search: 
        //      given a curr node: 
        //      node->right-> all left to leaf == height? 
        //      true: node = node->right, count += node->left->all leaf count
        //      false: node = node->left, count no change
        //  until leaf: left is NULL

        if (root == nullptr)
            return 0; 
        // get height
        TreeNode *curr = root; 
        int height = 0; 
        while (curr != nullptr){
            curr = curr->left; 
            height++; 
        }
        int count = (1 << (height-1)) - 1; 
        // cout << "height, count: " << height << ",  " << count << endl; 

        curr = root; 
        int currheight = 1; 
        int tmpheight; 
        TreeNode *tmpnode; 
        while (1){
            if (curr->left == nullptr){
                count++; 
                break; 
            }

            // if (curr->right == nullptr){
            //     curr = curr->left; 
            //     currheight++; 
            //     continue; 
            // }

            tmpheight = currheight; 
            tmpnode = curr->right; 
            while (tmpnode != nullptr){
                tmpnode = tmpnode->left; 
                tmpheight++; 
            }
            if (tmpheight == height){
                curr = curr->right; 
                currheight++; 
                count += (1 << (height - currheight)); 
            }
            else{
                curr = curr->left; 
                currheight++; 
            }
        }

        return count; 
    }
};
