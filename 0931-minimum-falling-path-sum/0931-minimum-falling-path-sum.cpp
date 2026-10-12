class Solution {
private:
    int fall(int row,int col,int n,vector<vector<int>>& matrix, vector<vector<int>> &dp){
        if(row == n - 1) return matrix[row][col];
        if(dp[row][col] != 1e9) return dp[row][col];
        int left = INT_MAX;
        int right = INT_MAX;
        if(col - 1 >= 0){
            left = fall(row + 1, col - 1,n, matrix, dp);
        }
        if(col + 1 <= n-1){
            right = fall(row + 1, col + 1,n, matrix, dp);
        }

        int bottom = fall(row + 1, col,n, matrix, dp);
        return dp[row][col] = matrix[row][col] + min(bottom, min(left, right));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        vector<vector<int>> dp(n, vector<int>(n,1e9));
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            ans = min(ans, fall(0, i, n ,matrix,dp));
        }
        return ans;
    }
};