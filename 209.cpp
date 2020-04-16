class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        // use a 2 indexes method
        // ... [], [s], [], ... , [], [e], [], ...
        //          start              end
        // start from the first element, find the first end point >s
        // then shift right to collect the information
        
        int len = nums.size(); 
        if(len == 0) return 0; 
        if(s == 0) return 1; 
        int start, end, sum, min, state, init; //state = 1:>=s, 0:<s
        start = 0; end = 0; sum = 0; state = 0; init = 0; 
        
        while(end < len){
            // the current added is indexed by end
            if(state == 0) sum += nums[end]; 
            
            if(sum < s){
                state = 0; 
                end++; 
            }
            else{
                // record
                state = 1; 
                if(init == 0) init = 1; 
                if((start == 0) || (min > (end - start + 1))) min = end - start + 1; 
                sum -= nums[start]; 
                start++; 
            }
        }
        
        return (init == 0) ? 0 : min; 
    }
};
