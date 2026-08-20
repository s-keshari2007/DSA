class DisjointSet{
    

    public:
        vector<int> parent, rank, size;
        DisjointSet(int n){
            // this done using 1  based indexing    z
            rank.resize(n+1, 0);
            parent.resize(n+1, 0);
            size.resize(n+1 ,0); 
            for(int i = 0; i <= n; i++){
                parent[i] = i; //firstly  everybody is the parent of itself
                size[i] = 1;
            }
        }

        int FindUpar(int node){
            if(node == parent[node]) return node;

            return parent[node] = FindUpar(parent[node]);
        }

        void unionByRank(int u, int v){
            int ulp_u = FindUpar(u);
            int ulp_v = FindUpar(v);
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
        void unionBySize(int u, int v){
            int ulp_u = FindUpar(u);
            int ulp_v = FindUpar(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
             }
        }


};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int  n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for(auto it: stones){
                maxRow = max(maxRow, it[0]);
                maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1); // 1 is taken as security measure
        unordered_map<int,int> stoneNodes;
        for(auto it: stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1; //just use it for storing the present coloums and rows  
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;
        for(auto it: stoneNodes){
            if(ds.FindUpar(it.first) == it.first){
                cnt++;
            }
        }
        return n - cnt;
    }
};