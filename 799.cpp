class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double state[query_row+1]; 
        for(int i = 0; i < (query_row+1); i++) state[i] = 0; 
        state[0] = poured; 
        
        for(int curr = 0; curr < query_row; curr++){
            // we will compute form right to the left.. 
            // 0-0
            // 1-0, 1-1
            // 2-0, 2-1, 2-2
            // ..
            // i-0, i-1, .., i-j, .., i-i (total i+1 entries)
            for(int index = curr; index >= 0; index--){
                if(state[index] > 1){
                    double part = (state[index] - 1)/2; 
                    state[index+1] += part; 
                    state[index] = part; 
                }
                else{
                    state[index] = 0; 
                }
            }
        }
        
        if(state[query_glass] > 1) return 1; 
        else return state[query_glass]; 
    }
};
