class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ret; 
        long unsigned num, i, j, k; 
        num = 1 << nums.size(); 
        
        for(i = 0; i < num; i++){
            vector<int> temp; 
            k = 0; 
            for(j = 0; j < nums.size(); j++){
                if((i & (1<<j)) != 0) temp.push_back(nums[k]); 
                k++; 
            }
            ret.push_back(temp); 
        }
        
        return ret; 
    }
};
