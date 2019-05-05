class Solution {
public:
    double myPow(double x, int n) {
        bool sign; 
        unsigned tempn; 
        if(n < 0){
            sign = 1; 
            if(n == -2147483648) tempn = (unsigned)n; 
            else tempn = -n;
        }
        else{
            sign = 0; 
            tempn = n; 
        }
        
        //divide and conquer
        // x^25: 25 = 16+8+1
        // x, x2, x4, x8, x16.. 
        double tempx = x; 
        double power = 1; 
        while(tempn){
            if(tempn%2 == 1){
                power *= tempx; 
            }
            tempn /= 2; 
            tempx *= tempx; 
        }
        
        if(sign) return (1/power); 
        return power; 
    }
};
