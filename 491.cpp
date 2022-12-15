class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& ret, vector<int>& tmp, int pos, bool flag, unordered_set<string>& hash){
        if (pos == nums.size()){
            if (flag == true){
                string key = ""; 
                for (int& val : tmp){
                    key += (to_string(val)+"#"); 
                }
                if (hash.count(key) == 0){
                    ret.push_back(tmp); 
                    hash.insert(key); 
                }
            }
            return; 
        }

        if (tmp.size() == 0){
            tmp.push_back(nums[pos]); 
            helper(nums, ret, tmp, pos+1, false, hash); // push
            tmp.pop_back(); 
            helper(nums, ret, tmp, pos+1, false, hash); // no push
            return; 
        }

        int last = tmp[tmp.size()-1]; 
        // try to push
        if (nums[pos] >= last){
            tmp.push_back(nums[pos]); 
            helper(nums, ret, tmp, pos+1, true, hash); 
            tmp.pop_back(); 
        }
        // no push
        helper(nums, ret, tmp, pos+1, flag, hash); 
        return; 
    }


    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ret; 
        if (nums.size() <= 1)
            return ret; 

        vector<int> tmp; 
        int pos = 0; // pos in nums
        unordered_set<string> hash; 
        helper(nums, ret, tmp, pos, false, hash); 
        return ret; 
    }
};




/*
     helper(vector<int>& nums, int start, int end, vector<vector<int>>& ret, int ){
        vector<vector<int>> ret; 
        if ((end - start) <= 1)
            return ret; 
        
        vector<vector<int>> left, right; 
        int mid = (start + end)/2; 
        left = helper(nums, start, mid); 
        right = helper(nums, mid, end); 

        // 4 parts: 
        // left 1 + right res; left res + right 1; left res + right res; left 1 + right 1

        // left 1 + right res
        if (right.size() > 0){
            for (int i = start; i < mid; i++){
                int curr = nums[i]; 
                for ()
            }
        }


    }
*/
