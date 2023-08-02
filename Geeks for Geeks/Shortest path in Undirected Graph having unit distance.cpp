class Solution {
  public:
    void dfs(int src,vector<int> adj[],vector<int> &ans){ 
      ans[src]++;
      int val=ans[src]+1;
      for(auto it:adj[src]){
          if(ans[it]==-1){
              ans[it]=ans[src];
              dfs(it,adj,ans);
            }
          else{
              if(ans[it]>val){
                  ans[it]=ans[src];
                  dfs(it,adj,ans);
                }
            }
        }
    }
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        vector<int> ans(N,-1);
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
             adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(src,adj,ans);
        return ans;
    }
};
