class DisjointSet{
    

    public:
        vector<int> parent, rank, size;
        DisjointSet(int n){
            // this done using 1  based indexing   
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
private:
    bool isValid(int newr, int newc, int n){
        if(newr >=0 && newr < n && newc >=0 && newc < n){
            return true;
        }
        return false;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
       int n  = grid.size();
       DisjointSet ds(n*n);
       
    // this is the the part where we are adding the the combining islands 
       for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 0) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};
                for(int i = 0;  i < 4; i++){
                    int newr = row + dr[i];
                    int newc = col + dc[i];
                    if(isValid(newr,newc,n) && grid[newr][newc] == 1){
                        int nodeNo = row*n + col;
                        int adjNodeNo = newr*n + newc;
                        ds.unionBySize(nodeNo,adjNodeNo);
                    }
                }

            }
       }
    //    this  step turns 0 -> 1 and calculate the size
    int mx = 0;
    for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};
                set<int>st;
                for(int i = 0;  i < 4; i++){
                    int newr = row + dr[i];
                    int newc = col + dc[i];
                    if(isValid(newr,newc,n) && grid[newr][newc] == 1){
                        st.insert(ds.FindUpar(newr*n + newc));
                    }
                }
                int size = 0;
                for(auto it: st){
                    size += ds.size[it];
                }
                mx =  max(mx, size+1);
            }
       }
       // in case the grid contain all 1 
       for(int cellNo = 0; cellNo < n * n; cellNo++){
        mx = max(mx, ds.size[ds.FindUpar(cellNo)]);
       } 

       return mx;
    }
};