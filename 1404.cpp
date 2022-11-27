class Solution {
public:
    int numSteps(string s) {
        // if we have 0: then res++ and "shift right"
        // if we have 1: res++ for add 1, but we can opt: 
        //      count number of continuous "1", each of them will imply a 0
        
        int currlen = s.size(); 
        bool carry = false; // we have 1 in the end. 
        bool fake0 = false; // represent curr 0 contains carry
        int res = 0; 

        while (currlen > 1){
            char curr = s[currlen-1]; 
            if (carry == false){
                if (curr == '0' && fake0 == false){
                    res++; 
                    currlen--; 
                }
                else{
                    res += 2; // 1 for add, 1 for shift
                    carry = true; 
                    currlen--; 
                }
            }
            else{
                if (curr == '1'){
                    res++; // shift
                    currlen--; 
                }
                else{
                    fake0 = true; // 0->1
                    carry = false; 
                    // currlen no change
                    // res no change

                    // this can be improved: 
                    // res++; 
                    // currlen--; 
                }
            }
        }
        if (carry == 1)
            res++; // 1 shift
        
        return res; 
    }
};
