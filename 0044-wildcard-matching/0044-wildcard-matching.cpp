class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // Base case 1: empty s matches empty p
        dp[0][0] = true;

        // Base case 2: i == 0, p must be all '*' up to j
        for(int j = 1; j <= m; j++){
            if(p[j - 1] == '*') dp[0][j] = dp[0][j - 1];
            else break;   // stays false from here on
        }

        // Base case 3: j == 0 and i > 0 is already false

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(p[j - 1] == '*'){
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                else if(p[j - 1] == '?' || s[i - 1] == p[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};