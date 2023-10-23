class Solution {
public:

    int find(int node,vector<int>&parent){
        while(parent[node] != node){
            node = parent[node];
        }
        return node;
    }

    void unionSet(vector<int>& parent, int x, int y) {
        int rootX = find(x,parent );
        int rootY = find(y,parent );
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
         int n = edges.size();
         vector<int> parent(n+1);

         for(int i=0;i<=n; i++){
            parent[i] = i;
         }

         for(auto edge : edges){
             if(find(edge[0],parent) == find(edge[1],parent)) return edge;
             unionSet(parent,edge[0],edge[1]);
         }

         return {};
    }
};
