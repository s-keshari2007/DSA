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
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntextra = 0;
        for(auto it:connections){
            int u = it[0];
            int v = it[1];

            if(ds.FindUpar(u) == ds.FindUpar(v)){
                cntextra++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        int cntComponent = 0;
        for(int i = 0; i < n; i++){  
            if(ds.parent[i] == i){ //when a element points towartds itself it mean it a component boss
                cntComponent++;
            }
        } 
        int ans = cntComponent - 1; // cntComponent - 1 is the number of wires to connect cntComponents
        if(cntextra  >= ans){
            return ans;
        }
        return -1;
    }
};