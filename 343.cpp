class Solution {
public:
    int integerBreak(int n) {
        // 7 => 12, 3x4
        // 8 => 18, 2x3x3
        // 9 => 27, 3x3x3
        // 10 => 36, 3x3x2x2
        // 22 -> 3*7+1.. 3*6+4, 3^6x4? 
        if((n == 1) || (n == 2)) return 1; 
        if(n == 3) return 2; 
        if(n == 4) return 4; 
        
        int ret = 1; 
        while(n > 4){
            ret *= 3; 
            n -= 3; 
        }
        ret *= n; 
        return ret; 
    }
};
