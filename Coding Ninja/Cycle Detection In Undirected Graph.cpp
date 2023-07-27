#include <unordered_map>
#include<list>
#include<queue>
bool isCyclic(int node, unordered_map<int,list<int>>& adj,vector<bool>& visited){
    unordered_map<int,int> parent;
    parent[node] = -1;
    visited[node] = 1;
    queue<int>q;
    q.push(node);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto x: adj[front]){
            if(visited[x]==1 && x != parent[front]) return true;
            else if(!visited[x]){
                q.push(x);
                visited[x]=1;
                parent[x] = front;
            }
        }
    }
    return false;

}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int,list<int>> adj;
    for(int i =0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>visited(m);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans = isCyclic(i,adj,visited);
            if(ans==1) return "Yes";
        }
    }
    return "No";
}
