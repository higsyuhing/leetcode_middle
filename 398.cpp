class Solution {
public:
    map<int, vector<int> > checkmap; 
    
    Solution(vector<int>& nums) {
        vector<int> temp; 
        for(int i = 0; i < nums.size(); i++){
            int curr = nums[i]; 
            if(checkmap.find(curr) == checkmap.end()){
                checkmap[curr] = temp; 
                checkmap[curr].push_back(i); 
            }
            else{
                checkmap[curr].push_back(i); 
            }
        }
    }
    
    int pick(int target) {
        int index = rand() % (checkmap[target].size()); 
        return checkmap[target][index];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
