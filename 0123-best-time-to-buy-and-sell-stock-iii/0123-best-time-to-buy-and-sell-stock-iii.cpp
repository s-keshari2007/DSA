class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int ind = n - 1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy ++){
                for(int tra = 0; tra <= 1; tra++){
                    int profit = 0;
                    if (buy == 1) {
                        profit = max(-prices[ind] + dp[ind + 1][0][tra],
                                    dp[ind + 1][1][tra]);
                    } else {
                        profit = max(prices[ind] + dp[ind + 1][1][tra+1],
                                    dp[ind + 1][0][tra]);
                    }

                    dp[ind][buy][tra] = profit;
                }
            }
        }
        return dp[0][1][0];
    }
};