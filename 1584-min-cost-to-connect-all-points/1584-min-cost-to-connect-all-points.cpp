class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // we are creating adjancey list from points
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);

        vector<vector<int>> edges;

        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j  < n; j++){
                int d;
                d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({i, j , d});
            }
        }

        for(auto &e: edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }


        vector<int> vis(n,0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        int sum = 0;
        
        //{wt, node}
        pq.push({0,0});
        
        // E is the TC of this while loop and not the whole loop
        while(!pq.empty()){
            
            //log(E)
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            
            if(vis[node] == 1) continue;
            vis[node] = 1;
            sum += wt;
            
            // Elog(E)
            for(auto it : adj[node]){
                int adjnode = it.first;
                int Ew = it.second;
                if(vis[adjnode] == 0){
                    pq.push({Ew, adjnode});
                }
            }
        }
        
        // overall complexity is Elog(E) + Elog(E) == Elog(E)
        return sum;
    }
};