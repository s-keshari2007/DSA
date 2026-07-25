class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int,long long>>> adj(n);
        for (auto &e : roads) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> dis(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        dis[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if (time > dis[node]) continue; // stale entry, skip

            for (auto &[adjnode, t] : adj[node]) {
                long long newDist = time + t;

                if (newDist < dis[adjnode]) {
                    dis[adjnode] = newDist;
                    ways[adjnode] = ways[node];
                    pq.push({newDist, adjnode});
                } 
                else if (newDist == dis[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % MOD;
                    // no need to push again, dist didn't change
                }
            }
        }

        return ways[n-1];
    }
};