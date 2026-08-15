// class Solution {
// public:
//     bool isAnagram(string s, string t) {

//         if(s.length() != t.length()) return false;

//         int n = s.length();
        
//         int sl[26] = {};
//         int tl[26] = {};

//         for(int i = 0; i <n; i++){
//             sl[s[i]  - 'a']++;
//             tl[t[i]  - 'a']++;
//         }
//         for(int i = 0; i < 26; i++){
//             if(sl[i] != tl[i]) return false;
//         }
//         return true;
//     }
// };
class Solution {
    public:
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    unordered_map<char32_t, int> counts;
    // (assuming s and t are already decoded into sequences of code points,
    // e.g. via char32_t or a Unicode-aware string type)

    for (char32_t c : s) counts[c]++;
    for (char32_t c : t) {
        if (counts.find(c) == counts.end()) return false;
        if (--counts[c] < 0) return false;
    }
    return true;
}
};