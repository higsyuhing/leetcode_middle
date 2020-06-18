class Solution {
public:
    vector<int> countBits(int num) {
        // note that: every lsb will be 1 on every odd index
        // every last-lsb will be 1 on every 2 odd index .. 
        
        //vector<int> res; 
        //res.reserve(num+1); 
        //int i; 
        //for(i = 0; i < (num+1); i++) res[i] = 0; 
        
        // wow.. 
        vector<int> v(num+1,0);
        for(int i=1 ; i<=num ; i++){
            if(i%2 == 0)
                v[i] = v[i>>1]; // if i is even then same as i/2 (as last bit is 0)
            else
                v[i] = v[i-1]+1; // if odd then previous ans + 1 
        }
        return v;
        
        
    }
};
