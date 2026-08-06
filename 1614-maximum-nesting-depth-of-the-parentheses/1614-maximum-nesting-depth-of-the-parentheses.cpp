class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        stack<char> st;

        for(auto ch : s){
            if(ch == '('){
                st.push(ch);
                maxi = max((int)st.size(),maxi);
            }
            else if(st.size() != 0 && ch == ')'){
                st.pop();
            }
        }

        return maxi;
    }
};