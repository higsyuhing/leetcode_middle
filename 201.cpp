class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // note that lower case are all getting 0, for AND
        // it will only be 2^p if 2^p <= m and n < 2^(p+1)
        // otherwise, they will be 0. 
        long unsigned a, b; 
        a = 1; b = 2; 
        while(1){
            if(((long unsigned)m >= a) && ((long unsigned)n < b)){
                int remain = rangeBitwiseAnd(m-a, n-a); 
                return (a+remain); 
            }
            if(a >= n) return 0; 
            a = a << 1; 
            b = b << 1; 
        }
    }
};
