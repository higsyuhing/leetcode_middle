class Solution {
public:
    int longestMountain(vector<int>& A) {
        // not hard two pointer problem.. 
        // state 0: no mountain
        // state 1: increasing; 2: decreasing
        
        int state = 0; 
        int last, curr; 
        int len = A.size(); 
        if(len < 3) return 0; 
        int indexi; // for start point
        int mlen = -1; 
        
        last = A[0]; curr = A[1]; 
        indexi = -1; 
        if(curr > last){
            state = 1; 
            indexi = 0; 
        }
        
        for(int i = 2; i < len; i++){
            last = curr; 
            curr = A[i]; 
            
            if(state == 0){
                if(curr > last){
                    state = 1; 
                    indexi = i-1; 
                }
            }
            else if(state == 1){
                if(curr < last){
                    state = 2; 
                }
                else if(curr == last){
                    state = 0; 
                }
            }
            else{ // state == 2
                if(last == curr){
                    if((i-indexi) > mlen) mlen = i-indexi; 
                    indexi = -1; 
                    state = 0; 
                }
                else if(last < curr){
                    if((i-indexi) > mlen) mlen = i-indexi; 
                    indexi = i-1; 
                    state = 1; 
                }
            }
        }
        
        if(state == 2){
            if((len-indexi) > mlen) mlen = len-indexi; 
        }
        
        if(mlen == -1) mlen = 0; 
        return mlen; 
    }
};
