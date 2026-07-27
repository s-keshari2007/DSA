class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<int> count(n, 0);
        vector<vector<pair<int, int>>> adj(n);

        for(auto &e: edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        for(int i = 0; i < n; i++){
            int src = i;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            vector<int> dis(n, INT_MAX);

            dis[src] = 0;

            pq.push({0, src});

            while(!pq.empty()){
                auto p = pq.top();
                int node = p.second;
                int distance = p.first;
                pq.pop();

                for(auto it: adj[node]){
                    int adjnode = it.first;
                    int wt = it.second;
                    if(dis[node] + wt  < dis[adjnode] && (dis[node] + wt) <= distanceThreshold){
                        dis[adjnode] = dis[node] + wt;
                        pq.push({dis[adjnode], adjnode});
                    }
                }
            }
            int reachable = 0;
            for(int j = 0; j < n; j++){
                if(j != i && dis[j] <= distanceThreshold) reachable++;
    }
    count[i] = reachable;
        }
        int mini = INT_MAX;
        int ans ;
        for(int i = 0; i < n; i++){
            if(count[i] <= mini){
                mini = count[i];
                ans = i;
            }
        }
        return ans;
    }
};