class Solution {
private:
bool dfs(vector<int> &vis, vector<vector<int>>& adj, int node){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(vis[it] == 1){
            return false; // a cylce is detected;
        }
        if(vis[it] == 0){
            if(!(dfs(vis, adj, it))) return false;
        }
    }
    vis[node] = 2; // fully processed node
    return true;
}

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0);

        for(auto &e : prerequisites){
            adj[e[1]].push_back(e[0]);
        }

        for(int i = 0; i < numCourses; i++){
            if(vis[i] == 0){
                if(!(dfs(vis, adj, i))) return false; //cycle detected
            } 
        }

        return true;    

    }
};