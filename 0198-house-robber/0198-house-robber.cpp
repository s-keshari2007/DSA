class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() ==1) return nums[0];
        int n = nums.size();
        vector<int>dp(n, INT_MIN);

        dp[0] = nums[0];
        dp[1] = nums[1];

        for(int i = 0; i < n; i++){
            
            int step = -1;
            for(int j = 0; j < i; j++){
                if(i - j > 1){
                    int step = nums[i] + dp[j];
                    dp[i] = max(dp[i], step);
                }
            }
        }

        int ans = -1;
        for(int i = 0; i  < n; i++){
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};