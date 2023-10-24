class Solution {
public:
    bool dfs(int node, vector<int>& visited, vector<vector<int>>& adjList, stack<int>& st) {
        visited[node] = 1; 
        for (auto it : adjList[node]) {
            if (visited[it] == 1) {
                return false; // Cycle detected
            } else if (visited[it] == 0) {
                if (!dfs(it, visited, adjList, st)) {
                    return false;
                }
            }
        }
        visited[node] = 2; // Mark the node as visited and added to the stack
        st.push(node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        int n = prerequisites.size();
        for(auto x : prerequisites){
            int i = x[0];
            int j = x[1];
            adjList[j].push_back(i);
        }
        vector<int> visited(numCourses, 0);
        stack<int> st;

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (!dfs(i, visited, adjList, st)) {
                    return vector<int>(); // Return an empty vector to indicate a cycle
                }
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
