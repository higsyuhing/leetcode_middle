class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // feel like a DP problem
        
        int length = nums.size(); 
        if(length == 0) return 0; 
        vector<int> dp; 
        dp.reserve(length); 
        
        int tempmax, ret; 
        ret = 1; 
        for(int i = 0; i < length; i++){
            tempmax = 1; 
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    if(dp[j] >= tempmax) tempmax = dp[j]+1; 
                }
            }
            dp[i] = tempmax; 
            ret = tempmax > ret ? tempmax : ret; 
            //cout << tempmax << endl; 
        }
        
        return ret; 
    }
};

/*
// I get it, that's smart.. 

class Solution {
public:
    int ceil_(int x, vector<int> tail){
        int l = 0, h = tail.size()-1;
        int res;
        while(l <= h){
            int m = l + (h-l)/2;
            if(tail[m] >= x){
                res = m;
                h = m-1;
            }
            else l = m+1;
        }
        return res;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> tail;
        tail.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            if(nums[i] > tail[tail.size()-1]){
                tail.push_back(nums[i]);
            }
            else{
                int idx = ceil_(nums[i], tail);
                tail[idx] = nums[i];
            }
        }
        return tail.size();
    }
};
*/
