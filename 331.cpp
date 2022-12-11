class Solution {
public:
    bool helper(string& preorder, int& pos){
        // always '[0-9]+,' or '#,'
        if (pos == preorder.size()){
            return false; 
        }

        // leaf node
        if (preorder[pos] == '#'){
            pos += 2; // #,
            return true; 
        }
        // curr node
        while (preorder[pos] != ','){
            pos++; 
        }
        pos++; 
        bool retl = helper(preorder, pos); // left child
        if (retl == false){
            return false; 
        }
        bool retr = helper(preorder, pos); // right child
        return retr; 
    }


    bool isValidSerialization(string preorder) {
        preorder += ","; // ending mark
        int pos = 0; 
        bool ret = helper(preorder, pos); 
        if (ret == false){
            return false; 
        }
        return pos == preorder.size(); 
    }
};
