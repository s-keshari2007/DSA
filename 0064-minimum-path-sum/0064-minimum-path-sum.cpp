// class Solution {
// public:
//     int sum(int i, int j, vector<vector<int>>& grid,vector<vector<int>> &dp){
//         if(i == 0 && j== 0){
//             return grid[0][0];
//         }
//         int up = INT_MAX; 
//         int left = INT_MAX;

//         if(dp[i][j] != -1) return dp[i][j];

//         if(i > 0) up = sum(i - 1, j, grid,dp);
//         if(j > 0) left = sum(i, j-1, grid,dp);

//         return dp[i][j] = grid[i][j] + min(up,left);
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         vector<vector<int>> dp(m, vector<int>(n,-1));

//         return sum(m-1, n-1, grid, dp);
//         }
// };

// code for tabulation 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n,-1));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) dp[0][0] = grid[i][j];
                else{
                    int up = INT_MAX;
                    int down = INT_MAX;

                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) down = dp[i][j-1];

                    dp[i][j] = grid[i][j] + min(up,down);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
