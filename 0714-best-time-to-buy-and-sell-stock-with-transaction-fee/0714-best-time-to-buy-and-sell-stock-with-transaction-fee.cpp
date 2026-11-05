class Solution {
private:
    int f(int ind, int buy,vector<int>& prices, int n, vector<vector<int>> &dp, int fee){
        if(ind == n) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;
        if(buy == 1){
            profit = max(-prices[ind] + f(ind + 1, 0, prices, n,dp,fee), 0 + f(ind + 1, 1, prices, n,dp,fee));
        }

        else{
            profit = max(prices[ind] + f(ind + 1, 1, prices, n,dp,fee) - fee , 0 + f(ind + 1, 0, prices, n,dp, fee));
        }

        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n  = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, n,dp,fee);
    }
};
// class Solution {
// public:
//     int maxProfit(vector<int>& prices, int fee) {
//         int n  = prices.size();
//         vector<int> ahead(2, 0), cur(2, 0);
        
//         for(int ind = n - 1; ind >= 0; ind --){
//             for(int buy = 0; buy <= 1; buy++){
//                 int profit = 0;
//                 if(buy == 1){
//                     profit = max(-prices[ind] + ahead[0], 0 + ahead[1]);
//                 }

//                 else{
//                     profit = max(prices[ind] + ahead[1] - fee , 0 + ahead[0]);
//                 }
//                 cur[buy] = profit;
//             }
//             ahead = cur;
//         }
//         return ahead[1];
//     }
// };