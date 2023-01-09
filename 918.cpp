class Solution {
public:
    // int maxSubarraySumCircular(vector<int>& nums) {
    //     // kadane algo with a starting point.. 
    //     // no.. 2 parts kadane: within and cross

    //     int max_so_far = INT_MIN; 
    //     int max_ending_here = 0; 

    //     for (int i = 0; i < nums.size(); i++){
    //         max_ending_here = max_ending_here + nums[i]; 
    //         max_so_far = (max_so_far < max_ending_here) ? max_ending_here : max_so_far; 
    //         max_ending_here = (max_ending_here < 0) ? 0 : max_ending_here; 
    //     }
        
    //     int left, right; 
    //     max_ending_here = 0; 


    //     return max_so_far; 
    // }
    
    int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, maxSum = A[0], curMax = 0, minSum = A[0], curMin = 0;
        for (int& a : A) {
            curMax = max(curMax + a, a);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + a, a);
            minSum = min(minSum, curMin);
            total += a;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }

};
