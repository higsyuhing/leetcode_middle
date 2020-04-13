class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // use a decreasing production array: all/a[0], all/a[0]a[1], ... ,a[n-1], ?
        vector<int> res; 
        int i, temp; 
        for(i = 0; i < nums.size(); i++) res.push_back(1); 
        
        temp = 1; 
        for(i = nums.size() - 1; i > 0; i--){
            temp = temp*nums[i]; 
            res[i-1] = temp; 
        }
        // now start from the second one
        temp = nums[0]; 
        for(i = 1; i < nums.size(); i++){
            res[i] *= temp; 
            temp *= nums[i]; 
        }
        
        return res; 
    }
};
