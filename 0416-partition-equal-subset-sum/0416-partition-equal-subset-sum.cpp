class Solution {
private:
    bool f(int index, int target,vector<int>& nums, vector<vector<int>> &dp){
        if(target == 0) return true; 
        if(index == 0) return (nums[0] == target);
        
        if(dp[index][target] != -1) return dp[index][target];
        
        bool notTake = f(index - 1, target, nums, dp);
        bool take = false;
        if(target >= nums[index]) take = f(index - 1, target  - nums[index], nums, dp);
        
        return dp[index][target] = take || notTake ;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n  = nums.size();
        int sum = 0;
        for(auto it: nums){
            sum += it; 
        }
        if(sum % 2 != 0) return false;
        int k = sum / 2;
        vector<vector<int>> dp(n , vector<int>(k+1,  -1));
        return f(n-1, k, nums, dp);
    }
};