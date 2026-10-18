class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount + 1, 0));

        // base case: only the first coin available
        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0) dp[0][target] = 1;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= amount; target++) {
                unsigned long long notTake = dp[ind - 1][target];
                unsigned long long take = 0;
                if (target >= coins[ind]) take = dp[ind][target - coins[ind]];

                dp[ind][target] = take + notTake;
            }
        }

        return (int)dp[n - 1][amount];
    }
};