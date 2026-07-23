class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto &e: flights){
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<int> dis(n, 1e9);

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}}); // {stops, {node, cost}}

        dis[src] = 0;

        while(!q.empty()){
            auto it  = q.front();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            q.pop();    

            if(stops > k) continue;
            for(auto it : adj[node]){
                int adjnode =  it.first;
                int edw = it.second;
                
                if(cost + edw < dis[adjnode] && stops <= k){
                    dis[adjnode] = cost + edw;
                    q.push({stops+1, {adjnode, cost + edw}});
                }
            }
        }
        if(dis[dst] == 1e9) return -1;

        return dis[dst];
    }
};