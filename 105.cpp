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
    
    TreeNode *contree(vector<int>& preorder, vector<int>& inorder, int prei, int prej, int ini, int inj){
        if(prei == prej) return NULL; 
        if(ini == inj) return NULL; 
        if((prej-prei) != (inj-ini)){
            cout << "sub-distance not match! " << prei << " " << prej << " " << ini << " " << inj << endl; 
            return NULL; 
        }
        
        int j, temp; 
        TreeNode *templeft, *tempright; 
        
        temp = preorder[prei]; 
        for(j = ini; j < inj; j++){
            if(inorder[j] == temp) break; 
        }
        if(j == inj){
            cout << "not find temp! " << prei << " " << prej << " " << ini << " " << inj << endl; 
            return NULL; 
        }
        
        // note that, if have val (prei != prej), only guarantee is val is valid
        // it's possible for empty left subtree or empty right subtree
        templeft = contree(preorder, inorder, prei+1, prei+1+(j-ini), ini, j); 
        tempright = contree(preorder, inorder, prei+1+(j-ini), prej, j+1, inj); 
        return new TreeNode(temp, templeft, tempright); 
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // note that
        //      preorder = val [left val] [right val]
        //      inorder = [left val] val [right val]
        // since no duplicate, thus can seperate the vector into 2 parts. 
        // use 2x2 indexes for in-place function call. 
        
        return contree(preorder, inorder, 0, preorder.size(), 0, inorder.size()); 
        
    }
};
/*

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        preidx = 0;
        for(int i = 0; i < inorder.size(); i++) {
            idxmap.insert(make_pair(inorder[i], i));
        }
        return buildNode(0, inorder.size() - 1);
    }
private:
    vector<int> preorder;
    vector<int> inorder;
    unordered_map<int, int> idxmap;
    int preidx;
    
    TreeNode* buildNode(int left, int right) {
        if(left > right) return NULL;
        int val = preorder[preidx++];
        TreeNode* root = new TreeNode(val);
        int idx = idxmap.at(val);
        root->left = buildNode(left, idx - 1);
        root->right = buildNode(idx + 1, right);
        return root;
    }
};


*/
