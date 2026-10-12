class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));

        // Base case: last row
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = matrix[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int best = dp[i + 1][j];                 // straight down
                if (j > 0)     best = min(best, dp[i + 1][j - 1]);  // down-left
                if (j < n - 1) best = min(best, dp[i + 1][j + 1]);  // down-right
                dp[i][j] = matrix[i][j] + best;
            }
        }

        int mini = 1e9;
        for (int i = 0; i < n; i++) {
            mini = min(mini, dp[0][i]);
        }
        return mini;
    }
};