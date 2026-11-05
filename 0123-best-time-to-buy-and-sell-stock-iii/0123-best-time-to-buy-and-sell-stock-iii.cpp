class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(3, 0)), cur(2, vector<int>(3, 0));
        for(int ind = n - 1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy ++){
                for(int tra = 0; tra <= 1; tra++){
                    int profit = 0;
                    if (buy == 1) {
                        profit = max(-prices[ind] + ahead[0][tra],
                                    ahead[1][tra]);
                    } else {
                        profit = max(prices[ind] + ahead[1][tra+1],
                                    ahead[0][tra]);
                    }

                    cur[buy][tra] = profit;
                }
            }
            ahead = cur;
        }
        return cur[1][0];
    }
};