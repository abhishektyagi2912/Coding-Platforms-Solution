#include<bits/stdc++.h>

bool dfs(unordered_map<int,list<int>> &adj,vector<bool>& visited,vector<bool>& dfsVisited, int node){
  visited[node] = true;
  dfsVisited[node] = true;

  for(auto x: adj[node]){
    if(!visited[x]){
      bool ans =dfs(adj,visited,dfsVisited,x);
      if(ans) return true;
    }
    else if(dfsVisited[x]){
      return true;
    }
  }
  dfsVisited[node] = false;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int,list<int>> adj;
  for(int i =0;i<edges.size();i++){
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }
  vector<bool> visited(n);
  vector<bool>dfsVisited(n);
  for(int i =0;i<n;i++){
    if(!visited[i]){
      if(dfs(adj,visited,dfsVisited,i)){
        return 1;
      }
    }
  }
  return 0;
}
