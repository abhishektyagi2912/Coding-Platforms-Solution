class Solution {
    void dfs(vector<vector<int>>& isConnected,vector<bool>& visited,int node){
        visited[node] = true;
        for(int i =0;i<isConnected.size();i++){
            if(!visited[i] && isConnected[node][i]){
                dfs(isConnected,visited,i);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0;
        int n = isConnected.size();
        vector<bool> visited(n);
        for(int i =0;i<n;i++){
            if(!visited[i]){
                ans++;
                dfs(isConnected,visited,i);
            }
        }
        return ans;
    }
};
