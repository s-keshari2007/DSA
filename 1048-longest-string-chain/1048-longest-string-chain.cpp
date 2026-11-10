class Solution {
public:
    bool compare(const string& s1, const string& s2) {
        // s1 should be the shorter one, s2 the longer
        if (s2.size() != s1.size() + 1) return false;

        int first = 0, second = 0;
        while (first < s1.size() && second < s2.size()) {
            if (s1[first] == s2[second]) {
                first++;
            }
            second++;
        }
        return first == s1.size();
    }

    static bool cmp(const string& a, const string& b) {
        return a.size() < b.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), cmp);

        int maxi = 1;
        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (compare(words[prev], words[i]) && dp[i] < 1 + dp[prev]) {
                    dp[i] = 1 + dp[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};