class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n-1]; // start from the bottom row

        for (int row = n - 2; row >= 0; row--) {
            for (int j = 0; j <= row; j++) {
                dp[j] = triangle[row][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};