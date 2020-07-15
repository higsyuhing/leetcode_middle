class Solution {
    public boolean PredictTheWinner(int[] nums) {
        int[][] dp = new int[nums.length + 1][nums.length];
        for (int s = nums.length; s >= 0; s--) {
            for (int e = s + 1; e < nums.length; e++) {
                int a = nums[s] - dp[s + 1][e];
                int b = nums[e] - dp[s][e - 1];
                dp[s][e] = Math.max(a, b);
            }
        }
        return dp[0][nums.length - 1] >= 0;
    }
}

/*
// niubi.. 
also improved 1-D DP problem.. 

    public boolean PredictTheWinner(int[] nums) {
        int[] dp = new int[nums.length];
        for (int s = nums.length; s >= 0; s--) {
            for (int e = s + 1; e < nums.length; e++) {
                int a = nums[s] - dp[e];
                int b = nums[e] - dp[e - 1];
                dp[e] = Math.max(a, b);
            }
        }
        return dp[nums.length - 1] >= 0;
    }

and my stupid c++, incorrect answer, not considering smart p2: 

class Solution {
public:
    int inner_fill(int **scoredp, int i, int j, vector<int>& nums){
        if(i > j) return 0; // we have no more elements.. 
        if(scoredp[i][j] != -1) return scoredp[i][j]; 
        
        int ll, lr, rr; 
        ll = inner_fill(scoredp, i+2, j, nums); 
        lr = inner_fill(scoredp, i+1, j-1, nums); 
        rr = inner_fill(scoredp, i, j-2, nums); 
        
        int rll, rlr, rrl, rrr; // result + p1 left/right + p2 left/right
        rll = nums[i] + ll; // p1 score, p2 pick nums[i+1]
        rlr = nums[i] + lr; 
        rrl = nums[j] + lr; 
        rrr = nums[j] + rr; 
        
        int res; 
        rll = (rll > rlr) ? rll : rlr; 
        rrl = (rrl > rrr) ? rrl : rrr; 
        res = (rll > rrl) ? rll : rrl; 
        scoredp[i][j] = res; 
        cout << i << " " << j << " " << res << endl; 
        cout << ll << " " << lr << " " << rr << endl; 
        return res; 
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        // dp 2-D array for indicating i-j, when player 1 starts to play
        // it represents the max total points player 1 can get
        
        // scoredp[i][j] = the max total points player 1 can get in: 
        //                  remaining array [i, j], player 1 starts first
        
        int length = nums.size(); 
        int i, j; 
        int sum = 0; 
        for(i = 0; i < length; i++) sum += nums[i]; 
        int **scoredp = (int **)malloc(length*sizeof(int *)); 
        for(i = 0; i < length; i++){
            scoredp[i] = (int *)malloc(length*sizeof(int)); 
            for(j = 0; j < length; j++)
                scoredp[i][j] = -1; // not detected
        }
        
        if(length%2 == 0){ // even
            // the last case is remaining 2 get picked by player 1
            for(i = 0; i < (length - 1); i++){
                scoredp[i][i+1] = (nums[i] > nums[i+1]) ? nums[i] : nums[i+1]; 
            }
        }
        else{ // odd
            // the last case is remaining 1 get picked by player 1
            for(i = 0; i < length; i++){
                scoredp[i][i] = nums[i]; 
            }
        }
        
        int maxp1 = inner_fill(scoredp, 0, length-1, nums); 
        cout << maxp1; 
        
        return (maxp1 > (sum - maxp1)); 
    }
};


*/
