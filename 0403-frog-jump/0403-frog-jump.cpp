class Solution {
    unordered_map<int,int> mpp;      // stone value -> index
    int n;
    vector<vector<int>> memo;        // memo[pos][jump]: -1 unknown, 0 false, 1 true
    bool solve(int pos, int jump, vector<int>& stones) {
        if (pos == n - 1) return true;
        if (pos < 0 || pos >= n) return false;              // defensive
        if (memo[pos][jump] != -1) return memo[pos][jump];  // cached!
        for (int k = -1; k <= 1; ++k) {
            int nextJump = jump + k;
            if (nextJump <= 0) continue;
            if (mpp.find(stones[pos] + nextJump) != mpp.end())
                if (solve(mpp[stones[pos] + nextJump], nextJump, stones))
                    return memo[pos][jump] = true;
        }
        return memo[pos][jump] = false;
    }
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false;
        n = stones.size();
        memo.assign(n, vector<int>(n + 1, -1));
        for (int i = 0; i < stones.size(); ++i) mpp[stones[i]] = i;
        return solve(0, 0, stones);
    }
};