class Solution {
public:
    int helper(int amount, vector<int>& coins, map<int, int>& dp2d, int currCindex){
        if(amount == 0) return 1; 
        if(currCindex < 0) return 0; // run out of coins
        int hashkey = amount*1000+currCindex;
        if(dp2d.find(hashkey) != dp2d.end()) return dp2d[hashkey]; 
        
        int res = 0; 
        for(int i = 0; i <= (amount/coins[currCindex]); i++){
            res += helper(amount - i*coins[currCindex], coins, dp2d, currCindex-1); 
        }
        //cout << amount << " " << currCindex << " " << res << endl; 
        dp2d[hashkey] = res; 
        return res; 
    }
    
    int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1; 
        
        // init 2d dp: amount-coinLimit
        // use a hash.. since they are in [0, 5000], thus 
        // amount-coinLimit: 5000x1000+500
        map<int, int> dp2d; 
        sort(coins.begin(), coins.end()); 
        return helper(amount, coins, dp2d, coins.size()-1); 
    }
    /*
    
    500
[3,5,7,8,9,10,11]

    int helper(vector<int>& dp, vector<int>& coins, int target){
        if (dp[target] != -1) return dp[target]; 
        
        int res = 0, tempres; 
        for (int i = 0; i < coins.size(); i++){
            if ((target - coins[i]) > 0){ // never ==, since assigned
                tempres = helper(dp, coins, target - coins[i]); 
            }
            if (tempres != -1){
                res += tempres; 
            }
        }
        
        if (res == 0){
            dp[target] = -1; 
            return -1; 
        }
        else{
            dp[target] = res; 
            return res; 
        }
    }
    
    
    int change(int amount, vector<int>& coins) {
        vector<int> dp;
        // init
        int maxlen = amount; 
        for (int i = 0; i < coins.size(); i++) maxlen = (maxlen > coins[i]) ? maxlen : coins[i]; 
        for (int i = 0; i < (maxlen+1); i++) dp.push_back(-1); 
        for (int i = 0; i < coins.size(); i++) dp[coins[i]] = 1; 
        dp[0] = 1; 
        //cout << "before recursive\n"; 
        return helper(dp, coins, amount); 
    }
    */
};

/*
// solution is good.. 
class Solution {
  public int change(int amount, int[] coins) {
    int[] dp = new int[amount + 1];
    dp[0] = 1;

    for (int coin : coins) {
      for (int x = coin; x < amount + 1; ++x) {
        dp[x] += dp[x - coin];
      }
    }
    return dp[amount];
  }
}
*/
