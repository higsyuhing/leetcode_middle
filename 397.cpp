class Solution {
public:
    int integerReplacement(int n) {
        if(n==1) return 0;
        if(n==3) return 2;
        if(n==INT_MAX) return 32;
        if(n%2==0) return 1+integerReplacement(n/2);
        else{
            if((n+1)%4==0){
                return 1+integerReplacement(n+1);
            }
            else{
                return 1+integerReplacement(n-1);
            }
        }
    }
};

/*
// it's pretty similar, but corner cases.. 

class Solution {
public:
    int integerReplacement(int n) {
        // if you have 2 continuous 1s in its bit representation, add 1 better
        // 11xx1 -> +1
        // 10000 -> shift right
        // 1111101 -> -1, >>2, +1
        
        int step = 0; 
        while(n > 1){
            if(n & 1){ // odd
                if((n & 3) == 3){
                    n++; 
                }
                else{
                    n--; 
                }
            }
            else{
                n = n >> 1; 
            }
            step++; 
        }
        return step; 
    }
};

*/
