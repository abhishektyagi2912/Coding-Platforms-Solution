class Solution {
public:
    bool dfs(int node, vector<bool>& visited,vector<bool>& curr, vector<int>adj[]){
        visited[node] = true;
        curr[node] = true;
        for(int x: adj[node]){
            if(!visited[x]){
                if(dfs(x,visited,curr,adj)) return true;
            }
            else if(visited[x]&&curr[x]) return true;
        }
        curr[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<bool> visited(numCourses,false),curr(numCourses,false);
        for(auto x: prerequisites){
            int i = x[0];
            int j = x[1];
            adj[i].push_back(j);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,visited,curr,adj)) return false;
            }
        }
        return true;
    }
};
