class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        // min-heap: {bottleneck_value, row, col}
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0,0}});
        
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        while (!pq.empty()) {
            auto it = pq.top();
            int d = it.first;
            int x = it.second.first;
            int y = it.second.second;
            pq.pop();
            
            if (d > dist[x][y]) continue; // stale entry, skip
            if (x == n-1 && y == n-1) return d;
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                
                int newBottleneck = max(d, grid[nx][ny]);
                if (newBottleneck < dist[nx][ny]) {
                    dist[nx][ny] = newBottleneck;
                    pq.push({newBottleneck, {nx, ny}});
                }
            }
        }
        return -1; // unreachable, shouldn't happen for valid input
    }
};