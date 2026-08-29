class Solution {
public:
    int minAddToMakeValid(string s) {
        int clo = 0;
        int op = 0;

        stack<char> st;

        for(char ch: s){
            if(st.size() != 0 && ch  == ')'){
                if(st.top() == '('){
                    st.pop();
                    clo--;
                }
                else{
                    st.push(ch);
                    op++;
                }
            }
            else{
                st.push(ch);
                if(ch == '('){
                    op++;
                }
                else{
                    clo++;
                }
            }
        }
        return  clo+op;
    }
};