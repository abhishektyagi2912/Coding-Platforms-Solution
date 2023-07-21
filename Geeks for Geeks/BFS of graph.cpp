class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int>vis(V,0);
        vis[0]=1;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            for(auto x:adj[temp]){
                if(!vis[x]){
                    q.push(x);
                    vis[x] = 1;
                }
            }
        }
        return ans;
    }
};
