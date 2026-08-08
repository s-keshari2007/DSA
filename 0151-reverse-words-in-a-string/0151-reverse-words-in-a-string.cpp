class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string ans;

        int i = 0;
        for(i; i < s.size(); i++){
             if(s[i] == ' '){
                continue;
             }
             else{
                int initial = i;
                while( i < s.size() && s[i] != ' '){
                    i++;
                }
                string word = s.substr(initial, i - initial);
                st.push(word);
             }
        }
        while(!st.empty()){
            if(st.size() != 1){
            ans += st.top() + " ";
            st.pop();
            }
            else{
                ans += st.top();
                st.pop();
            }
        }
        return ans;
    }
};