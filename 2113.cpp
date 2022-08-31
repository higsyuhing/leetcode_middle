class Solution {
public:
    vector<int> elementInNums(vector<int>& nums, vector<vector<int>>& queries) {
        
        // the movement can be decomposed as 2 steps: 
        //  step 1: for(i=0; i < n; i++) curr_arr = nums[i, n); time 0 - n-1
        //  step 2: for(j=0; j < n; j++) curr_arr = nums[0, j); time n - 2n-1
        // every cycle is 2n: n each for step 1/2. 
        
        int n = nums.size(); 
        vector<int> ret; 
        
        for (vector<int>& query : queries)
        {
            int time = query[0]; 
            int index = query[1]; 
            
            time = time % (2*n); // 0 - 2n-1
            int pos = time%n; 
            
            if (time < n)
            {
                // first half, step 1, 0 - n-1
                // pos is i here. 
                int loc = pos + index; 
                if (loc < n) ret.push_back(nums[loc]); 
                else ret.push_back(-1); 
            }
            else
            {
                // second half, step 2, n - 2n-1
                // pos is j here. 
                int loc = index; 
                if (loc < pos) ret.push_back(nums[loc]); 
                else ret.push_back(-1); 
            }
        }
        
        return ret; 
    }
};
