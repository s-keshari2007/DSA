class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // done via bfs
        queue<pair<string, int>> q; // to store the current word in the word log && int contain number of transformation
        q.push({beginWord, 1});// 1 is the number of transformation
        unordered_set<string> st(wordList.begin(), wordList.end()); // List is stored in a set to reduce TC in searrching word
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endWord) return steps;

            // TC = 26 * word.length() * time taken by set to find the word
            for(int i = 0; i < word.size(); i++){
                char original = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;

                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps+1});
                    } 
                }
                word[i] = original;
            }
        }
        return 0; //endword not found in the word list
    }
};