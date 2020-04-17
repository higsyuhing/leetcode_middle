class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        // more like an index sort
        
        int temp, i; 
        int len = nums.size(); 
        for(i = 0; i < len; i++){
            
            while(nums[i] > 0){
                temp = nums[i]; 
                
                if((nums[temp-1] > 0) || (nums[temp-1] == -2)){
                    // swap
                    nums[i] = nums[temp-1]; 
                    nums[temp-1] = 0; 
                }
                else{
                    nums[i] = -2; 
                    nums[temp-1]--; 
                }
            }
        }
        
        vector<int> res; 
        for(i = 0; i < len; i++){
            if(nums[i] == -1) res.push_back(i+1); 
        }
        
        return res; 
    }
};
