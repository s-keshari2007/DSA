class Solution {
public:
string compare(string &a, string &b){
    string s = "";
    for(int i = 0; i < min(a.size(), b.size()); i++){
        if(a[i] == b[i]) s += a[i];
        else break;
    }
    return s;
}
    string longestCommonPrefix(vector<string>& strs) {
            if(strs.size() == 1) return strs[0];
            string ans = "";
            int n = strs.size();

            ans = compare(strs[0], strs[1]);

            for(int i = 2; i < n ; i++){

                ans = compare(ans, strs[i]);

                if(ans == "") break;
            }


            return ans;
    }
};