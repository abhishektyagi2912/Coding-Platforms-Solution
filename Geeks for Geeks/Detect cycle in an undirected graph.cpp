lass Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool dfs(vector<int> adj[],vector<bool>& visited, int node,int parent){
        visited[node] = true;
        
        for(auto x: adj[node]){
            if(!visited[x]){
                bool ans = dfs(adj,visited,x,node);
                if(ans) return true;
            }
            else if(x != parent ) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V);
        for(int i =0;i<V;i++){
            if(!visited[i]){
                bool ans = dfs(adj,visited,i,-1);
                if(ans == 1) return 1;
            }
         }
        return 0;
    }
};
