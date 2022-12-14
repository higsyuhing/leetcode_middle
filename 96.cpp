class Solution {
public:
    int dp[20]; // memorize result

    int helper(int n){
        if (dp[n] != -1){
            return dp[n]; 
        }

        // n > 2 guarantee.. 
        int ret = 0; 
        for (int i = 0; i < n; i++){
            // node i is the root
            int left = helper(i); 
            int right = helper(n-1-i); 
            if (left > 0 && right > 0){
                ret += (left*right); 
            }
            else{
                ret += (left + right); 
            }
        }
        dp[n] = ret; 
        return ret; 
    }

    int numTrees(int n) {
        if (n <= 2){
            return n; 
        }
        for (int i = 0; i < 20; i++){
            dp[i] = -1; 
        }
        dp[0] = 0; // NULL
        dp[1] = 1; 
        dp[2] = 2; 
        return helper(n); 
    }
};
