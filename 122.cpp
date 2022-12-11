class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // find all "go up" segments
        int ret = 0; 
        for (int i = 1; i < prices.size(); i++){
            int inc = prices[i] - prices[i-1]; 
            ret += ((inc > 0) ? inc : 0); 
        }
        return ret; 
    }
};
