class Solution {
public:
    int MOD = 1e9 + 7;
    vector<int> pw;
    unordered_map<long long, int> memo;

    int f(int l, int r, vector<int>& nums, int target) {
        if (l > r) return 0;

        long long key = (long long)l * 100001 + r;
        if (memo.count(key)) return memo[key];

        int res;
        if (nums[l] + nums[r] > target)
            res = f(l, r - 1, nums, target);
        else
            res = (pw[r - l] + f(l + 1, r, nums, target)) % MOD;

        return memo[key] = res;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        pw.resize(nums.size() + 1);
        pw[0] = 1;
        for (int i = 1; i < pw.size(); i++)
            pw[i] = pw[i - 1] * 2 % MOD;

        return f(0, nums.size() - 1, nums, target);
    }
};