/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void encode(TreeNode *curr, string& ret){
        if (curr == NULL){
            ret += ((char)0b11000000); 
            return; 
        }
        
        char *ptr = (char *)(&curr->val); 
        ret += (*ptr); ptr++; 
        ret += (*ptr); ptr++; 
        ret += (*ptr); ptr++; 
        ret += (*ptr); ptr++; 
        encode(curr->left, ret); 
        encode(curr->right, ret); 
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // use '.' as a separator, extra '.' will be used as NULL for child
        string ret = ""; 
        encode(root, ret); 
        return ret; 
    }


    TreeNode* decode(string& data, int& pos){
        if (pos >= data.size()){
            cout << "Error: no more data.. " << endl; 
            return NULL; 
        }

        if (data[pos] == ((char)0b11000000) ){
            pos++; 
            return NULL; 
        }

        // scan the val
        char tmp[4]; 
        tmp[0] = data[pos]; pos++; 
        tmp[1] = data[pos]; pos++; 
        tmp[2] = data[pos]; pos++; 
        tmp[3] = data[pos]; pos++; 
        int val = *((int *)tmp); 

        TreeNode* ret = new TreeNode(val); 
        ret->left = decode(data, pos); 
        ret->right = decode(data, pos); 
        return ret; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0; 
        TreeNode* ret = decode(data, pos); 
        if (pos != data.size()){
            cout << "Error: data remains.. " << endl; 
        }
        return ret; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

/*
opt: 
1. use binary representation of int, not use string: 4 bytes always. 

check out this one!! 
https://www.youtube.com/watch?v=GDqVCQcmxgU

*/


