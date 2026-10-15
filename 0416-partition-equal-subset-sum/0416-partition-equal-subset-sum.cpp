class Solution {
private:
    bool subsetK(int n,vector<int>& nums,int k){
        vector<bool> prev(k+1,0), cur(k+1, 0);
        prev[0] = cur[0] = true;
        if(nums[0] <= k) prev[nums[0]] = true;

        for(int ind = 1; ind < n; ind++){
            for(int target = 1; target <= k; target++){
                bool notTake = prev[target];
                bool take = false;
                if(nums[ind] <= target) take = prev[target - nums[ind]];
                cur[target]  = take || notTake;
            }
            prev = cur;
        }
        return prev[k];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n =  nums.size();
        int sum = 0;
        for(auto it: nums){
            sum += it;
        } 
        if(sum % 2 != 0) return false;

        int target = sum / 2;

        return subsetK(n, nums, target);
    }
};