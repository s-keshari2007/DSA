class Solution {
private:
    bool dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st){
        vis[node] = 1; // 1 = currently in recursion stack

        for(auto it : adj[node]){
            if(vis[it] == 1){
                // back edge to a node on the current path -> cycle
                return false;
            }
            if(vis[it] == 0){
                if(!dfs(it, vis, adj, st)) return false;
            }
            // if vis[it] == 2, it's already fully processed, safe to skip
        }

        vis[node] = 2; // 2 = fully processed
        st.push(node);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0);
        stack<int> st;
        for(auto &e : prerequisites){
            adj[e[1]].push_back(e[0]);
        }
        for(int i = 0; i < numCourses; i++){
            if(vis[i] == 0){
                if(!dfs(i, vis, adj, st)) return {}; // cycle found -> no valid order
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};