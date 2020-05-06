class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        // one time looping, saying using K times 0->1, how long it will be
        // set a maxlen
        // start, end, remain(about K)
        
        if(A.size() == 0) return 0; 
        if(A.size() <= K) return A.size(); 
        
        int maxlen = K; 
        int start, end, remain, len; 
        remain = K; 
        start = 0; end = 0; 
        len = A.size(); 
        
        // [start, end)
        while(end < len){
            // end is valid here. 
            // measure the next one, i.e. end]
            
            if(A[end] == 1){
                end++; 
                if((end-start) > maxlen) maxlen = end-start; 
            }
            else{
                if(remain > 0){
                    end++; remain--; 
                    if((end-start) > maxlen) maxlen = end-start; 
                }
                else{
                    end++; 
                    while(A[start] == 1) start++; // find the next 0 after start
                    start++; // get rid of this 0
                    // remain keeps same
                    // never get longer.. since at least same length
                }
            }
        }
        
        return maxlen; 
    }
};
