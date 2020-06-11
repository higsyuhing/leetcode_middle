class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        // assume nums is not empty
        int left = 0;
        int right = nums.size()-1;
        int count = missingCount(nums, right);
        
        if(k > count) {
            return nums[right] + k - count;
        }
        
        while(left < right) {  
            int mid = left + (right - left) /2 ;
            count = missingCount(nums, mid);
            if(count >= k){
                right = mid;   
            } else {
                left = mid + 1;
            }
        }
        return nums[left-1] + k - missingCount(nums, left-1);
    }
    
    int missingCount(vector<int>& nums, int idx){
        return nums[idx] - nums[0] - idx;
    }
};

/*
binary search in nums array, if on the right most, it will be larger than all empty slots.. 

*/
