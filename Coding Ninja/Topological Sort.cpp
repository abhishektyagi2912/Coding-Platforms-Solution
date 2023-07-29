#include <bits/stdc++.h> 

void topo(unordered_map<int,list<int>>& adj,vector<bool>& visited,stack<int>& st,int node){
    visited[node] = true;
    for(auto x: adj[node]){
        if(!visited[x]){
            topo(adj,visited,st,x);
        }
    }
    st.push(node);

}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>> adj;
    for(int i =0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
    vector<bool> visited(v);
    stack<int> st;
    for(int i =0;i<v;i++){
        if(!visited[i]){
            topo(adj,visited,st,i);
        }
    }
    vector<int>ans;

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
