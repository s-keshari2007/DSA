class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.find(endWord) == st.end()) return ans;

        // parents[word] = list of predecessors that lead to it on a shortest path
        unordered_map<string, vector<string>> parents;

        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visitedThisLevel;
        st.erase(beginWord);
        bool found = false;

        while(!q.empty() && !found){
            int sz = q.size();
            visitedThisLevel.clear();

            for(int i = 0; i < sz; i++){
                string word = q.front();
                q.pop();

                for(int j = 0; j < (int)word.size(); j++){
                    string temp = word;
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        if(ch == word[j]) continue;
                        temp[j] = ch;

                        if(st.count(temp)){
                            // first time seeing 'temp' on this level -> push to queue
                            if(visitedThisLevel.find(temp) == visitedThisLevel.end()){
                                visitedThisLevel.insert(temp);
                                q.push(temp);
                            }
                            parents[temp].push_back(word);

                            if(temp == endWord) found = true;
                        }
                    }
                }
            }

            // remove all words used on this level so they aren't reused on deeper levels
            for(auto& w : visitedThisLevel){
                st.erase(w);
            }
        }

        if(!found) return ans;

        // backtrack from endWord to beginWord using parents map
        vector<string> path = {endWord};
        function<void(string&)> backtrack = [&](string& word){
            if(word == beginWord){
                vector<string> temp(path.rbegin(), path.rend());
                ans.push_back(temp);
                return;
            }
            for(auto& p : parents[word]){
                path.push_back(p);
                backtrack(p);
                path.pop_back();
            }
        };

        backtrack(path[0]);
        return ans;
    }
};