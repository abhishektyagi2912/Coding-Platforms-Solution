class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        // Code here
        vector<vector<int>> ans;
        
        for(int i=0;i<V;i++){
            vector<int> temp;
            temp.push_back(i);
            for(auto x: adj[i]){
                temp.push_back(x);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
