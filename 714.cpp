class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, hold = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            cash=(cash > (hold + prices[i] - fee)) ? cash : (hold + prices[i] - fee); 
            hold=(hold > (cash - prices[i])) ? hold : (cash - prices[i]); 
        }
        return cash;
    }
};
