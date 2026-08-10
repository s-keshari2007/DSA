class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 1;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            // after loop, left+1 to right-1 is the valid palindrome
            int len = right - left - 1;
            if (len > maxLen) {
                maxLen = len;
                start = left + 1;
            }
        };

        for (int i = 0; i < s.size(); i++) {
            expand(i, i);       // odd length, center = i
            expand(i, i + 1);   // even length, center = gap between i, i+1
        }

        return s.substr(start, maxLen);
    }
};