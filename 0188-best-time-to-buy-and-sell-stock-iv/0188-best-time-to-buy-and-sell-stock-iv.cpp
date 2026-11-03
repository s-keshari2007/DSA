class Solution {
private:
    int f(int ind, int buy, vector<int>& prices, int n, vector<vector<vector<int>>>& dp, int tra) {
        if (tra < 0) return 0;      // completed k transactions
        if (ind == n) return 0;

        if (dp[ind][buy][tra] != -1) return dp[ind][buy][tra];

        int profit = 0;
        if (buy == 1) {
            profit = max(-prices[ind] + f(ind + 1, 0, prices, n, dp, tra),
                         f(ind + 1, 1, prices, n, dp, tra));
        } else {
            profit = max(prices[ind] + f(ind + 1, 1, prices, n, dp, tra - 1),
                         f(ind + 1, 0, prices, n, dp, tra));
        }

        return dp[ind][buy][tra] = profit;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k, -1)));
        return f(0, 1, prices, n, dp, k - 1);
    }
};