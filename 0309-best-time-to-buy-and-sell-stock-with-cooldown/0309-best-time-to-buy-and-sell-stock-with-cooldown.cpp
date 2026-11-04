class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    for(int ind = n - 1; ind >= 0; ind--){
        // buy = 1: we may buy
        dp[ind][1] = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
        // buy = 0: we hold a stock, may sell (then cooldown)
        dp[ind][0] = max(prices[ind] + dp[ind + 2][1], dp[ind + 1][0]);
    }
    return dp[0][1];
}
};