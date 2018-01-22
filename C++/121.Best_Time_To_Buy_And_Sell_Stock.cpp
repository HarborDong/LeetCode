class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = 0;
        int profit = 0;
        if(prices.size() == 0) return profit;
        buyPrice = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            if(buyPrice > prices[i]) {
                buyPrice = prices[i];
            } 
            if((prices[i] - buyPrice) > profit) {
                profit = prices[i] - buyPrice;
            }
        }
        return profit;
    }
};
