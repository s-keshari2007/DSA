class Solution {
private:
    int f(int ind, int prev,vector<int>& nums,int n,vector<vector<int>> &dp){
        if(ind == n) return 0;
        if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1]; //coordinate shift is being done to avoid -1 thing

        int notTake = f(ind + 1, prev, nums,n,dp);

        int take = 0;
        if(prev == -1 || nums[ind] > nums[prev]){
            take = 1 + f(ind + 1, ind, nums,n,dp);
        } 
        return dp[ind][prev + 1] = max(notTake, take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n , vector(n + 1, -1));
        return f(0, -1, nums,n, dp);
    }
};