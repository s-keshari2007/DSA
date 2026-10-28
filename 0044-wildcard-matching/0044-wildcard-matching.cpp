class Solution {
private:
    bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return true;
        if(j == 0) return false;          // pattern exhausted, s remains
        if(i == 0){                       // s exhausted: rest of p must be all '*'
            for(int k = 0; k < j; k++)
                if(p[k] != '*') return false;
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(p[j - 1] == '*'){
            return dp[i][j] = f(i, j - 1, s, p, dp) || f(i - 1, j, s, p, dp);
        }

        if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
            return dp[i][j] = f(i - 1, j - 1, s, p, dp);

        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(n, m, s, p, dp);
    }
};