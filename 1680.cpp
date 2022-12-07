class Solution {
public:
    int concatenatedBinary(int n) {
        // convert into binary format
        // then compute for each bit.. 
        // if the number is too large, we can divide into pieces.. 

        int64_t res = 0; 

        // only keep 2^lastpos % 10^9+7
        // compute curr val = val*2^(currpos-lastpos) % 10^9+7
        int64_t val; 
        
        int lastpos = -1; // position of last 1
        int currposbase = 0; // position base of current number
        for (int currnum = n; currnum > 0; currnum--){
            int posinc = 0; 
            int tmp = currnum; 
            while (tmp > 0){
                if (tmp % 2 == 1){
                    int currpos = currposbase + posinc; 
                    if (lastpos == -1){ // init case, run once only
                        val = 1 << currpos; 
                        lastpos = currpos; 
                        res = val; 
                    }
                    else{
                        val = val*(1LL << (currpos-lastpos)) % (1000000007LL); 
                        lastpos = currpos; 
                        res = (res + val) % (1000000007LL); 
                    }
                }
                tmp = tmp >> 1; 
                posinc++; 
            }
            currposbase += posinc; 
        }

        return (int)res; 
    }
};


// 1 147483634
// 2 294967268
// 8 179869065


/*

MOD = 10^9+7
assume we have 1 in position 70 and 1 in position 60: 
    1 in pos 60: 
        num60 = 1<<60
        num60 = p60*MOD + q60
        so 'q60' is the mod result for "1 in pos 60"
    1 in pos 70: 
        num70 = 1<<70 = 1<<60 * 1<<10 = num60*1024
        num70 = num60*1024 = (p60*MOD + q60)*1024 = (p60*1024)*MOD + q60*1024
        so 'q60*1024 % MOD' is the mod result for "1 in pos 70"

follow the same idea, we start from the complete binary string, 
then from the lowest to highest, compute the mod result for each "1"


*/














