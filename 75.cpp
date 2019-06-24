class Solution {
public:
    void sortColors(vector<int>& nums) {
        // one pass is done by 2 position: 
        // red/white & white/blue boundary
        // this is special for 3 color case.. 
        
        // boundary for [red, ?/white), [?/white, blue)
        int bound1, bound2, curr; 
        bound1 = -1; 
        bound2 = nums.size() - 1; 
        
        // need to swap and check
        curr = 0; 
        while(1){
            if(curr > bound2) break; // include equal? 
            
            if(nums[curr] == 0){
                bound1++; 
                // nums[bound1] is unknown/white, 
                // however, in this case, if unknown, it's curr, it's 0
                nums[curr] = nums[bound1]; 
                nums[bound1] = 0; 
                curr++; 
            }
            else if(nums[curr] == 1){
                curr++; 
            }
            else{ // nums[curr] == 2
                nums[curr] = nums[bound2]; 
                nums[bound2] = 2; 
                bound2--; 
            }
        }
    }
};
