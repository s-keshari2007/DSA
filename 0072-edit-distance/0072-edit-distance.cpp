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