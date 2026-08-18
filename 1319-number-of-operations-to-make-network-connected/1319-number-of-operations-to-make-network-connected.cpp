class Solution {
private:
    void DFS(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]) DFS(it, adj, vis);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if((int)connections.size() < n - 1) return -1;

        vector<vector<int>> adj(n);
        for(auto& it : connections){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        int components = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                DFS(i, adj, vis);
                components++;
            }
        }
        return components - 1;
    }
};