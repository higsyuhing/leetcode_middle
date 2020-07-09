class Solution {
public:
    int inner_compute(vector<int>& dp, vector<int>& coins, int curr){
        // end case
        //cout << curr << endl; 
        if(curr < 0) return -1; 
        if(dp[curr] == -1) return -1; 
        
        if(dp[curr] == -2){
            int res, value; 
            value = -1; 
            for(int i = 0; i < coins.size(); i++){
                res = inner_compute(dp, coins, curr - coins[i]) + 1; 
                if(res > 0){
                    if(value > 0){
                        value = (res < value) ? res : value; 
                    }
                    else value = res; 
                }
            }
            
            dp[curr] = value; 
        }
        return dp[curr]; // already filled
    }
    
    int coinChange(vector<int>& coins, int amount) {
        // from geo: condition: a1x1+a2x2+..anxn = amount
        //  target: x1+x2+..+xn minimal integer solution
        //  no! incorrect.. 
        
        // dp[amount] = min{dp[amount-c[i]]} + 1
        // if we traceback to a negative index, it represents there is no sol. 
        
        if(amount < 0) return -1; 
        if(amount == 0) return 0; 
        
        vector<int> dp; 
        dp.reserve(amount+1); 
        for(int i = 0; i < (amount+1); i++) dp.push_back(-2); 
        for(int i = 0; i < coins.size(); i++){
            if(coins[i] < (amount+1)) dp[coins[i]] = 1; 
        }
        return inner_compute(dp, coins, amount); 
    }
};

/*
same code but cleaner.. 

class Solution {
public:
    int needNCoin(vector<int>& coins, int remain, int* save) {
        if (remain <  0) return -1;
        if (remain == 0) return  0;
        if (save[remain - 1] != 0) return save[remain - 1];
        
        int min = INT_MAX;
        for (int i : coins) {
            int need = needNCoin(coins, remain - i, save);
            if (need >= 0 && need < min) min = need + 1;
        }
        
        save[remain - 1] = min == INT_MAX ? -1 : min;
        return save[remain - 1];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        int save[amount];
        for (int i = 0; i < amount; i++) save[i] = 0;
        return needNCoin(coins, amount, save);
    }
};

*/
