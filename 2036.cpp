class Solution {
public:
    
    long long helper_func(vector<int>& nums, int start){
        vector<long long> vecsubsum; 
        long long subsum = 0; 
        bool possign = (nums[start] >= 0); 
        
        for (int i = start; i < nums.size(); i++){
            int curr = (((i - start) % 2) == 0) ? nums[i] : -nums[i]; 
            if ( (possign == (curr >= 0)) || 
                 ((!possign) == (curr < 0)) )
            {
                subsum += curr; 
            }
            else{
                possign = (curr >= 0); 
                vecsubsum.push_back(subsum); 
                subsum = curr; 
            }
        }
        vecsubsum.push_back(subsum); 
        
        for (long long val : vecsubsum){
            cout << val << ", "; 
        }
        cout << endl; 
        
        vector<long long> vecsum; 
        vecsum.push_back(0); 
        long long sum = 0; 
        for (long long val : vecsubsum){
            sum += val; 
            vecsum.push_back(sum); 
        }
        
        for (long long val : vecsum){
            cout << val << ", "; 
        }
        cout << endl; 
        
        long long ret = 0; 
        for (int i = 0; i < (vecsum.size()-1); i++){
            for (int j = i+1; j < vecsum.size(); j++){
                long long tmp = vecsum[j] - vecsum[i]; 
                ret = (tmp > ret) ? tmp : ret; 
            }
        }
        
        return ret; 
    }
    
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        
        // 1. convert into two arrays: 
        // nums[0], -nums[1], nums[2], -nums[3] ... 
        // (nums[0] always +), nums[1], -nums[2], ...
        // 2. compute the maximum subarray sum: 
        // use a vector of sub-sums
        
        if (nums.size() == 1) return nums[0]; 
        
        // long long val1 = helper_func(nums, 0); 
        // long long val2 = helper_func(nums, 1); 
        // cout << val1 << ", " << val2 << endl; 
        
        // use Kadane's Algorithm
        // [0, n-1]: 
        long long maxsum1 = INT_MIN; 
        long long currsum = 0; 
        for (int i = 0; i < nums.size(); i++){
            int curr = ((i % 2) == 0) ? nums[i] : -nums[i]; 
            currsum += curr; 
            if (currsum > maxsum1) maxsum1 = currsum; 
            if ((currsum < 0) && ((i % 2) != 0)) currsum = 0; 
        }
        
        long long maxsum2 = INT_MIN; 
        currsum = 0; 
        for (int i = 1; i < nums.size(); i++){
            int curr = (((i-1) % 2) == 0) ? nums[i] : -nums[i]; 
            currsum += curr; 
            if (currsum > maxsum2) maxsum2 = currsum; 
            if ((currsum < 0) && (((i-1) % 2) != 0)) currsum = 0; 
        }
        
        // cout << maxsum1 << ", " << maxsum2 << endl; 
        
        return ((maxsum1 > maxsum2) ? maxsum1 : maxsum2); 
        
    }
};


/*

    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        long long lastMinus = INT_MIN;
        long long lastPlus = INT_MIN;
        long long res = INT_MIN;
        for(long long num: nums) {
            auto currPlus = max(lastMinus + num, num);
            lastMinus = lastPlus - num;           
            lastPlus = currPlus;
            res = max(res, max(lastMinus, lastPlus));
        }
        return res;
    }

*/










