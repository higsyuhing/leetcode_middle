class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // if we have length of k Arithmetic Slices: [i, i+k)
        // we will have: k-2, k-3, k-4, ..., 1
        // total (k-1)*(k-2)/2
        if (nums.size() < 3)
            return 0; 
        int ret = 0; 
        int start = 0; 
        int interval = nums[1] - nums[0]; 
        for (int i = 2; i < nums.size(); i++){
            int tmpint = nums[i] - nums[i-1]; 
            if (tmpint != interval){
                int k = i - start; 
                ret += ((k-1)*(k-2)/2); // if we have 2 elements same, k-1 will be 0. 
                start = i-1; 
                interval = tmpint; 
            }
            // else, do nothing
        }
        // ending
        int k = nums.size() - start; 
        ret += ((k-1)*(k-2)/2); 

        return ret; 
    }
};


/*
class Solution {
public:

    // sub array [i, j), with current sum, 
    // need j-i >= 3
    pair<bool, int> helper(vector<int>& nums, int i, int j, int &sum, unordered_set<int> &hash){
        if ((i+3) == j){
            if ((nums[i+2] - nums[i+1]) == (nums[i+1] - nums[i])){
                if (hash.count((i << 16) +j) == 0){
                    sum++; 
                    hash.insert((i << 16)+j); 
                }
                // it's already in the hash, but we still need to return true
                return make_pair(true, nums[i+1] - nums[i]); 
            }
            return make_pair(false, 0); 
        }

        pair<bool, int> left = helper(nums, i, j-1, sum, hash); 
        pair<bool, int> right = helper(nums, i+1, j, sum, hash); 
        if (left.first == true && right.first == true && left.second == right.second){
            if (hash.count((i << 16)+j) == 0){
                sum++; 
                hash.insert((i << 16)+j); 
            }
            return make_pair(true, left.second); ; 
        }
        return make_pair(false, 0); 
    }


    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3)
            return 0; 
        int sum = 0; 
        unordered_set<int> hash; 
        helper(nums, 0, nums.size(), sum, hash); 
        return sum; 
    }
};
*/
