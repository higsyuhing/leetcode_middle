class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // you need to iterate through all possible combination to verify
        // that is 2^len(nums) for each +/-
        // then how to quickly get the new sum? use gray code
        // thus there is only 1 number change each time, fast sum calculation
        // 0 is +, 1 is -
        
        int i, j, len, prev, curr, count, sum, mask, sign; 
        len = nums.size(); 
        prev = 0; // prev gray code
        sum = 0; 
        for(i = 0; i < len; i++) sum += nums[i]; 
        // one test case contains 0....
        //if(sum == S) return 1; // all others are definitely less than S
        //count = 0; 
        count = (sum == S) ? 1 : 0; 
        
        for(i = 1; i < (1 << len); i++){
            curr = i ^ (i >> 1);
            mask = curr ^ prev; // find out which bit changed
            
            // if curr doesn't have bit 1, thus it's from 1->0
            sign = ((curr & mask) == 0) ? 2 : (-2); 
            
            j = 0; 
            while(1){
                mask = mask >> 1; 
                if(mask == 0) break; 
                j++; 
            }
            sum += sign*nums[j]; 
            
            count += (sum == S) ? 1 : 0; 
            //if(sum == S) cout << curr << endl; 
            prev = curr; 
        }
        
        return count; 
    }
};
