class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int cheapestPrice = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < cheapestPrice) {
                cheapestPrice = prices[i];
            }

            if (prices[i] - cheapestPrice > maxProfit) {
                maxProfit = prices[i] - cheapestPrice;
            }
        }

        return maxProfit;
    }
};