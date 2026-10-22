class Solution {
private:
    int f(int st, int end, string &s, vector<vector<int>> &dp){
        if(st >= end) return 0;

        if(dp[st][end] != -1) return dp[st][end];
        
        if(s[st] == s[end])return dp[st][end] = 0 + f(st + 1, end - 1, s,dp);

        return dp[st][end] = 1 + min(f(st + 1, end, s,dp), f(st, end - 1, s,dp));
    }
public:
    int minInsertions(string s) {
        int  n = s.size();
        vector<vector<int>> dp(n , vector(n, -1));
        return f(0, n - 1, s,dp);
    }
};