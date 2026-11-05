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
// class Solution {
// private:
//     int f(int ind, int buy, vector<int>& prices, int n, vector<vector<vector<int>>>& dp, int tra) {
//         if (tra == 2) return 0;      // completed 2 transactions
//         if (ind == n) return 0;

//         if (dp[ind][buy][tra] != -1) return dp[ind][buy][tra];

//         int profit = 0;
//         if (buy == 1) {
//             profit = max(-prices[ind] + f(ind + 1, 0, prices, n, dp, tra),
//                          f(ind + 1, 1, prices, n, dp, tra));
//         } else {
//             profit = max(prices[ind] + f(ind + 1, 1, prices, n, dp, tra + 1),
//                          f(ind + 1, 0, prices, n, dp, tra));
//         }

//         return dp[ind][buy][tra] = profit;
//     }

// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
//         return f(0, 1, prices, n, dp, 0);
//     }
// };