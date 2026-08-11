class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";
        for(auto ch : s){
            if(ch == '(' && st.size() == 0){
                st.push(ch);
            }
            else if(st.size() != 0 && ch == '('){
                st.push('(');
                ans = ans + '(';
            }
            else if(ch == ')' && st.size() != 1){
                st.pop();
                ans = ans + ')'; 
            }
            else {
                st.pop();
            }
        }
        return ans;
    }
};