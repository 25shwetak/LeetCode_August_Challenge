/*

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(3, vector<int>(2, 0)));
        dp[0][1][0] = numeric_limits<int>::max();
        dp[0][2][0] = numeric_limits<int>::max();
        for (int i = 0; i < prices.size(); ++i) {
            dp[i+1][2][1] = max(dp[i][2][1], prices[i] - dp[i][2][0]);
            dp[i+1][2][0] = min(dp[i][2][0], prices[i] - dp[i][1][1]);
            dp[i+1][1][1] = max(dp[i][1][1], prices[i] - dp[i][1][0]);
            dp[i+1][1][0] = min(dp[i][1][0], prices[i]);
        }
        
        return dp[prices.size()][2][1];
    }
};
