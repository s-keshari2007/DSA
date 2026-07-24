class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> vis(n+1);

        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &e : times){
            adj[e[0]].push_back({e[1], e[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k}); // {time , node}
        int time_taken = 0;

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            
            int node = p.second;
            int time = p.first;

            if(vis[node] == 0){
                time_taken = max(time , time_taken);
                vis[node] = 1;
            }

            for(auto it: adj[node]){
                int adjnode = it.first;
                int t = it.second;

                if(vis[adjnode] == 0){
                    pq.push({time + t, adjnode});
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(vis[i] == 0) return -1;
        }
        return time_taken ;
    }
};