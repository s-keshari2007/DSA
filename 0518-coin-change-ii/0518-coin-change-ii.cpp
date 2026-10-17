class Solution {
private:
    int f(int ind,vector<int>& coins, int target,vector<vector<int>> &dp){
        if(target == 0) return 1;
        
        if(dp[ind][target] != -1)return dp[ind][target];


        int notTake = 0;
        if(ind > 0)notTake = f(ind - 1, coins, target,dp);
        int take = 0;
        if(target >= coins[ind]) take = f(ind, coins, target - coins[ind],dp);

        return dp[ind][target] = take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>>dp(n ,vector<int>(amount + 1,-1));
        //sort(coins.begin(), coins.end());
        return f(n - 1, coins, amount,dp);
    }
};