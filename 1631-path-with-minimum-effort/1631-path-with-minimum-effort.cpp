class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        // {differene, {row, col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        vector<vector<int>>dis(n , vector<int>(m , 1e9));
        dis[0][0] = 0;

        pq.push({0, {0,0}});
        
        while(!pq.empty()){
            auto it = pq.top();
            int dif = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();

            if(row == n-1 && col == m-1) return dif;

            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m){
                    int newdif = max(abs(heights[row][col] - heights[nrow][ncol]) , dif);
                         if(newdif < dis[nrow][ncol]){
                            dis[nrow][ncol] = newdif;
                            pq.push({newdif, {nrow, ncol}});
                         }
                    }
                } 
            }
        return 0;
    }
};