class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<int> prev(m+1, 0), cur(m+1, 0);
        for(int j = 0; j <= m; j++) prev[j] = j;

        for(int i = 1; i <= n; i++){
            cur[0] = i;
            for(int j = 1; j <= m; j++){

                if(s[i - 1] == t[j - 1])  cur[j] = 0 + prev[j - 1];
                else cur[j] = 1 + min(prev[j], min(cur[j - 1], prev[j-1]));
                // replace....insert....delete
                
            }
            prev = cur;
        }

        return prev[m];
    }
};
// class Solution {
// private:
//     int f(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
//         if (i == 0)
//             return j;
//         if (j == 0)
//             return i;

//         if (dp[i][j] != -1)
//             return dp[i][j];
//         if (s[i - 1] == t[j - 1])
//             return dp[i][j] = 0 + f(i - 1, j - 1, s, t, dp);

//         return dp[i][j] =
//                    1 + min(f(i - 1, j - 1, s, t, dp),
//                            min(f(i, j - 1, s, t, dp), f(i - 1, j, s, t, dp)));
//         // replace....insert....delete
//     }

// public:
//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();

//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

//         return f(n, m, word1, word2, dp);
//     }
// };
// class Solution {
// private:
//     int f(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
//         if (i == 0)
//             return j;
//         if (j == 0)
//             return i;

//         if (dp[i][j] != -1)
//             return dp[i][j];
//         if (s[i - 1] == t[j - 1])
//             return dp[i][j] = 0 + f(i - 1, j - 1, s, t, dp);

//         return dp[i][j] =
//                    1 + min(f(i - 1, j - 1, s, t, dp),
//                            min(f(i, j - 1, s, t, dp), f(i - 1, j, s, t, dp)));
//         // replace....insert....delete
//     }

// public:
//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();

//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

//         return f(n, m, word1, word2, dp);
//     }
// };