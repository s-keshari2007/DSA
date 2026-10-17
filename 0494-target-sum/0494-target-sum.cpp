class Solution {
private:
    int f(int ind,vector<int>& nums,int target, int sum, vector<vector<int>>& dp, int k){
        if(ind == 0){
            if(sum + nums[0] == target && sum - nums[0] == target) return 2;
            else if (sum + nums[0] == target || sum - nums[0] == target)return 1;
            else return 0;
        }
        if(dp[ind][sum + k] != -1) return dp[ind][sum + k];

        int negative = f(ind - 1, nums, target, sum - nums[ind], dp, k);
        int positive = f(ind  - 1, nums, target, sum + nums[ind], dp, k);

        return dp[ind][sum + k] = negative + positive;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int k = 0;
        for(auto it: nums) k += it; 

        if (abs(target) > k) return 0;

        vector<vector<int>>dp(n, vector<int>((2*k)+1, -1));
        return f(n - 1, nums, target, 0, dp, k);
    }
};