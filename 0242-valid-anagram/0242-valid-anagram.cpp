class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()) return false;

        int n = s.length();
        
        int sl[26] = {};
        int tl[26] = {};

        for(int i = 0; i <n; i++){
            sl[s[i]  - 'a']++;
            tl[t[i]  - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(sl[i] != tl[i]) return false;
        }
        return true;
    }
};